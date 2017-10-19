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
#ifndef _picture_h
#define _picture_h

#include "Pictures.h"

#ifndef MIN
#define MIN(a,b) ((a) < (b) ?  (a) : (b))
#endif

#ifndef MAX
#define MAX(a,b) ((a) > (b) ?  (a) : (b))
#endif

#ifndef ABS
#define ABS(a)   ((a) < 0   ? -(a) : (a))
#endif

typedef struct { Float x, y; } point;

#define POINT_SIZE 720/254

extern Bool landscape;
extern double Scale; /* Scale factor */
extern Int columns; /* Number of columns */
extern Bool singlefile;
extern Int paper_width, paper_height; /* Page size in mm */
extern Int column_width;

extern double Scale;	/* Scale factor */
extern Int arrow_size;
extern Int curve_size;
extern Bool no_arrow;
extern Bool translate_makes_copy;

point pt (Float x, Float y);
point entry_pt (Picture p);
point exit_pt (Picture p);

Picture empty_pic (void);
Picture fill (Picture p);
Picture dash (Picture p, Int d);

List_Picture pics1 (Picture a);
List_Picture pics2 (Picture a, Picture b);
List_Picture pics3 (Picture a, Picture b, Picture c);
List_Picture pics4 (Picture a, Picture b, Picture c, Picture d);

Picture pic2 (Picture a, Picture b);
Picture pic3 (Picture a, Picture b, Picture c);
Picture pic4 (Picture a, Picture b, Picture c, Picture d);

/* An oval with top-lef x,y and size w,h */
Picture oval (Int x, Int y, Int w, Int h);

/* A box containing text and arrow at entry */
Picture text_box (String t, Ident font);

/* An oval containing text and arrow at entry */
Picture text_oval (String t, Ident font);

List_Picture seq  (Picture a, List_Picture l);
List_Picture seqs (List_Picture a, List_Picture b);

/* Group elements of into one picture */
Picture compound (List_Picture l);

/* Draw a box around p with distance dx,dy to p */
Picture box (Picture p, int dx, int dy, Int dash);

/* Put p next to q, at distance dx, centers aligned */
Picture center_horizontally (Picture p, Picture q, Int dx);

/* Put p above q, at distance dy, centers aligned */
Picture center_vertically (Picture p, Picture q, Int dy);

/* Draw a line from p1 to p2 */
Picture draw_line (Picture p1, Picture p2);

/* Draw a line from a b to */
List_Picture line (point a, point b, Bool hor, Bool arrow, Int cs);

/* Translation by dx,dy */
Picture      translate  (Picture p, Int dx, Int dy);
List_Picture translates (List_Picture l, Int dx, Int dy);

/* Elements of p next to each other with distance dx */
Picture horizontal (List_Picture p, double dx);

/* Elements of p above each other with distance dy */
Picture vertical (List_Picture p, int dy);

/* Mirror around x */
Picture hor_flip (Picture p, Int x);

/* Mirror around y */
Picture ver_flip (Picture p, Int y);

Float text_width (String s, Ident font);

/* Change the font if needed */
void set_font (Ident font);

/* Break down picture into basic elements */
Picture break_down (Picture p);

/* Print picture in PostScript format */
void print_picture (Picture p);

/* Start/end of PS file */
void PS_prologue (String title, String creator);
void PS_epilogue (void);

/* Start/end of PS page */
void PS_start_page (Int page, Int dx, Int dy);
void PS_end_page (void);

/* Split drawings into pages */
List_Picture paginate (List_Picture drawings);

/* Print pictures, one per column */
void print_pictures (String fn, String title, String creator, 
                            List_Picture l, Int columns,
			    Int dx, Int dy);

void Picture_init (void);

#endif /* _picture_h */
