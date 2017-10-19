#ifndef _grammar
#define _grammar

#include <stdarg.h>
#include <stddef.h>
#include <front/basic_types.h>

typedef enum {
  grammar_ChoiceRE_kind,
  grammar_SeqRE_kind,
  grammar_OptRE_kind,
  grammar_PlusRE_kind,
  grammar_TimesRE_kind,
  grammar_StringRE_kind,
  grammar_SOLRE_kind,
  grammar_EOLRE_kind,
  grammar_IdRE_kind,
  grammar_ParRE_kind,
  grammar_AnyRE_kind
} grammar_RegExpr_tag;
extern char *grammar_RegExpr_tag_names[];
#define NUM_grammar_RegExpr_tag 11

typedef enum {
  grammar_NT_Rule_kind,
  grammar_Import_Rule_kind,
  grammar_Extra_Rule_kind
} grammar_ProdRule_tag;
extern char *grammar_ProdRule_tag_names[];
#define NUM_grammar_ProdRule_tag 3

#ifndef DEF_TYPE_grammar_grammar
#define DEF_TYPE_grammar_grammar
typedef struct s_grammar_grammar        *grammar_grammar;
#endif

#ifndef DEF_TYPE_grammar_Scanner
#define DEF_TYPE_grammar_Scanner
typedef struct s_grammar_Scanner        *grammar_Scanner;
#endif

#ifndef DEF_TYPE_grammar_Token
#define DEF_TYPE_grammar_Token
typedef struct s_grammar_Token  *grammar_Token;
#endif

#ifndef DEF_TYPE_grammar_RegExpr
#define DEF_TYPE_grammar_RegExpr
typedef struct s_grammar_RegExpr        *grammar_RegExpr;
typedef grammar_RegExpr grammar_AnyRE;
typedef grammar_RegExpr grammar_ParRE;
typedef grammar_RegExpr grammar_IdRE;
typedef grammar_RegExpr grammar_EOLRE;
typedef grammar_RegExpr grammar_SOLRE;
typedef grammar_RegExpr grammar_StringRE;
typedef grammar_RegExpr grammar_BasicRE;
typedef grammar_RegExpr grammar_TimesRE;
typedef grammar_RegExpr grammar_PlusRE;
typedef grammar_RegExpr grammar_OptRE;
typedef grammar_RegExpr grammar_PostRE;
typedef grammar_RegExpr grammar_SeqRE;
typedef grammar_RegExpr grammar_ChoiceRE;
#endif

#ifndef DEF_TYPE_grammar_Parser
#define DEF_TYPE_grammar_Parser
typedef struct s_grammar_Parser *grammar_Parser;
#endif

#ifndef DEF_TYPE_grammar_ProdRule
#define DEF_TYPE_grammar_ProdRule
typedef struct s_grammar_ProdRule       *grammar_ProdRule;
typedef grammar_ProdRule grammar_Extra_Rule;
typedef grammar_ProdRule grammar_Import_Rule;
typedef grammar_ProdRule grammar_NT_Rule;
#endif

#ifndef DEF_TYPE_grammar_Scope
#define DEF_TYPE_grammar_Scope
typedef struct s_grammar_Scope  *grammar_Scope;
#endif

#ifndef DEF_TYPE_List_grammar_ProdRule
#define DEF_TYPE_List_grammar_ProdRule
typedef struct s_List_grammar_ProdRule  *List_grammar_ProdRule;
#endif

#ifndef DEF_TYPE_List_grammar_Token
#define DEF_TYPE_List_grammar_Token
typedef struct s_List_grammar_Token     *List_grammar_Token;
#endif

#include <front/scan_support.h>
#include <front/print_support.h>
#include <front/SymTab.h>
#include "grammar_parse.h"
#include "grammar_defs.h"

#include "front.h"
#include "Types.h"
extern grammar_grammar grammar_root;

#ifndef DEF_STRUCT_grammar_grammar
#define DEF_STRUCT_grammar_grammar

struct s_grammar_grammar {
  SrcInfo       src_info;  
  grammar_Scanner       scanner;  
  grammar_Parser        parser;  
} ;

#define grammar_grammar_src_info(_p)    ((*_p).src_info)
#define grammar_grammar_srcinfo(_p)     ((*_p).src_info)
#define grammar_grammar_loc(_p) ((*_p).src_info->loc)
#define grammar_grammar_scanner(_p)     ((*_p).scanner)
#define grammar_grammar_parser(_p)      ((*_p).parser)

extern grammar_grammar Create_grammar_grammar	(SrcInfo src_info, grammar_Scanner scanner, grammar_Parser parser);

#endif /* DEF_STRUCT_grammar_grammar */

#ifndef DEF_STRUCT_grammar_Scanner
#define DEF_STRUCT_grammar_Scanner

struct s_grammar_Scanner {
  SrcInfo       src_info;  
  List_grammar_Token    tokens;  
} ;

#define grammar_Scanner_src_info(_p)    ((*_p).src_info)
#define grammar_Scanner_srcinfo(_p)     ((*_p).src_info)
#define grammar_Scanner_loc(_p) ((*_p).src_info->loc)
#define grammar_Scanner_tokens(_p)      ((*_p).tokens)

extern grammar_Scanner Create_grammar_Scanner	(SrcInfo src_info, List_grammar_Token tokens);

#endif /* DEF_STRUCT_grammar_Scanner */

#ifndef DEF_STRUCT_grammar_Token
#define DEF_STRUCT_grammar_Token

struct s_grammar_Token {
  SrcInfo       src_info;  
  grammar_RegExpr       re;  
  List_String   actions;  
  Ident id;  
  Ident type;  
} ;

#define grammar_Token_src_info(_p)      ((*_p).src_info)
#define grammar_Token_srcinfo(_p)       ((*_p).src_info)
#define grammar_Token_loc(_p)   ((*_p).src_info->loc)
#define grammar_Token_re(_p)    ((*_p).re)
#define grammar_Token_actions(_p)       ((*_p).actions)
#define grammar_Token_id(_p)    ((*_p).id)
#define grammar_Token_type(_p)  ((*_p).type)

extern grammar_Token Create_grammar_Token	(SrcInfo src_info, grammar_RegExpr re, List_String actions);

#endif /* DEF_STRUCT_grammar_Token */

#ifndef DEF_STRUCT_grammar_RegExpr
#define DEF_STRUCT_grammar_RegExpr

struct s_grammar_RegExpr {
  SrcInfo       src_info;  
  grammar_RegExpr_tag   tag;  
  union {
  struct s_grammar_ChoiceRE {
    grammar_RegExpr     head;  
    grammar_RegExpr     tail;  
  } grammar_ChoiceRE;
  struct s_grammar_SeqRE {
    grammar_RegExpr     head;  
    grammar_RegExpr     tail;  
  } grammar_SeqRE;
  struct s_grammar_PostRE {
    grammar_RegExpr     re;  
  } grammar_PostRE;
  struct s_grammar_BasicRE {
    union {
    struct s_grammar_StringRE {
      String    s;  
    } grammar_StringRE;
    struct s_grammar_SOLRE {
    } grammar_SOLRE;
    struct s_grammar_EOLRE {
    } grammar_EOLRE;
    struct s_grammar_IdRE {
      Ident     id;  
    } grammar_IdRE;
    struct s_grammar_ParRE {
      grammar_RegExpr   re;  
    } grammar_ParRE;
    struct s_grammar_AnyRE {
    } grammar_AnyRE;
  } sub;
  } grammar_BasicRE;
} sub;
} ;

#define grammar_RegExpr_src_info(_p)    ((*_p).src_info)
#define grammar_RegExpr_srcinfo(_p)     ((*_p).src_info)
#define grammar_RegExpr_loc(_p) ((*_p).src_info->loc)
#define grammar_RegExpr_tag(_p) ((*_p).tag)
#define grammar_ChoiceRE_head(_p)       ((*_p).sub.grammar_ChoiceRE.head)
#define grammar_ChoiceRE_tail(_p)       ((*_p).sub.grammar_ChoiceRE.tail)
#define grammar_SeqRE_head(_p)  ((*_p).sub.grammar_SeqRE.head)
#define grammar_SeqRE_tail(_p)  ((*_p).sub.grammar_SeqRE.tail)
#define grammar_PostRE_re(_p)   ((*_p).sub.grammar_PostRE.re)
#define grammar_StringRE_s(_p)  ((*_p).sub.grammar_BasicRE.sub.grammar_StringRE.s)
#define grammar_IdRE_id(_p)     ((*_p).sub.grammar_BasicRE.sub.grammar_IdRE.id)
#define grammar_ParRE_re(_p)    ((*_p).sub.grammar_BasicRE.sub.grammar_ParRE.re)

extern grammar_AnyRE Create_grammar_AnyRE	(SrcInfo src_info);
extern grammar_ParRE Create_grammar_ParRE	(SrcInfo src_info, grammar_RegExpr re);
extern grammar_IdRE Create_grammar_IdRE	(SrcInfo src_info, Ident id);
extern grammar_EOLRE Create_grammar_EOLRE	(SrcInfo src_info);
extern grammar_SOLRE Create_grammar_SOLRE	(SrcInfo src_info);
extern grammar_StringRE Create_grammar_StringRE	(SrcInfo src_info, String s);
extern grammar_TimesRE Create_grammar_TimesRE	(SrcInfo src_info, grammar_RegExpr re);
extern grammar_PlusRE Create_grammar_PlusRE	(SrcInfo src_info, grammar_RegExpr re);
extern grammar_OptRE Create_grammar_OptRE	(SrcInfo src_info, grammar_RegExpr re);
extern grammar_SeqRE Create_grammar_SeqRE	(SrcInfo src_info, grammar_RegExpr head, grammar_RegExpr tail);
extern grammar_ChoiceRE Create_grammar_ChoiceRE	(SrcInfo src_info, grammar_RegExpr head, grammar_RegExpr tail);

#endif /* DEF_STRUCT_grammar_RegExpr */

#ifndef DEF_STRUCT_grammar_Parser
#define DEF_STRUCT_grammar_Parser

struct s_grammar_Parser {
  SrcInfo       src_info;  
  List_grammar_ProdRule rules;  
} ;

#define grammar_Parser_src_info(_p)     ((*_p).src_info)
#define grammar_Parser_srcinfo(_p)      ((*_p).src_info)
#define grammar_Parser_loc(_p)  ((*_p).src_info->loc)
#define grammar_Parser_rules(_p)        ((*_p).rules)

extern grammar_Parser Create_grammar_Parser	(SrcInfo src_info, List_grammar_ProdRule rules);

#endif /* DEF_STRUCT_grammar_Parser */

#ifndef DEF_STRUCT_grammar_ProdRule
#define DEF_STRUCT_grammar_ProdRule

struct s_grammar_ProdRule {
  SrcInfo       src_info;  
  grammar_ProdRule_tag  tag;  
  Ident lhs;  
  List_field    fields;  
  union {
  struct s_grammar_NT_Rule {
    NonTerminal nt;  
    Alternative alt;  
    List_Symbol rhs;  
    List_Field  fields;  
  } grammar_NT_Rule;
  struct s_grammar_Import_Rule {
    Ident       type;  
    Ident       grammar;  
    ImportedNonTerminal imp;  
  } grammar_Import_Rule;
  struct s_grammar_Extra_Rule {
    Symbol      sym;  
  } grammar_Extra_Rule;
} sub;
} ;

#define grammar_ProdRule_src_info(_p)   ((*_p).src_info)
#define grammar_ProdRule_srcinfo(_p)    ((*_p).src_info)
#define grammar_ProdRule_loc(_p)        ((*_p).src_info->loc)
#define grammar_ProdRule_tag(_p)        ((*_p).tag)
#define grammar_ProdRule_lhs(_p)        ((*_p).lhs)
#define grammar_ProdRule_fields(_p)     ((*_p).fields)
#define grammar_NT_Rule_nt(_p)  ((*_p).sub.grammar_NT_Rule.nt)
#define grammar_NT_Rule_alt(_p) ((*_p).sub.grammar_NT_Rule.alt)
#define grammar_NT_Rule_rhs(_p) ((*_p).sub.grammar_NT_Rule.rhs)
#define grammar_NT_Rule_fields(_p)      ((*_p).sub.grammar_NT_Rule.fields)
#define grammar_Import_Rule_type(_p)    ((*_p).sub.grammar_Import_Rule.type)
#define grammar_Import_Rule_grammar(_p) ((*_p).sub.grammar_Import_Rule.grammar)
#define grammar_Import_Rule_imp(_p)     ((*_p).sub.grammar_Import_Rule.imp)
#define grammar_Extra_Rule_sym(_p)      ((*_p).sub.grammar_Extra_Rule.sym)

extern grammar_Extra_Rule Create_grammar_Extra_Rule	(SrcInfo src_info, Ident lhs);
extern grammar_Import_Rule Create_grammar_Import_Rule	(SrcInfo src_info, Ident lhs);
extern grammar_NT_Rule Create_grammar_NT_Rule	(SrcInfo src_info, Ident lhs);

#endif /* DEF_STRUCT_grammar_ProdRule */

#ifndef DEF_STRUCT_grammar_Scope
#define DEF_STRUCT_grammar_Scope

struct s_grammar_Scope {
  grammar_Scope next;  
  Int   _self;  
  Int   _end;  
} ;

#define grammar_Scope_next(_p)  ((*_p).next)
#define grammar_Scope__self(_p) ((*_p)._self)
#define grammar_Scope__end(_p)  ((*_p)._end)

extern grammar_Scope Create_grammar_Scope	(grammar_Scope next);

#endif /* DEF_STRUCT_grammar_Scope */

#ifndef DEF_STRUCT_List_grammar_ProdRule
#define DEF_STRUCT_List_grammar_ProdRule

struct s_List_grammar_ProdRule {
  grammar_ProdRule      data;  
  List_grammar_ProdRule next;  
} ;

#define List_grammar_ProdRule_data(_p)  ((*_p).data)
#define List_grammar_ProdRule_next(_p)  ((*_p).next)

#ifndef Create_List_grammar_ProdRule
#define Create_List_grammar_ProdRule(x,y) (List_grammar_ProdRule)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_grammar_ProdRule_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_grammar_ProdRule */

#ifndef DEF_STRUCT_List_grammar_Token
#define DEF_STRUCT_List_grammar_Token

struct s_List_grammar_Token {
  grammar_Token data;  
  List_grammar_Token    next;  
} ;

#define List_grammar_Token_data(_p)     ((*_p).data)
#define List_grammar_Token_next(_p)     ((*_p).next)

#ifndef Create_List_grammar_Token
#define Create_List_grammar_Token(x,y) (List_grammar_Token)Create_Front_List((void*)(x),(Front_List)(y))
#endif

#define List_grammar_Token_size(l) List_size((Front_List)l)


#endif /* DEF_STRUCT_List_grammar_Token */

#define PRE_ACTION  1
#define POST_ACTION 0

typedef struct s_grammar_TraverseTable {
  Front_Traversal traversal;
  Pointer (*action_grammar[2]) (grammar_grammar, Pointer);
  Bool skip_children_grammar;
  Pointer (*action_Scanner[2]) (grammar_Scanner, Pointer);
  Bool skip_children_Scanner;
  Pointer (*action_Token[2]) (grammar_Token, Pointer);
  Bool skip_children_Token;
  Pointer (*action_RegExpr[2]) (grammar_RegExpr, Pointer);
  Bool skip_children_RegExpr;
  Pointer (*action_ChoiceRE[2]) (grammar_ChoiceRE, Pointer);
  Bool skip_children_ChoiceRE;
  Pointer (*action_SeqRE[2]) (grammar_SeqRE, Pointer);
  Bool skip_children_SeqRE;
  Pointer (*action_PostRE[2]) (grammar_PostRE, Pointer);
  Bool skip_children_PostRE;
  Pointer (*action_OptRE[2]) (grammar_OptRE, Pointer);
  Bool skip_children_OptRE;
  Pointer (*action_PlusRE[2]) (grammar_PlusRE, Pointer);
  Bool skip_children_PlusRE;
  Pointer (*action_TimesRE[2]) (grammar_TimesRE, Pointer);
  Bool skip_children_TimesRE;
  Pointer (*action_BasicRE[2]) (grammar_BasicRE, Pointer);
  Bool skip_children_BasicRE;
  Pointer (*action_StringRE[2]) (grammar_StringRE, Pointer);
  Bool skip_children_StringRE;
  Pointer (*action_SOLRE[2]) (grammar_SOLRE, Pointer);
  Bool skip_children_SOLRE;
  Pointer (*action_EOLRE[2]) (grammar_EOLRE, Pointer);
  Bool skip_children_EOLRE;
  Pointer (*action_IdRE[2]) (grammar_IdRE, Pointer);
  Bool skip_children_IdRE;
  Pointer (*action_ParRE[2]) (grammar_ParRE, Pointer);
  Bool skip_children_ParRE;
  Pointer (*action_AnyRE[2]) (grammar_AnyRE, Pointer);
  Bool skip_children_AnyRE;
  Pointer (*action_Parser[2]) (grammar_Parser, Pointer);
  Bool skip_children_Parser;
  Pointer (*action_ProdRule[2]) (grammar_ProdRule, Pointer);
  Bool skip_children_ProdRule;
  Pointer (*action_NT_Rule[2]) (grammar_NT_Rule, Pointer);
  Bool skip_children_NT_Rule;
  Pointer (*action_Import_Rule[2]) (grammar_Import_Rule, Pointer);
  Bool skip_children_Import_Rule;
  Pointer (*action_Extra_Rule[2]) (grammar_Extra_Rule, Pointer);
  Bool skip_children_Extra_Rule;
  Pointer (*action_Scope[2]) (grammar_Scope, Pointer);
  Bool skip_children_Scope;
  Pointer (*action_List_ProdRule[2]) (List_grammar_ProdRule, Pointer);
  Bool skip_children_List_ProdRule;
  Pointer (*action_List_Token[2]) (List_grammar_Token, Pointer);
  Bool skip_children_List_Token;
} *grammar_TraverseTable;

extern Pointer Traverse_grammar_grammar (grammar_grammar me, grammar_TraverseTable table, Pointer val);
extern Pointer Traverse_grammar_Scanner (grammar_Scanner me, grammar_TraverseTable table, Pointer val);
extern Pointer Traverse_grammar_Token (grammar_Token me, grammar_TraverseTable table, Pointer val);
extern Pointer Traverse_grammar_RegExpr (grammar_RegExpr me, grammar_TraverseTable table, Pointer val);
extern Pointer Traverse_grammar_Parser (grammar_Parser me, grammar_TraverseTable table, Pointer val);
extern Pointer Traverse_grammar_ProdRule (grammar_ProdRule me, grammar_TraverseTable table, Pointer val);
extern Pointer Traverse_grammar_Scope (grammar_Scope me, grammar_TraverseTable table, Pointer val);
extern Pointer Traverse_List_grammar_ProdRule (List_grammar_ProdRule me, grammar_TraverseTable table, Pointer val);
extern Pointer Traverse_List_grammar_Token (List_grammar_Token me, grammar_TraverseTable table, Pointer val);

typedef struct s_void_grammar_TraverseTable {
  void (*action_grammar[2]) (grammar_grammar);
  Bool skip_children_grammar;
  void (*action_Scanner[2]) (grammar_Scanner);
  Bool skip_children_Scanner;
  void (*action_Token[2]) (grammar_Token);
  Bool skip_children_Token;
  void (*action_RegExpr[2]) (grammar_RegExpr);
  Bool skip_children_RegExpr;
  void (*action_ChoiceRE[2]) (grammar_ChoiceRE);
  Bool skip_children_ChoiceRE;
  void (*action_SeqRE[2]) (grammar_SeqRE);
  Bool skip_children_SeqRE;
  void (*action_PostRE[2]) (grammar_PostRE);
  Bool skip_children_PostRE;
  void (*action_OptRE[2]) (grammar_OptRE);
  Bool skip_children_OptRE;
  void (*action_PlusRE[2]) (grammar_PlusRE);
  Bool skip_children_PlusRE;
  void (*action_TimesRE[2]) (grammar_TimesRE);
  Bool skip_children_TimesRE;
  void (*action_BasicRE[2]) (grammar_BasicRE);
  Bool skip_children_BasicRE;
  void (*action_StringRE[2]) (grammar_StringRE);
  Bool skip_children_StringRE;
  void (*action_SOLRE[2]) (grammar_SOLRE);
  Bool skip_children_SOLRE;
  void (*action_EOLRE[2]) (grammar_EOLRE);
  Bool skip_children_EOLRE;
  void (*action_IdRE[2]) (grammar_IdRE);
  Bool skip_children_IdRE;
  void (*action_ParRE[2]) (grammar_ParRE);
  Bool skip_children_ParRE;
  void (*action_AnyRE[2]) (grammar_AnyRE);
  Bool skip_children_AnyRE;
  void (*action_Parser[2]) (grammar_Parser);
  Bool skip_children_Parser;
  void (*action_ProdRule[2]) (grammar_ProdRule);
  Bool skip_children_ProdRule;
  void (*action_NT_Rule[2]) (grammar_NT_Rule);
  Bool skip_children_NT_Rule;
  void (*action_Import_Rule[2]) (grammar_Import_Rule);
  Bool skip_children_Import_Rule;
  void (*action_Extra_Rule[2]) (grammar_Extra_Rule);
  Bool skip_children_Extra_Rule;
  void (*action_Scope[2]) (grammar_Scope);
  Bool skip_children_Scope;
  void (*action_List_ProdRule[2]) (List_grammar_ProdRule);
  Bool skip_children_List_ProdRule;
  void (*action_List_Token[2]) (List_grammar_Token);
  Bool skip_children_List_Token;
} *void_grammar_TraverseTable;

extern void Traverse_void_grammar_grammar (grammar_grammar me, void_grammar_TraverseTable table);
extern void Traverse_void_grammar_Scanner (grammar_Scanner me, void_grammar_TraverseTable table);
extern void Traverse_void_grammar_Token (grammar_Token me, void_grammar_TraverseTable table);
extern void Traverse_void_grammar_RegExpr (grammar_RegExpr me, void_grammar_TraverseTable table);
extern void Traverse_void_grammar_Parser (grammar_Parser me, void_grammar_TraverseTable table);
extern void Traverse_void_grammar_ProdRule (grammar_ProdRule me, void_grammar_TraverseTable table);
extern void Traverse_void_grammar_Scope (grammar_Scope me, void_grammar_TraverseTable table);
extern void Traverse_void_List_grammar_ProdRule (List_grammar_ProdRule me, void_grammar_TraverseTable table);
extern void Traverse_void_List_grammar_Token (List_grammar_Token me, void_grammar_TraverseTable table);

typedef struct s_copy_grammar_TraverseTable {
  Front_ClearBackEdges clear_back_edges;
  grammar_grammar (*action_grammar[2]) (grammar_grammar, grammar_grammar);
  Bool skip_children_grammar;
  grammar_Scanner (*action_Scanner[2]) (grammar_Scanner, grammar_Scanner);
  Bool skip_children_Scanner;
  grammar_Token (*action_Token[2]) (grammar_Token, grammar_Token);
  Bool skip_children_Token;
  grammar_RegExpr (*action_RegExpr[2]) (grammar_RegExpr, grammar_RegExpr);
  Bool skip_children_RegExpr;
  grammar_ChoiceRE (*action_ChoiceRE[2]) (grammar_ChoiceRE, grammar_ChoiceRE);
  Bool skip_children_ChoiceRE;
  grammar_SeqRE (*action_SeqRE[2]) (grammar_SeqRE, grammar_SeqRE);
  Bool skip_children_SeqRE;
  grammar_PostRE (*action_PostRE[2]) (grammar_PostRE, grammar_PostRE);
  Bool skip_children_PostRE;
  grammar_OptRE (*action_OptRE[2]) (grammar_OptRE, grammar_OptRE);
  Bool skip_children_OptRE;
  grammar_PlusRE (*action_PlusRE[2]) (grammar_PlusRE, grammar_PlusRE);
  Bool skip_children_PlusRE;
  grammar_TimesRE (*action_TimesRE[2]) (grammar_TimesRE, grammar_TimesRE);
  Bool skip_children_TimesRE;
  grammar_BasicRE (*action_BasicRE[2]) (grammar_BasicRE, grammar_BasicRE);
  Bool skip_children_BasicRE;
  grammar_StringRE (*action_StringRE[2]) (grammar_StringRE, grammar_StringRE);
  Bool skip_children_StringRE;
  grammar_SOLRE (*action_SOLRE[2]) (grammar_SOLRE, grammar_SOLRE);
  Bool skip_children_SOLRE;
  grammar_EOLRE (*action_EOLRE[2]) (grammar_EOLRE, grammar_EOLRE);
  Bool skip_children_EOLRE;
  grammar_IdRE (*action_IdRE[2]) (grammar_IdRE, grammar_IdRE);
  Bool skip_children_IdRE;
  grammar_ParRE (*action_ParRE[2]) (grammar_ParRE, grammar_ParRE);
  Bool skip_children_ParRE;
  grammar_AnyRE (*action_AnyRE[2]) (grammar_AnyRE, grammar_AnyRE);
  Bool skip_children_AnyRE;
  grammar_Parser (*action_Parser[2]) (grammar_Parser, grammar_Parser);
  Bool skip_children_Parser;
  grammar_ProdRule (*action_ProdRule[2]) (grammar_ProdRule, grammar_ProdRule);
  Bool skip_children_ProdRule;
  grammar_NT_Rule (*action_NT_Rule[2]) (grammar_NT_Rule, grammar_NT_Rule);
  Bool skip_children_NT_Rule;
  grammar_Import_Rule (*action_Import_Rule[2]) (grammar_Import_Rule, grammar_Import_Rule);
  Bool skip_children_Import_Rule;
  grammar_Extra_Rule (*action_Extra_Rule[2]) (grammar_Extra_Rule, grammar_Extra_Rule);
  Bool skip_children_Extra_Rule;
  grammar_Scope (*action_Scope[2]) (grammar_Scope, grammar_Scope);
  Bool skip_children_Scope;
  List_grammar_ProdRule (*action_List_ProdRule[2]) (List_grammar_ProdRule, List_grammar_ProdRule);
  Bool skip_children_List_ProdRule;
  List_grammar_Token (*action_List_Token[2]) (List_grammar_Token, List_grammar_Token);
  Bool skip_children_List_Token;
} *copy_grammar_TraverseTable;

extern grammar_grammar Traverse_copy_grammar_grammar (grammar_grammar me, copy_grammar_TraverseTable table);
#ifndef COPY_grammar_grammar
#define COPY_grammar_grammar(x) Traverse_copy_grammar_grammar(x, &grammar_copy_actions)
#endif
extern grammar_Scanner Traverse_copy_grammar_Scanner (grammar_Scanner me, copy_grammar_TraverseTable table);
#ifndef COPY_grammar_Scanner
#define COPY_grammar_Scanner(x) Traverse_copy_grammar_Scanner(x, &grammar_copy_actions)
#endif
extern grammar_Token Traverse_copy_grammar_Token (grammar_Token me, copy_grammar_TraverseTable table);
#ifndef COPY_grammar_Token
#define COPY_grammar_Token(x) Traverse_copy_grammar_Token(x, &grammar_copy_actions)
#endif
extern grammar_RegExpr Traverse_copy_grammar_RegExpr (grammar_RegExpr me, copy_grammar_TraverseTable table);
#ifndef COPY_grammar_RegExpr
#define COPY_grammar_RegExpr(x) Traverse_copy_grammar_RegExpr(x, &grammar_copy_actions)
#endif
extern grammar_Parser Traverse_copy_grammar_Parser (grammar_Parser me, copy_grammar_TraverseTable table);
#ifndef COPY_grammar_Parser
#define COPY_grammar_Parser(x) Traverse_copy_grammar_Parser(x, &grammar_copy_actions)
#endif
extern grammar_ProdRule Traverse_copy_grammar_ProdRule (grammar_ProdRule me, copy_grammar_TraverseTable table);
#ifndef COPY_grammar_ProdRule
#define COPY_grammar_ProdRule(x) Traverse_copy_grammar_ProdRule(x, &grammar_copy_actions)
#endif
extern grammar_Scope Traverse_copy_grammar_Scope (grammar_Scope me, copy_grammar_TraverseTable table);
#ifndef COPY_grammar_Scope
#define COPY_grammar_Scope(x) Traverse_copy_grammar_Scope(x, &grammar_copy_actions)
#endif
extern List_grammar_ProdRule Traverse_copy_List_grammar_ProdRule (List_grammar_ProdRule me, copy_grammar_TraverseTable table);
#ifndef COPY_grammar_List_ProdRule
#define COPY_grammar_List_ProdRule(x) Traverse_copy_List_grammar_ProdRule(x, &grammar_copy_actions)
#endif
extern List_grammar_Token Traverse_copy_List_grammar_Token (List_grammar_Token me, copy_grammar_TraverseTable table);
#ifndef COPY_grammar_List_Token
#define COPY_grammar_List_Token(x) Traverse_copy_List_grammar_Token(x, &grammar_copy_actions)
#endif

typedef struct s_compare_grammar_TraverseTable {
  int (*action_grammar[2]) (grammar_grammar, grammar_grammar);
  Bool skip_children_grammar;
  int (*action_Scanner[2]) (grammar_Scanner, grammar_Scanner);
  Bool skip_children_Scanner;
  int (*action_Token[2]) (grammar_Token, grammar_Token);
  Bool skip_children_Token;
  int (*action_RegExpr[2]) (grammar_RegExpr, grammar_RegExpr);
  Bool skip_children_RegExpr;
  int (*action_ChoiceRE[2]) (grammar_ChoiceRE, grammar_ChoiceRE);
  Bool skip_children_ChoiceRE;
  int (*action_SeqRE[2]) (grammar_SeqRE, grammar_SeqRE);
  Bool skip_children_SeqRE;
  int (*action_PostRE[2]) (grammar_PostRE, grammar_PostRE);
  Bool skip_children_PostRE;
  int (*action_OptRE[2]) (grammar_OptRE, grammar_OptRE);
  Bool skip_children_OptRE;
  int (*action_PlusRE[2]) (grammar_PlusRE, grammar_PlusRE);
  Bool skip_children_PlusRE;
  int (*action_TimesRE[2]) (grammar_TimesRE, grammar_TimesRE);
  Bool skip_children_TimesRE;
  int (*action_BasicRE[2]) (grammar_BasicRE, grammar_BasicRE);
  Bool skip_children_BasicRE;
  int (*action_StringRE[2]) (grammar_StringRE, grammar_StringRE);
  Bool skip_children_StringRE;
  int (*action_SOLRE[2]) (grammar_SOLRE, grammar_SOLRE);
  Bool skip_children_SOLRE;
  int (*action_EOLRE[2]) (grammar_EOLRE, grammar_EOLRE);
  Bool skip_children_EOLRE;
  int (*action_IdRE[2]) (grammar_IdRE, grammar_IdRE);
  Bool skip_children_IdRE;
  int (*action_ParRE[2]) (grammar_ParRE, grammar_ParRE);
  Bool skip_children_ParRE;
  int (*action_AnyRE[2]) (grammar_AnyRE, grammar_AnyRE);
  Bool skip_children_AnyRE;
  int (*action_Parser[2]) (grammar_Parser, grammar_Parser);
  Bool skip_children_Parser;
  int (*action_ProdRule[2]) (grammar_ProdRule, grammar_ProdRule);
  Bool skip_children_ProdRule;
  int (*action_NT_Rule[2]) (grammar_NT_Rule, grammar_NT_Rule);
  Bool skip_children_NT_Rule;
  int (*action_Import_Rule[2]) (grammar_Import_Rule, grammar_Import_Rule);
  Bool skip_children_Import_Rule;
  int (*action_Extra_Rule[2]) (grammar_Extra_Rule, grammar_Extra_Rule);
  Bool skip_children_Extra_Rule;
  int (*action_Scope[2]) (grammar_Scope, grammar_Scope);
  Bool skip_children_Scope;
  int (*action_List_ProdRule[2]) (List_grammar_ProdRule, List_grammar_ProdRule);
  Bool skip_children_List_ProdRule;
  int (*action_List_Token[2]) (List_grammar_Token, List_grammar_Token);
  Bool skip_children_List_Token;
} *compare_grammar_TraverseTable;

extern int Traverse_compare_grammar_grammar (grammar_grammar x, grammar_grammar y, compare_grammar_TraverseTable table);
extern int Traverse_compare_grammar_Scanner (grammar_Scanner x, grammar_Scanner y, compare_grammar_TraverseTable table);
extern int Traverse_compare_grammar_Token (grammar_Token x, grammar_Token y, compare_grammar_TraverseTable table);
extern int Traverse_compare_grammar_RegExpr (grammar_RegExpr x, grammar_RegExpr y, compare_grammar_TraverseTable table);
extern int Traverse_compare_grammar_Parser (grammar_Parser x, grammar_Parser y, compare_grammar_TraverseTable table);
extern int Traverse_compare_grammar_ProdRule (grammar_ProdRule x, grammar_ProdRule y, compare_grammar_TraverseTable table);
extern int Traverse_compare_grammar_Scope (grammar_Scope x, grammar_Scope y, compare_grammar_TraverseTable table);
extern int Traverse_compare_List_grammar_ProdRule (List_grammar_ProdRule x, List_grammar_ProdRule y, compare_grammar_TraverseTable table);
extern int Traverse_compare_List_grammar_Token (List_grammar_Token x, List_grammar_Token y, compare_grammar_TraverseTable table);


extern void grammar_fill_table (grammar_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void void_grammar_fill_table (void_grammar_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void copy_grammar_fill_table (copy_grammar_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern void compare_grammar_fill_table (compare_grammar_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action));
extern struct s_grammar_TraverseTable grammar_scope_actions;

extern struct s_void_grammar_TraverseTable grammar_defining_actions;

extern struct s_void_grammar_TraverseTable grammar_applied_actions;

extern struct s_void_grammar_TraverseTable grammar_check_actions;

extern struct s_void_grammar_TraverseTable grammar_print_actions;

extern struct s_copy_grammar_TraverseTable grammar_copy_actions;

extern struct s_compare_grammar_TraverseTable grammar_compare_actions;

typedef int grammar_NameSpaces;

extern grammar_NameSpaces grammar_namespaces[1];

#define grammar_DefaultNameSpace grammar_namespaces[0]

#define grammar_NUM_NAMESPACES 1

extern void Decorate_grammar (grammar_grammar r);

#endif /* _grammar */
