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
#ifndef Types_Types_OPERATOR
#define Types_Types_OPERATOR(a) ((a)==NULL?(unsigned)~0:Types_Types_kind)
#endif
#ifndef Types_Types_HAS_OPER
#define Types_Types_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Types_Types_REPLACE 
#define Types_Types_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Types_Types
#define COPY_Types_Types(x) Traverse_copy_Types_Types(x, &Types_copy_actions)
#endif

#ifndef NEW_Types_Types
#define NEW_Types_Types(src_info, enums, pointers, subs, inc2, impdefs, binds, r1, r2, types, yyy) Create_Types_Types(NO_SRCINFO, enums, pointers, subs, inc2, impdefs, binds, r1, r2, types)
#endif

#define Types_Types_GET_List_Types_EnumType(i,me)	(i == 0 ? Types_Types_enums(me) : 0)
#define Types_Types_GET_List_Types_PointerType(i,me)	(i == 1 ? Types_Types_pointers(me) : 0)
#define Types_Types_GET_List_Types_subtypedef(i,me)	(i == 2 ? Types_Types_subs(me) : i == 4 ? Types_Types_impdefs(me) : 0)
#define Types_Types_GET_Types_includes2(i,me)	(i == 3 ? Types_Types_inc2(me) : 0)
#define Types_Types_GET_List_Types_BindType(i,me)	(i == 5 ? Types_Types_binds(me) : 0)
#define Types_Types_GET_Ident(i,me)	(i == 6 ? Types_Types_r1(me) : i == 7 ? Types_Types_r2(me) : 0)
#define Types_Types_GET_List_Types_StructType(i,me)	(i == 8 ? Types_Types_types(me) : 0)

#ifndef Types_includes2_OPERATOR
#define Types_includes2_OPERATOR(a) ((a)==NULL?(unsigned)~0:Types_includes2_kind)
#endif
#ifndef Types_includes2_HAS_OPER
#define Types_includes2_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Types_includes2_REPLACE 
#define Types_includes2_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Types_includes2
#define COPY_Types_includes2(x) Traverse_copy_Types_includes2(x, &Types_copy_actions)
#endif

#ifndef NEW_Types_includes2
#define NEW_Types_includes2(src_info, id1, id2, uses, yyy) Create_Types_includes2(NO_SRCINFO, id1, id2, uses)
#endif

#define Types_includes2_GET_Ident(i,me)	(i == 0 ? Types_includes2_id1(me) : i == 1 ? Types_includes2_id2(me) : 0)
#define Types_includes2_GET_List_Ident(i,me)	(i == 2 ? Types_includes2_uses(me) : 0)

#ifndef Types_EnumType_OPERATOR
#define Types_EnumType_OPERATOR(a) ((a)==NULL?(unsigned)~0:Types_EnumType_kind)
#endif
#ifndef Types_EnumType_HAS_OPER
#define Types_EnumType_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Types_EnumType_REPLACE 
#define Types_EnumType_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Types_EnumType
#define COPY_Types_EnumType(x) Traverse_copy_Types_EnumType(x, &Types_copy_actions)
#endif

#ifndef NEW_Types_EnumType
#define NEW_Types_EnumType(src_info, enums, id, str, tag, num, yyy) Create_Types_EnumType(NO_SRCINFO, enums, id, str, tag, num)
#endif

#define Types_EnumType_GET_List_Types_TypeName(i,me)	(i == 0 ? Types_EnumType_enums(me) : 0)
#define Types_EnumType_GET_Ident(i,me)	(i == 1 ? Types_EnumType_id(me) : i == 2 ? Types_EnumType_str(me) : i == 3 ? Types_EnumType_tag(me) : 0)
#define Types_EnumType_GET_Int(i,me)	(i == 4 ? Types_EnumType_num(me) : 0)

#ifndef Types_BindType_OPERATOR
#define Types_BindType_OPERATOR(a) ((a)==NULL?(unsigned)~0:Types_BindType_kind)
#endif
#ifndef Types_BindType_HAS_OPER
#define Types_BindType_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Types_BindType_REPLACE 
#define Types_BindType_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Types_BindType
#define COPY_Types_BindType(x) Traverse_copy_Types_BindType(x, &Types_copy_actions)
#endif

#ifndef NEW_Types_BindType
#define NEW_Types_BindType(src_info, id1, id2, id3, id4, id5, id6, id7, num, yyy) Create_Types_BindType(NO_SRCINFO, id1, id2, id3, id4, id5, id6, id7, num)
#endif

#define Types_BindType_GET_Ident(i,me)	(i == 0 ? Types_BindType_id1(me) : i == 1 ? Types_BindType_id2(me) : i == 2 ? Types_BindType_id3(me) : i == 3 ? Types_BindType_id4(me) : i == 4 ? Types_BindType_id5(me) : i == 5 ? Types_BindType_id6(me) : i == 6 ? Types_BindType_id7(me) : 0)
#define Types_BindType_GET_Int(i,me)	(i == 7 ? Types_BindType_num(me) : 0)

#ifndef Types_PointerType_OPERATOR
#define Types_PointerType_OPERATOR(a) ((a)==NULL?(unsigned)~0:Types_PointerType_kind)
#endif
#ifndef Types_PointerType_HAS_OPER
#define Types_PointerType_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Types_PointerType_REPLACE 
#define Types_PointerType_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Types_PointerType
#define COPY_Types_PointerType(x) Traverse_copy_Types_PointerType(x, &Types_copy_actions)
#endif

#ifndef NEW_Types_PointerType
#define NEW_Types_PointerType(src_info, id1, id2, id3, id, subs, yyy) Create_Types_PointerType(NO_SRCINFO, id1, id2, id3, id, subs)
#endif

#define Types_PointerType_GET_Ident(i,me)	(i == 0 ? Types_PointerType_id1(me) : i == 1 ? Types_PointerType_id2(me) : i == 2 ? Types_PointerType_id3(me) : i == 3 ? Types_PointerType_id(me) : 0)
#define Types_PointerType_GET_List_Types_subtypedef(i,me)	(i == 4 ? Types_PointerType_subs(me) : 0)

#ifndef Types_subtypedef_OPERATOR
#define Types_subtypedef_OPERATOR(a) ((a)==NULL?(unsigned)~0:Types_subtypedef_kind)
#endif
#ifndef Types_subtypedef_HAS_OPER
#define Types_subtypedef_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Types_subtypedef_REPLACE 
#define Types_subtypedef_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Types_subtypedef
#define COPY_Types_subtypedef(x) Traverse_copy_Types_subtypedef(x, &Types_copy_actions)
#endif

#ifndef NEW_Types_subtypedef
#define NEW_Types_subtypedef(src_info, super, id, yyy) Create_Types_subtypedef(NO_SRCINFO, super, id)
#endif

#define Types_subtypedef_GET_Ident(i,me)	(i == 0 ? Types_subtypedef_super(me) : i == 1 ? Types_subtypedef_id(me) : 0)

#ifndef Types_StructType_OPERATOR
#define Types_StructType_OPERATOR(a) ((a)==NULL?(unsigned)~0:Types_StructType_kind)
#endif
#ifndef Types_StructType_HAS_OPER
#define Types_StructType_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Types_StructType_REPLACE 
#define Types_StructType_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Types_StructType
#define COPY_Types_StructType(x) Traverse_copy_Types_StructType(x, &Types_copy_actions)
#endif

#ifndef NEW_Types_StructType
#define NEW_Types_StructType(src_info, id1, id2, type, macros, creates, id3, yyy) Create_Types_StructType(NO_SRCINFO, id1, id2, type, macros, creates, id3)
#endif

#define Types_StructType_GET_Ident(i,me)	(i == 0 ? Types_StructType_id1(me) : i == 1 ? Types_StructType_id2(me) : i == 5 ? Types_StructType_id3(me) : 0)
#define Types_StructType_GET_Types_struct_type(i,me)	(i == 2 ? Types_StructType_type(me) : 0)
#define Types_StructType_GET_List_Types_macro(i,me)	(i == 3 ? Types_StructType_macros(me) : 0)
#define Types_StructType_GET_List_Types_CreateFunction(i,me)	(i == 4 ? Types_StructType_creates(me) : 0)

#ifndef Types_struct_type_OPERATOR
#define Types_struct_type_OPERATOR(a) ((a)==NULL?(unsigned)~0:Types_struct_type_kind)
#endif
#ifndef Types_struct_type_HAS_OPER
#define Types_struct_type_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Types_struct_type_REPLACE 
#define Types_struct_type_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Types_struct_type
#define COPY_Types_struct_type(x) Traverse_copy_Types_struct_type(x, &Types_copy_actions)
#endif

#ifndef NEW_Types_struct_type
#define NEW_Types_struct_type(src_info, tag, user, fields1, sub_types, fields2, id, yyy) Create_Types_struct_type(NO_SRCINFO, tag, user, fields1, sub_types, fields2, id)
#endif

#define Types_struct_type_GET_Ident(i,me)	(i == 0 ? Types_struct_type_tag(me) : i == 1 ? Types_struct_type_user(me) : i == 5 ? Types_struct_type_id(me) : 0)
#define Types_struct_type_GET_List_Types_field(i,me)	(i == 2 ? Types_struct_type_fields1(me) : i == 4 ? Types_struct_type_fields2(me) : 0)
#define Types_struct_type_GET_List_Types_struct_type(i,me)	(i == 3 ? Types_struct_type_sub_types(me) : 0)

#ifndef Types_macro_OPERATOR
#define Types_macro_OPERATOR(a) ((a)==NULL?(unsigned)~0:Types_macro_tag(a))
#endif
#ifndef Types_macro_HAS_OPER
#define Types_macro_HAS_OPER(a,op) ((a) != NULL && Types_macro_tag(a) == op)
#endif
#ifndef Types_macro_REPLACE 
#define Types_macro_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Types_macro
#define COPY_Types_macro(x) Traverse_copy_Types_macro(x, &Types_copy_actions)
#endif

#ifndef NEW_Types_access_macro
#define NEW_Types_access_macro(src_info, type, id, r, types, f, yyy) Create_Types_access_macro(NO_SRCINFO, type, id, r, types, f)
#endif

#define Types_access_macro_GET_Ident(i,me)	(i == 0 ? Types_macro_type(me) : i == 1 ? Types_macro_id(me) : i == 2 ? Types_access_macro_r(me) : i == 4 ? Types_macro_f(me) : 0)
#define Types_access_macro_GET_List_Ident(i,me)	(i == 3 ? Types_macro_types(me) : 0)

#ifndef NEW_Types_plain_macro
#define NEW_Types_plain_macro(src_info, type, id, types, f, yyy) Create_Types_plain_macro(NO_SRCINFO, type, id, types, f)
#endif

#define Types_plain_macro_GET_Ident(i,me)	(i == 0 ? Types_macro_type(me) : i == 1 ? Types_macro_id(me) : i == 3 ? Types_macro_f(me) : 0)
#define Types_plain_macro_GET_List_Ident(i,me)	(i == 2 ? Types_macro_types(me) : 0)

#ifndef Types_field_OPERATOR
#define Types_field_OPERATOR(a) ((a)==NULL?(unsigned)~0:Types_field_kind)
#endif
#ifndef Types_field_HAS_OPER
#define Types_field_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Types_field_REPLACE 
#define Types_field_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Types_field
#define COPY_Types_field(x) Traverse_copy_Types_field(x, &Types_copy_actions)
#endif

#ifndef NEW_Types_field
#define NEW_Types_field(src_info, type, id, yyy) Create_Types_field(NO_SRCINFO, type, id)
#endif

#define Types_field_GET_List_Types_TypeName(i,me)	(i == 0 ? Types_field_type(me) : 0)
#define Types_field_GET_Ident(i,me)	(i == 1 ? Types_field_id(me) : 0)

#ifndef Types_TypeName_OPERATOR
#define Types_TypeName_OPERATOR(a) ((a)==NULL?(unsigned)~0:Types_TypeName_kind)
#endif
#ifndef Types_TypeName_HAS_OPER
#define Types_TypeName_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Types_TypeName_REPLACE 
#define Types_TypeName_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Types_TypeName
#define COPY_Types_TypeName(x) Traverse_copy_Types_TypeName(x, &Types_copy_actions)
#endif

#ifndef NEW_Types_TypeName
#define NEW_Types_TypeName(src_info, full, yyy) Create_Types_TypeName(NO_SRCINFO, full)
#endif

#define Types_TypeName_GET_Ident(i,me)	(i == 0 ? Types_TypeName_full(me) : 0)

#ifndef Types_CreateFunction_OPERATOR
#define Types_CreateFunction_OPERATOR(a) ((a)==NULL?(unsigned)~0:Types_CreateFunction_kind)
#endif
#ifndef Types_CreateFunction_HAS_OPER
#define Types_CreateFunction_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Types_CreateFunction_REPLACE 
#define Types_CreateFunction_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Types_CreateFunction
#define COPY_Types_CreateFunction(x) Traverse_copy_Types_CreateFunction(x, &Types_copy_actions)
#endif

#ifndef NEW_Types_CreateFunction
#define NEW_Types_CreateFunction(src_info, fields, yyy) Create_Types_CreateFunction(NO_SRCINFO, fields)
#endif

#define Types_CreateFunction_GET_List_Types_field(i,me)	(i == 0 ? Types_CreateFunction_fields(me) : 0)

#ifndef Types_Scope_OPERATOR
#define Types_Scope_OPERATOR(a) ((a)==NULL?(unsigned)~0:Types_Scope_tag(a))
#endif
#ifndef Types_Scope_HAS_OPER
#define Types_Scope_HAS_OPER(a,op) ((a) != NULL && Types_Scope_tag(a) == op)
#endif
#ifndef Types_Scope_REPLACE 
#define Types_Scope_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Types_Scope
#define COPY_Types_Scope(x) Traverse_copy_Types_Scope(x, &Types_copy_actions)
#endif

#ifndef NEW_Types_struct_typeScope
#define NEW_Types_struct_typeScope(next, data, yyy) Create_Types_struct_typeScope(NO_SRCINFO, data)
#endif

#define Types_struct_typeScope_GET_Types_struct_type(i,me)	(i == 0 ? Types_struct_typeScope_data(me) : 0)

#ifndef List_Types_struct_type_OPERATOR
#define List_Types_struct_type_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Types_struct_type_kind)
#endif
#ifndef List_Types_struct_type_HAS_OPER
#define List_Types_struct_type_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Types_struct_type_REPLACE 
#define List_Types_struct_type_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Types_struct_type
#define COPY_List_Types_struct_type(x) Traverse_copy_List_Types_struct_type(x, &Types_copy_actions)
#endif

#ifndef NEW_List_Types_struct_type
#define NEW_List_Types_struct_type(xxx, data, next, yyy) Create_List_Types_struct_type(data, next)
#endif

#define List_Types_struct_type_GET_Types_struct_type(i,me)	(i == 0 ? List_Types_struct_type_data(me) : 0)
#define List_Types_struct_type_GET_List_Types_struct_type(i,me)	(i == 1 ? List_Types_struct_type_next(me) : 0)

#ifndef List_Types_field_OPERATOR
#define List_Types_field_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Types_field_kind)
#endif
#ifndef List_Types_field_HAS_OPER
#define List_Types_field_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Types_field_REPLACE 
#define List_Types_field_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Types_field
#define COPY_List_Types_field(x) Traverse_copy_List_Types_field(x, &Types_copy_actions)
#endif

#ifndef NEW_List_Types_field
#define NEW_List_Types_field(xxx, data, next, yyy) Create_List_Types_field(data, next)
#endif

#define List_Types_field_GET_Types_field(i,me)	(i == 0 ? List_Types_field_data(me) : 0)
#define List_Types_field_GET_List_Types_field(i,me)	(i == 1 ? List_Types_field_next(me) : 0)

#ifndef List_Types_CreateFunction_OPERATOR
#define List_Types_CreateFunction_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Types_CreateFunction_kind)
#endif
#ifndef List_Types_CreateFunction_HAS_OPER
#define List_Types_CreateFunction_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Types_CreateFunction_REPLACE 
#define List_Types_CreateFunction_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Types_CreateFunction
#define COPY_List_Types_CreateFunction(x) Traverse_copy_List_Types_CreateFunction(x, &Types_copy_actions)
#endif

#ifndef NEW_List_Types_CreateFunction
#define NEW_List_Types_CreateFunction(xxx, data, next, yyy) Create_List_Types_CreateFunction(data, next)
#endif

#define List_Types_CreateFunction_GET_Types_CreateFunction(i,me)	(i == 0 ? List_Types_CreateFunction_data(me) : 0)
#define List_Types_CreateFunction_GET_List_Types_CreateFunction(i,me)	(i == 1 ? List_Types_CreateFunction_next(me) : 0)

#ifndef List_Types_macro_OPERATOR
#define List_Types_macro_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Types_macro_kind)
#endif
#ifndef List_Types_macro_HAS_OPER
#define List_Types_macro_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Types_macro_REPLACE 
#define List_Types_macro_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Types_macro
#define COPY_List_Types_macro(x) Traverse_copy_List_Types_macro(x, &Types_copy_actions)
#endif

#ifndef NEW_List_Types_macro
#define NEW_List_Types_macro(xxx, data, next, yyy) Create_List_Types_macro(data, next)
#endif

#define List_Types_macro_GET_Types_macro(i,me)	(i == 0 ? List_Types_macro_data(me) : 0)
#define List_Types_macro_GET_List_Types_macro(i,me)	(i == 1 ? List_Types_macro_next(me) : 0)

#ifndef List_Types_TypeName_OPERATOR
#define List_Types_TypeName_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Types_TypeName_kind)
#endif
#ifndef List_Types_TypeName_HAS_OPER
#define List_Types_TypeName_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Types_TypeName_REPLACE 
#define List_Types_TypeName_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Types_TypeName
#define COPY_List_Types_TypeName(x) Traverse_copy_List_Types_TypeName(x, &Types_copy_actions)
#endif

#ifndef NEW_List_Types_TypeName
#define NEW_List_Types_TypeName(xxx, data, next, yyy) Create_List_Types_TypeName(data, next)
#endif

#define List_Types_TypeName_GET_Types_TypeName(i,me)	(i == 0 ? List_Types_TypeName_data(me) : 0)
#define List_Types_TypeName_GET_List_Types_TypeName(i,me)	(i == 1 ? List_Types_TypeName_next(me) : 0)

#ifndef List_Ident_OPERATOR
#define List_Ident_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Ident_kind)
#endif
#ifndef List_Ident_HAS_OPER
#define List_Ident_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Ident_REPLACE 
#define List_Ident_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Ident
#define COPY_List_Ident(x) Traverse_copy_List_Ident(x, &Types_copy_actions)
#endif

#ifndef List_Types_StructType_OPERATOR
#define List_Types_StructType_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Types_StructType_kind)
#endif
#ifndef List_Types_StructType_HAS_OPER
#define List_Types_StructType_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Types_StructType_REPLACE 
#define List_Types_StructType_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Types_StructType
#define COPY_List_Types_StructType(x) Traverse_copy_List_Types_StructType(x, &Types_copy_actions)
#endif

#ifndef NEW_List_Types_StructType
#define NEW_List_Types_StructType(xxx, data, next, yyy) Create_List_Types_StructType(data, next)
#endif

#define List_Types_StructType_GET_Types_StructType(i,me)	(i == 0 ? List_Types_StructType_data(me) : 0)
#define List_Types_StructType_GET_List_Types_StructType(i,me)	(i == 1 ? List_Types_StructType_next(me) : 0)

#ifndef List_Types_BindType_OPERATOR
#define List_Types_BindType_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Types_BindType_kind)
#endif
#ifndef List_Types_BindType_HAS_OPER
#define List_Types_BindType_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Types_BindType_REPLACE 
#define List_Types_BindType_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Types_BindType
#define COPY_List_Types_BindType(x) Traverse_copy_List_Types_BindType(x, &Types_copy_actions)
#endif

#ifndef NEW_List_Types_BindType
#define NEW_List_Types_BindType(xxx, data, next, yyy) Create_List_Types_BindType(data, next)
#endif

#define List_Types_BindType_GET_Types_BindType(i,me)	(i == 0 ? List_Types_BindType_data(me) : 0)
#define List_Types_BindType_GET_List_Types_BindType(i,me)	(i == 1 ? List_Types_BindType_next(me) : 0)

#ifndef List_Types_subtypedef_OPERATOR
#define List_Types_subtypedef_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Types_subtypedef_kind)
#endif
#ifndef List_Types_subtypedef_HAS_OPER
#define List_Types_subtypedef_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Types_subtypedef_REPLACE 
#define List_Types_subtypedef_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Types_subtypedef
#define COPY_List_Types_subtypedef(x) Traverse_copy_List_Types_subtypedef(x, &Types_copy_actions)
#endif

#ifndef NEW_List_Types_subtypedef
#define NEW_List_Types_subtypedef(xxx, data, next, yyy) Create_List_Types_subtypedef(data, next)
#endif

#define List_Types_subtypedef_GET_Types_subtypedef(i,me)	(i == 0 ? List_Types_subtypedef_data(me) : 0)
#define List_Types_subtypedef_GET_List_Types_subtypedef(i,me)	(i == 1 ? List_Types_subtypedef_next(me) : 0)

#ifndef List_Types_PointerType_OPERATOR
#define List_Types_PointerType_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Types_PointerType_kind)
#endif
#ifndef List_Types_PointerType_HAS_OPER
#define List_Types_PointerType_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Types_PointerType_REPLACE 
#define List_Types_PointerType_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Types_PointerType
#define COPY_List_Types_PointerType(x) Traverse_copy_List_Types_PointerType(x, &Types_copy_actions)
#endif

#ifndef NEW_List_Types_PointerType
#define NEW_List_Types_PointerType(xxx, data, next, yyy) Create_List_Types_PointerType(data, next)
#endif

#define List_Types_PointerType_GET_Types_PointerType(i,me)	(i == 0 ? List_Types_PointerType_data(me) : 0)
#define List_Types_PointerType_GET_List_Types_PointerType(i,me)	(i == 1 ? List_Types_PointerType_next(me) : 0)

#ifndef List_Types_EnumType_OPERATOR
#define List_Types_EnumType_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Types_EnumType_kind)
#endif
#ifndef List_Types_EnumType_HAS_OPER
#define List_Types_EnumType_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Types_EnumType_REPLACE 
#define List_Types_EnumType_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Types_EnumType
#define COPY_List_Types_EnumType(x) Traverse_copy_List_Types_EnumType(x, &Types_copy_actions)
#endif

#ifndef NEW_List_Types_EnumType
#define NEW_List_Types_EnumType(xxx, data, next, yyy) Create_List_Types_EnumType(data, next)
#endif

#define List_Types_EnumType_GET_Types_EnumType(i,me)	(i == 0 ? List_Types_EnumType_data(me) : 0)
#define List_Types_EnumType_GET_List_Types_EnumType(i,me)	(i == 1 ? List_Types_EnumType_next(me) : 0)

#ifndef Types_macro_tag_OPERATOR
#define Types_macro_tag_OPERATOR(a) (a)
#endif
#ifndef Types_macro_tag_HAS_OPER
#define Types_macro_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef Types_macro_tag_REPLACE 
#define Types_macro_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_Types_macro_tag
#define COPY_Types_macro_tag(x) (x)
#endif

#ifndef NEW_Types_plain_macro_kind
#define NEW_Types_plain_macro_kind(x,y)	Types_plain_macro_kind
#endif
#ifndef NEW_Types_access_macro_kind
#define NEW_Types_access_macro_kind(x,y)	Types_access_macro_kind
#endif
#ifndef Types_Scope_tag_OPERATOR
#define Types_Scope_tag_OPERATOR(a) (a)
#endif
#ifndef Types_Scope_tag_HAS_OPER
#define Types_Scope_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef Types_Scope_tag_REPLACE 
#define Types_Scope_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_Types_Scope_tag
#define COPY_Types_Scope_tag(x) (x)
#endif

#ifndef NEW_Types_struct_typeScope_kind
#define NEW_Types_struct_typeScope_kind(x,y)	Types_struct_typeScope_kind
#endif
#ifndef Bind_Types_struct_type_OPERATOR
#define Bind_Types_struct_type_OPERATOR(a) (a)
#endif
#ifndef Bind_Types_struct_type_HAS_OPER
#define Bind_Types_struct_type_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef Bind_Types_struct_type_REPLACE 
#define Bind_Types_struct_type_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_Bind_Types_struct_type
#define COPY_Bind_Types_struct_type(x) (x)
#endif

