#ifndef CREATE_LIST          
#define CREATE_LIST(t,a,b)   (Create_##t((a),(b)))
#endif                       
#ifndef LIST_HAS_LIST        
#define LIST_HAS_LIST(i,l)   ((l) != NULL)
#endif                       
#ifndef LIST_GET_LIST        
#define LIST_GET_LIST(i,l)   ((i)==0?Front_data((Front_List)(l)) : (i)==1 ? Front_next((Front_List)(l)) : NULL)
#endif                       
#ifndef LIST                 
#define LIST                 Front_List
#endif                       
#ifndef LIST_REPLACE         
#define LIST_REPLACE(a,b,i)  (*(a) = *(b))
#endif                       
#ifndef CONVERT_I_TO_Int     
#define CONVERT_I_TO_Int(i)  (i)
#endif                       
#ifndef CONVERT_Int_TO_I     
#define CONVERT_Int_TO_I(i)  (i)
#endif                       
#ifndef CONVERT_Bool_TO_B    
#define CONVERT_Bool_TO_B(i) (i)
#endif                       
#ifndef CONVERT_B_TO_Bool    
#define CONVERT_B_TO_Bool(i) (i)
#endif                       
#ifndef IS_NULL              
#define IS_NULL(i)           ((i) == NULL)
#endif                       
#ifndef COPY_Ident           
#define COPY_Ident(x)        (x)
#endif                       
#ifndef COPY_Int             
#define COPY_Int(x)          (x)
#endif                       
#ifndef COPY_Bool            
#define COPY_Bool(x)         (x)
#endif                       
#ifndef COPY_Char            
#define COPY_Char(x)         (x)
#endif                       
#ifndef COPY_String          
#define COPY_String(x)       (x)
#endif                       
#ifndef COPY_Float           
#define COPY_Float(x)        (x)
#endif                       
#ifndef COPY_I               
#define COPY_I(x)            (x)
#endif                       
#ifndef COPY_B               
#define COPY_B(x)            (x)
#endif                       
#ifndef grammar_grammar_OPERATOR
#define grammar_grammar_OPERATOR(a) ((a)==NULL?(unsigned)~0:grammar_grammar_kind)
#endif
#ifndef grammar_grammar_HAS_OPER
#define grammar_grammar_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef grammar_grammar_REPLACE 
#define grammar_grammar_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_grammar_grammar
#define COPY_grammar_grammar(x) Traverse_copy_grammar_grammar(x, &grammar_copy_actions)
#endif

#ifndef NEW_grammar_grammar
#define NEW_grammar_grammar(src_info, scanner, parser, yyy) Create_grammar_grammar(NO_SRCINFO, scanner, parser)
#endif

#define grammar_grammar_GET_grammar_Scanner(i,me)	(i == 0 ? grammar_grammar_scanner(me) : 0)
#define grammar_grammar_GET_grammar_Parser(i,me)	(i == 1 ? grammar_grammar_parser(me) : 0)

#ifndef grammar_Scanner_OPERATOR
#define grammar_Scanner_OPERATOR(a) ((a)==NULL?(unsigned)~0:grammar_Scanner_kind)
#endif
#ifndef grammar_Scanner_HAS_OPER
#define grammar_Scanner_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef grammar_Scanner_REPLACE 
#define grammar_Scanner_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_grammar_Scanner
#define COPY_grammar_Scanner(x) Traverse_copy_grammar_Scanner(x, &grammar_copy_actions)
#endif

#ifndef NEW_grammar_Scanner
#define NEW_grammar_Scanner(src_info, tokens, yyy) Create_grammar_Scanner(NO_SRCINFO, tokens)
#endif

#define grammar_Scanner_GET_List_grammar_Token(i,me)	(i == 0 ? grammar_Scanner_tokens(me) : 0)

#ifndef grammar_Token_OPERATOR
#define grammar_Token_OPERATOR(a) ((a)==NULL?(unsigned)~0:grammar_Token_kind)
#endif
#ifndef grammar_Token_HAS_OPER
#define grammar_Token_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef grammar_Token_REPLACE 
#define grammar_Token_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_grammar_Token
#define COPY_grammar_Token(x) Traverse_copy_grammar_Token(x, &grammar_copy_actions)
#endif

#ifndef NEW_grammar_Token
#define NEW_grammar_Token(src_info, re, actions, yyy) Create_grammar_Token(NO_SRCINFO, re, actions)
#endif

#define grammar_Token_GET_grammar_RegExpr(i,me)	(i == 0 ? grammar_Token_re(me) : 0)
#define grammar_Token_GET_List_String(i,me)	(i == 1 ? grammar_Token_actions(me) : 0)

#ifndef grammar_RegExpr_OPERATOR
#define grammar_RegExpr_OPERATOR(a) ((a)==NULL?(unsigned)~0:grammar_RegExpr_tag(a))
#endif
#ifndef grammar_RegExpr_HAS_OPER
#define grammar_RegExpr_HAS_OPER(a,op) ((a) != NULL && grammar_RegExpr_tag(a) == op)
#endif
#ifndef grammar_RegExpr_REPLACE 
#define grammar_RegExpr_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_grammar_RegExpr
#define COPY_grammar_RegExpr(x) Traverse_copy_grammar_RegExpr(x, &grammar_copy_actions)
#endif

#ifndef NEW_grammar_AnyRE
#define NEW_grammar_AnyRE(src_info, yyy) Create_grammar_AnyRE(NO_SRCINFO)
#endif


#ifndef NEW_grammar_ParRE
#define NEW_grammar_ParRE(src_info, re, yyy) Create_grammar_ParRE(NO_SRCINFO, re)
#endif

#define grammar_ParRE_GET_grammar_RegExpr(i,me)	(i == 0 ? grammar_ParRE_re(me) : 0)

#ifndef NEW_grammar_IdRE
#define NEW_grammar_IdRE(src_info, id, yyy) Create_grammar_IdRE(NO_SRCINFO, id)
#endif

#define grammar_IdRE_GET_Ident(i,me)	(i == 0 ? grammar_IdRE_id(me) : 0)

#ifndef NEW_grammar_EOLRE
#define NEW_grammar_EOLRE(src_info, yyy) Create_grammar_EOLRE(NO_SRCINFO)
#endif


#ifndef NEW_grammar_SOLRE
#define NEW_grammar_SOLRE(src_info, yyy) Create_grammar_SOLRE(NO_SRCINFO)
#endif


#ifndef NEW_grammar_StringRE
#define NEW_grammar_StringRE(src_info, s, yyy) Create_grammar_StringRE(NO_SRCINFO, s)
#endif

#define grammar_StringRE_GET_String(i,me)	(i == 0 ? grammar_StringRE_s(me) : 0)

#ifndef NEW_grammar_TimesRE
#define NEW_grammar_TimesRE(src_info, re, yyy) Create_grammar_TimesRE(NO_SRCINFO, re)
#endif

#define grammar_TimesRE_GET_grammar_RegExpr(i,me)	(i == 0 ? grammar_PostRE_re(me) : 0)

#ifndef NEW_grammar_PlusRE
#define NEW_grammar_PlusRE(src_info, re, yyy) Create_grammar_PlusRE(NO_SRCINFO, re)
#endif

#define grammar_PlusRE_GET_grammar_RegExpr(i,me)	(i == 0 ? grammar_PostRE_re(me) : 0)

#ifndef NEW_grammar_OptRE
#define NEW_grammar_OptRE(src_info, re, yyy) Create_grammar_OptRE(NO_SRCINFO, re)
#endif

#define grammar_OptRE_GET_grammar_RegExpr(i,me)	(i == 0 ? grammar_PostRE_re(me) : 0)

#ifndef NEW_grammar_SeqRE
#define NEW_grammar_SeqRE(src_info, head, tail, yyy) Create_grammar_SeqRE(NO_SRCINFO, head, tail)
#endif

#define grammar_SeqRE_GET_grammar_RegExpr(i,me)	(i == 0 ? grammar_SeqRE_head(me) : i == 1 ? grammar_SeqRE_tail(me) : 0)

#ifndef NEW_grammar_ChoiceRE
#define NEW_grammar_ChoiceRE(src_info, head, tail, yyy) Create_grammar_ChoiceRE(NO_SRCINFO, head, tail)
#endif

#define grammar_ChoiceRE_GET_grammar_RegExpr(i,me)	(i == 0 ? grammar_ChoiceRE_head(me) : i == 1 ? grammar_ChoiceRE_tail(me) : 0)

#ifndef grammar_Parser_OPERATOR
#define grammar_Parser_OPERATOR(a) ((a)==NULL?(unsigned)~0:grammar_Parser_kind)
#endif
#ifndef grammar_Parser_HAS_OPER
#define grammar_Parser_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef grammar_Parser_REPLACE 
#define grammar_Parser_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_grammar_Parser
#define COPY_grammar_Parser(x) Traverse_copy_grammar_Parser(x, &grammar_copy_actions)
#endif

#ifndef NEW_grammar_Parser
#define NEW_grammar_Parser(src_info, rules, yyy) Create_grammar_Parser(NO_SRCINFO, rules)
#endif

#define grammar_Parser_GET_List_grammar_ProdRule(i,me)	(i == 0 ? grammar_Parser_rules(me) : 0)

#ifndef grammar_ProdRule_OPERATOR
#define grammar_ProdRule_OPERATOR(a) ((a)==NULL?(unsigned)~0:grammar_ProdRule_tag(a))
#endif
#ifndef grammar_ProdRule_HAS_OPER
#define grammar_ProdRule_HAS_OPER(a,op) ((a) != NULL && grammar_ProdRule_tag(a) == op)
#endif
#ifndef grammar_ProdRule_REPLACE 
#define grammar_ProdRule_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_grammar_ProdRule
#define COPY_grammar_ProdRule(x) Traverse_copy_grammar_ProdRule(x, &grammar_copy_actions)
#endif

#ifndef NEW_grammar_Extra_Rule
#define NEW_grammar_Extra_Rule(src_info, lhs, yyy) Create_grammar_Extra_Rule(NO_SRCINFO, lhs)
#endif

#define grammar_Extra_Rule_GET_Ident(i,me)	(i == 0 ? grammar_ProdRule_lhs(me) : 0)

#ifndef NEW_grammar_Import_Rule
#define NEW_grammar_Import_Rule(src_info, lhs, yyy) Create_grammar_Import_Rule(NO_SRCINFO, lhs)
#endif

#define grammar_Import_Rule_GET_Ident(i,me)	(i == 0 ? grammar_ProdRule_lhs(me) : 0)

#ifndef NEW_grammar_NT_Rule
#define NEW_grammar_NT_Rule(src_info, lhs, yyy) Create_grammar_NT_Rule(NO_SRCINFO, lhs)
#endif

#define grammar_NT_Rule_GET_Ident(i,me)	(i == 0 ? grammar_ProdRule_lhs(me) : 0)

#ifndef grammar_Scope_OPERATOR
#define grammar_Scope_OPERATOR(a) ((a)==NULL?(unsigned)~0:grammar_Scope_kind)
#endif
#ifndef grammar_Scope_HAS_OPER
#define grammar_Scope_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef grammar_Scope_REPLACE 
#define grammar_Scope_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_grammar_Scope
#define COPY_grammar_Scope(x) Traverse_copy_grammar_Scope(x, &grammar_copy_actions)
#endif

#ifndef NEW_grammar_Scope
#define NEW_grammar_Scope(next, yyy) Create_grammar_Scope(NO_SRCINFO)
#endif


#ifndef List_grammar_ProdRule_OPERATOR
#define List_grammar_ProdRule_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_grammar_ProdRule_kind)
#endif
#ifndef List_grammar_ProdRule_HAS_OPER
#define List_grammar_ProdRule_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_grammar_ProdRule_REPLACE 
#define List_grammar_ProdRule_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_grammar_ProdRule
#define COPY_List_grammar_ProdRule(x) Traverse_copy_List_grammar_ProdRule(x, &grammar_copy_actions)
#endif

#ifndef NEW_List_grammar_ProdRule
#define NEW_List_grammar_ProdRule(xxx, data, next, yyy) Create_List_grammar_ProdRule(data, next)
#endif

#define List_grammar_ProdRule_GET_grammar_ProdRule(i,me)	(i == 0 ? List_grammar_ProdRule_data(me) : 0)
#define List_grammar_ProdRule_GET_List_grammar_ProdRule(i,me)	(i == 1 ? List_grammar_ProdRule_next(me) : 0)

#ifndef List_String_OPERATOR
#define List_String_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_String_kind)
#endif
#ifndef List_String_HAS_OPER
#define List_String_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_String_REPLACE 
#define List_String_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_String
#define COPY_List_String(x) Traverse_copy_List_String(x, &grammar_copy_actions)
#endif

#ifndef List_grammar_Token_OPERATOR
#define List_grammar_Token_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_grammar_Token_kind)
#endif
#ifndef List_grammar_Token_HAS_OPER
#define List_grammar_Token_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_grammar_Token_REPLACE 
#define List_grammar_Token_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_grammar_Token
#define COPY_List_grammar_Token(x) Traverse_copy_List_grammar_Token(x, &grammar_copy_actions)
#endif

#ifndef NEW_List_grammar_Token
#define NEW_List_grammar_Token(xxx, data, next, yyy) Create_List_grammar_Token(data, next)
#endif

#define List_grammar_Token_GET_grammar_Token(i,me)	(i == 0 ? List_grammar_Token_data(me) : 0)
#define List_grammar_Token_GET_List_grammar_Token(i,me)	(i == 1 ? List_grammar_Token_next(me) : 0)

#ifndef grammar_RegExpr_tag_OPERATOR
#define grammar_RegExpr_tag_OPERATOR(a) (a)
#endif
#ifndef grammar_RegExpr_tag_HAS_OPER
#define grammar_RegExpr_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef grammar_RegExpr_tag_REPLACE 
#define grammar_RegExpr_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_grammar_RegExpr_tag
#define COPY_grammar_RegExpr_tag(x) (x)
#endif

#ifndef NEW_grammar_ChoiceRE_kind
#define NEW_grammar_ChoiceRE_kind(x,y)	grammar_ChoiceRE_kind
#endif
#ifndef NEW_grammar_SeqRE_kind
#define NEW_grammar_SeqRE_kind(x,y)	grammar_SeqRE_kind
#endif
#ifndef NEW_grammar_OptRE_kind
#define NEW_grammar_OptRE_kind(x,y)	grammar_OptRE_kind
#endif
#ifndef NEW_grammar_PlusRE_kind
#define NEW_grammar_PlusRE_kind(x,y)	grammar_PlusRE_kind
#endif
#ifndef NEW_grammar_TimesRE_kind
#define NEW_grammar_TimesRE_kind(x,y)	grammar_TimesRE_kind
#endif
#ifndef NEW_grammar_StringRE_kind
#define NEW_grammar_StringRE_kind(x,y)	grammar_StringRE_kind
#endif
#ifndef NEW_grammar_SOLRE_kind
#define NEW_grammar_SOLRE_kind(x,y)	grammar_SOLRE_kind
#endif
#ifndef NEW_grammar_EOLRE_kind
#define NEW_grammar_EOLRE_kind(x,y)	grammar_EOLRE_kind
#endif
#ifndef NEW_grammar_IdRE_kind
#define NEW_grammar_IdRE_kind(x,y)	grammar_IdRE_kind
#endif
#ifndef NEW_grammar_ParRE_kind
#define NEW_grammar_ParRE_kind(x,y)	grammar_ParRE_kind
#endif
#ifndef NEW_grammar_AnyRE_kind
#define NEW_grammar_AnyRE_kind(x,y)	grammar_AnyRE_kind
#endif
#ifndef grammar_ProdRule_tag_OPERATOR
#define grammar_ProdRule_tag_OPERATOR(a) (a)
#endif
#ifndef grammar_ProdRule_tag_HAS_OPER
#define grammar_ProdRule_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef grammar_ProdRule_tag_REPLACE 
#define grammar_ProdRule_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_grammar_ProdRule_tag
#define COPY_grammar_ProdRule_tag(x) (x)
#endif

#ifndef NEW_grammar_NT_Rule_kind
#define NEW_grammar_NT_Rule_kind(x,y)	grammar_NT_Rule_kind
#endif
#ifndef NEW_grammar_Import_Rule_kind
#define NEW_grammar_Import_Rule_kind(x,y)	grammar_Import_Rule_kind
#endif
#ifndef NEW_grammar_Extra_Rule_kind
#define NEW_grammar_Extra_Rule_kind(x,y)	grammar_Extra_Rule_kind
#endif
