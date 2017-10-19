#ifndef egg_NO_DEFS
#define _egg_h

#ifndef GroupScope
#define GroupScope egg_GroupScope
#endif
#ifndef GroupScope_kind
#define GroupScope_kind egg_GroupScope_kind
#endif
#ifndef NUM_Scope_tag
#define NUM_Scope_tag NUM_egg_Scope_tag
#endif
#ifndef Scope_tag
#define Scope_tag egg_Scope_tag
#endif
#ifndef PostMsg
#define PostMsg egg_PostMsg
#endif
#ifndef KeyMsg
#define KeyMsg egg_KeyMsg
#endif
#ifndef DisabledMsg
#define DisabledMsg egg_DisabledMsg
#endif
#ifndef WarningMsg
#define WarningMsg egg_WarningMsg
#endif
#ifndef ErrorMsg
#define ErrorMsg egg_ErrorMsg
#endif
#ifndef NUM_MessageKind
#define NUM_MessageKind NUM_egg_MessageKind
#endif
#ifndef MessageKind
#define MessageKind egg_MessageKind
#endif
#ifndef Group_kind
#define Group_kind egg_Group_kind
#endif
#ifndef Message_kind
#define Message_kind egg_Message_kind
#endif
#ifndef NUM_Statement_tag
#define NUM_Statement_tag NUM_egg_Statement_tag
#endif
#ifndef Statement_tag
#define Statement_tag egg_Statement_tag
#endif
#ifndef IdExpr_kind
#define IdExpr_kind egg_IdExpr_kind
#endif
#ifndef CallExpr_kind
#define CallExpr_kind egg_CallExpr_kind
#endif
#ifndef StringExpr_kind
#define StringExpr_kind egg_StringExpr_kind
#endif
#ifndef NUM_Expression_tag
#define NUM_Expression_tag NUM_egg_Expression_tag
#endif
#ifndef Expression_tag
#define Expression_tag egg_Expression_tag
#endif
#ifndef egg
#define egg egg_egg
#endif
#ifndef Uses
#define Uses egg_Uses
#endif
#ifndef Declaration
#define Declaration egg_Declaration
#endif
#ifndef StringExpr
#define StringExpr egg_StringExpr
#endif
#ifndef CallExpr
#define CallExpr egg_CallExpr
#endif
#ifndef IdExpr
#define IdExpr egg_IdExpr
#endif
#ifndef Expression
#define Expression egg_Expression
#endif
#ifndef Message
#define Message egg_Message
#endif
#ifndef Group
#define Group egg_Group
#endif
#ifndef Statement
#define Statement egg_Statement
#endif
#ifndef SubMessage
#define SubMessage egg_SubMessage
#endif
#ifndef Scope
#define Scope egg_Scope
#endif
#ifndef List_Statement
#define List_Statement List_egg_Statement
#endif
#ifndef List_String
#define List_String List_String
#endif
#ifndef List_Expression
#define List_Expression List_egg_Expression
#endif
#ifndef List_SubMessage
#define List_SubMessage List_egg_SubMessage
#endif
#ifndef List_Declaration
#define List_Declaration List_egg_Declaration
#endif
#ifndef egg_src_info
#define egg_src_info egg_egg_src_info
#endif
#ifndef egg_srcinfo
#define egg_srcinfo egg_egg_srcinfo
#endif
#ifndef egg_loc
#define egg_loc egg_egg_loc
#endif
#ifndef egg_uses
#define egg_uses egg_egg_uses
#endif
#ifndef egg_groups
#define egg_groups egg_egg_groups
#endif
#ifndef Uses_src_info
#define Uses_src_info egg_Uses_src_info
#endif
#ifndef Uses_srcinfo
#define Uses_srcinfo egg_Uses_srcinfo
#endif
#ifndef Uses_loc
#define Uses_loc egg_Uses_loc
#endif
#ifndef Uses_uses
#define Uses_uses egg_Uses_uses
#endif
#ifndef Declaration_src_info
#define Declaration_src_info egg_Declaration_src_info
#endif
#ifndef Declaration_srcinfo
#define Declaration_srcinfo egg_Declaration_srcinfo
#endif
#ifndef Declaration_loc
#define Declaration_loc egg_Declaration_loc
#endif
#ifndef Declaration_kind
#define Declaration_kind egg_Declaration_kind
#endif
#ifndef Declaration_exprs
#define Declaration_exprs egg_Declaration_exprs
#endif
#ifndef Declaration_group
#define Declaration_group egg_Declaration_group
#endif
#ifndef Expression_src_info
#define Expression_src_info egg_Expression_src_info
#endif
#ifndef Expression_srcinfo
#define Expression_srcinfo egg_Expression_srcinfo
#endif
#ifndef Expression_loc
#define Expression_loc egg_Expression_loc
#endif
#ifndef StringExpr_s
#define StringExpr_s egg_StringExpr_s
#endif
#ifndef CallExpr_id
#define CallExpr_id egg_CallExpr_id
#endif
#ifndef CallExpr_params
#define CallExpr_params egg_CallExpr_params
#endif
#ifndef IdExpr_id
#define IdExpr_id egg_IdExpr_id
#endif
#ifndef Statement_src_info
#define Statement_src_info egg_Statement_src_info
#endif
#ifndef Statement_srcinfo
#define Statement_srcinfo egg_Statement_srcinfo
#endif
#ifndef Statement_loc
#define Statement_loc egg_Statement_loc
#endif
#ifndef Statement__num
#define Statement__num egg_Statement__num
#endif
#ifndef Statement_scope
#define Statement_scope egg_Statement_scope
#endif
#ifndef Statement_old_scope
#define Statement_old_scope egg_Statement_old_scope
#endif
#ifndef Statement_fatal
#define Statement_fatal egg_Statement_fatal
#endif
#ifndef Statement_id
#define Statement_id egg_Statement_id
#endif
#ifndef Message_msgs
#define Message_msgs egg_Message_msgs
#endif
#ifndef Group_type
#define Group_type egg_Group_type
#endif
#ifndef Group_group
#define Group_group egg_Group_group
#endif
#ifndef Group_decls
#define Group_decls egg_Group_decls
#endif
#ifndef Group_stats
#define Group_stats egg_Group_stats
#endif
#ifndef Statement_parent
#define Statement_parent egg_Statement_parent
#endif
#ifndef SubMessage_src_info
#define SubMessage_src_info egg_SubMessage_src_info
#endif
#ifndef SubMessage_srcinfo
#define SubMessage_srcinfo egg_SubMessage_srcinfo
#endif
#ifndef SubMessage_loc
#define SubMessage_loc egg_SubMessage_loc
#endif
#ifndef SubMessage_kind
#define SubMessage_kind egg_SubMessage_kind
#endif
#ifndef SubMessage_msg
#define SubMessage_msg egg_SubMessage_msg
#endif
#ifndef Scope_next
#define Scope_next egg_Scope_next
#endif
#ifndef Scope__self
#define Scope__self egg_Scope__self
#endif
#ifndef Scope__end
#define Scope__end egg_Scope__end
#endif
#ifndef GroupScope_data
#define GroupScope_data egg_GroupScope_data
#endif
#ifndef List_Declaration_data
#define List_Declaration_data List_egg_Declaration_data
#endif
#ifndef List_Declaration_next
#define List_Declaration_next List_egg_Declaration_next
#endif
#ifndef List_SubMessage_data
#define List_SubMessage_data List_egg_SubMessage_data
#endif
#ifndef List_SubMessage_next
#define List_SubMessage_next List_egg_SubMessage_next
#endif
#ifndef List_Expression_data
#define List_Expression_data List_egg_Expression_data
#endif
#ifndef List_Expression_next
#define List_Expression_next List_egg_Expression_next
#endif
#ifndef List_String_data
#define List_String_data List_String_data
#endif
#ifndef List_String_next
#define List_String_next List_String_next
#endif
#ifndef List_Statement_data
#define List_Statement_data List_egg_Statement_data
#endif
#ifndef List_Statement_next
#define List_Statement_next List_egg_Statement_next
#endif

/* Abbreviations for egg.h */

#ifndef Create_egg
#define Create_egg Create_egg_egg
#endif
#ifndef Create_Uses
#define Create_Uses Create_egg_Uses
#endif
#ifndef Create_Declaration
#define Create_Declaration Create_egg_Declaration
#endif
#ifndef Create_IdExpr
#define Create_IdExpr Create_egg_IdExpr
#endif
#ifndef Create_CallExpr
#define Create_CallExpr Create_egg_CallExpr
#endif
#ifndef Create_StringExpr
#define Create_StringExpr Create_egg_StringExpr
#endif
#ifndef Create_Group
#define Create_Group Create_egg_Group
#endif
#ifndef Create_Message
#define Create_Message Create_egg_Message
#endif
#ifndef Create_SubMessage
#define Create_SubMessage Create_egg_SubMessage
#endif
#ifndef Create_GroupScope
#define Create_GroupScope Create_egg_GroupScope
#endif
#ifndef Create_List_Declaration
#define Create_List_Declaration Create_List_egg_Declaration
#endif
#ifndef List_Declaration_size
#define List_Declaration_size List_egg_Declaration_size
#endif
#ifndef Create_List_SubMessage
#define Create_List_SubMessage Create_List_egg_SubMessage
#endif
#ifndef List_SubMessage_size
#define List_SubMessage_size List_egg_SubMessage_size
#endif
#ifndef Create_List_Expression
#define Create_List_Expression Create_List_egg_Expression
#endif
#ifndef List_Expression_size
#define List_Expression_size List_egg_Expression_size
#endif
#ifndef Create_List_Statement
#define Create_List_Statement Create_List_egg_Statement
#endif
#ifndef List_Statement_size
#define List_Statement_size List_egg_Statement_size
#endif
#ifndef s_TraverseTable
#define s_TraverseTable s_egg_TraverseTable
#endif
#ifndef TraverseTable
#define TraverseTable egg_TraverseTable
#endif
#ifndef Traverse_MessageKind
#define Traverse_MessageKind Traverse_egg_MessageKind
#endif
#ifndef Traverse_egg
#define Traverse_egg Traverse_egg_egg
#endif
#ifndef Traverse_Uses
#define Traverse_Uses Traverse_egg_Uses
#endif
#ifndef Traverse_Declaration
#define Traverse_Declaration Traverse_egg_Declaration
#endif
#ifndef Traverse_Expression
#define Traverse_Expression Traverse_egg_Expression
#endif
#ifndef Traverse_Statement
#define Traverse_Statement Traverse_egg_Statement
#endif
#ifndef Traverse_SubMessage
#define Traverse_SubMessage Traverse_egg_SubMessage
#endif
#ifndef Traverse_Scope
#define Traverse_Scope Traverse_egg_Scope
#endif
#ifndef Traverse_List_Declaration
#define Traverse_List_Declaration Traverse_List_egg_Declaration
#endif
#ifndef Traverse_List_SubMessage
#define Traverse_List_SubMessage Traverse_List_egg_SubMessage
#endif
#ifndef Traverse_List_Expression
#define Traverse_List_Expression Traverse_List_egg_Expression
#endif
#ifndef Traverse_List_Statement
#define Traverse_List_Statement Traverse_List_egg_Statement
#endif
#ifndef s_void_TraverseTable
#define s_void_TraverseTable s_void_egg_TraverseTable
#endif
#ifndef void_TraverseTable
#define void_TraverseTable void_egg_TraverseTable
#endif
#ifndef Traverse_void_MessageKind
#define Traverse_void_MessageKind Traverse_void_egg_MessageKind
#endif
#ifndef Traverse_void_egg
#define Traverse_void_egg Traverse_void_egg_egg
#endif
#ifndef Traverse_void_Uses
#define Traverse_void_Uses Traverse_void_egg_Uses
#endif
#ifndef Traverse_void_Declaration
#define Traverse_void_Declaration Traverse_void_egg_Declaration
#endif
#ifndef Traverse_void_Expression
#define Traverse_void_Expression Traverse_void_egg_Expression
#endif
#ifndef Traverse_void_Statement
#define Traverse_void_Statement Traverse_void_egg_Statement
#endif
#ifndef Traverse_void_SubMessage
#define Traverse_void_SubMessage Traverse_void_egg_SubMessage
#endif
#ifndef Traverse_void_Scope
#define Traverse_void_Scope Traverse_void_egg_Scope
#endif
#ifndef Traverse_void_List_Declaration
#define Traverse_void_List_Declaration Traverse_void_List_egg_Declaration
#endif
#ifndef Traverse_void_List_SubMessage
#define Traverse_void_List_SubMessage Traverse_void_List_egg_SubMessage
#endif
#ifndef Traverse_void_List_Expression
#define Traverse_void_List_Expression Traverse_void_List_egg_Expression
#endif
#ifndef Traverse_void_List_Statement
#define Traverse_void_List_Statement Traverse_void_List_egg_Statement
#endif
#ifndef s_copy_TraverseTable
#define s_copy_TraverseTable s_copy_egg_TraverseTable
#endif
#ifndef copy_TraverseTable
#define copy_TraverseTable copy_egg_TraverseTable
#endif
#ifndef Traverse_copy_MessageKind
#define Traverse_copy_MessageKind Traverse_copy_egg_MessageKind
#endif
#ifndef COPY_MessageKind
#define COPY_MessageKind COPY_egg_MessageKind
#endif
#ifndef copy_actions
#define copy_actions egg_copy_actions
#endif
#ifndef Traverse_copy_egg
#define Traverse_copy_egg Traverse_copy_egg_egg
#endif
#ifndef COPY_egg
#define COPY_egg COPY_egg_egg
#endif
#ifndef Traverse_copy_Uses
#define Traverse_copy_Uses Traverse_copy_egg_Uses
#endif
#ifndef COPY_Uses
#define COPY_Uses COPY_egg_Uses
#endif
#ifndef Traverse_copy_Declaration
#define Traverse_copy_Declaration Traverse_copy_egg_Declaration
#endif
#ifndef COPY_Declaration
#define COPY_Declaration COPY_egg_Declaration
#endif
#ifndef Traverse_copy_Expression
#define Traverse_copy_Expression Traverse_copy_egg_Expression
#endif
#ifndef COPY_Expression
#define COPY_Expression COPY_egg_Expression
#endif
#ifndef Traverse_copy_Statement
#define Traverse_copy_Statement Traverse_copy_egg_Statement
#endif
#ifndef COPY_Statement
#define COPY_Statement COPY_egg_Statement
#endif
#ifndef Traverse_copy_SubMessage
#define Traverse_copy_SubMessage Traverse_copy_egg_SubMessage
#endif
#ifndef COPY_SubMessage
#define COPY_SubMessage COPY_egg_SubMessage
#endif
#ifndef Traverse_copy_Scope
#define Traverse_copy_Scope Traverse_copy_egg_Scope
#endif
#ifndef COPY_Scope
#define COPY_Scope COPY_egg_Scope
#endif
#ifndef Traverse_copy_List_Declaration
#define Traverse_copy_List_Declaration Traverse_copy_List_egg_Declaration
#endif
#ifndef COPY_List_Declaration
#define COPY_List_Declaration COPY_egg_List_Declaration
#endif
#ifndef Traverse_copy_List_SubMessage
#define Traverse_copy_List_SubMessage Traverse_copy_List_egg_SubMessage
#endif
#ifndef COPY_List_SubMessage
#define COPY_List_SubMessage COPY_egg_List_SubMessage
#endif
#ifndef Traverse_copy_List_Expression
#define Traverse_copy_List_Expression Traverse_copy_List_egg_Expression
#endif
#ifndef COPY_List_Expression
#define COPY_List_Expression COPY_egg_List_Expression
#endif
#ifndef Traverse_copy_List_Statement
#define Traverse_copy_List_Statement Traverse_copy_List_egg_Statement
#endif
#ifndef COPY_List_Statement
#define COPY_List_Statement COPY_egg_List_Statement
#endif
#ifndef s_compare_TraverseTable
#define s_compare_TraverseTable s_compare_egg_TraverseTable
#endif
#ifndef compare_TraverseTable
#define compare_TraverseTable compare_egg_TraverseTable
#endif
#ifndef Traverse_compare_MessageKind
#define Traverse_compare_MessageKind Traverse_compare_egg_MessageKind
#endif
#ifndef Traverse_compare_egg
#define Traverse_compare_egg Traverse_compare_egg_egg
#endif
#ifndef Traverse_compare_Uses
#define Traverse_compare_Uses Traverse_compare_egg_Uses
#endif
#ifndef Traverse_compare_Declaration
#define Traverse_compare_Declaration Traverse_compare_egg_Declaration
#endif
#ifndef Traverse_compare_Expression
#define Traverse_compare_Expression Traverse_compare_egg_Expression
#endif
#ifndef Traverse_compare_Statement
#define Traverse_compare_Statement Traverse_compare_egg_Statement
#endif
#ifndef Traverse_compare_SubMessage
#define Traverse_compare_SubMessage Traverse_compare_egg_SubMessage
#endif
#ifndef Traverse_compare_Scope
#define Traverse_compare_Scope Traverse_compare_egg_Scope
#endif
#ifndef Traverse_compare_List_Declaration
#define Traverse_compare_List_Declaration Traverse_compare_List_egg_Declaration
#endif
#ifndef Traverse_compare_List_SubMessage
#define Traverse_compare_List_SubMessage Traverse_compare_List_egg_SubMessage
#endif
#ifndef Traverse_compare_List_Expression
#define Traverse_compare_List_Expression Traverse_compare_List_egg_Expression
#endif
#ifndef Traverse_compare_List_Statement
#define Traverse_compare_List_Statement Traverse_compare_List_egg_Statement
#endif
#ifndef fill_table
#define fill_table egg_fill_table
#endif
#ifndef void_fill_table
#define void_fill_table void_egg_fill_table
#endif
#ifndef copy_fill_table
#define copy_fill_table copy_egg_fill_table
#endif
#ifndef compare_fill_table
#define compare_fill_table compare_egg_fill_table
#endif
#ifndef scope_actions
#define scope_actions egg_scope_actions
#endif
#ifndef defining_actions
#define defining_actions egg_defining_actions
#endif
#ifndef applied_actions
#define applied_actions egg_applied_actions
#endif
#ifndef check_actions
#define check_actions egg_check_actions
#endif
#ifndef print_actions
#define print_actions egg_print_actions
#endif
#ifndef compare_actions
#define compare_actions egg_compare_actions
#endif
#ifndef NameSpaces
#define NameSpaces egg_NameSpaces
#endif
#ifndef namespaces
#define namespaces egg_namespaces
#endif
#ifndef DefaultNameSpace
#define DefaultNameSpace egg_DefaultNameSpace
#endif
#ifndef NUM_NAMESPACES
#define NUM_NAMESPACES egg_NUM_NAMESPACES
#endif
#ifndef Expression_tag_names
#define Expression_tag_names egg_Expression_tag_names
#endif
#ifndef Statement_tag_names
#define Statement_tag_names egg_Statement_tag_names
#endif
#ifndef MessageKind_names
#define MessageKind_names egg_MessageKind_names
#endif
#ifndef Scope_tag_names
#define Scope_tag_names egg_Scope_tag_names
#endif

/* Abbreviations for egg_parse.h */

#ifndef Parse_egg
#define Parse_egg Parse_egg_egg
#endif
#ifndef Parse_Uses
#define Parse_Uses Parse_egg_Uses
#endif
#ifndef Parse_Strings
#define Parse_Strings Parse_egg_Strings
#endif
#ifndef Parse_Declarations
#define Parse_Declarations Parse_egg_Declarations
#endif
#ifndef Parse_Declaration
#define Parse_Declaration Parse_egg_Declaration
#endif
#ifndef Parse_Expression
#define Parse_Expression Parse_egg_Expression
#endif
#ifndef Parse_Params
#define Parse_Params Parse_egg_Params
#endif
#ifndef Parse_Statements
#define Parse_Statements Parse_egg_Statements
#endif
#ifndef Parse_Statement
#define Parse_Statement Parse_egg_Statement
#endif
#ifndef Parse_MessageKind
#define Parse_MessageKind Parse_egg_MessageKind
#endif
#ifndef Parse_Message
#define Parse_Message Parse_egg_Message
#endif
#ifndef Parse_SubMessages
#define Parse_SubMessages Parse_egg_SubMessages
#endif
#ifndef Parse_SubMessage
#define Parse_SubMessage Parse_egg_SubMessage
#endif
#ifndef Parse_Group
#define Parse_Group Parse_egg_Group
#endif
#ifndef Parse_OPTMORE_Group
#define Parse_OPTMORE_Group Parse_egg_OPTMORE_Group
#endif
#ifndef Parse_ALT_Stringsym_SEP_commasym
#define Parse_ALT_Stringsym_SEP_commasym Parse_egg_ALT_Stringsym_SEP_commasym
#endif
#ifndef Parse_OPTMORE_Declaration
#define Parse_OPTMORE_Declaration Parse_egg_OPTMORE_Declaration
#endif
#ifndef Parse_MORE_Expression
#define Parse_MORE_Expression Parse_egg_MORE_Expression
#endif
#ifndef Parse_ALT_Expression_SEP_commasym
#define Parse_ALT_Expression_SEP_commasym Parse_egg_ALT_Expression_SEP_commasym
#endif
#ifndef Parse_OPTMORE_Statement
#define Parse_OPTMORE_Statement Parse_egg_OPTMORE_Statement
#endif
#ifndef Parse_ALT_SubMessage_SEP_commasym
#define Parse_ALT_SubMessage_SEP_commasym Parse_egg_ALT_SubMessage_SEP_commasym
#endif
#ifndef Parse_state_egg
#define Parse_state_egg Parse_state_egg_egg
#endif
#ifndef parse_string
#define parse_string egg_parse_string
#endif
#ifndef Parse_state_Uses
#define Parse_state_Uses Parse_state_egg_Uses
#endif
#ifndef Parse_state_Strings
#define Parse_state_Strings Parse_state_egg_Strings
#endif
#ifndef Parse_state_Declarations
#define Parse_state_Declarations Parse_state_egg_Declarations
#endif
#ifndef Parse_state_Declaration
#define Parse_state_Declaration Parse_state_egg_Declaration
#endif
#ifndef Parse_state_Expression
#define Parse_state_Expression Parse_state_egg_Expression
#endif
#ifndef Parse_state_Params
#define Parse_state_Params Parse_state_egg_Params
#endif
#ifndef Parse_state_Statements
#define Parse_state_Statements Parse_state_egg_Statements
#endif
#ifndef Parse_state_Statement
#define Parse_state_Statement Parse_state_egg_Statement
#endif
#ifndef Parse_state_MessageKind
#define Parse_state_MessageKind Parse_state_egg_MessageKind
#endif
#ifndef Parse_state_Message
#define Parse_state_Message Parse_state_egg_Message
#endif
#ifndef Parse_state_SubMessages
#define Parse_state_SubMessages Parse_state_egg_SubMessages
#endif
#ifndef Parse_state_SubMessage
#define Parse_state_SubMessage Parse_state_egg_SubMessage
#endif
#ifndef Parse_state_Group
#define Parse_state_Group Parse_state_egg_Group
#endif
#ifndef Parse_state_OPTMORE_Group
#define Parse_state_OPTMORE_Group Parse_state_egg_OPTMORE_Group
#endif
#ifndef Parse_state_ALT_Stringsym_SEP_commasym
#define Parse_state_ALT_Stringsym_SEP_commasym Parse_state_egg_ALT_Stringsym_SEP_commasym
#endif
#ifndef Parse_state_OPTMORE_Declaration
#define Parse_state_OPTMORE_Declaration Parse_state_egg_OPTMORE_Declaration
#endif
#ifndef Parse_state_MORE_Expression
#define Parse_state_MORE_Expression Parse_state_egg_MORE_Expression
#endif
#ifndef Parse_state_ALT_Expression_SEP_commasym
#define Parse_state_ALT_Expression_SEP_commasym Parse_state_egg_ALT_Expression_SEP_commasym
#endif
#ifndef Parse_state_OPTMORE_Statement
#define Parse_state_OPTMORE_Statement Parse_state_egg_OPTMORE_Statement
#endif
#ifndef Parse_state_ALT_SubMessage_SEP_commasym
#define Parse_state_ALT_SubMessage_SEP_commasym Parse_state_egg_ALT_SubMessage_SEP_commasym
#endif
#ifndef Print_egg
#define Print_egg Print_egg_egg
#endif
#ifndef PRINT_egg
#define PRINT_egg PRINT_egg_egg
#endif
#ifndef Text_egg
#define Text_egg Text_egg_egg
#endif
#ifndef Print_Uses
#define Print_Uses Print_egg_Uses
#endif
#ifndef PRINT_Uses
#define PRINT_Uses PRINT_egg_Uses
#endif
#ifndef Text_Uses
#define Text_Uses Text_egg_Uses
#endif
#ifndef Print_Declaration
#define Print_Declaration Print_egg_Declaration
#endif
#ifndef PRINT_Declaration
#define PRINT_Declaration PRINT_egg_Declaration
#endif
#ifndef Text_Declaration
#define Text_Declaration Text_egg_Declaration
#endif
#ifndef Print_Expression
#define Print_Expression Print_egg_Expression
#endif
#ifndef PRINT_Expression
#define PRINT_Expression PRINT_egg_Expression
#endif
#ifndef Text_Expression
#define Text_Expression Text_egg_Expression
#endif
#ifndef Print_Statement
#define Print_Statement Print_egg_Statement
#endif
#ifndef PRINT_Statement
#define PRINT_Statement PRINT_egg_Statement
#endif
#ifndef Text_Statement
#define Text_Statement Text_egg_Statement
#endif
#ifndef Print_SubMessage
#define Print_SubMessage Print_egg_SubMessage
#endif
#ifndef PRINT_SubMessage
#define PRINT_SubMessage PRINT_egg_SubMessage
#endif
#ifndef Text_SubMessage
#define Text_SubMessage Text_egg_SubMessage
#endif
#ifndef Print_Scope
#define Print_Scope Print_egg_Scope
#endif
#ifndef PRINT_Scope
#define PRINT_Scope PRINT_egg_Scope
#endif
#ifndef Text_Scope
#define Text_Scope Text_egg_Scope
#endif
#ifndef Print_List_Declaration
#define Print_List_Declaration Print_List_egg_Declaration
#endif
#ifndef PRINT_List_Declaration
#define PRINT_List_Declaration PRINT_List_egg_Declaration
#endif
#ifndef Text_List_Declaration
#define Text_List_Declaration Text_List_egg_Declaration
#endif
#ifndef Print_List_SubMessage
#define Print_List_SubMessage Print_List_egg_SubMessage
#endif
#ifndef PRINT_List_SubMessage
#define PRINT_List_SubMessage PRINT_List_egg_SubMessage
#endif
#ifndef Text_List_SubMessage
#define Text_List_SubMessage Text_List_egg_SubMessage
#endif
#ifndef Print_List_Expression
#define Print_List_Expression Print_List_egg_Expression
#endif
#ifndef PRINT_List_Expression
#define PRINT_List_Expression PRINT_List_egg_Expression
#endif
#ifndef Text_List_Expression
#define Text_List_Expression Text_List_egg_Expression
#endif
#ifndef Print_List_Statement
#define Print_List_Statement Print_List_egg_Statement
#endif
#ifndef PRINT_List_Statement
#define PRINT_List_Statement PRINT_List_egg_Statement
#endif
#ifndef Text_List_Statement
#define Text_List_Statement Text_List_egg_Statement
#endif
#ifndef Print_MessageKind
#define Print_MessageKind Print_egg_MessageKind
#endif
#ifndef PRINT_MessageKind
#define PRINT_MessageKind PRINT_egg_MessageKind
#endif
#ifndef Text_MessageKind
#define Text_MessageKind Text_egg_MessageKind
#endif
#endif /* egg_NO_DEFS */

