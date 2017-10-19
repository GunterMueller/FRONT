#ifndef _Diagrams
#define _Diagrams

#include <stdarg.h>
#include <stddef.h>
#include "basic_types.h"

typedef enum {
  Diagrams_Left,
  Diagrams_Right,
  Diagrams_Up,
  Diagrams_Down,
  Diagrams_Center
} Diagrams_Direction;
extern char *Diagrams_Direction_names[];
#define NUM_Diagrams_Direction 5

typedef enum {
  Diagrams_Empty_kind,
  Diagrams_Box_kind,
  Diagrams_Curve_kind,
  Diagrams_Line_kind,
  Diagrams_Arrow_kind,
  Diagrams_Text_kind,
  Diagrams_OrBlock_kind,
  Diagrams_AndBlock_kind,
  Diagrams_AltBlock_kind,
  Diagrams_Compound_kind
} Diagrams_Picture_tag;
extern char *Diagrams_Picture_tag_names[];
#define NUM_Diagrams_Picture_tag 10

#ifndef DEF_TYPE_Diagrams_Diagrams
#define DEF_TYPE_Diagrams_Diagrams
typedef struct s_Diagrams_Diagrams      *Diagrams_Diagrams;
#endif

#ifndef DEF_TYPE_Diagrams_Picture
#define DEF_TYPE_Diagrams_Picture
typedef struct s_Diagrams_Picture       *Diagrams_Picture;
typedef Diagrams_Picture Diagrams_Compound;
typedef Diagrams_Picture Diagrams_AltBlock;
typedef Diagrams_Picture Diagrams_AndBlock;
typedef Diagrams_Picture Diagrams_OrBlock;
typedef Diagrams_Picture Diagrams_Text;
typedef Diagrams_Picture Diagrams_Arrow;
typedef Diagrams_Picture Diagrams_Line;
typedef Diagrams_Picture Diagrams_Curve;
typedef Diagrams_Picture Diagrams_Box;
typedef Diagrams_Picture Diagrams_Empty;
#endif

#ifndef DEF_TYPE_Diagrams_Scope
#define DEF_TYPE_Diagrams_Scope
typedef struct s_Diagrams_Scope *Diagrams_Scope;
#endif

#ifndef DEF_TYPE_List_Diagrams_Direction
#define DEF_TYPE_List_Diagrams_Direction
typedef struct s_List_Diagrams_Direction        *List_Diagrams_Direction;
#endif

#ifndef DEF_TYPE_List_Diagrams_Picture
#define DEF_TYPE_List_Diagrams_Picture
typedef struct s_List_Diagrams_Picture  *List_Diagrams_Picture;
#endif

#include "scan_support.h"
#include "print_support.h"
#include "SymTab.h"
#include "Diagrams_parse.h"
#include "Diagrams_defs.h"

extern Diagrams_Diagrams Diagrams_root;

#ifndef DEF_STRUCT_Diagrams_Diagrams
#define DEF_STRUCT_Diagrams_Diagrams

struct s_Diagrams_Diagrams {
  SrcInfo       src_info;
  List_Diagrams_Picture pics;
} ;

#define Diagrams_Diagrams_src_info(_p)  ((*_p).src_info)
#define Diagrams_Diagrams_srcinfo(_p)   ((*_p).src_info)
#define Diagrams_Diagrams_loc(_p)       ((*_p).src_info->loc)
#define Diagrams_Diagrams_pics(_p)      ((*_p).pics)

extern Diagrams_Diagrams Create_Diagrams_Diagrams	(SrcInfo src_info, List_Diagrams_Picture pics);

#endif /* DEF_STRUCT_Diagrams_Diagrams */

#ifndef DEF_STRUCT_Diagrams_Picture
#define DEF_STRUCT_Diagrams_Picture

struct s_Diagrams_Picture {
  SrcInfo       src_info;
  Diagrams_Picture_tag  tag;
  Int   x;
  Int   y;
  Int   w;
  Int   h;
  int   d;
  union {
  struct s_Diagrams_Empty {
  } Diagrams_Empty;
  struct s_Diagrams_Box {
  } Diagrams_Box;
  struct s_Diagrams_Curve {
    Bool        d1;
    Bool        d2;
  } Diagrams_Curve;
  struct s_Diagrams_Line {
  } Diagrams_Line;
  struct s_Diagrams_Arrow {
    Diagrams_Direction  dir;
  } Diagrams_Arrow;
  struct s_Diagrams_Text {
    String      text;
    Ident       font;
  } Diagrams_Text;
  struct s_Diagrams_OrBlock {
    List_Diagrams_Picture       sub;
    List_Diagrams_Direction     dirs;
  } Diagrams_OrBlock;
  struct s_Diagrams_AndBlock {
    List_Diagrams_Picture       sub;
    List_Diagrams_Direction     dirs;
  } Diagrams_AndBlock;
  struct s_Diagrams_AltBlock {
    Diagrams_Picture    a;
    Diagrams_Picture    b;
    Bool        turn_left;
  } Diagrams_AltBlock;
  struct s_Diagrams_Compound {
    List_Diagrams_Picture       sub;
  } Diagrams_Compound;
} sub;
} ;

#define Diagrams_Picture_src_info(_p)   ((*_p).src_info)
#define Diagrams_Picture_srcinfo(_p)    ((*_p).src_info)
#define Diagrams_Picture_loc(_p)        ((*_p).src_info->loc)
#define Diagrams_Picture_tag(_p)        ((*_p).tag)
#define Diagrams_Picture_x(_p)  ((*_p).x)
#define Diagrams_Picture_y(_p)  ((*_p).y)
#define Diagrams_Picture_w(_p)  ((*_p).w)
#define Diagrams_Picture_h(_p)  ((*_p).h)
#define Diagrams_Picture_d(_p)  ((*_p).d)
#define Diagrams_Curve_d1(_p)   ((*_p).sub.Diagrams_Curve.d1)
#define Diagrams_Curve_d2(_p)   ((*_p).sub.Diagrams_Curve.d2)
#define Diagrams_Arrow_dir(_p)  ((*_p).sub.Diagrams_Arrow.dir)
#define Diagrams_Text_text(_p)  ((*_p).sub.Diagrams_Text.text)
#define Diagrams_Text_font(_p)  ((*_p).sub.Diagrams_Text.font)
#define Diagrams_OrBlock_sub(_p)        ((*_p).sub.Diagrams_OrBlock.sub)
#define Diagrams_OrBlock_dirs(_p)       ((*_p).sub.Diagrams_OrBlock.dirs)
#define Diagrams_AndBlock_sub(_p)       ((*_p).sub.Diagrams_AndBlock.sub)
#define Diagrams_AndBlock_dirs(_p)      ((*_p).sub.Diagrams_AndBlock.dirs)
#define Diagrams_AltBlock_a(_p) ((*_p).sub.Diagrams_AltBlock.a)
#define Diagrams_AltBlock_b(_p) ((*_p).sub.Diagrams_AltBlock.b)
#define Diagrams_AltBlock_turn_left(_p) ((*_p).sub.Diagrams_AltBlock.turn_left)
#define Diagrams_Compound_sub(_p)       ((*_p).sub.Diagrams_Compound.sub)

extern Diagrams_Compound Create_Diagrams_Compound	(SrcInfo src_info, Int x, Int y, Int w, Int h, List_Diagrams_Picture sub);
extern Diagrams_AltBlock Create_Diagrams_AltBlock	(SrcInfo src_info, Int x, Int y, Int w, Int h, Diagrams_Picture a, Diagrams_Picture b, Bool turn_left);
extern Diagrams_AndBlock Create_Diagrams_AndBlock	(SrcInfo src_info, Int x, Int y, Int w, Int h, List_Diagrams_Picture sub, List_Diagrams_Direction dirs);
extern Diagrams_OrBlock Create_Diagrams_OrBlock	(SrcInfo src_info, Int x, Int y, Int w, Int h, List_Diagrams_Picture sub, List_Diagrams_Direction dirs);
extern Diagrams_Text Create_Diagrams_Text	(SrcInfo src_info, Int x, Int y, Int w, Int h, String text, Ident font);
extern Diagrams_Arrow Create_Diagrams_Arrow	(SrcInfo src_info, Int x, Int y, Int w, Int h, Diagrams_Direction dir);
extern Diagrams_Line Create_Diagrams_Line	(SrcInfo src_info, Int x, Int y, Int w, Int h);
extern Diagrams_Curve Create_Diagrams_Curve	(SrcInfo src_info, Int x, Int y, Int w, Int h, Bool d1, Bool d2);
extern Diagrams_Box Create_Diagrams_Box	(SrcInfo src_info, Int x, Int y, Int w, Int h);
extern Diagrams_Empty Create_Diagrams_Empty	(SrcInfo src_info, Int x, Int y, Int w, Int h);

#endif /* DEF_STRUCT_Diagrams_Picture */

#ifndef DEF_STRUCT_Diagrams_Scope
#define DEF_STRUCT_Diagrams_Scope

struct s_Diagrams_Scope {
  Diagrams_Scope        next;
} ;

#define Diagrams_Scope_next(_p) ((*_p).next)

extern Diagrams_Scope Create_Diagrams_Scope	(Diagrams_Scope next);

#endif /* DEF_STRUCT_Diagrams_Scope */

#ifndef DEF_STRUCT_List_Diagrams_Direction
#define DEF_STRUCT_List_Diagrams_Direction

struct s_List_Diagrams_Direction {
  Diagrams_Direction    data;
  List_Diagrams_Direction       next;
} ;

#define List_Diagrams_Direction_data(_p)        ((*_p).data)
#define List_Diagrams_Direction_next(_p)        ((*_p).next)

#ifndef Create_List_Diagrams_Direction
#define Create_List_Diagrams_Direction(x,y) (List_Diagrams_Direction)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Diagrams_Direction_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Diagrams_Direction */

#ifndef DEF_STRUCT_List_Diagrams_Picture
#define DEF_STRUCT_List_Diagrams_Picture

struct s_List_Diagrams_Picture {
  Diagrams_Picture      data;
  List_Diagrams_Picture next;
} ;

#define List_Diagrams_Picture_data(_p)  ((*_p).data)
#define List_Diagrams_Picture_next(_p)  ((*_p).next)

#ifndef Create_List_Diagrams_Picture
#define Create_List_Diagrams_Picture(x,y) (List_Diagrams_Picture)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_Diagrams_Picture_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_Diagrams_Picture */

#define PRE_ACTION  1
#define POST_ACTION 0

typedef struct s_Diagrams_TraverseTable {
  Front_Traversal traversal;
  Pointer (*action_Diagrams[2]) (Diagrams_Diagrams, Pointer);
  Bool skip_children_Diagrams;
  Pointer (*action_Picture[2]) (Diagrams_Picture, Pointer);
  Bool skip_children_Picture;
  Pointer (*action_Empty[2]) (Diagrams_Empty, Pointer);
  Bool skip_children_Empty;
  Pointer (*action_Box[2]) (Diagrams_Box, Pointer);
  Bool skip_children_Box;
  Pointer (*action_Curve[2]) (Diagrams_Curve, Pointer);
  Bool skip_children_Curve;
  Pointer (*action_Line[2]) (Diagrams_Line, Pointer);
  Bool skip_children_Line;
  Pointer (*action_Arrow[2]) (Diagrams_Arrow, Pointer);
  Bool skip_children_Arrow;
  Pointer (*action_Text[2]) (Diagrams_Text, Pointer);
  Bool skip_children_Text;
  Pointer (*action_OrBlock[2]) (Diagrams_OrBlock, Pointer);
  Bool skip_children_OrBlock;
  Pointer (*action_AndBlock[2]) (Diagrams_AndBlock, Pointer);
  Bool skip_children_AndBlock;
  Pointer (*action_AltBlock[2]) (Diagrams_AltBlock, Pointer);
  Bool skip_children_AltBlock;
  Pointer (*action_Compound[2]) (Diagrams_Compound, Pointer);
  Bool skip_children_Compound;
  Pointer (*action_Scope[2]) (Diagrams_Scope, Pointer);
  Bool skip_children_Scope;
  Pointer (*action_List_Direction[2]) (List_Diagrams_Direction, Pointer);
  Bool skip_children_List_Direction;
  Pointer (*action_List_Picture[2]) (List_Diagrams_Picture, Pointer);
  Bool skip_children_List_Picture;
  Pointer (*action_Direction[2]) (Diagrams_Direction, Pointer);
  Bool skip_children_Direction;
  Pointer (*action_Left[2]) (Diagrams_Direction, Pointer);
  Bool skip_children_Left;
  Pointer (*action_Right[2]) (Diagrams_Direction, Pointer);
  Bool skip_children_Right;
  Pointer (*action_Up[2]) (Diagrams_Direction, Pointer);
  Bool skip_children_Up;
  Pointer (*action_Down[2]) (Diagrams_Direction, Pointer);
  Bool skip_children_Down;
  Pointer (*action_Center[2]) (Diagrams_Direction, Pointer);
  Bool skip_children_Center;
} *Diagrams_TraverseTable;

extern Pointer Traverse_Diagrams_Direction (Diagrams_Direction me, Diagrams_TraverseTable table, Pointer val);
extern Pointer Traverse_Diagrams_Diagrams (Diagrams_Diagrams me, Diagrams_TraverseTable table, Pointer val);
extern Pointer Traverse_Diagrams_Picture (Diagrams_Picture me, Diagrams_TraverseTable table, Pointer val);
extern Pointer Traverse_Diagrams_Scope (Diagrams_Scope me, Diagrams_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Diagrams_Direction (List_Diagrams_Direction me, Diagrams_TraverseTable table, Pointer val);
extern Pointer Traverse_List_Diagrams_Picture (List_Diagrams_Picture me, Diagrams_TraverseTable table, Pointer val);

typedef struct s_void_Diagrams_TraverseTable {
  void (*action_Diagrams[2]) (Diagrams_Diagrams);
  Bool skip_children_Diagrams;
  void (*action_Picture[2]) (Diagrams_Picture);
  Bool skip_children_Picture;
  void (*action_Empty[2]) (Diagrams_Empty);
  Bool skip_children_Empty;
  void (*action_Box[2]) (Diagrams_Box);
  Bool skip_children_Box;
  void (*action_Curve[2]) (Diagrams_Curve);
  Bool skip_children_Curve;
  void (*action_Line[2]) (Diagrams_Line);
  Bool skip_children_Line;
  void (*action_Arrow[2]) (Diagrams_Arrow);
  Bool skip_children_Arrow;
  void (*action_Text[2]) (Diagrams_Text);
  Bool skip_children_Text;
  void (*action_OrBlock[2]) (Diagrams_OrBlock);
  Bool skip_children_OrBlock;
  void (*action_AndBlock[2]) (Diagrams_AndBlock);
  Bool skip_children_AndBlock;
  void (*action_AltBlock[2]) (Diagrams_AltBlock);
  Bool skip_children_AltBlock;
  void (*action_Compound[2]) (Diagrams_Compound);
  Bool skip_children_Compound;
  void (*action_Scope[2]) (Diagrams_Scope);
  Bool skip_children_Scope;
  void (*action_List_Direction[2]) (List_Diagrams_Direction);
  Bool skip_children_List_Direction;
  void (*action_List_Picture[2]) (List_Diagrams_Picture);
  Bool skip_children_List_Picture;
  void (*action_Direction[2]) (Diagrams_Direction);
  Bool skip_children_Direction;
  void (*action_Left[2]) (Diagrams_Direction);
  Bool skip_children_Left;
  void (*action_Right[2]) (Diagrams_Direction);
  Bool skip_children_Right;
  void (*action_Up[2]) (Diagrams_Direction);
  Bool skip_children_Up;
  void (*action_Down[2]) (Diagrams_Direction);
  Bool skip_children_Down;
  void (*action_Center[2]) (Diagrams_Direction);
  Bool skip_children_Center;
} *void_Diagrams_TraverseTable;

extern void Traverse_void_Diagrams_Direction (Diagrams_Direction me, void_Diagrams_TraverseTable table);
extern void Traverse_void_Diagrams_Diagrams (Diagrams_Diagrams me, void_Diagrams_TraverseTable table);
extern void Traverse_void_Diagrams_Picture (Diagrams_Picture me, void_Diagrams_TraverseTable table);
extern void Traverse_void_Diagrams_Scope (Diagrams_Scope me, void_Diagrams_TraverseTable table);
extern void Traverse_void_List_Diagrams_Direction (List_Diagrams_Direction me, void_Diagrams_TraverseTable table);
extern void Traverse_void_List_Diagrams_Picture (List_Diagrams_Picture me, void_Diagrams_TraverseTable table);

typedef struct s_copy_Diagrams_TraverseTable {
  Front_ClearBackEdges clear_back_edges;
  Diagrams_Diagrams (*action_Diagrams[2]) (Diagrams_Diagrams, Diagrams_Diagrams);
  Diagrams_Picture (*action_Picture[2]) (Diagrams_Picture, Diagrams_Picture);
  Diagrams_Empty (*action_Empty[2]) (Diagrams_Empty, Diagrams_Empty);
  Diagrams_Box (*action_Box[2]) (Diagrams_Box, Diagrams_Box);
  Diagrams_Curve (*action_Curve[2]) (Diagrams_Curve, Diagrams_Curve);
  Diagrams_Line (*action_Line[2]) (Diagrams_Line, Diagrams_Line);
  Diagrams_Arrow (*action_Arrow[2]) (Diagrams_Arrow, Diagrams_Arrow);
  Diagrams_Text (*action_Text[2]) (Diagrams_Text, Diagrams_Text);
  Diagrams_OrBlock (*action_OrBlock[2]) (Diagrams_OrBlock, Diagrams_OrBlock);
  Diagrams_AndBlock (*action_AndBlock[2]) (Diagrams_AndBlock, Diagrams_AndBlock);
  Diagrams_AltBlock (*action_AltBlock[2]) (Diagrams_AltBlock, Diagrams_AltBlock);
  Diagrams_Compound (*action_Compound[2]) (Diagrams_Compound, Diagrams_Compound);
  Diagrams_Scope (*action_Scope[2]) (Diagrams_Scope, Diagrams_Scope);
  List_Diagrams_Direction (*action_List_Direction[2]) (List_Diagrams_Direction, List_Diagrams_Direction);
  List_Diagrams_Picture (*action_List_Picture[2]) (List_Diagrams_Picture, List_Diagrams_Picture);
  Diagrams_Direction (*action_Direction[2]) (Diagrams_Direction, Diagrams_Direction);
  Diagrams_Direction (*action_Left[2]) (Diagrams_Direction, Diagrams_Direction);
  Diagrams_Direction (*action_Right[2]) (Diagrams_Direction, Diagrams_Direction);
  Diagrams_Direction (*action_Up[2]) (Diagrams_Direction, Diagrams_Direction);
  Diagrams_Direction (*action_Down[2]) (Diagrams_Direction, Diagrams_Direction);
  Diagrams_Direction (*action_Center[2]) (Diagrams_Direction, Diagrams_Direction);
} *copy_Diagrams_TraverseTable;

extern Diagrams_Direction Traverse_copy_Diagrams_Direction (Diagrams_Direction me, copy_Diagrams_TraverseTable table);
#ifndef COPY_Diagrams_Direction
#define COPY_Diagrams_Direction(x) Traverse_copy_Diagrams_Direction(x, &Diagrams_copy_actions)
#endif
extern Diagrams_Diagrams Traverse_copy_Diagrams_Diagrams (Diagrams_Diagrams me, copy_Diagrams_TraverseTable table);
#ifndef COPY_Diagrams_Diagrams
#define COPY_Diagrams_Diagrams(x) Traverse_copy_Diagrams_Diagrams(x, &Diagrams_copy_actions)
#endif
extern Diagrams_Picture Traverse_copy_Diagrams_Picture (Diagrams_Picture me, copy_Diagrams_TraverseTable table);
#ifndef COPY_Diagrams_Picture
#define COPY_Diagrams_Picture(x) Traverse_copy_Diagrams_Picture(x, &Diagrams_copy_actions)
#endif
extern Diagrams_Scope Traverse_copy_Diagrams_Scope (Diagrams_Scope me, copy_Diagrams_TraverseTable table);
#ifndef COPY_Diagrams_Scope
#define COPY_Diagrams_Scope(x) Traverse_copy_Diagrams_Scope(x, &Diagrams_copy_actions)
#endif
extern List_Diagrams_Direction Traverse_copy_List_Diagrams_Direction (List_Diagrams_Direction me, copy_Diagrams_TraverseTable table);
#ifndef COPY_Diagrams_List_Direction
#define COPY_Diagrams_List_Direction(x) Traverse_copy_List_Diagrams_Direction(x, &Diagrams_copy_actions)
#endif
extern List_Diagrams_Picture Traverse_copy_List_Diagrams_Picture (List_Diagrams_Picture me, copy_Diagrams_TraverseTable table);
#ifndef COPY_Diagrams_List_Picture
#define COPY_Diagrams_List_Picture(x) Traverse_copy_List_Diagrams_Picture(x, &Diagrams_copy_actions)
#endif

typedef struct s_compare_Diagrams_TraverseTable {
  int (*action_Diagrams[2]) (Diagrams_Diagrams, Diagrams_Diagrams);
  Bool skip_children_Diagrams;
  int (*action_Picture[2]) (Diagrams_Picture, Diagrams_Picture);
  Bool skip_children_Picture;
  int (*action_Empty[2]) (Diagrams_Empty, Diagrams_Empty);
  Bool skip_children_Empty;
  int (*action_Box[2]) (Diagrams_Box, Diagrams_Box);
  Bool skip_children_Box;
  int (*action_Curve[2]) (Diagrams_Curve, Diagrams_Curve);
  Bool skip_children_Curve;
  int (*action_Line[2]) (Diagrams_Line, Diagrams_Line);
  Bool skip_children_Line;
  int (*action_Arrow[2]) (Diagrams_Arrow, Diagrams_Arrow);
  Bool skip_children_Arrow;
  int (*action_Text[2]) (Diagrams_Text, Diagrams_Text);
  Bool skip_children_Text;
  int (*action_OrBlock[2]) (Diagrams_OrBlock, Diagrams_OrBlock);
  Bool skip_children_OrBlock;
  int (*action_AndBlock[2]) (Diagrams_AndBlock, Diagrams_AndBlock);
  Bool skip_children_AndBlock;
  int (*action_AltBlock[2]) (Diagrams_AltBlock, Diagrams_AltBlock);
  Bool skip_children_AltBlock;
  int (*action_Compound[2]) (Diagrams_Compound, Diagrams_Compound);
  Bool skip_children_Compound;
  int (*action_Scope[2]) (Diagrams_Scope, Diagrams_Scope);
  Bool skip_children_Scope;
  int (*action_List_Direction[2]) (List_Diagrams_Direction, List_Diagrams_Direction);
  Bool skip_children_List_Direction;
  int (*action_List_Picture[2]) (List_Diagrams_Picture, List_Diagrams_Picture);
  Bool skip_children_List_Picture;
  int (*action_Direction[2]) (Diagrams_Direction, Diagrams_Direction);
  Bool skip_children_Direction;
  int (*action_Left[2]) (Diagrams_Direction, Diagrams_Direction);
  Bool skip_children_Left;
  int (*action_Right[2]) (Diagrams_Direction, Diagrams_Direction);
  Bool skip_children_Right;
  int (*action_Up[2]) (Diagrams_Direction, Diagrams_Direction);
  Bool skip_children_Up;
  int (*action_Down[2]) (Diagrams_Direction, Diagrams_Direction);
  Bool skip_children_Down;
  int (*action_Center[2]) (Diagrams_Direction, Diagrams_Direction);
  Bool skip_children_Center;
} *compare_Diagrams_TraverseTable;

extern int Traverse_compare_Diagrams_Direction (Diagrams_Direction x, Diagrams_Direction y, compare_Diagrams_TraverseTable table);
extern int Traverse_compare_Diagrams_Diagrams (Diagrams_Diagrams x, Diagrams_Diagrams y, compare_Diagrams_TraverseTable table);
extern int Traverse_compare_Diagrams_Picture (Diagrams_Picture x, Diagrams_Picture y, compare_Diagrams_TraverseTable table);
extern int Traverse_compare_Diagrams_Scope (Diagrams_Scope x, Diagrams_Scope y, compare_Diagrams_TraverseTable table);
extern int Traverse_compare_List_Diagrams_Direction (List_Diagrams_Direction x, List_Diagrams_Direction y, compare_Diagrams_TraverseTable table);
extern int Traverse_compare_List_Diagrams_Picture (List_Diagrams_Picture x, List_Diagrams_Picture y, compare_Diagrams_TraverseTable table);


extern void Diagrams_fill_table (Diagrams_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool memo, Int action));
extern void void_Diagrams_fill_table (void_Diagrams_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool memo, Int action));
extern void copy_Diagrams_fill_table (copy_Diagrams_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool memo, Int action));
extern void compare_Diagrams_fill_table (compare_Diagrams_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool memo, Int action));
extern struct s_Diagrams_TraverseTable Diagrams_scope_actions;

extern struct s_void_Diagrams_TraverseTable Diagrams_defining_actions;

extern struct s_void_Diagrams_TraverseTable Diagrams_applied_actions;

extern struct s_void_Diagrams_TraverseTable Diagrams_check_actions;

extern struct s_void_Diagrams_TraverseTable Diagrams_print_actions;

extern struct s_copy_Diagrams_TraverseTable Diagrams_copy_actions;

extern struct s_compare_Diagrams_TraverseTable Diagrams_compare_actions;

typedef int Diagrams_NameSpaces;

extern Diagrams_NameSpaces Diagrams_namespaces[1];

#define Diagrams_DefaultNameSpace Diagrams_namespaces[0]

#define Diagrams_NUM_NAMESPACES 1

extern void Decorate_Diagrams (Diagrams_Diagrams r);

#endif /* _Diagrams */
