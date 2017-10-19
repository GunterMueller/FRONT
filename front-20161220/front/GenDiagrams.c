/*
 * Copyright (C) 2000-2005 Philips Electronics N.V.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 */
#include <string.h>
#include <assert.h>
#include "GenTypes.h"
#include "GenGrammar.h"
#include "GenDiagrams.h"
#include "pictures/Picture.h"

Bool diagrams = FALSE;

static int set_scale        (int argc, char **argv);
static int set_cols         (int argc, char **argv);
static int set_height       (int argc, char **argv);
static int set_width        (int argc, char **argv);

fe_cli_flag cli_diagram_flags[] = {
  { "-diagrams",         &diagrams,   NULL,         DFLT_NAME, { "Generate .ps file with syntax diagrams." } },
  { "-landscape",        &landscape,  NULL,         DFLT_NAME, { "Generate syntax diagrams in landscape." } },
  { "-singlefile",       &singlefile, NULL,         DFLT_NAME, { "Generate syntax diagrams in one file." } },
  { "-scale",            NULL, set_scale,        "-scale a b", { "Set scale for syntax diagrams to a/b." } },
  { "-height",           NULL, set_height,        "-height h", { "Set paper height to h mm, default A4." } },
  { "-width",            NULL, set_width,          "-width w", { "Set paper width  to w mm, default A4." } },
  { "-columns",          NULL, set_cols,         "-columns n", { "Set number of columns for syntax diagrams to n." } },
};

const int num_cli_diagram_flags=(sizeof(cli_diagram_flags) / sizeof(*cli_diagram_flags));

Int Width = 0;	/* Width of whole drawing */

static List_Picture drawings = NULL; /* All drawings, one for each non-terminal */

static List_Picture layouts (List_Picture l);

/* ----------------------------------------------------------------------------
 * Several function to parse specifiy command line options
 */
static int set_scale (int argc, char **argv)
{ Int a, b;
  
  if (argc < 2 || sscanf (argv[1], "%d", &a) != 1) {
    FrontError (TRUE, "Missing scale argument");
  } else {
    
    if (argc < 3 || sscanf (argv[1], "%d", &b) != 1) {
      FrontError (TRUE, "Missing scale argument");
    } else {
      Scale = Scale*a/b;
    }
  }
  return 2;
}

static int set_cols (int argc, char **argv)
{ 
  if (argc < 2 || sscanf (argv[1], "%d", &columns) != 1) {
    FrontError (TRUE, "Missing columns argument");
  }
  return 1;
}

static int set_height (int argc, char **argv)
{ 
  if (argc < 2 || sscanf (argv[1], "%d", &paper_height) != 1) {
    FrontError (TRUE, "Missing height argument");
  }
  return 1;
}

static int set_width (int argc, char **argv)
{ 
  if (argc < 2 || sscanf (argv[1], "%d", &paper_width) != 1) {
    FrontError (TRUE, "Missing width argument");
  }
  return 1;
}


/* Put pictures sequential */
static Picture sequence (List_Picture l)
{
  Picture p;
  Int w = 0;
  List_Picture m;
  List_Picture a = NULL;
  Int h1 = 0, h2 = 0;
  point q;
  
  if (l==NULL) return NULL;
  l = layouts (l);
  if (List_Picture_next(l)==NULL) return List_Picture_data(l);

  /* Compute total height, h1 from top to entry, h2 from entry to bottom */
  for (m = l; m; m = List_Picture_next(m)) {
    Picture p = List_Picture_data(m);
    h1 = MAX(h1, Picture_d(p));
    h2 = MAX(h2, Picture_h(p)-Picture_d(p));
  }
  
  q = pt (0, h1); /* Entry */
  
  for (m = l; m; m = List_Picture_next(m)) {
    Picture p = List_Picture_data(m);
    p = translate (p, w, h1-Picture_d(p));
    a = seq (p, a);
    w += Picture_w(p)+10;    
    if (l != m) a = seqs (line (q, entry_pt(p), TRUE, FALSE, 0), a);
    q = exit_pt (p);
  }
  p = Create_Compound (no_srcinfo, 0, 0, w-10, h1+h2, a);
  Picture_d(p) = h1;
  return p;
}

/* Compute or_alignment, w is total width of and-construction, pw is picture width */
static Int align_and (Direction and, Int w, Int pw)
{
  switch (and) {
    case Left:   return 0;
    case Right:  return w - pw;
    case Center: return 0;
    default:     return (w - pw)/2;
  }
  return 0;
}

/* Compute or_alignment, w is total width of or-construction, pw is picture width */
static Int align_or (Direction or, Int w, Int pw)
{
  switch (or) {
    case Center: return (w - pw)/2;
    case Left:   return 0;
    case Right:  return w - pw;
    default:     break;
  }
  return 0;
}

/* Stack pictures, use ors and align for alignment.
   d is disatnce between elements.
   Returns width and height.
*/
static List_Picture stack (List_Picture l, List_Direction ors, 
                           Int (*align)(Direction,Int,Int),
			   Int d, Int *w, Int *h)
{
  List_Picture m;
  List_Picture a = NULL;
  Direction or = Center;
  
  if (ors) or = List_Or_data(ors);

  /* Compute width */
  for (m = l, *w=0; m; m = List_Picture_next(m)) {
    Picture p = List_Picture_data(m);
    *w = MAX(*w, Picture_w(p));
  }
  
  for (m = l, *h=0; m; m = List_Picture_next(m)) {
    Picture p = List_Picture_data(m);
    Int w1 = align (or, *w, Picture_w(p));
    p = translate (p, w1, *h);
    a = seqs (a, pics1(p));
    *h += Picture_h(p)+d;
    if (ors) {
      or  = List_Or_data(ors);
      ors = List_Or_next(ors);
    }
  }
  *h -= d;
  return a;
}

static List_Picture stack_alt (Picture a, Picture b, Bool top, Int *w, Int *h, Picture *a1);

static Bool is_opt (List_Picture l)
{ Picture p;
  if (l==NULL) return FALSE;
  p = List_Picture_data(l);
  l = List_Picture_next(l);
  if (l != NULL) return is_opt (l);
  return Picture_tag(p) == Empty_kind;
}

/* Generate a shortcut for s=[ a | b | c ] in a vertical sequence.
   Last means s is the last in the vertical sequence. In that case, a connection
   to *out1 must be generated. *out1 might be moved to the right of the layout
   of s requires so.
   *h1, *w1 will hold the size of s.
   *a1 will hold the pictures generated for s.
   *in1 is the entry point for s upon call to this functions.
   After return, it holds the exit point of s. 
*/
static Bool opt_shortcut (Picture s, Bool last, List_Picture *a1, 
                          Int *h1, Int *w1, Int *d1, point *in1, point *out1)
{
  Int w, h;
  List_Picture l, m;
  List_Picture a;
  point in = *in1;
  point out;
  
  if (Picture_tag(s) != OrBlock_kind) return FALSE;
  l = OrBlock_sub(s);
  if (!is_opt(l)) return FALSE;
  
  /* Layout a|b|c and, stack them vertically and translate to *h1 */
  l = layouts(l);
  l = stack (l, OrBlock_dirs(s), align_or, 10, &w, &h);    
  l = translates (l, 10, *h1);
  a = seqs (*a1, l);
  
  /* Compute new height en width */
  h += *h1;
  w += 20;
  out = pt (w, h-curve_size); /* Lower right output */
  
  for (m = l; m; m = List_Picture_next(m)) {
    Picture p = List_Picture_data(m);
        
    if (List_Picture_next(m) != NULL) {
      /* Connect in to p and p to lower right output */
      a = seqs (line (in, entry_pt(p), FALSE, FALSE, curve_size), a);
      a = seqs (line (exit_pt(p), out, TRUE,  FALSE, curve_size), a);
      continue;
    }
    
    /* Last empty branch, special layout */
    if (last) {
      point m = pt (w+10, h); /* Lower right corner */
      point out2;
      w = MAX (w+20, out1->x) + 20;
      *out1 = pt (w, out1->y); /* New output */
      out2 = pt (out1->x-10, out1->y+10); /* Just a little SW of output */
      
      a = seqs (line (in,   m,      FALSE, FALSE, curve_size), a); /* Shortcut at bottom */
      a = seqs (line (out,  m,      FALSE, FALSE, curve_size), a); /* Connect last element to bottom line */
      a = seqs (line (m,    out2,   TRUE,  FALSE, curve_size), a); /* Connect bottom line towards output */
      a = seqs (line (out2, *out1,  FALSE, FALSE, curve_size), a); /* Last turn to output */
    } else {
      /* Not the last in a sequence */
      point m = pt (curve_size, h); /* Almost lower left */
      h += 10;
      *in1 = pt (0, h);  	    /* Output, is input of successor */
      a = seqs (line (in,  *in1, FALSE, FALSE, curve_size), a);  /* shortcut to new output */
      a = seqs (line (out, m,    FALSE, FALSE, curve_size), a);  /* Connect last element */
      a = seqs (line (m,   *in1, TRUE,  FALSE, curve_size), a);  /* Last turn to output */
    }
  }
  /* Produce results */
  *h1 = h;
  *a1 = a;
  *w1 = w;
  *d1 = Picture_d (List_Picture_data(l));
  *out1 = pt (MAX(out1->x,w), out1->y);
  return TRUE;
}

/* Generate a shortcut for a // b in a vertical sequence
   Last means s is the last in the vertical sequence. In that case, a connection
   to *out1 must be generated. *out1 might be moved to the right of the layout
   of s requires so.
   *h1, *w1 will hold the size of s.
   *a1 will hold the pictures generated for s.
   *in1 is the entry point for s upon call to this functions.
   After return, it holds the exit point of s. 
*/
static Bool alt_shortcut (Picture s, Bool last, List_Picture *a1, 
                          Int *h1, Int *w1, Int *d1, point *in1, point *out1)
{
  Int w, h, d;
  List_Picture l, m;
  List_Picture a;
  point in = *in1;
  point out;
  Picture t = NULL;
  
  if (Picture_tag(s) != AltBlock_kind) return FALSE;
  if (!AltBlock_turn_left(s)) return FALSE;
  
  /* Stack a and b and flip b, t will hold a */
  l = stack_alt (AltBlock_a(s), AltBlock_b(s), AltBlock_turn_left(s), &w, &h, &t);    
  l = translates (l, 0, *h1);
  a = seqs (*a1, l);
  
  d = Picture_d(List_Picture_data(l));       /* Entry point height */
  out = pt (w, exit_pt(t).y+*h1-curve_size); /* Just above output of a */
  in = pt (0, *h1+d);			     /* New input point */
  h += *h1;

  for (m = l; m; m = List_Picture_next(m)) {
    Picture p = List_Picture_data(m);
    
    if (List_Picture_next(m) != NULL) {
      /* Not the last one (this will be t) yet */
      point m1 = pt (0, entry_pt(p).y); /* left of entry of p */
      a = seqs (line (entry_pt(p), m1,  FALSE,  TRUE,  0), a); /* Arrow to the left */
      a = seqs (line (out, exit_pt(p), FALSE, FALSE, curve_size), a); /* Connection from t to entry */
      if (l==m) a = seqs (line (in, m1,  FALSE,  FALSE,  0), a); /* Input must be connected to arrow */
      continue;
    }
    
    /* Last picture, this is t */
    
    /* Line from input to last picture entry */
    a = seqs (line (pt(0, MIN(in.y, in1->y)), entry_pt(p),  FALSE, FALSE, curve_size), a);
    /* Line from last picture exit to output */
    a = seqs (line (exit_pt(p), out,  TRUE,  FALSE, curve_size), a);
    
    if (!last && Picture_w(p)==0) {
      /* t is empty */
      h += 10;
      in = *in1;
      *in1 = pt (0, h);
      /* Create short cut to successor */
      a = seqs (line (pt(0,d), *in1,   FALSE, FALSE, curve_size), a);
    } else if (!last) {
      /* t is not empty, not last in sequence */
      point out2 = pt (w, h+curve_size); /* Lower right */
      point in2 = pt (curve_size, h+10); /* Lower left */
      h += 10+curve_size;
      in = pt (0, h); /* New input */
      a = seqs (line (exit_pt(p), out2, TRUE,  FALSE, curve_size), a); /* Connect exit to lower right*/
      a = seqs (line (out2,       in2,  FALSE, FALSE, curve_size), a); /* Connect on to lower left */
      a = seqs (line (in2,        in,   TRUE, FALSE, curve_size), a);  /* Connect on to new input */
      *in1 = in;  
    } else {
      /* t is last in sequence, to connection to successor but to out1 */
      point out2;
      w = MAX (w+20, out1->x) + 10; /* Stretch w if needed */
      *out1 = pt (w, d);	    /* New output */
      out2 = pt (out1->x-10, out1->y+10); /* A bit SW of output */
      a = seqs (line (exit_pt(p), out2,  TRUE,  FALSE, curve_size), a); /* p to output */
      a = seqs (line (out2,       *out1, FALSE, FALSE, curve_size), a); /* last turn to output */
    }
  }
  /* Produce results */
  *h1 = h;
  *a1 = a;
  *w1 = w;
  *d1 = d;
  *out1 = pt (MAX(out1->x,w), out1->y);
  return TRUE;
}

/* Put pictures sequential vertically */
static Picture seq_ver (List_Picture s, List_Direction ands)
{
  Picture p;
  Int w, h, h1 = 0;
  List_Picture m;
  List_Picture a = NULL;
  point in, out, mid;
  List_Picture l = layouts (s);
  Int d = 0;
  
  if (l==NULL) return NULL;
  if (List_Picture_next(l)==NULL) return List_Picture_data(l);
  
  l = stack (l, ands, align_and, 20, &w, &h);
  
  w += 20;
  in  = pt (0, Picture_d(List_Picture_data(l)));
  out = pt (w, in.y);
  
  for (m = l; m; m = List_Picture_next(m), s = List_Picture_next(s)) {
    Picture q = List_Picture_data(s); /* Before layout */
    Picture p = List_Picture_data(m); /* After layout  */
    Bool last = List_Picture_next(m)==NULL;
    Int d2;
    Int *d1 = l==m ? &d : &d2;
    
    /* Try special cases */
    if (opt_shortcut (q, last, &a, &h1, &w, d1, &in, &out)) continue;
    if (alt_shortcut (q, last, &a, &h1, &w, d1, &in, &out)) continue;
    
    /* Normal case */
    p = translate (p, 10, 0);
    if (l==m) d = Picture_d(p); /* Entry of result */
    a = seq (p, a);
    mid = pt (Picture_x(p), Picture_y(p)+Picture_h(p)+10); /* Lower left */
    a = seqs (line (in, entry_pt(p), FALSE, FALSE, curve_size), a); /* Entry connection */
    if (last) { 
      /* Last in sequence, connect to out */
      point q = pt(out.x, out.y+10);
      w = out.x+10;
      out = pt (w, out.y);
      a = seqs (line (exit_pt(p), q, TRUE,  FALSE, curve_size), a);
      a = seqs (line (q, out,        FALSE, FALSE, curve_size), a);
    } else { 
      /* q is lower right */
      point q = pt (Picture_x(p)+Picture_w(p)+curve_size, Picture_y(p)+Picture_d(p)+curve_size);
      in  = pt (0, mid.y+10); /* Exit point, is entry od next one */
      /* Connect p -> q -> mid -> in */
      a = seqs (line (exit_pt(p), q,   TRUE,  FALSE, curve_size), a);
      a = seqs (line (q,          mid, FALSE, FALSE, curve_size), a);
      a = seqs (line (mid,        in,  TRUE,  FALSE, curve_size), a);
    }
    h1 = Picture_y(p)+Picture_h(p)+20;
  }
  p = Create_Compound (no_srcinfo, 0, 0, w, h, a);
  Picture_d(p) = d;
  return p;
}

/* Transform And into Direction */ 
static List_Direction strip_ands (List_And l)
{
  List_Direction m;
  And a;
  if (l==NULL) return NULL;
  m = strip_ands (List_And_next(l));
  a = List_And_data(l);
  switch (a) {
    case AndTranspose: return Create_List_Direction (Up, m);
    case AndLeft:      return Create_List_Direction (Left, m);
    case AndRight:     return Create_List_Direction (Right, m);
    case AndCenter:    return Create_List_Direction (Center, m);
  }
  return m;
}

/* Transform Or into Direction */ 
static List_Direction strip_ors (List_Or l)
{
  List_Direction m;
  Or a;
  if (l==NULL) return NULL;
  m = strip_ors (List_Or_next(l));
  a = List_Or_data(l);
  switch (a) {
    case OrCenter:    return Create_List_Direction (Center, m);
    case OrLeft:      return Create_List_Direction (Left, m);
    case OrRight:     return Create_List_Direction (Right, m);
    case OrTranspose: return Create_List_Direction (Up, m);
  }
  return m;
}

/* Put choice horizontally */
static Picture choice_seq (List_Picture l)
{
  Picture p;
  Int w1 = 20;
  Int w = 20;
  List_Picture m;
  List_Picture a = NULL;
  Int h1 = 0, h2 = 0;
  point in, out;
  int cs = curve_size;
  
  if (l==NULL) return NULL;
  l = layouts(l);
  if (List_Picture_next(l)==NULL) return List_Picture_data(l);

  /* Compute height and total width */
  for (m = l; m; m = List_Picture_next(m)) {
    Picture p = List_Picture_data(m);
    h1 = MAX(h1, Picture_d(p));
    h2 = MAX(h2, Picture_h(p)-Picture_d(p));
    w += Picture_w(p) + 20;
  }
  h1+= 10;
  h2+= 10;
  in = pt (0,0);
  out = pt (w, h1+h2);
  
  for (m = l; m; m = List_Picture_next(m)) {
    Picture p = List_Picture_data(m);
    point r; 
    p = translate (p, w1, h1-Picture_d(p));
    a = seq (p, a);
    w1 += Picture_w(p)+20;
    r = pt (entry_pt(p).x-10, entry_pt(p).y-10); /* NW of p */
    a = seqs (line (in, r, TRUE, FALSE, cs), a);
    a = seqs (line (r, entry_pt(p), FALSE, FALSE, cs), a);
    r = pt (exit_pt(p).x+10, exit_pt(p).y+10); /* SE of p */
    a = seqs (line (exit_pt(p), r, TRUE, FALSE, cs), a);
    a = seqs (line (r, out, FALSE, FALSE, cs), a);
  }
  w += 20;
  /* Connect to output (w,0) */
  a = seqs (line (out, pt(w-10,10), TRUE, FALSE, cs), a);
  a = seqs (line (pt(w-10,10), pt(w,0), FALSE, FALSE, cs), a);
  p = Create_Compound (no_srcinfo, 0, 0, w, h1+h2, a);
  Picture_d(p) = 0;
  return p;
}

static Picture layout (Picture p);

/* Stack b above a and flip b */
static List_Picture stack_alt (Picture a, Picture b, Bool top, Int *w, Int *h, Picture *a1)
{
  List_Picture l = pics1(b); 
  List_Direction ors = NULL;
  List_Picture m;
  
  if (Picture_tag(b) == OrBlock_kind) {
    l = OrBlock_sub(b);
    ors = OrBlock_dirs(b);
  }
  
  if (top) l = seqs (l, pics1(a));
  else l = seq (a, l);
  l = layouts (l);
  l = stack (l, ors, align_or, 10, w, h);
  l = translates (l, 10, 0);
  *w += 20;
  
  /* Flip b */
  *a1 = NULL;
  for (m = l; m; m = List_Picture_next(m)) {
    Picture p = List_Picture_data(m);
    if (top && List_Picture_next(m)==NULL) *a1 = p;
    if (!top && l==m) *a1 = p;
    if (*a1 == p) continue;
    List_Picture_data(m) = hor_flip(p, *w/2);
  }
  return l;
}

/* Layout of Alt, a // b (top) or a \\ b (!top) */
static Picture alt (Picture a, Picture b, Bool top)
{
  Int w, h;
  List_Picture l = stack_alt (a, b, top, &w, &h, &a); 
  point in, out;
  List_Picture m;
      
  /* Entry, exit at level of a */
  in  = pt (0, entry_pt(a).y);
  out = pt (w, in.y);

  for (m = l; m; m = List_Picture_next(m)) {
    Picture p = List_Picture_data(m);
    if (p==a) continue;
    /* Connect output to p and p to input */
    l = seqs (line (out, exit_pt(p), FALSE, FALSE, curve_size),  l);
    l = seqs (line (entry_pt(p), in, TRUE,  TRUE,  curve_size),  l);
  }
  /* Connect input to a and a to output */
  l = seqs (line (in, entry_pt(a), TRUE,  FALSE, 0), l);
  l = seqs (line (exit_pt(a), out, TRUE,  FALSE, 0), l);
  
  b = Create_Compound (no_srcinfo, 0, 0, w, h, l);
  Picture_d(b) = in.y;
  return b;
}

/******************************/

static Picture choice_ver (List_Picture l, List_Direction ors);

/* Remove And, Or, Alt blocks by adding layout and connections */
static List_Picture layouts (List_Picture l)
{
  if (l == NULL) return NULL;
  return seq (layout(List_Picture_data(l)), layouts(List_Picture_next(l)));
}

/* Remove And, Or, Alt blocks by adding layout and connections */
static Picture layout (Picture p)
{
  if (p==NULL) return NULL;
  switch (Picture_tag(p)) {
    case AndBlock_kind:
      assert (Picture_x(p) == 0);
      assert (Picture_y(p) == 0);
      if (AndBlock_dirs(p)==NULL) return sequence (AndBlock_sub(p));
      return seq_ver (AndBlock_sub(p), AndBlock_dirs(p));
    case OrBlock_kind:
      assert (Picture_x(p) == 0);
      assert (Picture_y(p) == 0);
      if (OrBlock_dirs(p)==NULL) return choice_seq (OrBlock_sub(p));
      return choice_ver (OrBlock_sub(p), AndBlock_dirs(p));
    case AltBlock_kind:
      assert (Picture_x(p) == 0);
      assert (Picture_y(p) == 0);
      return alt (AltBlock_a(p), AltBlock_b(p), AltBlock_turn_left(p));
    default:
      break;
  }
  return p;
}

/******************************/

/* Put pictures parallel, a|b|c */
static Picture choice_ver (List_Picture l, List_Direction ors)
{
  Picture p;
  Int w = 0, h = 0;
  List_Picture m;
  List_Picture a = NULL;
  point in, out;
  
  if (l==NULL) return NULL;
  l = layouts(l);
  if (List_Picture_next(l)==NULL) return List_Picture_data(l);
  
  /* Stack l with distance 10 */
  l = stack (l, ors, align_or, 10, &w, &h);
  
  w += 20;
  l = translates (l, 10, 0);
  in  = pt (0, Picture_d(List_Picture_data(l)));
  out = pt (w, in.y);
  a = l;
  
  for (m = l; m; m = List_Picture_next(m)) {
    Picture p = List_Picture_data(m);
    Int curve = curve_size;
    if (List_Picture_next(m) != NULL) curve = 0; /* Only last one has turn */
    /* Connect entry and exit */
    a = seqs (line (in, entry_pt(p), FALSE, FALSE, curve), a);
    a = seqs (line (exit_pt(p), out, TRUE,  TRUE,  curve), a);
  }
  p = Create_Compound (no_srcinfo, 0, 0, w, h, a);
  Picture_d(p) = Picture_d(List_Picture_data(l));
  return p;
}

/* Create AndBlock */
static Picture make_and (List_Picture l, List_Direction d)
{
  if (l==NULL) return NULL;
  if (List_Picture_next(l) == NULL) return List_Picture_data(l);
  return Create_AndBlock (no_srcinfo, 0, 0, 0, 0, l, d);
}

/* Create OrBlock */
static Picture make_or (List_Picture l, List_Direction d)
{
  if (l==NULL) return NULL;
  if (List_Picture_next(l) == NULL) return List_Picture_data(l);
  return Create_OrBlock (no_srcinfo, 0, 0, 0, 0, l, d);
}

/* Create AltBlock */
static Picture make_alt (Picture a, Picture b, Bool l)
{
  return Create_AltBlock (no_srcinfo, 0, 0, 0, 0, a, b, l);
}

/* Combine AndCenter into one picture 
   This translate a \ b c \ d into a \ (b c) \ d
*/
static List_Picture seq_hor (List_Picture l, List_Picture a, List_And ands)
{
  And and;
  Picture p;
  
  if (l==NULL || ands == NULL) return pics1 (make_and (seqs (a, l), NULL));
  p = List_Symbol_data(l);
  l = List_Symbol_next(l);
  and  = List_And_data(ands);
  ands = List_And_next(ands);
  if (and == AndCenter || a == NULL) {
    return seq_hor (l, seqs (a, pics1(p)), ands);
  }
  return seq (make_and (a, NULL), seq_hor (l, pics1(p), ands));
}

/* Combine OrTranspose into one picture 
   This translate a | b \| c | d into a | (b \| c) | d
*/
static List_Picture choice_hor (List_Picture l, List_Picture a, List_Or ors)
{
  And or;
  Picture p;
  
  if (l==NULL) return pics1 (make_or (seqs (a, l), NULL));
  if (ors==NULL) return seq (make_or (a, NULL), l);
  p = List_Picture_data(l);
  l = List_Picture_next(l);
  or  = List_Or_data(ors);
  ors = List_Or_next(ors);
  if (or == OrTranspose || a == NULL) {
    return choice_hor (l, seqs (a, pics1(p)), ors);
  }
  return seq (make_or (a, NULL), choice_hor (l, pics1(p), ors));
}

/* Put pictures sequential */
static Picture and (List_Picture l, List_And ands)
{
  if (l==NULL) return NULL;
  l = seq_hor (List_Picture_next(l), pics1(List_Picture_data(l)), ands);
  return make_and (l, strip_ands(ands));
}

/* Put pictures parallel */
static Picture or (List_Picture l, List_Or ors)
{
  if (l==NULL) return NULL;
  l = choice_hor (List_Picture_next(l), pics1(List_Picture_data(l)), ors);
  return make_or (l, strip_ors(ors));
}

static Picture draw_alt (Alternative a);
static List_Picture draw_sym (Symbol s);

/* Map symbol to picture */
static List_Picture draw_syms (List_Symbol l)
{ if (l==NULL) return NULL;
  return seqs (draw_sym(List_Symbol_data(l)), draw_syms(List_Symbol_next(l)));
}

/* Literal: print in courier font */
static Picture str_pic (String s)
{
  return text_oval (s, Create_Ident ("Courier"));
}

/* Symbol name: print in helvetica font */
static Picture id_pic (Ident id)
{
  return text_box (Ident_name(id), Create_Ident ("Helvetica"));
}

/* Add one | at the end of l. Used to translate [ a | b ] into (a | b |) */ 
static List_Or add_center (List_Or l)
{
  if (l==NULL) return Create_List_Or (OrCenter, l);
  return Create_List_Or (List_Or_data(l), add_center (List_Or_next(l)));
}

/* Transform Symbol into Picture */
static List_Picture draw_sym (Symbol s)
{ 
  Picture p = NULL;
  if (s==NULL) return NULL;
  switch (Symbol_tag(s)) {
    case LabeledSym_kind:
      return draw_sym(LabeledSym_sym(s));
    case CompareSym_kind:
      return draw_sym(Symbol2_sym(s));
    case DefiningSym_kind:
      if (Defining_id_tag(DefiningSym_id(s)) != DefId_kind) break;
      return draw_sym(DefId_id(DefiningSym_id(s)));
    case AppliedSym_kind:
      if (AppliedSym_field(s) == AppliedField) break;
      return pics1(str_pic (Ident_name(AppliedSym_name(s))));
    case IdSym_kind: {
      NonTerminal nt = IdSym_nt(s);
      if (nt != NULL && is_macro(nt)) {
        return pics1(draw_alt (NonTerminal_alt(nt)));
      }
      if (TermType(IdSym_id(s)) || 
          (nt != NULL && NonTerminal_scan(nt) != NULL)) {
        return pics1(str_pic (Ident_name(IdSym_id(s))));
      }
      return pics1(id_pic (IdSym_id(s)));
    }
    case StringSymbol_kind:
      return pics1(str_pic (StringSymbol_string(s)));
    case CharSymbol_kind:
      return pics1(str_pic (CharSymbol_chr(s)));
    case KeywordSymbol_kind:
      return pics1(str_pic (KeywordSymbol_keyword(s)));
    case SymbolSeq_kind:
      if (SymbolSeq_symbols(s) == NULL) return pics1(empty_pic());
      return pics1 (and (draw_syms(SymbolSeq_symbols(s)), SymbolSeq_ands(s)));
    case AltSymbol_kind:
      p = make_alt (make_and(draw_sym (AltSymbol_syms1(s)), NULL), 
                    make_and(draw_syms(AltSymbol_syms (s)), NULL), 
	            AltSymbol_alt(s));
      break;
    case MoreSymbol_kind:
      p = make_alt (or (draw_syms(CompoundSym_sym(s)), CompoundSym_ops(s)), empty_pic(), TRUE);
      break;
    case OptMoreSymbol_kind:
      p = make_alt (empty_pic(), or (draw_syms(CompoundSym_sym(s)), CompoundSym_ops(s)), TRUE);
      break;
    case OnceSymbol_kind:
      p = or (draw_syms(CompoundSym_sym(s)), CompoundSym_ops(s));
      break;
    case OptSymbol_kind:
      p = or (seqs (draw_syms(CompoundSym_sym(s)), pics1(empty_pic())), add_center(CompoundSym_ops(s)));
      break;
    case EmptySym_kind:
    case LayoutString_kind:
    case LayoutAction_kind:
      break;
  }
  if (p==NULL) return NULL;
  return pics1(p);
}

/* Transform alternatives into Picture */
static List_Picture draw_alts (List_Alternative l)
{ 
  Picture p;
  List_Picture q;
  if (l==NULL) return NULL;
  p = draw_alt  (List_Alternative_data(l));
  q = draw_alts (List_Alternative_next(l));
  if (p==NULL) p = empty_pic();
  return Create_List_Picture (p, q);
}

/* Transform alternative into Picture */
static Picture draw_alt (Alternative a)
{ 
  switch (Alternative_tag(a)) {
    case UnLabeledAlt_kind:
      return and (draw_sym(UnLabeledAlt_syms(a)), NULL);
    case LabeledAlt_kind: {
      Rhs r = LabeledAlt_rhs(a);
      Symbol s1 = Rhs_syms1(r);
      List_Alternative l = Rhs_alts(r);
      Symbol s2 = Rhs_syms2(r);
      List_Picture p1 = draw_sym(s1);
      List_Picture p2 = draw_alts(l);
      List_Picture p3 = draw_sym(s2);
      return and (seqs (p1, seq (or (p2, Rhs_ops(r)), p3)), NULL);
    }
  }
  return NULL;
}

/* Draw non-terminal.
   Add a label, entry line + exit arrow and add it to drawings.
*/
static void draw_nt (NonTerminal nt)
{ Picture p;
  Ident font = Create_Ident("Helvetica");
  
  if (is_macro(nt)) return;
  p = draw_alt (NonTerminal_alt(nt));
  p = layout (p);
  if (p != NULL) {
    String name = Ident_name (NonTerminal_id(nt));
    List_Picture l;
    point in, out;
    Picture q;
    Int d = Picture_d(p);
    
    if (d == 0) d = arrow_size/2; else d = 0;
    
    p = translate (p, 10, d);
    l = pics1(p);
    in = entry_pt(p);
    out = exit_pt(p);
    l = seqs (line (pt(0,in.y), in, TRUE, FALSE, 0), l);
    l = seqs (line (out, pt(out.x+10, out.y), FALSE, TRUE, 0), l);
    l = translates (l, 0, 10);
    l = seq (Create_Text (no_srcinfo, 0, 0, text_width (name, font), 0, name, font), l);
    q = compound (l);
        
    Front_List_append_node ((Front_List*)&drawings, q);
    
    Width = MAX (Width, Picture_w(q));
  }
}

/* Map grammar to diagrams */
static void gen_diagrams (front f)
{
  List_NonTerminal l;
  for (l = front_rules(f); l; l = List_NonTerminal_next(l)) {
    draw_nt (List_NonTerminal_data(l));
  }
}


/* Generate syntax diagrams in postscript for f */
void GenDiagrams (front f)
{
  Picture_init ();
  gen_diagrams(f);
  Scale *= (double)column_width / Width;
  printf ("CW = %d, W = %d, Scale = %g\n", column_width, Width, Scale);
  drawings = paginate (drawings);
  print_pictures (Rootstr, "Diagrams", "Front", drawings, columns, 0, 0);
}
