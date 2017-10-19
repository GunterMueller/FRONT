#ifndef grammar_NO_DEFS
#define _grammar_h

#ifndef Extra_Rule_kind
#define Extra_Rule_kind grammar_Extra_Rule_kind
#endif
#ifndef Import_Rule_kind
#define Import_Rule_kind grammar_Import_Rule_kind
#endif
#ifndef NT_Rule_kind
#define NT_Rule_kind grammar_NT_Rule_kind
#endif
#ifndef NUM_ProdRule_tag
#define NUM_ProdRule_tag NUM_grammar_ProdRule_tag
#endif
#ifndef ProdRule_tag
#define ProdRule_tag grammar_ProdRule_tag
#endif
#ifndef AnyRE_kind
#define AnyRE_kind grammar_AnyRE_kind
#endif
#ifndef ParRE_kind
#define ParRE_kind grammar_ParRE_kind
#endif
#ifndef IdRE_kind
#define IdRE_kind grammar_IdRE_kind
#endif
#ifndef EOLRE_kind
#define EOLRE_kind grammar_EOLRE_kind
#endif
#ifndef SOLRE_kind
#define SOLRE_kind grammar_SOLRE_kind
#endif
#ifndef StringRE_kind
#define StringRE_kind grammar_StringRE_kind
#endif
#ifndef TimesRE_kind
#define TimesRE_kind grammar_TimesRE_kind
#endif
#ifndef PlusRE_kind
#define PlusRE_kind grammar_PlusRE_kind
#endif
#ifndef OptRE_kind
#define OptRE_kind grammar_OptRE_kind
#endif
#ifndef SeqRE_kind
#define SeqRE_kind grammar_SeqRE_kind
#endif
#ifndef ChoiceRE_kind
#define ChoiceRE_kind grammar_ChoiceRE_kind
#endif
#ifndef NUM_RegExpr_tag
#define NUM_RegExpr_tag NUM_grammar_RegExpr_tag
#endif
#ifndef RegExpr_tag
#define RegExpr_tag grammar_RegExpr_tag
#endif
#ifndef grammar
#define grammar grammar_grammar
#endif
#ifndef Scanner
#define Scanner grammar_Scanner
#endif
#ifndef Token
#define Token grammar_Token
#endif
#ifndef ChoiceRE
#define ChoiceRE grammar_ChoiceRE
#endif
#ifndef SeqRE
#define SeqRE grammar_SeqRE
#endif
#ifndef OptRE
#define OptRE grammar_OptRE
#endif
#ifndef PlusRE
#define PlusRE grammar_PlusRE
#endif
#ifndef TimesRE
#define TimesRE grammar_TimesRE
#endif
#ifndef PostRE
#define PostRE grammar_PostRE
#endif
#ifndef StringRE
#define StringRE grammar_StringRE
#endif
#ifndef SOLRE
#define SOLRE grammar_SOLRE
#endif
#ifndef EOLRE
#define EOLRE grammar_EOLRE
#endif
#ifndef IdRE
#define IdRE grammar_IdRE
#endif
#ifndef ParRE
#define ParRE grammar_ParRE
#endif
#ifndef AnyRE
#define AnyRE grammar_AnyRE
#endif
#ifndef BasicRE
#define BasicRE grammar_BasicRE
#endif
#ifndef RegExpr
#define RegExpr grammar_RegExpr
#endif
#ifndef Parser
#define Parser grammar_Parser
#endif
#ifndef NT_Rule
#define NT_Rule grammar_NT_Rule
#endif
#ifndef Import_Rule
#define Import_Rule grammar_Import_Rule
#endif
#ifndef Extra_Rule
#define Extra_Rule grammar_Extra_Rule
#endif
#ifndef ProdRule
#define ProdRule grammar_ProdRule
#endif
#ifndef Scope
#define Scope grammar_Scope
#endif
#ifndef List_Token
#define List_Token List_grammar_Token
#endif
#ifndef List_String
#define List_String List_String
#endif
#ifndef List_ProdRule
#define List_ProdRule List_grammar_ProdRule
#endif
#ifndef grammar_src_info
#define grammar_src_info grammar_grammar_src_info
#endif
#ifndef grammar_srcinfo
#define grammar_srcinfo grammar_grammar_srcinfo
#endif
#ifndef grammar_loc
#define grammar_loc grammar_grammar_loc
#endif
#ifndef grammar_scanner
#define grammar_scanner grammar_grammar_scanner
#endif
#ifndef grammar_parser
#define grammar_parser grammar_grammar_parser
#endif
#ifndef Scanner_src_info
#define Scanner_src_info grammar_Scanner_src_info
#endif
#ifndef Scanner_srcinfo
#define Scanner_srcinfo grammar_Scanner_srcinfo
#endif
#ifndef Scanner_loc
#define Scanner_loc grammar_Scanner_loc
#endif
#ifndef Scanner_tokens
#define Scanner_tokens grammar_Scanner_tokens
#endif
#ifndef Token_src_info
#define Token_src_info grammar_Token_src_info
#endif
#ifndef Token_srcinfo
#define Token_srcinfo grammar_Token_srcinfo
#endif
#ifndef Token_loc
#define Token_loc grammar_Token_loc
#endif
#ifndef Token_re
#define Token_re grammar_Token_re
#endif
#ifndef Token_actions
#define Token_actions grammar_Token_actions
#endif
#ifndef Token_id
#define Token_id grammar_Token_id
#endif
#ifndef Token_type
#define Token_type grammar_Token_type
#endif
#ifndef RegExpr_src_info
#define RegExpr_src_info grammar_RegExpr_src_info
#endif
#ifndef RegExpr_srcinfo
#define RegExpr_srcinfo grammar_RegExpr_srcinfo
#endif
#ifndef RegExpr_loc
#define RegExpr_loc grammar_RegExpr_loc
#endif
#ifndef ChoiceRE_head
#define ChoiceRE_head grammar_ChoiceRE_head
#endif
#ifndef ChoiceRE_tail
#define ChoiceRE_tail grammar_ChoiceRE_tail
#endif
#ifndef SeqRE_head
#define SeqRE_head grammar_SeqRE_head
#endif
#ifndef SeqRE_tail
#define SeqRE_tail grammar_SeqRE_tail
#endif
#ifndef PostRE_re
#define PostRE_re grammar_PostRE_re
#endif
#ifndef StringRE_s
#define StringRE_s grammar_StringRE_s
#endif
#ifndef IdRE_id
#define IdRE_id grammar_IdRE_id
#endif
#ifndef ParRE_re
#define ParRE_re grammar_ParRE_re
#endif
#ifndef Parser_src_info
#define Parser_src_info grammar_Parser_src_info
#endif
#ifndef Parser_srcinfo
#define Parser_srcinfo grammar_Parser_srcinfo
#endif
#ifndef Parser_loc
#define Parser_loc grammar_Parser_loc
#endif
#ifndef Parser_rules
#define Parser_rules grammar_Parser_rules
#endif
#ifndef ProdRule_src_info
#define ProdRule_src_info grammar_ProdRule_src_info
#endif
#ifndef ProdRule_srcinfo
#define ProdRule_srcinfo grammar_ProdRule_srcinfo
#endif
#ifndef ProdRule_loc
#define ProdRule_loc grammar_ProdRule_loc
#endif
#ifndef ProdRule_lhs
#define ProdRule_lhs grammar_ProdRule_lhs
#endif
#ifndef ProdRule_fields
#define ProdRule_fields grammar_ProdRule_fields
#endif
#ifndef NT_Rule_nt
#define NT_Rule_nt grammar_NT_Rule_nt
#endif
#ifndef NT_Rule_alt
#define NT_Rule_alt grammar_NT_Rule_alt
#endif
#ifndef NT_Rule_rhs
#define NT_Rule_rhs grammar_NT_Rule_rhs
#endif
#ifndef NT_Rule_fields
#define NT_Rule_fields grammar_NT_Rule_fields
#endif
#ifndef Import_Rule_type
#define Import_Rule_type grammar_Import_Rule_type
#endif
#ifndef Import_Rule_grammar
#define Import_Rule_grammar grammar_Import_Rule_grammar
#endif
#ifndef Import_Rule_imp
#define Import_Rule_imp grammar_Import_Rule_imp
#endif
#ifndef Extra_Rule_sym
#define Extra_Rule_sym grammar_Extra_Rule_sym
#endif
#ifndef Scope_next
#define Scope_next grammar_Scope_next
#endif
#ifndef Scope__self
#define Scope__self grammar_Scope__self
#endif
#ifndef Scope__end
#define Scope__end grammar_Scope__end
#endif
#ifndef List_ProdRule_data
#define List_ProdRule_data List_grammar_ProdRule_data
#endif
#ifndef List_ProdRule_next
#define List_ProdRule_next List_grammar_ProdRule_next
#endif
#ifndef List_String_data
#define List_String_data List_String_data
#endif
#ifndef List_String_next
#define List_String_next List_String_next
#endif
#ifndef List_Token_data
#define List_Token_data List_grammar_Token_data
#endif
#ifndef List_Token_next
#define List_Token_next List_grammar_Token_next
#endif

/* Abbreviations for grammar.h */

#ifndef Create_grammar
#define Create_grammar Create_grammar_grammar
#endif
#ifndef Create_Scanner
#define Create_Scanner Create_grammar_Scanner
#endif
#ifndef Create_Token
#define Create_Token Create_grammar_Token
#endif
#ifndef Create_AnyRE
#define Create_AnyRE Create_grammar_AnyRE
#endif
#ifndef Create_ParRE
#define Create_ParRE Create_grammar_ParRE
#endif
#ifndef Create_IdRE
#define Create_IdRE Create_grammar_IdRE
#endif
#ifndef Create_EOLRE
#define Create_EOLRE Create_grammar_EOLRE
#endif
#ifndef Create_SOLRE
#define Create_SOLRE Create_grammar_SOLRE
#endif
#ifndef Create_StringRE
#define Create_StringRE Create_grammar_StringRE
#endif
#ifndef Create_TimesRE
#define Create_TimesRE Create_grammar_TimesRE
#endif
#ifndef Create_PlusRE
#define Create_PlusRE Create_grammar_PlusRE
#endif
#ifndef Create_OptRE
#define Create_OptRE Create_grammar_OptRE
#endif
#ifndef Create_SeqRE
#define Create_SeqRE Create_grammar_SeqRE
#endif
#ifndef Create_ChoiceRE
#define Create_ChoiceRE Create_grammar_ChoiceRE
#endif
#ifndef Create_Parser
#define Create_Parser Create_grammar_Parser
#endif
#ifndef Create_Extra_Rule
#define Create_Extra_Rule Create_grammar_Extra_Rule
#endif
#ifndef Create_Import_Rule
#define Create_Import_Rule Create_grammar_Import_Rule
#endif
#ifndef Create_NT_Rule
#define Create_NT_Rule Create_grammar_NT_Rule
#endif
#ifndef Create_Scope
#define Create_Scope Create_grammar_Scope
#endif
#ifndef Create_List_ProdRule
#define Create_List_ProdRule Create_List_grammar_ProdRule
#endif
#ifndef List_ProdRule_size
#define List_ProdRule_size List_grammar_ProdRule_size
#endif
#ifndef Create_List_Token
#define Create_List_Token Create_List_grammar_Token
#endif
#ifndef List_Token_size
#define List_Token_size List_grammar_Token_size
#endif
#ifndef s_TraverseTable
#define s_TraverseTable s_grammar_TraverseTable
#endif
#ifndef TraverseTable
#define TraverseTable grammar_TraverseTable
#endif
#ifndef Traverse_grammar
#define Traverse_grammar Traverse_grammar_grammar
#endif
#ifndef Traverse_Scanner
#define Traverse_Scanner Traverse_grammar_Scanner
#endif
#ifndef Traverse_Token
#define Traverse_Token Traverse_grammar_Token
#endif
#ifndef Traverse_RegExpr
#define Traverse_RegExpr Traverse_grammar_RegExpr
#endif
#ifndef Traverse_Parser
#define Traverse_Parser Traverse_grammar_Parser
#endif
#ifndef Traverse_ProdRule
#define Traverse_ProdRule Traverse_grammar_ProdRule
#endif
#ifndef Traverse_Scope
#define Traverse_Scope Traverse_grammar_Scope
#endif
#ifndef Traverse_List_ProdRule
#define Traverse_List_ProdRule Traverse_List_grammar_ProdRule
#endif
#ifndef Traverse_List_Token
#define Traverse_List_Token Traverse_List_grammar_Token
#endif
#ifndef s_void_TraverseTable
#define s_void_TraverseTable s_void_grammar_TraverseTable
#endif
#ifndef void_TraverseTable
#define void_TraverseTable void_grammar_TraverseTable
#endif
#ifndef Traverse_void_grammar
#define Traverse_void_grammar Traverse_void_grammar_grammar
#endif
#ifndef Traverse_void_Scanner
#define Traverse_void_Scanner Traverse_void_grammar_Scanner
#endif
#ifndef Traverse_void_Token
#define Traverse_void_Token Traverse_void_grammar_Token
#endif
#ifndef Traverse_void_RegExpr
#define Traverse_void_RegExpr Traverse_void_grammar_RegExpr
#endif
#ifndef Traverse_void_Parser
#define Traverse_void_Parser Traverse_void_grammar_Parser
#endif
#ifndef Traverse_void_ProdRule
#define Traverse_void_ProdRule Traverse_void_grammar_ProdRule
#endif
#ifndef Traverse_void_Scope
#define Traverse_void_Scope Traverse_void_grammar_Scope
#endif
#ifndef Traverse_void_List_ProdRule
#define Traverse_void_List_ProdRule Traverse_void_List_grammar_ProdRule
#endif
#ifndef Traverse_void_List_Token
#define Traverse_void_List_Token Traverse_void_List_grammar_Token
#endif
#ifndef s_copy_TraverseTable
#define s_copy_TraverseTable s_copy_grammar_TraverseTable
#endif
#ifndef copy_TraverseTable
#define copy_TraverseTable copy_grammar_TraverseTable
#endif
#ifndef Traverse_copy_grammar
#define Traverse_copy_grammar Traverse_copy_grammar_grammar
#endif
#ifndef COPY_grammar
#define COPY_grammar COPY_grammar_grammar
#endif
#ifndef copy_actions
#define copy_actions grammar_copy_actions
#endif
#ifndef Traverse_copy_Scanner
#define Traverse_copy_Scanner Traverse_copy_grammar_Scanner
#endif
#ifndef COPY_Scanner
#define COPY_Scanner COPY_grammar_Scanner
#endif
#ifndef Traverse_copy_Token
#define Traverse_copy_Token Traverse_copy_grammar_Token
#endif
#ifndef COPY_Token
#define COPY_Token COPY_grammar_Token
#endif
#ifndef Traverse_copy_RegExpr
#define Traverse_copy_RegExpr Traverse_copy_grammar_RegExpr
#endif
#ifndef COPY_RegExpr
#define COPY_RegExpr COPY_grammar_RegExpr
#endif
#ifndef Traverse_copy_Parser
#define Traverse_copy_Parser Traverse_copy_grammar_Parser
#endif
#ifndef COPY_Parser
#define COPY_Parser COPY_grammar_Parser
#endif
#ifndef Traverse_copy_ProdRule
#define Traverse_copy_ProdRule Traverse_copy_grammar_ProdRule
#endif
#ifndef COPY_ProdRule
#define COPY_ProdRule COPY_grammar_ProdRule
#endif
#ifndef Traverse_copy_Scope
#define Traverse_copy_Scope Traverse_copy_grammar_Scope
#endif
#ifndef COPY_Scope
#define COPY_Scope COPY_grammar_Scope
#endif
#ifndef Traverse_copy_List_ProdRule
#define Traverse_copy_List_ProdRule Traverse_copy_List_grammar_ProdRule
#endif
#ifndef COPY_List_ProdRule
#define COPY_List_ProdRule COPY_grammar_List_ProdRule
#endif
#ifndef Traverse_copy_List_Token
#define Traverse_copy_List_Token Traverse_copy_List_grammar_Token
#endif
#ifndef COPY_List_Token
#define COPY_List_Token COPY_grammar_List_Token
#endif
#ifndef s_compare_TraverseTable
#define s_compare_TraverseTable s_compare_grammar_TraverseTable
#endif
#ifndef compare_TraverseTable
#define compare_TraverseTable compare_grammar_TraverseTable
#endif
#ifndef Traverse_compare_grammar
#define Traverse_compare_grammar Traverse_compare_grammar_grammar
#endif
#ifndef Traverse_compare_Scanner
#define Traverse_compare_Scanner Traverse_compare_grammar_Scanner
#endif
#ifndef Traverse_compare_Token
#define Traverse_compare_Token Traverse_compare_grammar_Token
#endif
#ifndef Traverse_compare_RegExpr
#define Traverse_compare_RegExpr Traverse_compare_grammar_RegExpr
#endif
#ifndef Traverse_compare_Parser
#define Traverse_compare_Parser Traverse_compare_grammar_Parser
#endif
#ifndef Traverse_compare_ProdRule
#define Traverse_compare_ProdRule Traverse_compare_grammar_ProdRule
#endif
#ifndef Traverse_compare_Scope
#define Traverse_compare_Scope Traverse_compare_grammar_Scope
#endif
#ifndef Traverse_compare_List_ProdRule
#define Traverse_compare_List_ProdRule Traverse_compare_List_grammar_ProdRule
#endif
#ifndef Traverse_compare_List_Token
#define Traverse_compare_List_Token Traverse_compare_List_grammar_Token
#endif
#ifndef fill_table
#define fill_table grammar_fill_table
#endif
#ifndef void_fill_table
#define void_fill_table void_grammar_fill_table
#endif
#ifndef copy_fill_table
#define copy_fill_table copy_grammar_fill_table
#endif
#ifndef compare_fill_table
#define compare_fill_table compare_grammar_fill_table
#endif
#ifndef scope_actions
#define scope_actions grammar_scope_actions
#endif
#ifndef defining_actions
#define defining_actions grammar_defining_actions
#endif
#ifndef applied_actions
#define applied_actions grammar_applied_actions
#endif
#ifndef check_actions
#define check_actions grammar_check_actions
#endif
#ifndef print_actions
#define print_actions grammar_print_actions
#endif
#ifndef compare_actions
#define compare_actions grammar_compare_actions
#endif
#ifndef NameSpaces
#define NameSpaces grammar_NameSpaces
#endif
#ifndef namespaces
#define namespaces grammar_namespaces
#endif
#ifndef DefaultNameSpace
#define DefaultNameSpace grammar_DefaultNameSpace
#endif
#ifndef NUM_NAMESPACES
#define NUM_NAMESPACES grammar_NUM_NAMESPACES
#endif
#ifndef RegExpr_tag_names
#define RegExpr_tag_names grammar_RegExpr_tag_names
#endif
#ifndef ProdRule_tag_names
#define ProdRule_tag_names grammar_ProdRule_tag_names
#endif

/* Abbreviations for grammar_parse.h */

#ifndef Parse_grammar
#define Parse_grammar Parse_grammar_grammar
#endif
#ifndef Parse_Scanner
#define Parse_Scanner Parse_grammar_Scanner
#endif
#ifndef Parse_Token
#define Parse_Token Parse_grammar_Token
#endif
#ifndef Parse_RegExpr
#define Parse_RegExpr Parse_grammar_RegExpr
#endif
#ifndef Parse_ChoiceRE
#define Parse_ChoiceRE Parse_grammar_ChoiceRE
#endif
#ifndef Parse_SeqRE
#define Parse_SeqRE Parse_grammar_SeqRE
#endif
#ifndef Parse_PostRE
#define Parse_PostRE Parse_grammar_PostRE
#endif
#ifndef Parse_BasicRE
#define Parse_BasicRE Parse_grammar_BasicRE
#endif
#ifndef Parse_ScanAction
#define Parse_ScanAction Parse_grammar_ScanAction
#endif
#ifndef Parse_Parser
#define Parse_Parser Parse_grammar_Parser
#endif
#ifndef Parse_ProdRule
#define Parse_ProdRule Parse_grammar_ProdRule
#endif
#ifndef Parse_OPTMORE_Token
#define Parse_OPTMORE_Token Parse_grammar_OPTMORE_Token
#endif
#ifndef Parse_OPTMORE_ScanAction_semicolonsym
#define Parse_OPTMORE_ScanAction_semicolonsym Parse_grammar_OPTMORE_ScanAction_semicolonsym
#endif
#ifndef Parse_OPTMORE_ProdRule
#define Parse_OPTMORE_ProdRule Parse_grammar_OPTMORE_ProdRule
#endif
#ifndef Parse_state_grammar
#define Parse_state_grammar Parse_state_grammar_grammar
#endif
#ifndef parse_string
#define parse_string grammar_parse_string
#endif
#ifndef Parse_state_Scanner
#define Parse_state_Scanner Parse_state_grammar_Scanner
#endif
#ifndef Parse_state_Token
#define Parse_state_Token Parse_state_grammar_Token
#endif
#ifndef Parse_state_RegExpr
#define Parse_state_RegExpr Parse_state_grammar_RegExpr
#endif
#ifndef Parse_state_ChoiceRE
#define Parse_state_ChoiceRE Parse_state_grammar_ChoiceRE
#endif
#ifndef Parse_state_SeqRE
#define Parse_state_SeqRE Parse_state_grammar_SeqRE
#endif
#ifndef Parse_state_PostRE
#define Parse_state_PostRE Parse_state_grammar_PostRE
#endif
#ifndef Parse_state_BasicRE
#define Parse_state_BasicRE Parse_state_grammar_BasicRE
#endif
#ifndef Parse_state_ScanAction
#define Parse_state_ScanAction Parse_state_grammar_ScanAction
#endif
#ifndef Parse_state_Parser
#define Parse_state_Parser Parse_state_grammar_Parser
#endif
#ifndef Parse_state_ProdRule
#define Parse_state_ProdRule Parse_state_grammar_ProdRule
#endif
#ifndef Parse_state_OPTMORE_Token
#define Parse_state_OPTMORE_Token Parse_state_grammar_OPTMORE_Token
#endif
#ifndef Parse_state_OPTMORE_ScanAction_semicolonsym
#define Parse_state_OPTMORE_ScanAction_semicolonsym Parse_state_grammar_OPTMORE_ScanAction_semicolonsym
#endif
#ifndef Parse_state_OPTMORE_ProdRule
#define Parse_state_OPTMORE_ProdRule Parse_state_grammar_OPTMORE_ProdRule
#endif
#ifndef Print_grammar
#define Print_grammar Print_grammar_grammar
#endif
#ifndef PRINT_grammar
#define PRINT_grammar PRINT_grammar_grammar
#endif
#ifndef Text_grammar
#define Text_grammar Text_grammar_grammar
#endif
#ifndef Print_Scanner
#define Print_Scanner Print_grammar_Scanner
#endif
#ifndef PRINT_Scanner
#define PRINT_Scanner PRINT_grammar_Scanner
#endif
#ifndef Text_Scanner
#define Text_Scanner Text_grammar_Scanner
#endif
#ifndef Print_Token
#define Print_Token Print_grammar_Token
#endif
#ifndef PRINT_Token
#define PRINT_Token PRINT_grammar_Token
#endif
#ifndef Text_Token
#define Text_Token Text_grammar_Token
#endif
#ifndef Print_RegExpr
#define Print_RegExpr Print_grammar_RegExpr
#endif
#ifndef PRINT_RegExpr
#define PRINT_RegExpr PRINT_grammar_RegExpr
#endif
#ifndef Text_RegExpr
#define Text_RegExpr Text_grammar_RegExpr
#endif
#ifndef Print_Parser
#define Print_Parser Print_grammar_Parser
#endif
#ifndef PRINT_Parser
#define PRINT_Parser PRINT_grammar_Parser
#endif
#ifndef Text_Parser
#define Text_Parser Text_grammar_Parser
#endif
#ifndef Print_ProdRule
#define Print_ProdRule Print_grammar_ProdRule
#endif
#ifndef PRINT_ProdRule
#define PRINT_ProdRule PRINT_grammar_ProdRule
#endif
#ifndef Text_ProdRule
#define Text_ProdRule Text_grammar_ProdRule
#endif
#ifndef Print_Scope
#define Print_Scope Print_grammar_Scope
#endif
#ifndef PRINT_Scope
#define PRINT_Scope PRINT_grammar_Scope
#endif
#ifndef Text_Scope
#define Text_Scope Text_grammar_Scope
#endif
#ifndef Print_List_ProdRule
#define Print_List_ProdRule Print_List_grammar_ProdRule
#endif
#ifndef PRINT_List_ProdRule
#define PRINT_List_ProdRule PRINT_List_grammar_ProdRule
#endif
#ifndef Text_List_ProdRule
#define Text_List_ProdRule Text_List_grammar_ProdRule
#endif
#ifndef Print_List_Token
#define Print_List_Token Print_List_grammar_Token
#endif
#ifndef PRINT_List_Token
#define PRINT_List_Token PRINT_List_grammar_Token
#endif
#ifndef Text_List_Token
#define Text_List_Token Text_List_grammar_Token
#endif
#endif /* grammar_NO_DEFS */

