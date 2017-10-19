#ifndef Diagrams_NO_DEFS
#define _Diagrams_h

#ifndef Compound_kind
#define Compound_kind Diagrams_Compound_kind
#endif
#ifndef AltBlock_kind
#define AltBlock_kind Diagrams_AltBlock_kind
#endif
#ifndef AndBlock_kind
#define AndBlock_kind Diagrams_AndBlock_kind
#endif
#ifndef OrBlock_kind
#define OrBlock_kind Diagrams_OrBlock_kind
#endif
#ifndef Text_kind
#define Text_kind Diagrams_Text_kind
#endif
#ifndef Arrow_kind
#define Arrow_kind Diagrams_Arrow_kind
#endif
#ifndef Line_kind
#define Line_kind Diagrams_Line_kind
#endif
#ifndef Curve_kind
#define Curve_kind Diagrams_Curve_kind
#endif
#ifndef Box_kind
#define Box_kind Diagrams_Box_kind
#endif
#ifndef Empty_kind
#define Empty_kind Diagrams_Empty_kind
#endif
#ifndef NUM_Picture_tag
#define NUM_Picture_tag NUM_Diagrams_Picture_tag
#endif
#ifndef Picture_tag
#define Picture_tag Diagrams_Picture_tag
#endif
#ifndef Center
#define Center Diagrams_Center
#endif
#ifndef Down
#define Down Diagrams_Down
#endif
#ifndef Up
#define Up Diagrams_Up
#endif
#ifndef Right
#define Right Diagrams_Right
#endif
#ifndef Left
#define Left Diagrams_Left
#endif
#ifndef NUM_Direction
#define NUM_Direction NUM_Diagrams_Direction
#endif
#ifndef Direction
#define Direction Diagrams_Direction
#endif
#ifndef Diagrams
#define Diagrams Diagrams_Diagrams
#endif
#ifndef Empty
#define Empty Diagrams_Empty
#endif
#ifndef Box
#define Box Diagrams_Box
#endif
#ifndef Curve
#define Curve Diagrams_Curve
#endif
#ifndef Line
#define Line Diagrams_Line
#endif
#ifndef Arrow
#define Arrow Diagrams_Arrow
#endif
#ifndef Text
#define Text Diagrams_Text
#endif
#ifndef OrBlock
#define OrBlock Diagrams_OrBlock
#endif
#ifndef AndBlock
#define AndBlock Diagrams_AndBlock
#endif
#ifndef AltBlock
#define AltBlock Diagrams_AltBlock
#endif
#ifndef Compound
#define Compound Diagrams_Compound
#endif
#ifndef Picture
#define Picture Diagrams_Picture
#endif
#ifndef Scope
#define Scope Diagrams_Scope
#endif
#ifndef List_Picture
#define List_Picture List_Diagrams_Picture
#endif
#ifndef List_Direction
#define List_Direction List_Diagrams_Direction
#endif
#ifndef Diagrams_src_info
#define Diagrams_src_info Diagrams_Diagrams_src_info
#endif
#ifndef Diagrams_srcinfo
#define Diagrams_srcinfo Diagrams_Diagrams_srcinfo
#endif
#ifndef Diagrams_loc
#define Diagrams_loc Diagrams_Diagrams_loc
#endif
#ifndef Diagrams_pics
#define Diagrams_pics Diagrams_Diagrams_pics
#endif
#ifndef Picture_src_info
#define Picture_src_info Diagrams_Picture_src_info
#endif
#ifndef Picture_srcinfo
#define Picture_srcinfo Diagrams_Picture_srcinfo
#endif
#ifndef Picture_loc
#define Picture_loc Diagrams_Picture_loc
#endif
#ifndef Picture_x
#define Picture_x Diagrams_Picture_x
#endif
#ifndef Picture_y
#define Picture_y Diagrams_Picture_y
#endif
#ifndef Picture_w
#define Picture_w Diagrams_Picture_w
#endif
#ifndef Picture_h
#define Picture_h Diagrams_Picture_h
#endif
#ifndef Picture_d
#define Picture_d Diagrams_Picture_d
#endif
#ifndef Curve_d1
#define Curve_d1 Diagrams_Curve_d1
#endif
#ifndef Curve_d2
#define Curve_d2 Diagrams_Curve_d2
#endif
#ifndef Arrow_dir
#define Arrow_dir Diagrams_Arrow_dir
#endif
#ifndef Text_text
#define Text_text Diagrams_Text_text
#endif
#ifndef Text_font
#define Text_font Diagrams_Text_font
#endif
#ifndef OrBlock_sub
#define OrBlock_sub Diagrams_OrBlock_sub
#endif
#ifndef OrBlock_dirs
#define OrBlock_dirs Diagrams_OrBlock_dirs
#endif
#ifndef AndBlock_sub
#define AndBlock_sub Diagrams_AndBlock_sub
#endif
#ifndef AndBlock_dirs
#define AndBlock_dirs Diagrams_AndBlock_dirs
#endif
#ifndef AltBlock_a
#define AltBlock_a Diagrams_AltBlock_a
#endif
#ifndef AltBlock_b
#define AltBlock_b Diagrams_AltBlock_b
#endif
#ifndef AltBlock_turn_left
#define AltBlock_turn_left Diagrams_AltBlock_turn_left
#endif
#ifndef Compound_sub
#define Compound_sub Diagrams_Compound_sub
#endif
#ifndef Scope_next
#define Scope_next Diagrams_Scope_next
#endif
#ifndef List_Direction_data
#define List_Direction_data List_Diagrams_Direction_data
#endif
#ifndef List_Direction_next
#define List_Direction_next List_Diagrams_Direction_next
#endif
#ifndef List_Picture_data
#define List_Picture_data List_Diagrams_Picture_data
#endif
#ifndef List_Picture_next
#define List_Picture_next List_Diagrams_Picture_next
#endif

/* Abbreviations for Diagrams.h */

#ifndef Create_Diagrams
#define Create_Diagrams Create_Diagrams_Diagrams
#endif
#ifndef Create_Compound
#define Create_Compound Create_Diagrams_Compound
#endif
#ifndef Create_AltBlock
#define Create_AltBlock Create_Diagrams_AltBlock
#endif
#ifndef Create_AndBlock
#define Create_AndBlock Create_Diagrams_AndBlock
#endif
#ifndef Create_OrBlock
#define Create_OrBlock Create_Diagrams_OrBlock
#endif
#ifndef Create_Text
#define Create_Text Create_Diagrams_Text
#endif
#ifndef Create_Arrow
#define Create_Arrow Create_Diagrams_Arrow
#endif
#ifndef Create_Line
#define Create_Line Create_Diagrams_Line
#endif
#ifndef Create_Curve
#define Create_Curve Create_Diagrams_Curve
#endif
#ifndef Create_Box
#define Create_Box Create_Diagrams_Box
#endif
#ifndef Create_Empty
#define Create_Empty Create_Diagrams_Empty
#endif
#ifndef Create_Scope
#define Create_Scope Create_Diagrams_Scope
#endif
#ifndef Create_List_Direction
#define Create_List_Direction Create_List_Diagrams_Direction
#endif
#ifndef List_Direction_size
#define List_Direction_size List_Diagrams_Direction_size
#endif
#ifndef Create_List_Picture
#define Create_List_Picture Create_List_Diagrams_Picture
#endif
#ifndef List_Picture_size
#define List_Picture_size List_Diagrams_Picture_size
#endif
#ifndef s_TraverseTable
#define s_TraverseTable s_Diagrams_TraverseTable
#endif
#ifndef TraverseTable
#define TraverseTable Diagrams_TraverseTable
#endif
#ifndef Traverse_Direction
#define Traverse_Direction Traverse_Diagrams_Direction
#endif
#ifndef Traverse_Diagrams
#define Traverse_Diagrams Traverse_Diagrams_Diagrams
#endif
#ifndef Traverse_Picture
#define Traverse_Picture Traverse_Diagrams_Picture
#endif
#ifndef Traverse_Scope
#define Traverse_Scope Traverse_Diagrams_Scope
#endif
#ifndef Traverse_List_Direction
#define Traverse_List_Direction Traverse_List_Diagrams_Direction
#endif
#ifndef Traverse_List_Picture
#define Traverse_List_Picture Traverse_List_Diagrams_Picture
#endif
#ifndef s_void_TraverseTable
#define s_void_TraverseTable s_void_Diagrams_TraverseTable
#endif
#ifndef void_TraverseTable
#define void_TraverseTable void_Diagrams_TraverseTable
#endif
#ifndef Traverse_void_Direction
#define Traverse_void_Direction Traverse_void_Diagrams_Direction
#endif
#ifndef Traverse_void_Diagrams
#define Traverse_void_Diagrams Traverse_void_Diagrams_Diagrams
#endif
#ifndef Traverse_void_Picture
#define Traverse_void_Picture Traverse_void_Diagrams_Picture
#endif
#ifndef Traverse_void_Scope
#define Traverse_void_Scope Traverse_void_Diagrams_Scope
#endif
#ifndef Traverse_void_List_Direction
#define Traverse_void_List_Direction Traverse_void_List_Diagrams_Direction
#endif
#ifndef Traverse_void_List_Picture
#define Traverse_void_List_Picture Traverse_void_List_Diagrams_Picture
#endif
#ifndef s_copy_TraverseTable
#define s_copy_TraverseTable s_copy_Diagrams_TraverseTable
#endif
#ifndef copy_TraverseTable
#define copy_TraverseTable copy_Diagrams_TraverseTable
#endif
#ifndef Traverse_copy_Direction
#define Traverse_copy_Direction Traverse_copy_Diagrams_Direction
#endif
#ifndef COPY_Direction
#define COPY_Direction COPY_Diagrams_Direction
#endif
#ifndef copy_actions
#define copy_actions Diagrams_copy_actions
#endif
#ifndef Traverse_copy_Diagrams
#define Traverse_copy_Diagrams Traverse_copy_Diagrams_Diagrams
#endif
#ifndef COPY_Diagrams
#define COPY_Diagrams COPY_Diagrams_Diagrams
#endif
#ifndef Traverse_copy_Picture
#define Traverse_copy_Picture Traverse_copy_Diagrams_Picture
#endif
#ifndef COPY_Picture
#define COPY_Picture COPY_Diagrams_Picture
#endif
#ifndef Traverse_copy_Scope
#define Traverse_copy_Scope Traverse_copy_Diagrams_Scope
#endif
#ifndef COPY_Scope
#define COPY_Scope COPY_Diagrams_Scope
#endif
#ifndef Traverse_copy_List_Direction
#define Traverse_copy_List_Direction Traverse_copy_List_Diagrams_Direction
#endif
#ifndef COPY_List_Direction
#define COPY_List_Direction COPY_Diagrams_List_Direction
#endif
#ifndef Traverse_copy_List_Picture
#define Traverse_copy_List_Picture Traverse_copy_List_Diagrams_Picture
#endif
#ifndef COPY_List_Picture
#define COPY_List_Picture COPY_Diagrams_List_Picture
#endif
#ifndef s_compare_TraverseTable
#define s_compare_TraverseTable s_compare_Diagrams_TraverseTable
#endif
#ifndef compare_TraverseTable
#define compare_TraverseTable compare_Diagrams_TraverseTable
#endif
#ifndef Traverse_compare_Direction
#define Traverse_compare_Direction Traverse_compare_Diagrams_Direction
#endif
#ifndef Traverse_compare_Diagrams
#define Traverse_compare_Diagrams Traverse_compare_Diagrams_Diagrams
#endif
#ifndef Traverse_compare_Picture
#define Traverse_compare_Picture Traverse_compare_Diagrams_Picture
#endif
#ifndef Traverse_compare_Scope
#define Traverse_compare_Scope Traverse_compare_Diagrams_Scope
#endif
#ifndef Traverse_compare_List_Direction
#define Traverse_compare_List_Direction Traverse_compare_List_Diagrams_Direction
#endif
#ifndef Traverse_compare_List_Picture
#define Traverse_compare_List_Picture Traverse_compare_List_Diagrams_Picture
#endif
#ifndef fill_table
#define fill_table Diagrams_fill_table
#endif
#ifndef void_fill_table
#define void_fill_table void_Diagrams_fill_table
#endif
#ifndef copy_fill_table
#define copy_fill_table copy_Diagrams_fill_table
#endif
#ifndef compare_fill_table
#define compare_fill_table compare_Diagrams_fill_table
#endif
#ifndef scope_actions
#define scope_actions Diagrams_scope_actions
#endif
#ifndef defining_actions
#define defining_actions Diagrams_defining_actions
#endif
#ifndef applied_actions
#define applied_actions Diagrams_applied_actions
#endif
#ifndef check_actions
#define check_actions Diagrams_check_actions
#endif
#ifndef print_actions
#define print_actions Diagrams_print_actions
#endif
#ifndef compare_actions
#define compare_actions Diagrams_compare_actions
#endif
#ifndef NameSpaces
#define NameSpaces Diagrams_NameSpaces
#endif
#ifndef namespaces
#define namespaces Diagrams_namespaces
#endif
#ifndef DefaultNameSpace
#define DefaultNameSpace Diagrams_DefaultNameSpace
#endif
#ifndef NUM_NAMESPACES
#define NUM_NAMESPACES Diagrams_NUM_NAMESPACES
#endif
#ifndef Direction_names
#define Direction_names Diagrams_Direction_names
#endif
#ifndef Picture_tag_names
#define Picture_tag_names Diagrams_Picture_tag_names
#endif

/* Abbreviations for Diagrams_parse.h */

#ifndef Parse_Diagrams
#define Parse_Diagrams Parse_Diagrams_Diagrams
#endif
#ifndef Parse_Direction
#define Parse_Direction Parse_Diagrams_Direction
#endif
#ifndef Parse_Picture
#define Parse_Picture Parse_Diagrams_Picture
#endif
#ifndef Parse_OPTMORE_Picture
#define Parse_OPTMORE_Picture Parse_Diagrams_OPTMORE_Picture
#endif
#ifndef Parse_MORE_Picture
#define Parse_MORE_Picture Parse_Diagrams_MORE_Picture
#endif
#ifndef Parse_state_Diagrams
#define Parse_state_Diagrams Parse_state_Diagrams_Diagrams
#endif
#ifndef parse_string
#define parse_string Diagrams_parse_string
#endif
#ifndef Parse_state_Direction
#define Parse_state_Direction Parse_state_Diagrams_Direction
#endif
#ifndef Parse_state_Picture
#define Parse_state_Picture Parse_state_Diagrams_Picture
#endif
#ifndef Parse_state_OPTMORE_Picture
#define Parse_state_OPTMORE_Picture Parse_state_Diagrams_OPTMORE_Picture
#endif
#ifndef Parse_state_MORE_Picture
#define Parse_state_MORE_Picture Parse_state_Diagrams_MORE_Picture
#endif
#ifndef Print_Diagrams
#define Print_Diagrams Print_Diagrams_Diagrams
#endif
#ifndef PRINT_Diagrams
#define PRINT_Diagrams PRINT_Diagrams_Diagrams
#endif
#ifndef Print_Picture
#define Print_Picture Print_Diagrams_Picture
#endif
#ifndef PRINT_Picture
#define PRINT_Picture PRINT_Diagrams_Picture
#endif
#ifndef Print_Scope
#define Print_Scope Print_Diagrams_Scope
#endif
#ifndef PRINT_Scope
#define PRINT_Scope PRINT_Diagrams_Scope
#endif
#ifndef Print_List_Direction
#define Print_List_Direction Print_List_Diagrams_Direction
#endif
#ifndef PRINT_List_Direction
#define PRINT_List_Direction PRINT_List_Diagrams_Direction
#endif
#ifndef Print_List_Picture
#define Print_List_Picture Print_List_Diagrams_Picture
#endif
#ifndef PRINT_List_Picture
#define PRINT_List_Picture PRINT_List_Diagrams_Picture
#endif
#ifndef Print_Direction
#define Print_Direction Print_Diagrams_Direction
#endif
#ifndef PRINT_Direction
#define PRINT_Direction PRINT_Diagrams_Direction
#endif
#endif /* Diagrams_NO_DEFS */

