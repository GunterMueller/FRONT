#ifndef Pictures_NO_DEFS
#define _Pictures_h

#ifndef Compound_kind
#define Compound_kind Pictures_Compound_kind
#endif
#ifndef AltBlock_kind
#define AltBlock_kind Pictures_AltBlock_kind
#endif
#ifndef AndBlock_kind
#define AndBlock_kind Pictures_AndBlock_kind
#endif
#ifndef OrBlock_kind
#define OrBlock_kind Pictures_OrBlock_kind
#endif
#ifndef Text_kind
#define Text_kind Pictures_Text_kind
#endif
#ifndef Arrow_kind
#define Arrow_kind Pictures_Arrow_kind
#endif
#ifndef Line_kind
#define Line_kind Pictures_Line_kind
#endif
#ifndef Curve_kind
#define Curve_kind Pictures_Curve_kind
#endif
#ifndef Arc_kind
#define Arc_kind Pictures_Arc_kind
#endif
#ifndef Circle_kind
#define Circle_kind Pictures_Circle_kind
#endif
#ifndef Box_kind
#define Box_kind Pictures_Box_kind
#endif
#ifndef Empty_kind
#define Empty_kind Pictures_Empty_kind
#endif
#ifndef NUM_Picture_tag
#define NUM_Picture_tag NUM_Pictures_Picture_tag
#endif
#ifndef Picture_tag
#define Picture_tag Pictures_Picture_tag
#endif
#ifndef Center
#define Center Pictures_Center
#endif
#ifndef Down
#define Down Pictures_Down
#endif
#ifndef Up
#define Up Pictures_Up
#endif
#ifndef Right
#define Right Pictures_Right
#endif
#ifndef Left
#define Left Pictures_Left
#endif
#ifndef NUM_Direction
#define NUM_Direction NUM_Pictures_Direction
#endif
#ifndef Direction
#define Direction Pictures_Direction
#endif
#ifndef Pictures
#define Pictures Pictures_Pictures
#endif
#ifndef Empty
#define Empty Pictures_Empty
#endif
#ifndef Box
#define Box Pictures_Box
#endif
#ifndef Circle
#define Circle Pictures_Circle
#endif
#ifndef Arc
#define Arc Pictures_Arc
#endif
#ifndef Curve
#define Curve Pictures_Curve
#endif
#ifndef Line
#define Line Pictures_Line
#endif
#ifndef Arrow
#define Arrow Pictures_Arrow
#endif
#ifndef Text
#define Text Pictures_Text
#endif
#ifndef OrBlock
#define OrBlock Pictures_OrBlock
#endif
#ifndef AndBlock
#define AndBlock Pictures_AndBlock
#endif
#ifndef AltBlock
#define AltBlock Pictures_AltBlock
#endif
#ifndef Compound
#define Compound Pictures_Compound
#endif
#ifndef Picture
#define Picture Pictures_Picture
#endif
#ifndef Scope
#define Scope Pictures_Scope
#endif
#ifndef List_Picture
#define List_Picture List_Pictures_Picture
#endif
#ifndef List_Direction
#define List_Direction List_Pictures_Direction
#endif
#ifndef Pictures_src_info
#define Pictures_src_info Pictures_Pictures_src_info
#endif
#ifndef Pictures_srcinfo
#define Pictures_srcinfo Pictures_Pictures_srcinfo
#endif
#ifndef Pictures_loc
#define Pictures_loc Pictures_Pictures_loc
#endif
#ifndef Pictures_hook
#define Pictures_hook Pictures_Pictures_hook
#endif
#ifndef Pictures_pics
#define Pictures_pics Pictures_Pictures_pics
#endif
#ifndef Picture_src_info
#define Picture_src_info Pictures_Picture_src_info
#endif
#ifndef Picture_srcinfo
#define Picture_srcinfo Pictures_Picture_srcinfo
#endif
#ifndef Picture_loc
#define Picture_loc Pictures_Picture_loc
#endif
#ifndef Picture_hook
#define Picture_hook Pictures_Picture_hook
#endif
#ifndef Picture_x
#define Picture_x Pictures_Picture_x
#endif
#ifndef Picture_y
#define Picture_y Pictures_Picture_y
#endif
#ifndef Picture_w
#define Picture_w Pictures_Picture_w
#endif
#ifndef Picture_h
#define Picture_h Pictures_Picture_h
#endif
#ifndef Picture_d
#define Picture_d Pictures_Picture_d
#endif
#ifndef Picture_scale
#define Picture_scale Pictures_Picture_scale
#endif
#ifndef Picture_phi
#define Picture_phi Pictures_Picture_phi
#endif
#ifndef Picture_fill
#define Picture_fill Pictures_Picture_fill
#endif
#ifndef Picture_dash
#define Picture_dash Pictures_Picture_dash
#endif
#ifndef Picture_with_color
#define Picture_with_color Pictures_Picture_with_color
#endif
#ifndef Arc_phi_1
#define Arc_phi_1 Pictures_Arc_phi_1
#endif
#ifndef Arc_phi_2
#define Arc_phi_2 Pictures_Arc_phi_2
#endif
#ifndef Curve_d1
#define Curve_d1 Pictures_Curve_d1
#endif
#ifndef Curve_d2
#define Curve_d2 Pictures_Curve_d2
#endif
#ifndef Arrow_dir
#define Arrow_dir Pictures_Arrow_dir
#endif
#ifndef Text_text
#define Text_text Pictures_Text_text
#endif
#ifndef Text_font
#define Text_font Pictures_Text_font
#endif
#ifndef OrBlock_sub
#define OrBlock_sub Pictures_OrBlock_sub
#endif
#ifndef OrBlock_dirs
#define OrBlock_dirs Pictures_OrBlock_dirs
#endif
#ifndef AndBlock_sub
#define AndBlock_sub Pictures_AndBlock_sub
#endif
#ifndef AndBlock_dirs
#define AndBlock_dirs Pictures_AndBlock_dirs
#endif
#ifndef AltBlock_a
#define AltBlock_a Pictures_AltBlock_a
#endif
#ifndef AltBlock_b
#define AltBlock_b Pictures_AltBlock_b
#endif
#ifndef AltBlock_turn_left
#define AltBlock_turn_left Pictures_AltBlock_turn_left
#endif
#ifndef Compound_sub
#define Compound_sub Pictures_Compound_sub
#endif
#ifndef Scope_next
#define Scope_next Pictures_Scope_next
#endif
#ifndef Scope__self
#define Scope__self Pictures_Scope__self
#endif
#ifndef Scope__end
#define Scope__end Pictures_Scope__end
#endif
#ifndef List_Direction_data
#define List_Direction_data List_Pictures_Direction_data
#endif
#ifndef List_Direction_next
#define List_Direction_next List_Pictures_Direction_next
#endif
#ifndef List_Picture_data
#define List_Picture_data List_Pictures_Picture_data
#endif
#ifndef List_Picture_next
#define List_Picture_next List_Pictures_Picture_next
#endif

/* Abbreviations for Pictures.h */

#ifndef Create_Pictures
#define Create_Pictures Create_Pictures_Pictures
#endif
#ifndef Create_Compound
#define Create_Compound Create_Pictures_Compound
#endif
#ifndef Create_AltBlock
#define Create_AltBlock Create_Pictures_AltBlock
#endif
#ifndef Create_AndBlock
#define Create_AndBlock Create_Pictures_AndBlock
#endif
#ifndef Create_OrBlock
#define Create_OrBlock Create_Pictures_OrBlock
#endif
#ifndef Create_Text
#define Create_Text Create_Pictures_Text
#endif
#ifndef Create_Arrow
#define Create_Arrow Create_Pictures_Arrow
#endif
#ifndef Create_Line
#define Create_Line Create_Pictures_Line
#endif
#ifndef Create_Curve
#define Create_Curve Create_Pictures_Curve
#endif
#ifndef Create_Arc
#define Create_Arc Create_Pictures_Arc
#endif
#ifndef Create_Circle
#define Create_Circle Create_Pictures_Circle
#endif
#ifndef Create_Box
#define Create_Box Create_Pictures_Box
#endif
#ifndef Create_Empty
#define Create_Empty Create_Pictures_Empty
#endif
#ifndef Create_Scope
#define Create_Scope Create_Pictures_Scope
#endif
#ifndef Create_List_Direction
#define Create_List_Direction Create_List_Pictures_Direction
#endif
#ifndef List_Direction_size
#define List_Direction_size List_Pictures_Direction_size
#endif
#ifndef Create_List_Picture
#define Create_List_Picture Create_List_Pictures_Picture
#endif
#ifndef List_Picture_size
#define List_Picture_size List_Pictures_Picture_size
#endif
#ifndef s_TraverseTable
#define s_TraverseTable s_Pictures_TraverseTable
#endif
#ifndef TraverseTable
#define TraverseTable Pictures_TraverseTable
#endif
#ifndef Traverse_Direction
#define Traverse_Direction Traverse_Pictures_Direction
#endif
#ifndef Traverse_Pictures
#define Traverse_Pictures Traverse_Pictures_Pictures
#endif
#ifndef Traverse_Picture
#define Traverse_Picture Traverse_Pictures_Picture
#endif
#ifndef Traverse_Scope
#define Traverse_Scope Traverse_Pictures_Scope
#endif
#ifndef Traverse_List_Direction
#define Traverse_List_Direction Traverse_List_Pictures_Direction
#endif
#ifndef Traverse_List_Picture
#define Traverse_List_Picture Traverse_List_Pictures_Picture
#endif
#ifndef s_void_TraverseTable
#define s_void_TraverseTable s_void_Pictures_TraverseTable
#endif
#ifndef void_TraverseTable
#define void_TraverseTable void_Pictures_TraverseTable
#endif
#ifndef Traverse_void_Direction
#define Traverse_void_Direction Traverse_void_Pictures_Direction
#endif
#ifndef Traverse_void_Pictures
#define Traverse_void_Pictures Traverse_void_Pictures_Pictures
#endif
#ifndef Traverse_void_Picture
#define Traverse_void_Picture Traverse_void_Pictures_Picture
#endif
#ifndef Traverse_void_Scope
#define Traverse_void_Scope Traverse_void_Pictures_Scope
#endif
#ifndef Traverse_void_List_Direction
#define Traverse_void_List_Direction Traverse_void_List_Pictures_Direction
#endif
#ifndef Traverse_void_List_Picture
#define Traverse_void_List_Picture Traverse_void_List_Pictures_Picture
#endif
#ifndef s_copy_TraverseTable
#define s_copy_TraverseTable s_copy_Pictures_TraverseTable
#endif
#ifndef copy_TraverseTable
#define copy_TraverseTable copy_Pictures_TraverseTable
#endif
#ifndef Traverse_copy_Direction
#define Traverse_copy_Direction Traverse_copy_Pictures_Direction
#endif
#ifndef COPY_Direction
#define COPY_Direction COPY_Pictures_Direction
#endif
#ifndef copy_actions
#define copy_actions Pictures_copy_actions
#endif
#ifndef Traverse_copy_Pictures
#define Traverse_copy_Pictures Traverse_copy_Pictures_Pictures
#endif
#ifndef COPY_Pictures
#define COPY_Pictures COPY_Pictures_Pictures
#endif
#ifndef Traverse_copy_Picture
#define Traverse_copy_Picture Traverse_copy_Pictures_Picture
#endif
#ifndef COPY_Picture
#define COPY_Picture COPY_Pictures_Picture
#endif
#ifndef Traverse_copy_Scope
#define Traverse_copy_Scope Traverse_copy_Pictures_Scope
#endif
#ifndef COPY_Scope
#define COPY_Scope COPY_Pictures_Scope
#endif
#ifndef Traverse_copy_List_Direction
#define Traverse_copy_List_Direction Traverse_copy_List_Pictures_Direction
#endif
#ifndef COPY_List_Direction
#define COPY_List_Direction COPY_Pictures_List_Direction
#endif
#ifndef Traverse_copy_List_Picture
#define Traverse_copy_List_Picture Traverse_copy_List_Pictures_Picture
#endif
#ifndef COPY_List_Picture
#define COPY_List_Picture COPY_Pictures_List_Picture
#endif
#ifndef s_compare_TraverseTable
#define s_compare_TraverseTable s_compare_Pictures_TraverseTable
#endif
#ifndef compare_TraverseTable
#define compare_TraverseTable compare_Pictures_TraverseTable
#endif
#ifndef Traverse_compare_Direction
#define Traverse_compare_Direction Traverse_compare_Pictures_Direction
#endif
#ifndef Traverse_compare_Pictures
#define Traverse_compare_Pictures Traverse_compare_Pictures_Pictures
#endif
#ifndef Traverse_compare_Picture
#define Traverse_compare_Picture Traverse_compare_Pictures_Picture
#endif
#ifndef Traverse_compare_Scope
#define Traverse_compare_Scope Traverse_compare_Pictures_Scope
#endif
#ifndef Traverse_compare_List_Direction
#define Traverse_compare_List_Direction Traverse_compare_List_Pictures_Direction
#endif
#ifndef Traverse_compare_List_Picture
#define Traverse_compare_List_Picture Traverse_compare_List_Pictures_Picture
#endif
#ifndef fill_table
#define fill_table Pictures_fill_table
#endif
#ifndef void_fill_table
#define void_fill_table void_Pictures_fill_table
#endif
#ifndef copy_fill_table
#define copy_fill_table copy_Pictures_fill_table
#endif
#ifndef compare_fill_table
#define compare_fill_table compare_Pictures_fill_table
#endif
#ifndef scope_actions
#define scope_actions Pictures_scope_actions
#endif
#ifndef defining_actions
#define defining_actions Pictures_defining_actions
#endif
#ifndef applied_actions
#define applied_actions Pictures_applied_actions
#endif
#ifndef check_actions
#define check_actions Pictures_check_actions
#endif
#ifndef print_actions
#define print_actions Pictures_print_actions
#endif
#ifndef compare_actions
#define compare_actions Pictures_compare_actions
#endif
#ifndef NameSpaces
#define NameSpaces Pictures_NameSpaces
#endif
#ifndef namespaces
#define namespaces Pictures_namespaces
#endif
#ifndef DefaultNameSpace
#define DefaultNameSpace Pictures_DefaultNameSpace
#endif
#ifndef NUM_NAMESPACES
#define NUM_NAMESPACES Pictures_NUM_NAMESPACES
#endif
#ifndef Direction_names
#define Direction_names Pictures_Direction_names
#endif
#ifndef Picture_tag_names
#define Picture_tag_names Pictures_Picture_tag_names
#endif

/* Abbreviations for Pictures_parse.h */

#ifndef Parse_Pictures
#define Parse_Pictures Parse_Pictures_Pictures
#endif
#ifndef Parse_Direction
#define Parse_Direction Parse_Pictures_Direction
#endif
#ifndef Parse_Picture
#define Parse_Picture Parse_Pictures_Picture
#endif
#ifndef Parse_OPTMORE_Picture
#define Parse_OPTMORE_Picture Parse_Pictures_OPTMORE_Picture
#endif
#ifndef Parse_MORE_Picture
#define Parse_MORE_Picture Parse_Pictures_MORE_Picture
#endif
#ifndef Parse_state_Pictures
#define Parse_state_Pictures Parse_state_Pictures_Pictures
#endif
#ifndef parse_string
#define parse_string Pictures_parse_string
#endif
#ifndef Parse_state_Direction
#define Parse_state_Direction Parse_state_Pictures_Direction
#endif
#ifndef Parse_state_Picture
#define Parse_state_Picture Parse_state_Pictures_Picture
#endif
#ifndef Parse_state_OPTMORE_Picture
#define Parse_state_OPTMORE_Picture Parse_state_Pictures_OPTMORE_Picture
#endif
#ifndef Parse_state_MORE_Picture
#define Parse_state_MORE_Picture Parse_state_Pictures_MORE_Picture
#endif
#ifndef Print_Pictures
#define Print_Pictures Print_Pictures_Pictures
#endif
#ifndef PRINT_Pictures
#define PRINT_Pictures PRINT_Pictures_Pictures
#endif
#ifndef Text_Pictures
#define Text_Pictures Text_Pictures_Pictures
#endif
#ifndef Print_Picture
#define Print_Picture Print_Pictures_Picture
#endif
#ifndef PRINT_Picture
#define PRINT_Picture PRINT_Pictures_Picture
#endif
#ifndef Text_Picture
#define Text_Picture Text_Pictures_Picture
#endif
#ifndef Print_Scope
#define Print_Scope Print_Pictures_Scope
#endif
#ifndef PRINT_Scope
#define PRINT_Scope PRINT_Pictures_Scope
#endif
#ifndef Text_Scope
#define Text_Scope Text_Pictures_Scope
#endif
#ifndef Print_List_Direction
#define Print_List_Direction Print_List_Pictures_Direction
#endif
#ifndef PRINT_List_Direction
#define PRINT_List_Direction PRINT_List_Pictures_Direction
#endif
#ifndef Text_List_Direction
#define Text_List_Direction Text_List_Pictures_Direction
#endif
#ifndef Print_List_Picture
#define Print_List_Picture Print_List_Pictures_Picture
#endif
#ifndef PRINT_List_Picture
#define PRINT_List_Picture PRINT_List_Pictures_Picture
#endif
#ifndef Text_List_Picture
#define Text_List_Picture Text_List_Pictures_Picture
#endif
#ifndef Print_Direction
#define Print_Direction Print_Pictures_Direction
#endif
#ifndef PRINT_Direction
#define PRINT_Direction PRINT_Pictures_Direction
#endif
#ifndef Text_Direction
#define Text_Direction Text_Pictures_Direction
#endif
#endif /* Pictures_NO_DEFS */

