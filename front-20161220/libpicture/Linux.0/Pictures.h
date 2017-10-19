#ifndef _Pictures
#define _Pictures

#include <stdarg.h>
#include <stddef.h>
#include <front/basic_types.h>

typedef enum {
  Pictures_Left,
  Pictures_Right,
  Pictures_Up,
  Pictures_Down,
  Pictures_Center
} Pictures_Direction;
extern char *Pictures_Direction_names[];
#define NUM_Pictures_Direction 5

typedef enum {
  Pictures_Empty_kind,
  Pictures_Box_kind,
  Pictures_Circle_kind,
  Pictures_Arc_kind,
  Pictures_Curve_kind,
  Pictures_Line_kind,
  Pictures_Arrow_kind,
  Pictures_Text_kind,
  Pictures_OrBlock_kind,
  Pictures_AndBlock_kind,
  Pictures_AltBlock_kind,
  Pictures_Compound_kind
} Pictures_Picture_tag;
extern char *Pictures_Picture_tag_names[];
#define NUM_Pictures_Picture_tag 12

#ifndef DEF_TYPE_Pictures_Pictures
#define DEF_TYPE_Pictures_Pictures
typedef struct s_Pictures_Pictures      *Pictures_Pictures;
#endif

#ifndef DEF_TYPE_Pictures_Picture
#define DEF_TYPE_Pictures_Picture
typedef struct s_Pictures_Picture       *Pictures_Picture;
typedef Pictures_Picture Pictures_Compound;
typedef Pictures_Picture Pictures_AltBlock;
typedef Pictures_Picture Pictures_AndBlock;
typedef Pictures_Picture Pictures_OrBlock;
typedef Pictures_Picture Pictures_Text;
typedef Pictures_Picture Pictures_Arrow;
typedef Pictures_Picture Pictures_Line;
typedef Pictures_Picture Pictures_Curve;
typedef Pictures_Picture Pictures_Arc;
typedef Pictures_Picture Pictures_Circle;
typedef Pictures_Picture Pictures_Box;
typedef Pictures_Picture Pictures_Empty;
#endif

#ifndef DEF_TYPE_Pictures_Scope
#define DEF_TYPE_Pictures_Scope
typedef struct s_Pictures_Scope *Pictures_Scope;
#endif

#ifndef DEF_TYPE_List_Pictures_Direction
#define DEF_TYPE_List_Pictures_Direction
typedef struct s_List_Pictures_Direction        *List_Pictures_Direction;
#endif

#ifndef DEF_TYPE_List_Pictures_Picture
#define DEF_TYPE_List_Pictures_Picture
typedef struct s_List_Pictures_Picture  *List_Pictures_Picture;
#endif

#include <front/scan_support.h>
#include <front/print_support.h>
#include <front/SymTab.h>
#include "Pictures_parse.h"
#include "Pictures_defs.h"

extern Pictures_Pictures Pictures_root;

#ifndef DEF_STRUCT_Pictures_Pictures
#define DEF_STRUCT_Pictures_Pictures

struct s_Pictures_Pictures {
  SrcInfo       src_info;  
  struct Pictures_Pictures_hook*        hook;  
  List_Pictures_Picture pics;  
} ;

#define Pictures_Pictures_src_info(_p)  ((*_p).src_info)
#define Pictures_Pictures_srcinfo(_p)   ((*_p).src_info)
#define Pictures_Pictures_loc(_p)       ((*_p).src_info->loc)
#define Pictures_Pictures_hook(_p)      ((*_p).hook)
#define Pictures_Pictures_pics(_p)      ((*_p).pics)

extern Pictures_Pictures Create_Pictures_Pictures	(SrcInfo src_info, List_Pictures_Picture pics);

#endif /* DEF_STRUCT_Pictures_Pictures */

#ifndef DEF_STRUCT_Pictures_Picture
#define DEF_STRUCT_Pictures_Picture

struct s_Pictures_Picture {
  SrcInfo       src_info;  
  Pictures_Picture_tag  tag;  
  struct Pictures_Picture_hook* hook;  
  Float x;  
  Float y;  
  Float w;  
  Float h;  
  Float d;  
  Float scale;  
  Float phi;  
  Bool  fill;  
  Int   dash;  
  Bool  with_color;  
  union {
  struct s_Pictures_Empty {
  } Pictures_Empty;
  struct s_Pictures_Box {
  } Pictures_Box;
  struct s_Pictures_Circle {
  } Pictures_Circle;
  struct s_Pictures_Arc {
    Float       phi_1;  
    Float       phi_2;  
  } Pictures_Arc;
  struct s_Pictures_Curve {
    Bool        d1;  
    Bool        d2;  
  } Pictures_Curve;
  struct s_Pictures_Line {
  } Pictures_Line;
  struct s_Pictures_Arrow {
    Pictures_Direction  dir;  
  } Pictures_Arrow;
  struct s_Pictures_Text {
    String      text;  
    Ident       font;  
  } Pictures_Text;
  struct s_Pictures_OrBlock {
    List_Pictures_Picture       sub;  
    List_Pictures_Direction     dirs;  
  } Pictures_OrBlock;
  struct s_Pictures_AndBlock {
    List_Pictures_Picture       sub;  
    List_Pictures_Direction     dirs;  
  } Pictures_AndBlock;
  struct s_Pictures_AltBlock {
    Pictures_Picture    a;  
    Pictures_Picture    b;  
    Bool        turn_left;  
  } Pictures_AltBlock;
  struct s_Pictures_Compound {
    List_Pictures_Picture       sub;  
  } Pictures_Compound;
} sub;
} ;

#define Pictures_Picture_src_info(_p)   ((*_p).src_info)
#define Pictures_Picture_srcinfo(_p)    ((*_p).src_info)
#define Pictures_Picture_loc(_p)        ((*_p).src_info->loc)
#define Pictures_Picture_tag(_p)        ((*_p).tag)
#define Pictures_Picture_hook(_p)       ((*_p).hook)
#define Pictures_Picture_x(_p)  ((*_p).x)
#define Pictures_Picture_y(_p)  ((*_p).y)
#define Pictures_Picture_w(_p)  ((*_p).w)
#define Pictures_Picture_h(_p)  ((*_p).h)
#define Pictures_Picture_d(_p)  ((*_p).d)
#define Pictures_Picture_scale(_p)      ((*_p).scale)
#define Pictures_Picture_phi(_p)        ((*_p).phi)
#define Pictures_Picture_fill(_p)       ((*_p).fill)
#define Pictures_Picture_dash(_p)       ((*_p).dash)
#define Pictures_Picture_with_color(_p) ((*_p).with_color)
#define Pictures_Arc_phi_1(_p)  ((*_p).sub.Pictures_Arc.phi_1)
#define Pictures_Arc_phi_2(_p)  ((*_p).sub.Pictures_Arc.phi_2)
#define Pictures_Curve_d1(_p)   ((*_p).sub.Pictures_Curve.d1)
#define Pictures_Curve_d2(_p)   ((*_p).sub.Pictures_Curve.d2)
#define Pictures_Arrow_dir(_p)  ((*_p).sub.Pictures_Arrow.dir)
#define Pictures_Text_text(_p)  ((*_p).sub.Pictures_Text.text)
#define Pictures_Text_font(_p)  ((*_p).sub.Pictures_Text.font)
#define Pictures_OrBlock_sub(_p)        ((*_p).sub.Pictures_OrBlock.sub)
#define Pictures_OrBlock_dirs(_p)       ((*_p).sub.Pictures_OrBlock.dirs)
#define Pictures_AndBlock_sub(_p)       ((*_p).sub.Pictures_AndBlock.sub)
#define Pictures_AndBlock_dirs(_p)      ((*_p).sub.Pictures_AndBlock.dirs)
#define Pictures_AltBlock_a(_p) ((*_p).sub.Pictures_AltBlock.a)
#define Pictures_AltBlock_b(_p) ((*_p).sub.Pictures_AltBlock.b)
#define Pictures_AltBlock_turn_left(_p) ((*_p).sub.Pictures_AltBlock.turn_left)
#define Pictures_Compound_sub(_p)       ((*_p).sub.Pictures_Compound.sub)

extern Pictures_Compound Create_Pictures_Compound	(SrcInfo src_info, Float x, Float y, Float w, Float h, List_Pictures_Picture sub);
extern Pictures_AltBlock Create_Pictures_AltBlock	(SrcInfo src_info, Float x, Float y, Float w, Float h, Pictures_Picture a, Pictures_Picture b, Bool turn_left);
extern Pictures_AndBlock Create_Pictures_AndBlock	(SrcInfo src_info, Float x, Float y, Float w, Float h, List_Pictures_Picture sub, List_Pictures_Direction dirs);
extern Pictures_OrBlock Create_Pictures_OrBlock	(SrcInfo src_info, Float x, Float y, Float w, Float h, List_Pictures_Picture sub, List_Pictures_Direction dirs);
extern Pictures_Text Create_Pictures_Text	(SrcInfo src_info, Float x, Float y, Float w, Float h, String text, Ident font);
extern Pictures_Arrow Create_Pictures_Arrow	(SrcInfo src_info, Float x, Float y, Float w, Float h, Pictures_Direction dir);
extern Pictures_Line Create_Pictures_Line	(SrcInfo src_info, Float x, Float y, Float w, Float h);
extern Pictures_Curve Create_Pictures_Curve	(SrcInfo src_info, Float x, Float y, Float w, Float h, Bool d1, Bool d2);
extern Pictures_Arc Create_Pictures_Arc	(SrcInfo src_info, Float x, Float y, Float w, Float h, Float phi_1, Float phi_2);
extern Pictures_Circle Create_Pictures_Circle	(SrcInfo src_info, Float x, Float y, Float w, Float h);
extern Pictures_Box Create_Pictures_Box	(SrcInfo src_info, Float x, Float y, Float w, Float h);
extern Pictures_Empty Create_Pictures_Empty	(SrcInfo src_info, Float x, Float y, Float w, Float h);

#endif /* DEF_STRUCT_Pictures_Picture */

#ifndef DEF_STRUCT_Pictures_Scope
#define DEF_STRUCT_Pictures_Scope

struct s_Pictures_Scope {
  Pictures_Scope        next;  
  Int   _self;  
  Int   _end;  
} ;

#define Pictures_Scope_next(_p) ((*_p).next)
#define Pictures_Scope__self(_p)        ((*_p)._self)
#define Pictures_Scope__end(_p) ((*_p)._end)

extern Pictures_Scope Create_Pictures_Scope	(Pictures_Scope next);

#endif /* DEF_STRUCT_Pictures_Scope */

#ifndef DEF_STRUCT_List_Pictures_Direction
#define DEF_STRUCT_List_Pictures_Direction

struct s_List_Pictures_Direction {
  Pictures_Direction    data;  
  List_Pictures_Direction       next;  
} ;

#define List_Pictures_Direction_data(_p)        ((*_p).data)
#define List_Pictures_Direction_next(_p)        ((*_p).next)

#ifndef Create_List_Pictures_Direction
#define Create_List_Pictures_Direction(x,y) (List_Pictures_Direction)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Pictures_Direction_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Pictures_Direction */

#ifndef DEF_STRUCT_List_Pictures_Picture
#define DEF_STRUCT_List_Pictures_Picture

struct s_List_Pictures_Picture {
  Pictures_Picture      data;  
  List_Pictures_Picture next;  
} ;

#define List_Pictures_Picture_data(_p)  ((*_p).data)
#define List_Pictures_Picture_next(_p)  ((*_p).next)

#ifndef Create_List_Pictures_Picture
#define Create_List_Pictures_Picture(x,y) (List_Pictures_Picture)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Pictures_Picture_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Pictures_Picture */

#define PRE_ACTION  1
#define POST_ACTION 0

typedef struct s_Pictures_TraverseTable {
  Front_Traversal traversal;
  Pointer (*action_Pictures[2]) (Pictures_Pictures, Pointer);
  Bool skip_children_Pictures;
  Pointer (*action_Picture[2]) (Pictures_Picture, Pointer);
  Bool skip_children_Picture;
  Pointer (*action_Empty[2]) (Pictures_Empty, Pointer);
  Bool skip_children_Empty;
  Pointer (*action_Box[2]) (Pictures_Box, Pointer);
  Bool skip_children_Box;
  Pointer (*action_Circle[2]) (Pictures_Circle, Pointer);
  Bool skip_children_Circle;
  Pointer (*action_Arc[2]) (Pictures_Arc, Pointer);
  Bool skip_children_Arc;
  Pointer (*action_Curve[2]) (Pictures_Curve, Pointer);
  Bool skip_children_Curve;
  Pointer (*action_Line[2]) (Pictures_Line, Pointer);
  Bool skip_children_Line;
  Pointer (*action_Arrow[2]) (Pictures_Arrow, Pointer);
  Bool skip_children_Arrow;
  Pointer (*action_Text[2]) (Pictures_Text, Pointer);
  Bool skip_children_Text;
  Pointer (*action_OrBlock[2]) (Pictures_OrBlock, Pointer);
  Bool skip_children_OrBlock;
  Pointer (*action_AndBlock[2]) (Pictures_AndBlock, Pointer);
  Bool skip_children_AndBlock;
  Pointer (*action_AltBlock[2]) (Pictures_AltBlock, Pointer);
  Bool skip_children_AltBlock;
  Pointer (*action_Compound[2]) (Pictures_Compound, Pointer);
  Bool skip_children_Compound;
  Pointer (*action_Scope[2]) (Pictures_Scope, Pointer);
  Bool skip_children_Scope;
  Pointer (*action_List_Direction[2]) (List_Pictures_Direction, Pointer);
  Bool skip_children_List_Direction;
  Pointer (*action_List_Picture[2]) (List_Pictures_Picture, Pointer);
  Bool skip_children_List_Picture;
  Pointer (*action_Direction[2]) (Pictures_Direction, Pointer);
  Bool skip_children_Direction;
  Pointer (*action_Left[2]) (Pictures_Direction, Pointer);
  Bool skip_children_Left;
  Pointer (*action_Right[2]) (Pictures_Direction, Pointer);
  Bool skip_children_Right;
  Pointer (*action_Up[2]) (Pictures_Direction, Pointer);
  Bool skip_children_Up;
  Pointer (*action_Down[2]) (Pictures_Direction, Pointer);
  Bool skip_children_Down;
  Pointer (*action_Center[2]) (Pictures_Direction, Pointer);
  Bool skip_children_Center;
} *Pictures_TraverseTable;

extern Pointer Traverse_Pictures_Direction (Pictures_Direction me, Pictures_TraverseTable table, Pointer val);
extern Pointer Traverse_Pictures_Pictures (Pictures_Pictures me, Pictures_TraverseTable table, Pointer val);
extern Pointer Traverse_Pictures_Picture (Pictures_Picture me, Pictures_TraverseTable table, Pointer val);
extern Pointer Traverse_Pictures_Scope (Pictures_Scope me, Pictures_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Pictures_Direction (List_Pictures_Direction me, Pictures_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Pictures_Picture (List_Pictures_Picture me, Pictures_TraverseTable table, Pointer val);

typedef struct s_void_Pictures_TraverseTable {
  void (*action_Pictures[2]) (Pictures_Pictures);
  Bool skip_children_Pictures;
  void (*action_Picture[2]) (Pictures_Picture);
  Bool skip_children_Picture;
  void (*action_Empty[2]) (Pictures_Empty);
  Bool skip_children_Empty;
  void (*action_Box[2]) (Pictures_Box);
  Bool skip_children_Box;
  void (*action_Circle[2]) (Pictures_Circle);
  Bool skip_children_Circle;
  void (*action_Arc[2]) (Pictures_Arc);
  Bool skip_children_Arc;
  void (*action_Curve[2]) (Pictures_Curve);
  Bool skip_children_Curve;
  void (*action_Line[2]) (Pictures_Line);
  Bool skip_children_Line;
  void (*action_Arrow[2]) (Pictures_Arrow);
  Bool skip_children_Arrow;
  void (*action_Text[2]) (Pictures_Text);
  Bool skip_children_Text;
  void (*action_OrBlock[2]) (Pictures_OrBlock);
  Bool skip_children_OrBlock;
  void (*action_AndBlock[2]) (Pictures_AndBlock);
  Bool skip_children_AndBlock;
  void (*action_AltBlock[2]) (Pictures_AltBlock);
  Bool skip_children_AltBlock;
  void (*action_Compound[2]) (Pictures_Compound);
  Bool skip_children_Compound;
  void (*action_Scope[2]) (Pictures_Scope);
  Bool skip_children_Scope;
  void (*action_List_Direction[2]) (List_Pictures_Direction);
  Bool skip_children_List_Direction;
  void (*action_List_Picture[2]) (List_Pictures_Picture);
  Bool skip_children_List_Picture;
  void (*action_Direction[2]) (Pictures_Direction);
  Bool skip_children_Direction;
  void (*action_Left[2]) (Pictures_Direction);
  Bool skip_children_Left;
  void (*action_Right[2]) (Pictures_Direction);
  Bool skip_children_Right;
  void (*action_Up[2]) (Pictures_Direction);
  Bool skip_children_Up;
  void (*action_Down[2]) (Pictures_Direction);
  Bool skip_children_Down;
  void (*action_Center[2]) (Pictures_Direction);
  Bool skip_children_Center;
} *void_Pictures_TraverseTable;

extern void Traverse_void_Pictures_Direction (Pictures_Direction me, void_Pictures_TraverseTable table);
extern void Traverse_void_Pictures_Pictures (Pictures_Pictures me, void_Pictures_TraverseTable table);
extern void Traverse_void_Pictures_Picture (Pictures_Picture me, void_Pictures_TraverseTable table);
extern void Traverse_void_Pictures_Scope (Pictures_Scope me, void_Pictures_TraverseTable table);
extern void Traverse_void_List_Pictures_Direction (List_Pictures_Direction me, void_Pictures_TraverseTable table);
extern void Traverse_void_List_Pictures_Picture (List_Pictures_Picture me, void_Pictures_TraverseTable table);

typedef struct s_copy_Pictures_TraverseTable {
  Front_ClearBackEdges clear_back_edges;
  Pictures_Pictures (*action_Pictures[2]) (Pictures_Pictures, Pictures_Pictures);
  Bool skip_children_Pictures;
  Pictures_Picture (*action_Picture[2]) (Pictures_Picture, Pictures_Picture);
  Bool skip_children_Picture;
  Pictures_Empty (*action_Empty[2]) (Pictures_Empty, Pictures_Empty);
  Bool skip_children_Empty;
  Pictures_Box (*action_Box[2]) (Pictures_Box, Pictures_Box);
  Bool skip_children_Box;
  Pictures_Circle (*action_Circle[2]) (Pictures_Circle, Pictures_Circle);
  Bool skip_children_Circle;
  Pictures_Arc (*action_Arc[2]) (Pictures_Arc, Pictures_Arc);
  Bool skip_children_Arc;
  Pictures_Curve (*action_Curve[2]) (Pictures_Curve, Pictures_Curve);
  Bool skip_children_Curve;
  Pictures_Line (*action_Line[2]) (Pictures_Line, Pictures_Line);
  Bool skip_children_Line;
  Pictures_Arrow (*action_Arrow[2]) (Pictures_Arrow, Pictures_Arrow);
  Bool skip_children_Arrow;
  Pictures_Text (*action_Text[2]) (Pictures_Text, Pictures_Text);
  Bool skip_children_Text;
  Pictures_OrBlock (*action_OrBlock[2]) (Pictures_OrBlock, Pictures_OrBlock);
  Bool skip_children_OrBlock;
  Pictures_AndBlock (*action_AndBlock[2]) (Pictures_AndBlock, Pictures_AndBlock);
  Bool skip_children_AndBlock;
  Pictures_AltBlock (*action_AltBlock[2]) (Pictures_AltBlock, Pictures_AltBlock);
  Bool skip_children_AltBlock;
  Pictures_Compound (*action_Compound[2]) (Pictures_Compound, Pictures_Compound);
  Bool skip_children_Compound;
  Pictures_Scope (*action_Scope[2]) (Pictures_Scope, Pictures_Scope);
  Bool skip_children_Scope;
  List_Pictures_Direction (*action_List_Direction[2]) (List_Pictures_Direction, List_Pictures_Direction);
  Bool skip_children_List_Direction;
  List_Pictures_Picture (*action_List_Picture[2]) (List_Pictures_Picture, List_Pictures_Picture);
  Bool skip_children_List_Picture;
  Pictures_Direction (*action_Direction[2]) (Pictures_Direction, Pictures_Direction);
  Bool skip_children_Direction;
  Pictures_Direction (*action_Left[2]) (Pictures_Direction, Pictures_Direction);
  Bool skip_children_Left;
  Pictures_Direction (*action_Right[2]) (Pictures_Direction, Pictures_Direction);
  Bool skip_children_Right;
  Pictures_Direction (*action_Up[2]) (Pictures_Direction, Pictures_Direction);
  Bool skip_children_Up;
  Pictures_Direction (*action_Down[2]) (Pictures_Direction, Pictures_Direction);
  Bool skip_children_Down;
  Pictures_Direction (*action_Center[2]) (Pictures_Direction, Pictures_Direction);
  Bool skip_children_Center;
} *copy_Pictures_TraverseTable;

extern Pictures_Direction Traverse_copy_Pictures_Direction (Pictures_Direction me, copy_Pictures_TraverseTable table);
#ifndef COPY_Pictures_Direction
#define COPY_Pictures_Direction(x) Traverse_copy_Pictures_Direction(x, &Pictures_copy_actions)
#endif
extern Pictures_Pictures Traverse_copy_Pictures_Pictures (Pictures_Pictures me, copy_Pictures_TraverseTable table);
#ifndef COPY_Pictures_Pictures
#define COPY_Pictures_Pictures(x) Traverse_copy_Pictures_Pictures(x, &Pictures_copy_actions)
#endif
extern Pictures_Picture Traverse_copy_Pictures_Picture (Pictures_Picture me, copy_Pictures_TraverseTable table);
#ifndef COPY_Pictures_Picture
#define COPY_Pictures_Picture(x) Traverse_copy_Pictures_Picture(x, &Pictures_copy_actions)
#endif
extern Pictures_Scope Traverse_copy_Pictures_Scope (Pictures_Scope me, copy_Pictures_TraverseTable table);
#ifndef COPY_Pictures_Scope
#define COPY_Pictures_Scope(x) Traverse_copy_Pictures_Scope(x, &Pictures_copy_actions)
#endif
extern List_Pictures_Direction Traverse_copy_List_Pictures_Direction (List_Pictures_Direction me, copy_Pictures_TraverseTable table);
#ifndef COPY_Pictures_List_Direction
#define COPY_Pictures_List_Direction(x) Traverse_copy_List_Pictures_Direction(x, &Pictures_copy_actions)
#endif
extern List_Pictures_Picture Traverse_copy_List_Pictures_Picture (List_Pictures_Picture me, copy_Pictures_TraverseTable table);
#ifndef COPY_Pictures_List_Picture
#define COPY_Pictures_List_Picture(x) Traverse_copy_List_Pictures_Picture(x, &Pictures_copy_actions)
#endif

typedef struct s_compare_Pictures_TraverseTable {
  int (*action_Pictures[2]) (Pictures_Pictures, Pictures_Pictures);
  Bool skip_children_Pictures;
  int (*action_Picture[2]) (Pictures_Picture, Pictures_Picture);
  Bool skip_children_Picture;
  int (*action_Empty[2]) (Pictures_Empty, Pictures_Empty);
  Bool skip_children_Empty;
  int (*action_Box[2]) (Pictures_Box, Pictures_Box);
  Bool skip_children_Box;
  int (*action_Circle[2]) (Pictures_Circle, Pictures_Circle);
  Bool skip_children_Circle;
  int (*action_Arc[2]) (Pictures_Arc, Pictures_Arc);
  Bool skip_children_Arc;
  int (*action_Curve[2]) (Pictures_Curve, Pictures_Curve);
  Bool skip_children_Curve;
  int (*action_Line[2]) (Pictures_Line, Pictures_Line);
  Bool skip_children_Line;
  int (*action_Arrow[2]) (Pictures_Arrow, Pictures_Arrow);
  Bool skip_children_Arrow;
  int (*action_Text[2]) (Pictures_Text, Pictures_Text);
  Bool skip_children_Text;
  int (*action_OrBlock[2]) (Pictures_OrBlock, Pictures_OrBlock);
  Bool skip_children_OrBlock;
  int (*action_AndBlock[2]) (Pictures_AndBlock, Pictures_AndBlock);
  Bool skip_children_AndBlock;
  int (*action_AltBlock[2]) (Pictures_AltBlock, Pictures_AltBlock);
  Bool skip_children_AltBlock;
  int (*action_Compound[2]) (Pictures_Compound, Pictures_Compound);
  Bool skip_children_Compound;
  int (*action_Scope[2]) (Pictures_Scope, Pictures_Scope);
  Bool skip_children_Scope;
  int (*action_List_Direction[2]) (List_Pictures_Direction, List_Pictures_Direction);
  Bool skip_children_List_Direction;
  int (*action_List_Picture[2]) (List_Pictures_Picture, List_Pictures_Picture);
  Bool skip_children_List_Picture;
  int (*action_Direction[2]) (Pictures_Direction, Pictures_Direction);
  Bool skip_children_Direction;
  int (*action_Left[2]) (Pictures_Direction, Pictures_Direction);
  Bool skip_children_Left;
  int (*action_Right[2]) (Pictures_Direction, Pictures_Direction);
  Bool skip_children_Right;
  int (*action_Up[2]) (Pictures_Direction, Pictures_Direction);
  Bool skip_children_Up;
  int (*action_Down[2]) (Pictures_Direction, Pictures_Direction);
  Bool skip_children_Down;
  int (*action_Center[2]) (Pictures_Direction, Pictures_Direction);
  Bool skip_children_Center;
} *compare_Pictures_TraverseTable;

extern int Traverse_compare_Pictures_Direction (Pictures_Direction x, Pictures_Direction y, compare_Pictures_TraverseTable table);
extern int Traverse_compare_Pictures_Pictures (Pictures_Pictures x, Pictures_Pictures y, compare_Pictures_TraverseTable table);
extern int Traverse_compare_Pictures_Picture (Pictures_Picture x, Pictures_Picture y, compare_Pictures_TraverseTable table);
extern int Traverse_compare_Pictures_Scope (Pictures_Scope x, Pictures_Scope y, compare_Pictures_TraverseTable table);
extern int Traverse_compare_List_Pictures_Direction (List_Pictures_Direction x, List_Pictures_Direction y, compare_Pictures_TraverseTable table);
extern int Traverse_compare_List_Pictures_Picture (List_Pictures_Picture x, List_Pictures_Picture y, compare_Pictures_TraverseTable table);


extern void Pictures_fill_table (Pictures_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void void_Pictures_fill_table (void_Pictures_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void copy_Pictures_fill_table (copy_Pictures_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void compare_Pictures_fill_table (compare_Pictures_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern struct s_Pictures_TraverseTable Pictures_scope_actions;

extern struct s_void_Pictures_TraverseTable Pictures_defining_actions;

extern struct s_void_Pictures_TraverseTable Pictures_applied_actions;

extern struct s_void_Pictures_TraverseTable Pictures_check_actions;

extern struct s_void_Pictures_TraverseTable Pictures_print_actions;

extern struct s_copy_Pictures_TraverseTable Pictures_copy_actions;

extern struct s_compare_Pictures_TraverseTable Pictures_compare_actions;

typedef int Pictures_NameSpaces;

extern Pictures_NameSpaces Pictures_namespaces[1];

#define Pictures_DefaultNameSpace Pictures_namespaces[0]

#define Pictures_NUM_NAMESPACES 1

extern void Decorate_Pictures (Pictures_Pictures r);

#endif /* _Pictures */
