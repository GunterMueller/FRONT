#ifndef _egg
#define _egg

#include <stdarg.h>
#include <stddef.h>
#include <front/basic_types.h>

typedef enum {
  egg_StringExpr_kind,
  egg_CallExpr_kind,
  egg_IdExpr_kind
} egg_Expression_tag;
extern char *egg_Expression_tag_names[];
#define NUM_egg_Expression_tag 3

typedef enum {
  egg_Message_kind,
  egg_Group_kind
} egg_Statement_tag;
extern char *egg_Statement_tag_names[];
#define NUM_egg_Statement_tag 2

typedef enum {
  egg_ErrorMsg,
  egg_WarningMsg,
  egg_DisabledMsg,
  egg_KeyMsg,
  egg_PostMsg
} egg_MessageKind;
extern char *egg_MessageKind_names[];
#define NUM_egg_MessageKind 5

typedef enum {
  egg_GroupScope_kind
} egg_Scope_tag;
extern char *egg_Scope_tag_names[];
#define NUM_egg_Scope_tag 1

#ifndef DEF_TYPE_egg_egg
#define DEF_TYPE_egg_egg
typedef struct s_egg_egg        *egg_egg;
#endif

#ifndef DEF_TYPE_egg_Uses
#define DEF_TYPE_egg_Uses
typedef struct s_egg_Uses       *egg_Uses;
#endif

#ifndef DEF_TYPE_egg_Declaration
#define DEF_TYPE_egg_Declaration
typedef struct s_egg_Declaration        *egg_Declaration;
#endif

#ifndef DEF_TYPE_egg_Expression
#define DEF_TYPE_egg_Expression
typedef struct s_egg_Expression *egg_Expression;
typedef egg_Expression egg_IdExpr;
typedef egg_Expression egg_CallExpr;
typedef egg_Expression egg_StringExpr;
#endif

#ifndef DEF_TYPE_egg_Statement
#define DEF_TYPE_egg_Statement
typedef struct s_egg_Statement  *egg_Statement;
typedef egg_Statement egg_Group;
typedef egg_Statement egg_Message;
#endif

#ifndef DEF_TYPE_egg_SubMessage
#define DEF_TYPE_egg_SubMessage
typedef struct s_egg_SubMessage *egg_SubMessage;
#endif

#ifndef DEF_TYPE_egg_Scope
#define DEF_TYPE_egg_Scope
typedef struct s_egg_Scope      *egg_Scope;
typedef egg_Scope egg_GroupScope;
#endif

#ifndef DEF_TYPE_List_egg_Declaration
#define DEF_TYPE_List_egg_Declaration
typedef struct s_List_egg_Declaration   *List_egg_Declaration;
#endif

#ifndef DEF_TYPE_List_egg_SubMessage
#define DEF_TYPE_List_egg_SubMessage
typedef struct s_List_egg_SubMessage    *List_egg_SubMessage;
#endif

#ifndef DEF_TYPE_List_egg_Expression
#define DEF_TYPE_List_egg_Expression
typedef struct s_List_egg_Expression    *List_egg_Expression;
#endif

#ifndef DEF_TYPE_List_egg_Statement
#define DEF_TYPE_List_egg_Statement
typedef struct s_List_egg_Statement     *List_egg_Statement;
#endif

#include <front/scan_support.h>
#include <front/print_support.h>
#include <front/SymTab.h>
#include "egg_parse.h"
#include "egg_defs.h"

extern egg_egg egg_root;

#ifndef DEF_STRUCT_egg_egg
#define DEF_STRUCT_egg_egg

struct s_egg_egg {
  SrcInfo       src_info;  
  egg_Uses      uses;  
  List_egg_Statement    groups;  
} ;

#define egg_egg_src_info(_p)    ((*_p).src_info)
#define egg_egg_srcinfo(_p)     ((*_p).src_info)
#define egg_egg_loc(_p) ((*_p).src_info->loc)
#define egg_egg_uses(_p)        ((*_p).uses)
#define egg_egg_groups(_p)      ((*_p).groups)

extern egg_egg Create_egg_egg	(SrcInfo src_info, egg_Uses uses, List_egg_Statement groups);

#endif /* DEF_STRUCT_egg_egg */

#ifndef DEF_STRUCT_egg_Uses
#define DEF_STRUCT_egg_Uses

struct s_egg_Uses {
  SrcInfo       src_info;  
  List_String   uses;  
} ;

#define egg_Uses_src_info(_p)   ((*_p).src_info)
#define egg_Uses_srcinfo(_p)    ((*_p).src_info)
#define egg_Uses_loc(_p)        ((*_p).src_info->loc)
#define egg_Uses_uses(_p)       ((*_p).uses)

extern egg_Uses Create_egg_Uses	(SrcInfo src_info, List_String uses);

#endif /* DEF_STRUCT_egg_Uses */

#ifndef DEF_STRUCT_egg_Declaration
#define DEF_STRUCT_egg_Declaration

struct s_egg_Declaration {
  SrcInfo       src_info;  
  egg_MessageKind       kind;  
  List_egg_Expression   exprs;  
  egg_Statement group;  
} ;

#define egg_Declaration_src_info(_p)    ((*_p).src_info)
#define egg_Declaration_srcinfo(_p)     ((*_p).src_info)
#define egg_Declaration_loc(_p) ((*_p).src_info->loc)
#define egg_Declaration_kind(_p)        ((*_p).kind)
#define egg_Declaration_exprs(_p)       ((*_p).exprs)
#define egg_Declaration_group(_p)       ((*_p).group)

extern egg_Declaration Create_egg_Declaration	(SrcInfo src_info, egg_MessageKind kind, List_egg_Expression exprs);

#endif /* DEF_STRUCT_egg_Declaration */

#ifndef DEF_STRUCT_egg_Expression
#define DEF_STRUCT_egg_Expression

struct s_egg_Expression {
  SrcInfo       src_info;  
  egg_Expression_tag    tag;  
  union {
  struct s_egg_StringExpr {
    String      s;  
  } egg_StringExpr;
  struct s_egg_CallExpr {
    Ident       id;  
    List_egg_Expression params;  
  } egg_CallExpr;
  struct s_egg_IdExpr {
    Ident       id;  
  } egg_IdExpr;
} sub;
} ;

#define egg_Expression_src_info(_p)     ((*_p).src_info)
#define egg_Expression_srcinfo(_p)      ((*_p).src_info)
#define egg_Expression_loc(_p)  ((*_p).src_info->loc)
#define egg_Expression_tag(_p)  ((*_p).tag)
#define egg_StringExpr_s(_p)    ((*_p).sub.egg_StringExpr.s)
#define egg_CallExpr_id(_p)     ((*_p).sub.egg_CallExpr.id)
#define egg_CallExpr_params(_p) ((*_p).sub.egg_CallExpr.params)
#define egg_IdExpr_id(_p)       ((*_p).sub.egg_IdExpr.id)

extern egg_IdExpr Create_egg_IdExpr	(SrcInfo src_info, Ident id);
extern egg_CallExpr Create_egg_CallExpr	(SrcInfo src_info, Ident id, List_egg_Expression params);
extern egg_StringExpr Create_egg_StringExpr	(SrcInfo src_info, String s);

#endif /* DEF_STRUCT_egg_Expression */

#ifndef DEF_STRUCT_egg_Statement
#define DEF_STRUCT_egg_Statement

struct s_egg_Statement {
  SrcInfo       src_info;  
  Int   _num;  
  egg_Scope     scope;  
  egg_Scope     old_scope;  
  egg_Statement_tag     tag;  
  Bool  fatal;  
  Ident id;  
  union {
  struct s_egg_Message {
    List_egg_SubMessage msgs;  
  } egg_Message;
  struct s_egg_Group {
    Ident       type;  
    Bool        group;  
    List_egg_Declaration        decls;  
    List_egg_Statement  stats;  
  } egg_Group;
} sub;
  egg_Statement parent;  
} ;

#define egg_Statement_src_info(_p)      ((*_p).src_info)
#define egg_Statement_srcinfo(_p)       ((*_p).src_info)
#define egg_Statement_loc(_p)   ((*_p).src_info->loc)
#define egg_Statement__num(_p)  ((*_p)._num)
#define egg_Statement_scope(_p) ((*_p).scope)
#define egg_Statement_old_scope(_p)     ((*_p).old_scope)
#define egg_Statement_tag(_p)   ((*_p).tag)
#define egg_Statement_fatal(_p) ((*_p).fatal)
#define egg_Statement_id(_p)    ((*_p).id)
#define egg_Message_msgs(_p)    ((*_p).sub.egg_Message.msgs)
#define egg_Group_type(_p)      ((*_p).sub.egg_Group.type)
#define egg_Group_group(_p)     ((*_p).sub.egg_Group.group)
#define egg_Group_decls(_p)     ((*_p).sub.egg_Group.decls)
#define egg_Group_stats(_p)     ((*_p).sub.egg_Group.stats)
#define egg_Statement_parent(_p)        ((*_p).parent)

extern egg_Group Create_egg_Group	(SrcInfo src_info, Bool fatal, Ident id, Ident type, Bool group, List_egg_Declaration decls, List_egg_Statement stats);
extern egg_Message Create_egg_Message	(SrcInfo src_info, Bool fatal, Ident id, List_egg_SubMessage msgs);

#endif /* DEF_STRUCT_egg_Statement */

#ifndef DEF_STRUCT_egg_SubMessage
#define DEF_STRUCT_egg_SubMessage

struct s_egg_SubMessage {
  SrcInfo       src_info;  
  egg_MessageKind       kind;  
  String        msg;  
} ;

#define egg_SubMessage_src_info(_p)     ((*_p).src_info)
#define egg_SubMessage_srcinfo(_p)      ((*_p).src_info)
#define egg_SubMessage_loc(_p)  ((*_p).src_info->loc)
#define egg_SubMessage_kind(_p) ((*_p).kind)
#define egg_SubMessage_msg(_p)  ((*_p).msg)

extern egg_SubMessage Create_egg_SubMessage	(SrcInfo src_info, egg_MessageKind kind, String msg);

#endif /* DEF_STRUCT_egg_SubMessage */

#ifndef DEF_STRUCT_egg_Scope
#define DEF_STRUCT_egg_Scope

struct s_egg_Scope {
  egg_Scope     next;  
  Int   _self;  
  Int   _end;  
  egg_Scope_tag tag;  
  union {
  struct s_egg_GroupScope {
    egg_Statement       data;  
  } egg_GroupScope;
} sub;
} ;

#define egg_Scope_next(_p)      ((*_p).next)
#define egg_Scope__self(_p)     ((*_p)._self)
#define egg_Scope__end(_p)      ((*_p)._end)
#define egg_Scope_tag(_p)       ((*_p).tag)
#define egg_GroupScope_data(_p) ((*_p).sub.egg_GroupScope.data)

extern egg_GroupScope Create_egg_GroupScope	(egg_Scope next, egg_Statement data);

#endif /* DEF_STRUCT_egg_Scope */

#ifndef DEF_STRUCT_List_egg_Declaration
#define DEF_STRUCT_List_egg_Declaration

struct s_List_egg_Declaration {
  egg_Declaration       data;  
  List_egg_Declaration  next;  
} ;

#define List_egg_Declaration_data(_p)   ((*_p).data)
#define List_egg_Declaration_next(_p)   ((*_p).next)

#ifndef Create_List_egg_Declaration
#define Create_List_egg_Declaration(x,y) (List_egg_Declaration)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_egg_Declaration_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_egg_Declaration */

#ifndef DEF_STRUCT_List_egg_SubMessage
#define DEF_STRUCT_List_egg_SubMessage

struct s_List_egg_SubMessage {
  egg_SubMessage        data;  
  List_egg_SubMessage   next;  
} ;

#define List_egg_SubMessage_data(_p)    ((*_p).data)
#define List_egg_SubMessage_next(_p)    ((*_p).next)

#ifndef Create_List_egg_SubMessage
#define Create_List_egg_SubMessage(x,y) (List_egg_SubMessage)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_egg_SubMessage_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_egg_SubMessage */

#ifndef DEF_STRUCT_List_egg_Expression
#define DEF_STRUCT_List_egg_Expression

struct s_List_egg_Expression {
  egg_Expression        data;  
  List_egg_Expression   next;  
} ;

#define List_egg_Expression_data(_p)    ((*_p).data)
#define List_egg_Expression_next(_p)    ((*_p).next)

#ifndef Create_List_egg_Expression
#define Create_List_egg_Expression(x,y) (List_egg_Expression)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_egg_Expression_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_egg_Expression */

#ifndef DEF_STRUCT_List_egg_Statement
#define DEF_STRUCT_List_egg_Statement

struct s_List_egg_Statement {
  egg_Statement data;  
  List_egg_Statement    next;  
} ;

#define List_egg_Statement_data(_p)     ((*_p).data)
#define List_egg_Statement_next(_p)     ((*_p).next)

#ifndef Create_List_egg_Statement
#define Create_List_egg_Statement(x,y) (List_egg_Statement)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_egg_Statement_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_egg_Statement */

#define PRE_ACTION  1
#define POST_ACTION 0

typedef struct s_egg_TraverseTable {
  Front_Traversal traversal;
  Pointer (*action_egg[2]) (egg_egg, Pointer);
  Bool skip_children_egg;
  Pointer (*action_Uses[2]) (egg_Uses, Pointer);
  Bool skip_children_Uses;
  Pointer (*action_Declaration[2]) (egg_Declaration, Pointer);
  Bool skip_children_Declaration;
  Pointer (*action_Expression[2]) (egg_Expression, Pointer);
  Bool skip_children_Expression;
  Pointer (*action_StringExpr[2]) (egg_StringExpr, Pointer);
  Bool skip_children_StringExpr;
  Pointer (*action_CallExpr[2]) (egg_CallExpr, Pointer);
  Bool skip_children_CallExpr;
  Pointer (*action_IdExpr[2]) (egg_IdExpr, Pointer);
  Bool skip_children_IdExpr;
  Pointer (*action_Statement[2]) (egg_Statement, Pointer);
  Bool skip_children_Statement;
  Pointer (*action_Message[2]) (egg_Message, Pointer);
  Bool skip_children_Message;
  Pointer (*action_Group[2]) (egg_Group, Pointer);
  Bool skip_children_Group;
  Pointer (*action_SubMessage[2]) (egg_SubMessage, Pointer);
  Bool skip_children_SubMessage;
  Pointer (*action_Scope[2]) (egg_Scope, Pointer);
  Bool skip_children_Scope;
  Pointer (*action_GroupScope[2]) (egg_GroupScope, Pointer);
  Bool skip_children_GroupScope;
  Pointer (*action_List_Declaration[2]) (List_egg_Declaration, Pointer);
  Bool skip_children_List_Declaration;
  Pointer (*action_List_SubMessage[2]) (List_egg_SubMessage, Pointer);
  Bool skip_children_List_SubMessage;
  Pointer (*action_List_Expression[2]) (List_egg_Expression, Pointer);
  Bool skip_children_List_Expression;
  Pointer (*action_List_Statement[2]) (List_egg_Statement, Pointer);
  Bool skip_children_List_Statement;
  Pointer (*action_MessageKind[2]) (egg_MessageKind, Pointer);
  Bool skip_children_MessageKind;
  Pointer (*action_ErrorMsg[2]) (egg_MessageKind, Pointer);
  Bool skip_children_ErrorMsg;
  Pointer (*action_WarningMsg[2]) (egg_MessageKind, Pointer);
  Bool skip_children_WarningMsg;
  Pointer (*action_DisabledMsg[2]) (egg_MessageKind, Pointer);
  Bool skip_children_DisabledMsg;
  Pointer (*action_KeyMsg[2]) (egg_MessageKind, Pointer);
  Bool skip_children_KeyMsg;
  Pointer (*action_PostMsg[2]) (egg_MessageKind, Pointer);
  Bool skip_children_PostMsg;
} *egg_TraverseTable;

extern Pointer Traverse_egg_MessageKind (egg_MessageKind me, egg_TraverseTable table, Pointer val);
extern Pointer Traverse_egg_egg (egg_egg me, egg_TraverseTable table, Pointer val);
extern Pointer Traverse_egg_Uses (egg_Uses me, egg_TraverseTable table, Pointer val);
extern Pointer Traverse_egg_Declaration (egg_Declaration me, egg_TraverseTable table, Pointer val);
extern Pointer Traverse_egg_Expression (egg_Expression me, egg_TraverseTable table, Pointer val);
extern Pointer Traverse_egg_Statement (egg_Statement me, egg_TraverseTable table, Pointer val);
extern Pointer Traverse_egg_SubMessage (egg_SubMessage me, egg_TraverseTable table, Pointer val);
extern Pointer Traverse_egg_Scope (egg_Scope me, egg_TraverseTable table, Pointer val);
extern Pointer Traverse_List_egg_Declaration (List_egg_Declaration me, egg_TraverseTable table, Pointer val);
extern Pointer Traverse_List_egg_SubMessage (List_egg_SubMessage me, egg_TraverseTable table, Pointer val);
extern Pointer Traverse_List_egg_Expression (List_egg_Expression me, egg_TraverseTable table, Pointer val);
extern Pointer Traverse_List_egg_Statement (List_egg_Statement me, egg_TraverseTable table, Pointer val);

typedef struct s_void_egg_TraverseTable {
  void (*action_egg[2]) (egg_egg);
  Bool skip_children_egg;
  void (*action_Uses[2]) (egg_Uses);
  Bool skip_children_Uses;
  void (*action_Declaration[2]) (egg_Declaration);
  Bool skip_children_Declaration;
  void (*action_Expression[2]) (egg_Expression);
  Bool skip_children_Expression;
  void (*action_StringExpr[2]) (egg_StringExpr);
  Bool skip_children_StringExpr;
  void (*action_CallExpr[2]) (egg_CallExpr);
  Bool skip_children_CallExpr;
  void (*action_IdExpr[2]) (egg_IdExpr);
  Bool skip_children_IdExpr;
  void (*action_Statement[2]) (egg_Statement);
  Bool skip_children_Statement;
  void (*action_Message[2]) (egg_Message);
  Bool skip_children_Message;
  void (*action_Group[2]) (egg_Group);
  Bool skip_children_Group;
  void (*action_SubMessage[2]) (egg_SubMessage);
  Bool skip_children_SubMessage;
  void (*action_Scope[2]) (egg_Scope);
  Bool skip_children_Scope;
  void (*action_GroupScope[2]) (egg_GroupScope);
  Bool skip_children_GroupScope;
  void (*action_List_Declaration[2]) (List_egg_Declaration);
  Bool skip_children_List_Declaration;
  void (*action_List_SubMessage[2]) (List_egg_SubMessage);
  Bool skip_children_List_SubMessage;
  void (*action_List_Expression[2]) (List_egg_Expression);
  Bool skip_children_List_Expression;
  void (*action_List_Statement[2]) (List_egg_Statement);
  Bool skip_children_List_Statement;
  void (*action_MessageKind[2]) (egg_MessageKind);
  Bool skip_children_MessageKind;
  void (*action_ErrorMsg[2]) (egg_MessageKind);
  Bool skip_children_ErrorMsg;
  void (*action_WarningMsg[2]) (egg_MessageKind);
  Bool skip_children_WarningMsg;
  void (*action_DisabledMsg[2]) (egg_MessageKind);
  Bool skip_children_DisabledMsg;
  void (*action_KeyMsg[2]) (egg_MessageKind);
  Bool skip_children_KeyMsg;
  void (*action_PostMsg[2]) (egg_MessageKind);
  Bool skip_children_PostMsg;
} *void_egg_TraverseTable;

extern void Traverse_void_egg_MessageKind (egg_MessageKind me, void_egg_TraverseTable table);
extern void Traverse_void_egg_egg (egg_egg me, void_egg_TraverseTable table);
extern void Traverse_void_egg_Uses (egg_Uses me, void_egg_TraverseTable table);
extern void Traverse_void_egg_Declaration (egg_Declaration me, void_egg_TraverseTable table);
extern void Traverse_void_egg_Expression (egg_Expression me, void_egg_TraverseTable table);
extern void Traverse_void_egg_Statement (egg_Statement me, void_egg_TraverseTable table);
extern void Traverse_void_egg_SubMessage (egg_SubMessage me, void_egg_TraverseTable table);
extern void Traverse_void_egg_Scope (egg_Scope me, void_egg_TraverseTable table);
extern void Traverse_void_List_egg_Declaration (List_egg_Declaration me, void_egg_TraverseTable table);
extern void Traverse_void_List_egg_SubMessage (List_egg_SubMessage me, void_egg_TraverseTable table);
extern void Traverse_void_List_egg_Expression (List_egg_Expression me, void_egg_TraverseTable table);
extern void Traverse_void_List_egg_Statement (List_egg_Statement me, void_egg_TraverseTable table);

typedef struct s_copy_egg_TraverseTable {
  Front_ClearBackEdges clear_back_edges;
  egg_egg (*action_egg[2]) (egg_egg, egg_egg);
  Bool skip_children_egg;
  egg_Uses (*action_Uses[2]) (egg_Uses, egg_Uses);
  Bool skip_children_Uses;
  egg_Declaration (*action_Declaration[2]) (egg_Declaration, egg_Declaration);
  Bool skip_children_Declaration;
  egg_Expression (*action_Expression[2]) (egg_Expression, egg_Expression);
  Bool skip_children_Expression;
  egg_StringExpr (*action_StringExpr[2]) (egg_StringExpr, egg_StringExpr);
  Bool skip_children_StringExpr;
  egg_CallExpr (*action_CallExpr[2]) (egg_CallExpr, egg_CallExpr);
  Bool skip_children_CallExpr;
  egg_IdExpr (*action_IdExpr[2]) (egg_IdExpr, egg_IdExpr);
  Bool skip_children_IdExpr;
  egg_Statement (*action_Statement[2]) (egg_Statement, egg_Statement);
  Bool skip_children_Statement;
  egg_Message (*action_Message[2]) (egg_Message, egg_Message);
  Bool skip_children_Message;
  egg_Group (*action_Group[2]) (egg_Group, egg_Group);
  Bool skip_children_Group;
  egg_SubMessage (*action_SubMessage[2]) (egg_SubMessage, egg_SubMessage);
  Bool skip_children_SubMessage;
  egg_Scope (*action_Scope[2]) (egg_Scope, egg_Scope);
  Bool skip_children_Scope;
  egg_GroupScope (*action_GroupScope[2]) (egg_GroupScope, egg_GroupScope);
  Bool skip_children_GroupScope;
  List_egg_Declaration (*action_List_Declaration[2]) (List_egg_Declaration, List_egg_Declaration);
  Bool skip_children_List_Declaration;
  List_egg_SubMessage (*action_List_SubMessage[2]) (List_egg_SubMessage, List_egg_SubMessage);
  Bool skip_children_List_SubMessage;
  List_egg_Expression (*action_List_Expression[2]) (List_egg_Expression, List_egg_Expression);
  Bool skip_children_List_Expression;
  List_egg_Statement (*action_List_Statement[2]) (List_egg_Statement, List_egg_Statement);
  Bool skip_children_List_Statement;
  egg_MessageKind (*action_MessageKind[2]) (egg_MessageKind, egg_MessageKind);
  Bool skip_children_MessageKind;
  egg_MessageKind (*action_ErrorMsg[2]) (egg_MessageKind, egg_MessageKind);
  Bool skip_children_ErrorMsg;
  egg_MessageKind (*action_WarningMsg[2]) (egg_MessageKind, egg_MessageKind);
  Bool skip_children_WarningMsg;
  egg_MessageKind (*action_DisabledMsg[2]) (egg_MessageKind, egg_MessageKind);
  Bool skip_children_DisabledMsg;
  egg_MessageKind (*action_KeyMsg[2]) (egg_MessageKind, egg_MessageKind);
  Bool skip_children_KeyMsg;
  egg_MessageKind (*action_PostMsg[2]) (egg_MessageKind, egg_MessageKind);
  Bool skip_children_PostMsg;
} *copy_egg_TraverseTable;

extern egg_MessageKind Traverse_copy_egg_MessageKind (egg_MessageKind me, copy_egg_TraverseTable table);
#ifndef COPY_egg_MessageKind
#define COPY_egg_MessageKind(x) Traverse_copy_egg_MessageKind(x, &egg_copy_actions)
#endif
extern egg_egg Traverse_copy_egg_egg (egg_egg me, copy_egg_TraverseTable table);
#ifndef COPY_egg_egg
#define COPY_egg_egg(x) Traverse_copy_egg_egg(x, &egg_copy_actions)
#endif
extern egg_Uses Traverse_copy_egg_Uses (egg_Uses me, copy_egg_TraverseTable table);
#ifndef COPY_egg_Uses
#define COPY_egg_Uses(x) Traverse_copy_egg_Uses(x, &egg_copy_actions)
#endif
extern egg_Declaration Traverse_copy_egg_Declaration (egg_Declaration me, copy_egg_TraverseTable table);
#ifndef COPY_egg_Declaration
#define COPY_egg_Declaration(x) Traverse_copy_egg_Declaration(x, &egg_copy_actions)
#endif
extern egg_Expression Traverse_copy_egg_Expression (egg_Expression me, copy_egg_TraverseTable table);
#ifndef COPY_egg_Expression
#define COPY_egg_Expression(x) Traverse_copy_egg_Expression(x, &egg_copy_actions)
#endif
extern egg_Statement Traverse_copy_egg_Statement (egg_Statement me, copy_egg_TraverseTable table);
#ifndef COPY_egg_Statement
#define COPY_egg_Statement(x) Traverse_copy_egg_Statement(x, &egg_copy_actions)
#endif
extern egg_SubMessage Traverse_copy_egg_SubMessage (egg_SubMessage me, copy_egg_TraverseTable table);
#ifndef COPY_egg_SubMessage
#define COPY_egg_SubMessage(x) Traverse_copy_egg_SubMessage(x, &egg_copy_actions)
#endif
extern egg_Scope Traverse_copy_egg_Scope (egg_Scope me, copy_egg_TraverseTable table);
#ifndef COPY_egg_Scope
#define COPY_egg_Scope(x) Traverse_copy_egg_Scope(x, &egg_copy_actions)
#endif
extern List_egg_Declaration Traverse_copy_List_egg_Declaration (List_egg_Declaration me, copy_egg_TraverseTable table);
#ifndef COPY_egg_List_Declaration
#define COPY_egg_List_Declaration(x) Traverse_copy_List_egg_Declaration(x, &egg_copy_actions)
#endif
extern List_egg_SubMessage Traverse_copy_List_egg_SubMessage (List_egg_SubMessage me, copy_egg_TraverseTable table);
#ifndef COPY_egg_List_SubMessage
#define COPY_egg_List_SubMessage(x) Traverse_copy_List_egg_SubMessage(x, &egg_copy_actions)
#endif
extern List_egg_Expression Traverse_copy_List_egg_Expression (List_egg_Expression me, copy_egg_TraverseTable table);
#ifndef COPY_egg_List_Expression
#define COPY_egg_List_Expression(x) Traverse_copy_List_egg_Expression(x, &egg_copy_actions)
#endif
extern List_egg_Statement Traverse_copy_List_egg_Statement (List_egg_Statement me, copy_egg_TraverseTable table);
#ifndef COPY_egg_List_Statement
#define COPY_egg_List_Statement(x) Traverse_copy_List_egg_Statement(x, &egg_copy_actions)
#endif

typedef struct s_compare_egg_TraverseTable {
  int (*action_egg[2]) (egg_egg, egg_egg);
  Bool skip_children_egg;
  int (*action_Uses[2]) (egg_Uses, egg_Uses);
  Bool skip_children_Uses;
  int (*action_Declaration[2]) (egg_Declaration, egg_Declaration);
  Bool skip_children_Declaration;
  int (*action_Expression[2]) (egg_Expression, egg_Expression);
  Bool skip_children_Expression;
  int (*action_StringExpr[2]) (egg_StringExpr, egg_StringExpr);
  Bool skip_children_StringExpr;
  int (*action_CallExpr[2]) (egg_CallExpr, egg_CallExpr);
  Bool skip_children_CallExpr;
  int (*action_IdExpr[2]) (egg_IdExpr, egg_IdExpr);
  Bool skip_children_IdExpr;
  int (*action_Statement[2]) (egg_Statement, egg_Statement);
  Bool skip_children_Statement;
  int (*action_Message[2]) (egg_Message, egg_Message);
  Bool skip_children_Message;
  int (*action_Group[2]) (egg_Group, egg_Group);
  Bool skip_children_Group;
  int (*action_SubMessage[2]) (egg_SubMessage, egg_SubMessage);
  Bool skip_children_SubMessage;
  int (*action_Scope[2]) (egg_Scope, egg_Scope);
  Bool skip_children_Scope;
  int (*action_GroupScope[2]) (egg_GroupScope, egg_GroupScope);
  Bool skip_children_GroupScope;
  int (*action_List_Declaration[2]) (List_egg_Declaration, List_egg_Declaration);
  Bool skip_children_List_Declaration;
  int (*action_List_SubMessage[2]) (List_egg_SubMessage, List_egg_SubMessage);
  Bool skip_children_List_SubMessage;
  int (*action_List_Expression[2]) (List_egg_Expression, List_egg_Expression);
  Bool skip_children_List_Expression;
  int (*action_List_Statement[2]) (List_egg_Statement, List_egg_Statement);
  Bool skip_children_List_Statement;
  int (*action_MessageKind[2]) (egg_MessageKind, egg_MessageKind);
  Bool skip_children_MessageKind;
  int (*action_ErrorMsg[2]) (egg_MessageKind, egg_MessageKind);
  Bool skip_children_ErrorMsg;
  int (*action_WarningMsg[2]) (egg_MessageKind, egg_MessageKind);
  Bool skip_children_WarningMsg;
  int (*action_DisabledMsg[2]) (egg_MessageKind, egg_MessageKind);
  Bool skip_children_DisabledMsg;
  int (*action_KeyMsg[2]) (egg_MessageKind, egg_MessageKind);
  Bool skip_children_KeyMsg;
  int (*action_PostMsg[2]) (egg_MessageKind, egg_MessageKind);
  Bool skip_children_PostMsg;
} *compare_egg_TraverseTable;

extern int Traverse_compare_egg_MessageKind (egg_MessageKind x, egg_MessageKind y, compare_egg_TraverseTable table);
extern int Traverse_compare_egg_egg (egg_egg x, egg_egg y, compare_egg_TraverseTable table);
extern int Traverse_compare_egg_Uses (egg_Uses x, egg_Uses y, compare_egg_TraverseTable table);
extern int Traverse_compare_egg_Declaration (egg_Declaration x, egg_Declaration y, compare_egg_TraverseTable table);
extern int Traverse_compare_egg_Expression (egg_Expression x, egg_Expression y, compare_egg_TraverseTable table);
extern int Traverse_compare_egg_Statement (egg_Statement x, egg_Statement y, compare_egg_TraverseTable table);
extern int Traverse_compare_egg_SubMessage (egg_SubMessage x, egg_SubMessage y, compare_egg_TraverseTable table);
extern int Traverse_compare_egg_Scope (egg_Scope x, egg_Scope y, compare_egg_TraverseTable table);
extern int Traverse_compare_List_egg_Declaration (List_egg_Declaration x, List_egg_Declaration y, compare_egg_TraverseTable table);
extern int Traverse_compare_List_egg_SubMessage (List_egg_SubMessage x, List_egg_SubMessage y, compare_egg_TraverseTable table);
extern int Traverse_compare_List_egg_Expression (List_egg_Expression x, List_egg_Expression y, compare_egg_TraverseTable table);
extern int Traverse_compare_List_egg_Statement (List_egg_Statement x, List_egg_Statement y, compare_egg_TraverseTable table);


extern void egg_fill_table (egg_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void void_egg_fill_table (void_egg_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void copy_egg_fill_table (copy_egg_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void compare_egg_fill_table (compare_egg_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern struct s_egg_TraverseTable egg_scope_actions;

extern struct s_void_egg_TraverseTable egg_defining_actions;

extern struct s_void_egg_TraverseTable egg_applied_actions;

extern struct s_void_egg_TraverseTable egg_check_actions;

extern struct s_void_egg_TraverseTable egg_print_actions;

extern struct s_copy_egg_TraverseTable egg_copy_actions;

extern struct s_compare_egg_TraverseTable egg_compare_actions;

typedef int egg_NameSpaces;

extern egg_NameSpaces egg_namespaces[1];

#define egg_DefaultNameSpace egg_namespaces[0]

#define egg_NUM_NAMESPACES 1

extern void Decorate_egg (egg_egg r);

#endif /* _egg */
