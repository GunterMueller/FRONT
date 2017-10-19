/*
 * Copyright (C) 2000-2005 Philips Electronics N.V.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#include <string.h>
#include <limits.h>
#include <math.h>
#include <front/print_support.h>
#include "Fonts.h"
#include "Picture.h"
#include "PicturesPrint.h"

#define PAPER_WIDTH  paper_width*POINT_SIZE
#define PAPER_HEIGHT paper_height*POINT_SIZE
 
Int arrow_size = 6;
Int curve_size = 5;

double Scale = 1.0;	/* Scale factor */

static Int page_height;
static Int page_width;
Int column_width;

Bool landscape = FALSE; /* Print in landscape orientation */
Int columns = 1; 	/* Number of columns */
Bool singlefile = FALSE; /* Produce all pages in one output file */

Int paper_width = 210;  /* A4, mm */
Int paper_height = 297; /* A4, mm */
static Int margin = 40;

static Int col_sep = 20; /* Distance between two columns */
Bool no_arrow = FALSE;
Bool translate_makes_copy = TRUE;

static point tl, br; /* Top-left and bottom-right of visible area */

/*********/

static void swap (Float *x, Float *y)
{
  Float t = *x;
  *x = *y;
  *y = t;
}

static void iswap (Int *x, Int *y)
{
  Int t = *x;
  *x = *y;
  *y = t;
}

/* Operations on points */

point pt (Float x, Float y)
{ point p = {x, y};
  return p;
}

point entry_pt (Picture p)
{ return pt (Picture_x(p), Picture_y(p)+Picture_d(p));
}

point exit_pt (Picture p)
{ return pt (Picture_x(p)+Picture_w(p), Picture_y(p)+Picture_d(p));
}

Picture empty_pic (void)
{
  Picture p = Create_Empty (no_srcinfo, 0, 0, 0, 0);
  Picture_d(p) = 0;
  return p;
}

Picture fill (Picture p)
{ Picture_fill(p) = TRUE;
  return p;
}

Picture dash (Picture p, Int d)
{ Picture_dash(p) = d;
  return p;
}

List_Picture pics1 (Picture a)
{
  if (a == NULL) return NULL;
  return Create_List_Picture (a, NULL);
}

List_Picture pics2 (Picture a, Picture b)
{
  if (a == NULL) return pics1 (b);
  if (b == NULL) return pics1 (a);
  return Create_List_Picture (a, pics1(b));
}

List_Picture pics3 (Picture a, Picture b, Picture c)
{
  if (a == NULL) return pics2 (b, c);
  if (b == NULL) return pics2 (a, c);
  if (c == NULL) return pics2 (a, b);
  return Create_List_Picture (a, pics2(b, c));
}

List_Picture pics4 (Picture a, Picture b, Picture c, Picture d)
{
  if (a == NULL) return pics3 (b, c, d);
  if (b == NULL) return pics3 (a, c, d);
  if (c == NULL) return pics3 (a, b, d);
  if (d == NULL) return pics3 (a, b, c);
  return Create_List_Picture (a, pics3(b, c, d));
}

Picture pic2 (Picture a, Picture b)
{ return compound (pics2 (a,b));
}

Picture pic3 (Picture a, Picture b, Picture c)
{ return compound (pics3 (a,b,c));
}

Picture pic4 (Picture a, Picture b, Picture c, Picture d)
{ return compound (pics4 (a,b,c,d));
}

List_Picture seq (Picture a, List_Picture l)
{
  if (a == NULL) return l;
  return Create_List_Picture (a, l);
}

List_Picture seqs (List_Picture a, List_Picture b)
{
  return (List_Picture)Front_List_concat ((Front_List)a, (Front_List)b);
}

/* Translation by dx,dy */
List_Picture translates (List_Picture l, Int dx, Int dy)
{
  if (l==NULL) return l;
  return seq (translate  (List_Picture_data(l), dx, dy),
              translates (List_Picture_next(l), dx, dy));
}

/* Translation by dx,dy */
Picture translate (Picture p, Int dx, Int dy)
{
  Picture q = p;
  
  if (translate_makes_copy) {
    q = empty_pic ();
    *q = *p;
  }
  Picture_x(q) += dx;
  Picture_y(q) += dy;
  if (Picture_tag(q) == Compound_kind) {
    Compound_sub(q) = translates (Compound_sub(q), dx, dy);
  }
  return q;
}

/* Elements of p next to each other with distance dx */
Picture horizontal (List_Picture p, double dx)
{ List_Picture l;
  double x = 0;
  
  for (l = p; l; l = List_Picture_next (l)) {
    Picture q = List_Picture_data(l);
    List_Picture_data(l) = translate (q, x, 0);
    x += Picture_w(q) + dx;
  }
  return compound (p);
}

/* Elements of p above each other with distance dy */
Picture vertical (List_Picture p, int dy)
{ List_Picture l;
  Float y = 0;
  
  for (l = p; l; l = List_Picture_next (l)) {
    Picture q = List_Picture_data(l);
    List_Picture_data(l) = translate (q, 0, y);
    y += Picture_h(q) + dy;
  }
  return compound (p);
}

/* Change the font if needed */
void set_font (Ident font)
{
  static Ident cur_font = NULL;
  if (font == cur_font) return;
  cur_font = font;
  if (font==NULL) return;
  if (font == Create_Ident("Helvetica")) {
    cur_font_table = helvetica_table;
  } else {
    cur_font_table = courier_table;
  }
  fprintf (print_file, "/%s findfont 10 scalefont setfont\n", Ident_name(font));
}

/* Mirror around x */
static List_Picture hor_flips (List_Picture l, Int x)
{
  if (l == NULL) return NULL;
  return seq (hor_flip  (List_Picture_data(l), x), 
              hor_flips (List_Picture_next(l), x));
}

/* Mirror around x */
Picture hor_flip (Picture p, Int x)
{
  p = COPY_Picture(p); /* copy p */
  Picture_x(p) = 2*x-Picture_x(p)-Picture_w(p);  
  switch (Picture_tag(p)) {
    case Arrow_kind:
      switch (Arrow_dir(p)) {
        case Left:
	  Arrow_dir(p) = Right;
	  break;
        case Right:
	  Arrow_dir(p) = Left;
	  break;
	default: break;
      }
      break;
    case Curve_kind:
      Curve_d1(p) = !Curve_d1(p);
      Curve_d2(p) = !Curve_d2(p);
      break;
    case Compound_kind: {
      Compound_sub(p) = hor_flips (Compound_sub(p), x);
      break;
    }
    default:
      break;
  }
  return p;
}

/* Mirror around y */
static List_Picture ver_flips (List_Picture l, Int x)
{
  if (l == NULL) return NULL;
  return seq (ver_flip  (List_Picture_data(l), x), 
              ver_flips (List_Picture_next(l), x));
}

/* Mirror around y */
Picture ver_flip (Picture p, Int y)
{
  p = COPY_Picture (p); /* copy p */
  Picture_y(p) = 2*y-Picture_y(p)-Picture_h(p);  
  switch (Picture_tag(p)) {
    case Arrow_kind:
      switch (Arrow_dir(p)) {
        case Up:
	  Arrow_dir(p) = Down;
	  break;
        case Down:
	  Arrow_dir(p) = Up;
	  break;
	default: break;
      }
      break;
    case Compound_kind: {
      Compound_sub(p) = ver_flips (Compound_sub(p), y);
      break;
    }
    default:
      break;
  }
  return p;
}

/* Draw a box around p with distance dx,dy to p */
Picture box (Picture p, int dx, int dy, int d)
{
  Float w = Picture_w(p) + 2*dx;
  Float h = Picture_h(p) + 2*dy;
  Picture q = dash (Create_Box  (no_srcinfo, 0, 0, w, h), d);
  return pic2(q, translate (p, dx, dy));
}

/* Put p next to q, at distance dx, centers aligned */
Picture center_horizontally (Picture p, Picture q, Int dx)
{
  Float h1 = Picture_h(p);
  Float h2 = Picture_h(q);
  Float m = MAX(h1,h2);
  Float d1 = MAX (0, m-h1);
  Float d2 = MAX (0, m-h2);
  return pic2 (translate (p, 0,  d1/2),
               translate (q, dx, d2/2));
}

/* Put p above q, at distance dy, centers aligned */
Picture center_vertically (Picture p, Picture q, Int dy)
{
  Float w1 = Picture_w(p);
  Float w2 = Picture_w(q);
  Float m = MAX(w1,w2);
  Float d1 = MAX (0, m-w1);
  Float d2 = MAX (0, m-w2);
  return pic2 (translate (p, d1/2,  0),
               translate (q, d2/2, dy));
}

/* Draw a line from p1 to p2 */
Picture draw_line (Picture p1, Picture p2)
{
  if (p1==NULL) return NULL;
  if (p2==NULL) return NULL;
  { Float x1 = Picture_x(p1);
    Float x2 = Picture_x(p2);
    Float y1 = Picture_y(p1);
    Float y2 = Picture_y(p2);
    return Create_Line (no_srcinfo, x1, y1, x2-x1, y2-y1);
  }
}

/* Group elements of into one picture */
Picture compound (List_Picture l)
{
  List_Picture m;
  Float w=0, h=0;
  
  for (m = l; m; m = List_Picture_next(m)) {
    Picture p = List_Picture_data(m);
    w = MAX (Picture_x(p)+Picture_w(p), w);
    h = MAX (Picture_y(p)+Picture_h(p), h);
  }
  
  return Create_Compound (no_srcinfo, 0, 0, w, h, l);
}

/* Draw a line from a b to */
List_Picture line (point a, point b, Bool hor, Bool arrow, Int cs)
{
  Picture p, q, r = NULL;
  List_Picture l;
  Float w = ABS(a.x-b.x);
  Float h = ABS(a.y-b.y);
  Float dx = a.x < b.x ? -1 : 1;
  Float dy = a.y < b.y ? -1 : 1;
  Bool left_turn = (dx==dy)!=hor;
    
  cs = MIN(cs, w);
  cs = MIN(cs, h);
  w -= cs;
  h -= cs;

  if (hor) {
    Float x1 = MIN(a.x,b.x+dx*cs);
    Float y1 = MIN(a.y-dy*cs,b.y);
    p = Create_Line (no_srcinfo, x1, a.y, w, 0);
    q = Create_Line (no_srcinfo, b.x, y1, 0, h);
    if (cs > 0) {
      Bool d1 = a.x > b.x;
      Bool d2 = a.y < b.y;
      if (d1) x1 = b.x; else x1 = b.x-cs;
      if (d2) y1 = a.y; else y1 = a.y-cs;
      r = Create_Curve(no_srcinfo, x1, y1, cs, cs, d1==d2, d2==left_turn);
    }
  } else {
    Float x1 = MIN(a.x-dx*cs,b.x);
    Float y1 = MIN(a.y,b.y+dy*cs);
    p = Create_Line (no_srcinfo, a.x, MIN(a.y,b.y+dy*cs), 0, h);
    q = Create_Line (no_srcinfo, MIN(a.x-dx*cs,b.x), b.y, w, 0);
    if (cs > 0) {
      Bool d1 = a.x > b.x;
      Bool d2 = a.y < b.y;
      if (d1) x1 = a.x-cs; else x1 = a.x;
      if (d2) y1 = b.y-cs; else y1 = b.y;
      r = Create_Curve(no_srcinfo, x1, y1, cs, cs, d1==d2, d2==left_turn);
    }
  }
  if (r) l = pics3 (p, q, r);
  else l = pics2 (p, q);
  
  if (!arrow) return l;
  
  if (hor) {
    Direction d = a.y < b.y ? Down : Up;
    Float x = b.x - arrow_size/2;
    Float y = d == Down ? b.y-arrow_size : b.y ;
    r = fill (Create_Arrow (no_srcinfo, x, y, arrow_size, arrow_size, d));
  } else {
    Direction d = a.x < b.x ? Right : Left;
    Float x = d == Right ? b.x - arrow_size : b.x;
    Float y = b.y - arrow_size/2;
    r = fill (Create_Arrow (no_srcinfo, x, y, arrow_size, arrow_size, d));
  }
  l = seq (r, l);
#if 0
  if (Picture_x(r) < 0) l = translates (l, -Picture_x(r), 0);
  if (Picture_y(r) < 0) l = translates (l, 0, -Picture_y(r));
#endif
  return l;
}

#define FontSize 10

/* Width of text s in certain font */
Float text_width (String s, Ident font)
{
  Float t = 0;
  font_entry *table;
   if (font == Create_Ident("Helvetica")) {
    table = helvetica_table;
  } else {
    table = courier_table;
  }
  for (; s[0]; s++) {
    t += table[(int)s[0]].width;
  }
  return t * FontSize / 1000;
}

/* Remove string quotes */
static String unquote (String s)
{ int l = strlen(s);
  String t;
  if (s[0] != '\"' && s[l-1] != '\"') return s;
  t = strdup(s);
  t[l-1] = 0;
  return &t[1];
}

/* An oval with top-lef x,y and size w,h */
Picture oval (Int x, Int y, Int w, Int h)
{
  Float r = curve_size*2;
  List_Picture l = NULL;
  l = seqs (line (pt(x, y+h/2),   pt(x+w/2, y),   FALSE, FALSE, r), l);
  l = seqs (line (pt(x+w/2, y),   pt(x+w, y+h/2), TRUE,  FALSE, r), l);
  l = seqs (line (pt(x+w, y+h/2), pt(x+w/2, y+h), FALSE, FALSE, r), l);
  l = seqs (line (pt(x+w/2, y+h), pt(x, y+h/2),   TRUE,  FALSE, r), l);
  return compound (l);
}

/* A box containing text and arrow at entry */
Picture text_box (String t, Ident font)
{ String s = unquote (t);
  Float h = arrow_size;
  Float w = text_width (s, font);
  Picture a = Create_Text (no_srcinfo, 10, 13, w, 0, s, font);
  Picture b = Create_Box  (no_srcinfo, h+1, 0, w+10, 20);
  Picture c = no_arrow ? NULL : fill (Create_Arrow (no_srcinfo, 0, 10-h/2, h, h, Right));
  Picture d = no_arrow ? NULL : Create_Line  (no_srcinfo, h+1+w+10, 10, h, 0);
  Picture p = compound (pics4(a, b, c, d));
  Picture_d(p) = 10;
  return p;
}

/* An oval containing text and arrow at entry */
Picture text_oval (String t, Ident font)
{ String s = unquote (t);
  Float h = arrow_size;
  Float w = text_width (s, font);
  Picture a = Create_Text (no_srcinfo, 10, 13, w, 0, s, font);
  Picture b = oval (h+1, 0, w+10, 20);
  Picture c = no_arrow ? NULL : fill (Create_Arrow (no_srcinfo, 0, 10-h/2, h, h, Right));
  Picture d = no_arrow ? NULL : Create_Line  (no_srcinfo, h+1+w+10, 10, h, 0);
  Picture p = compound (pics4(a, b, c, d));
  Picture_d(p) = 10;
  return p;
}

/* Split drawings into pages */
List_Picture paginate (List_Picture drawings)
{
  List_Picture l = drawings;
  Float h = 0;
  List_Picture m = NULL;
    
  drawings = NULL;
  
  for (; l; l = List_Picture_next(l)) {
    Picture p = List_Picture_data(l);
    
    if (Scale*(h + Picture_h(p)) > page_height) {
      /* p does not fit on page */
      Front_List_append_node ((Front_List*)&drawings, compound(m));
      h = 0;
      m = NULL;
    }
    
    p = translate (p, 0, h);
    Front_List_append_node ((Front_List*)&m, p);
    h += Picture_h(p) + 30;
  }
  if (m != NULL) {
    /* Add last page */
    Front_List_append_node ((Front_List*)&drawings, compound(m));
  }
  return drawings;
}

/* Change non-printables into postscript escape sequence */
static void text (String s)
{
  for (; s[0]; s++) {
    char ch = s[0];
    if (ch  < ' ' ||ch > '~') {
      fprintf (print_file, "\\%o", ch);
    } else if (ch == '(' || ch == ')') {
      fprintf (print_file, "\\%c", ch);
    } else {
      fprintf (print_file, "%c", ch);
    }
  }
}

static Picture break_box (Box p, Box d)
{
  NOT_USED(d);
  Float x = Picture_x(p);
  Float y = Picture_y(p);
  Float w = Picture_w(p);
  Float h = Picture_h(p);
  Line h1 = compound (line (pt(x, y),   pt(x+w, y),   TRUE,  FALSE, 0));
  Line h2 = compound (line (pt(x, y+h), pt(x+w, y+h), TRUE,  FALSE, 0));
  Line v1 = compound (line (pt(x, y),   pt(x, y+h),   FALSE, FALSE, 0));
  Line v2 = compound (line (pt(x+w, y), pt(x+w, y+h), FALSE, FALSE, 0));
  return compound(pics4 (h1, h2, v1, v2));
}

static Picture break_text (Text p, Text d)
{
  NOT_USED(d);
  List_Picture r = NULL;
  Int i;
  String s = Text_text(p);
  Float x = Picture_x(p);
  Float y = Picture_y(p);
  Int l = strlen(s);
  if (l <= 1) return p;
  for (i = 0; i < l; i++) {
    char c = s[i];
    String t = Front_StrAllocf("%c", c);
    Float w = text_width (t, Text_font(p));
    Picture q = Create_Text (Picture_srcinfo(p), x, y, w, 0, t, Text_font(p));
    r = Create_List_Picture (q, r);
    x += w;
  }
  return compound(r);
}

/* Break down picture into basic elements */
Picture break_down (Picture p)
{
  static struct s_copy_Pictures_TraverseTable tab;
  tab.action_Box[POST_ACTION]  = break_box;
  tab.action_Text[POST_ACTION] = break_text;
  return Traverse_copy_Picture(p, &tab);
}

static Bool on_page (Picture p)
{
  Float x = Picture_x(p);
  Float y = Picture_y(p);
  Float w = Picture_w(p);
  Float h = Picture_h(p);
  Float x1 = x+w;
  Float y1 = y+h;
  
  if (x1 < x) swap (&x, &x1);
  if (y1 < y) swap (&y, &y1);

  if (x1 < tl.x) return FALSE; /* Too far left */
  if (x > br.x) return FALSE; /* Too far right */
  
  if (y1 < tl.y) return FALSE; /* Too far up */
  if (y > br.y) return FALSE; /* Too far down */
  return TRUE;
}

/* Print a picture in postscript format */
void print_picture (Picture p)
{
  Float scale = Picture_scale(p);
  Float phi = Picture_phi(p);
  Float x = Picture_x(p)/scale;
  Float y = Picture_y(p)/scale;
  Float w = Picture_w(p)/scale;
  Float h = Picture_h(p)/scale;
  String fill = "stroke";
  Float dash = Picture_dash(p);
  
  if (Picture_fill(p)) fill = "eofill";
  
  if (!on_page(p)) return;
  
  y = page_height/Scale/scale - y;
  h = -h;

  if (dash != 0 || scale != 1 || phi != 0) fprintf (print_file, "gsave ");
  if (dash != 0)  fprintf (print_file, "[%g %g] %g setdash\n", dash, dash, dash/2);    
  if (scale != 1) fprintf (print_file, "%g %g scale\n", scale, scale);    
  if (phi != 0)   {
    if (Picture_tag(p) == Arrow_kind) {
      fprintf (print_file, "%g %g translate %g rotate\n", x, y, phi);  
      x = -w/2; y = -h/2;  
    } else {
      fprintf (print_file, "%g %g translate %g rotate\n", x, y, phi);  
      x = 0; y = 0; 
    }
  }
  
  /* Color when mapping schedule on the machine */
  if (Picture_with_color(p) && Picture_tag(p)!=Compound_kind) {
    fprintf (print_file, "1 0 0 setrgbcolor\n");
  }

  switch (Picture_tag(p)) {
    case Empty_kind:
      break;
    case Line_kind:
      fprintf (print_file, "%g %g %g %g line\n", x, y, x+w, y+h);
      break;
    case Arc_kind: 
      fprintf (print_file, "%g %g moveto ", x, y);
      fprintf (print_file, "%g %g %g %g %g arc stroke\n", x+w, y+h, sqrt(w*w+h*h), Arc_phi_1(p), Arc_phi_2(p));
      break;
    case Curve_kind: {
      Bool d1 = Curve_d1(p);
      Bool d2 = Curve_d2(p);
      Float x1 = x;
      Float y1 = d1 ? y+h : y;
      Float x2 = x1+w;
      Float y2 = d1 ? y : y+h;
      
      fprintf (print_file, "%g %g moveto ", x1, y1);
      if (d2) {
        fprintf (print_file, "%g %g %g %g %d arctopop ", x1, y2, x2, y2, curve_size);
      } else {
        fprintf (print_file, "%g %g %g %g %d arctopop ", x2, y1, x2, y2, curve_size);
      }
      fprintf (print_file, "%g %g lineto stroke\n", x2, y2);
      break;
    }
    case Box_kind:
      fprintf (print_file, "%g %g %g %g %g %g %g %g rectangle %s\n", 
         x, y, x+w, y, x+w, y+h, x, y+h, fill);
      break;
    case Circle_kind:
      fprintf (print_file, "%g %g %g circle %s\n", x, y, w/2, fill);
      break;
    case Arrow_kind:
      switch (Arrow_dir(p)) {
        case Right:
	  fprintf (print_file, "%g %g %g %g %g %g triangle %s\n", x, y, x+w, y+h/2, x, y+h, fill);
	  break;
        case Left:
	  fprintf (print_file, "%g %g %g %g %g %g triangle %s\n", x, y+h/2, x+w, y, x+w, y+h, fill);
	  break;
        case Up:
	  fprintf (print_file, "%g %g %g %g %g %g triangle %s\n", x, y+h, x+w/2, y, x+w, y+h, fill);
	  break;
        case Down:
	  fprintf (print_file, "%g %g %g %g %g %g triangle %s\n", x, y, x+w, y, x+w/2, y+h, fill);
	  break;
	default: break;
      }
      break;
    case Text_kind:
      set_font (Text_font(p));
      fprintf (print_file, "("); text (Text_text(p)); fprintf (print_file, ") %g %g text\n", x, y);
      break;
    case Compound_kind: {
      List_Picture l;
      for (l = Compound_sub(p); l; l = List_Picture_next(l)) {
	Picture pict = List_Picture_data(l);
	/* Color when mapping schedule on the machine */
	if (Picture_with_color(pict)) fprintf (print_file, "1 0 0 setrgbcolor\n");
        print_picture (pict);
	if (Picture_with_color(pict)) fprintf (print_file, "0.1 0.1 0.1 setrgbcolor\n");
      }
      break;
    }
    default:
      Print_Picture(p);
      break;
  }
  /* Color when mapping schedule on the machine */
  if (Picture_with_color(p) && Picture_tag(p)!=Compound_kind) {
    fprintf (print_file, "0.1 0.1 0.1 setrgbcolor\n");
  }
  if (dash != 0 || scale != 1 || phi != 0) fprintf (print_file, "grestore\n");
}

void PS_prologue (String title, String creator)
{
  Int m = margin;
  set_margin(0); set_position(0);

  fprintf (print_file, "%%!PS-Adobe-2.0 EPSF-2.0\n");
  fprintf (print_file, "%%%%Title: %s\n", title);
  fprintf (print_file, "%%%%Creator: %s\n", creator);
  fprintf (print_file, "%%%%CreationDate: Wed Oct 16 11:42:44 2002\n");
  fprintf (print_file, "%%%%DocumentFonts: Helvetica\n");
  if (landscape) {
    fprintf (print_file, "%%%%BoundingBox: %d %d %d %d\n", 
       m-10, m-10, PAPER_HEIGHT-m+10, PAPER_WIDTH-m+10);
  } else {
    fprintf (print_file, "%%%%BoundingBox: %d %d %d %d\n", 
       m-10, m-10, PAPER_WIDTH-m+10, PAPER_HEIGHT-m+10);
  }
  fprintf (print_file, "%%%%EndProlog\n\n");

  fprintf (print_file, "/line { moveto lineto stroke } def\n");
  fprintf (print_file, "/arctopop { arcto pop pop pop pop } def\n");
  fprintf (print_file, "/polygon { 2 index 2 index moveto {lineto} repeat closepath } def\n");
  fprintf (print_file, "/triangle { 3 polygon } def\n");
  fprintf (print_file, "/rectangle { 4 polygon } def\n");
  fprintf (print_file, "/text { moveto show } def\n\n");
  fprintf (print_file, "/circle { 2 index 2 index moveto 0 360 arc } def\n\n");

  set_font (NULL);
  set_font (Create_Ident("Helvetica"));
}

void PS_epilogue (void)
{
  fprintf (print_file, "%%%%Trailer\n");
}

void PS_start_page (Int page, Int dx, Int dy)
{
  fprintf (print_file, "%%%%Page: \"%d\" %d\n\n", page, page);
  if (landscape) fprintf (print_file, "[0 1 -1 0 %d 0] concat\n", PAPER_HEIGHT);
  fprintf (print_file, "gsave %d %d translate\n", dx+40, dy+40);
  fprintf (print_file, "%.2g %.2g scale\n\n", Scale, Scale);

  tl = pt (-dx-40/Scale, -dy-40/Scale);
  if (FALSE && landscape) {
    br = pt ((-dx+page_height+40)/Scale, (-dy+page_width+40)/Scale);
  } else {
    br = pt ((-dx+page_width+40)/Scale, (-dy+page_height+40)/Scale);
  }
}

void PS_end_page (void)
{
  fprintf (print_file, "grestore\n");
  fprintf (print_file, "showpage\n");
}

/* Print pictures, one per column */
static void _print_pictures (String fn, String title, String creator, 
                             List_Picture l, Int columns, Int page, Int col,
			     Int dx, Int dy)
{
  Picture p;
  
  if (col == 1 && (page == 1 || !singlefile)) {
    String fn1 = fn;
    if (!singlefile) fn1 = Front_StrAllocf ("%s%d", fn, page);
    open_print_file (Front_StrAllocf ("%s%s", fn1, ".ps"), TRUE);
    PS_prologue (title, creator);
  }

  if (l==NULL) {
    if (col > 1) PS_end_page ();
    if (print_file != stdout) { /* print file is open, close it */
      PS_epilogue ();
      close_print_file();
    }
    return;
  }
  
  if (col == 1) PS_start_page (page, dx, dy);
  
  p = List_Picture_data(l);
  
  p = translate (p, (col-1)*(column_width+col_sep)/Scale, 0);
  print_picture (p);
  
  col++;
  if (col > columns) {
    page++;
    PS_end_page ();
    if (!singlefile) {
      PS_epilogue ();
      close_print_file();
    }
    col = 1;
  }
  
  _print_pictures (fn, title, creator, List_Picture_next(l), columns, page, col, dx, dy);
}

/* Print pictures, one per column */
void print_pictures (String fn, String title, String creator, 
                     List_Picture l, Int columns, Int dx, Int dy)
{
  _print_pictures (fn, title, creator, l, columns, 1, 1, dx, dy);
}

/* Set some dimensions and init traverse table */
void Picture_init (void)
{
  Pictures_print_actions.action_Picture[PRE_ACTION] = print_picture;
  
  if (landscape) {
    iswap (&paper_width, &paper_height);
  }

  page_width   = PAPER_WIDTH -2*margin;
  page_height  = PAPER_HEIGHT-2*margin;
  column_width = (page_width-col_sep*(columns-1))/columns;
}

