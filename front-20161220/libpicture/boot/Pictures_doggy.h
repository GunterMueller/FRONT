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
#ifndef Pictures_Pictures_OPERATOR
#define Pictures_Pictures_OPERATOR(a) ((a)==NULL?(unsigned)~0:Pictures_Pictures_kind)
#endif
#ifndef Pictures_Pictures_HAS_OPER
#define Pictures_Pictures_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Pictures_Pictures_REPLACE 
#define Pictures_Pictures_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Pictures_Pictures
#define COPY_Pictures_Pictures(x) Traverse_copy_Pictures_Pictures(x, &Pictures_copy_actions)
#endif

#ifndef NEW_Pictures_Pictures
#define NEW_Pictures_Pictures(src_info, pics, yyy) Create_Pictures_Pictures(NO_SRCINFO, pics)
#endif

#define Pictures_Pictures_GET_List_Pictures_Picture(i,me)	(i == 0 ? Pictures_Pictures_pics(me) : 0)

#ifndef Pictures_Picture_OPERATOR
#define Pictures_Picture_OPERATOR(a) ((a)==NULL?(unsigned)~0:Pictures_Picture_tag(a))
#endif
#ifndef Pictures_Picture_HAS_OPER
#define Pictures_Picture_HAS_OPER(a,op) ((a) != NULL && Pictures_Picture_tag(a) == op)
#endif
#ifndef Pictures_Picture_REPLACE 
#define Pictures_Picture_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Pictures_Picture
#define COPY_Pictures_Picture(x) Traverse_copy_Pictures_Picture(x, &Pictures_copy_actions)
#endif

#ifndef NEW_Pictures_Compound
#define NEW_Pictures_Compound(src_info, x, y, w, h, sub, yyy) Create_Pictures_Compound(NO_SRCINFO, x, y, w, h, sub)
#endif

#define Pictures_Compound_GET_Float(i,me)	(i == 0 ? Pictures_Picture_x(me) : i == 1 ? Pictures_Picture_y(me) : i == 2 ? Pictures_Picture_w(me) : i == 3 ? Pictures_Picture_h(me) : 0)
#define Pictures_Compound_GET_List_Pictures_Picture(i,me)	(i == 4 ? Pictures_Compound_sub(me) : 0)

#ifndef NEW_Pictures_AltBlock
#define NEW_Pictures_AltBlock(src_info, x, y, w, h, a, b, turn_left, yyy) Create_Pictures_AltBlock(NO_SRCINFO, x, y, w, h, a, b, turn_left)
#endif

#define Pictures_AltBlock_GET_Float(i,me)	(i == 0 ? Pictures_Picture_x(me) : i == 1 ? Pictures_Picture_y(me) : i == 2 ? Pictures_Picture_w(me) : i == 3 ? Pictures_Picture_h(me) : 0)
#define Pictures_AltBlock_GET_Pictures_Picture(i,me)	(i == 4 ? Pictures_AltBlock_a(me) : i == 5 ? Pictures_AltBlock_b(me) : 0)
#define Pictures_AltBlock_GET_Bool(i,me)	(i == 6 ? Pictures_AltBlock_turn_left(me) : 0)

#ifndef NEW_Pictures_AndBlock
#define NEW_Pictures_AndBlock(src_info, x, y, w, h, sub, dirs, yyy) Create_Pictures_AndBlock(NO_SRCINFO, x, y, w, h, sub, dirs)
#endif

#define Pictures_AndBlock_GET_Float(i,me)	(i == 0 ? Pictures_Picture_x(me) : i == 1 ? Pictures_Picture_y(me) : i == 2 ? Pictures_Picture_w(me) : i == 3 ? Pictures_Picture_h(me) : 0)
#define Pictures_AndBlock_GET_List_Pictures_Picture(i,me)	(i == 4 ? Pictures_AndBlock_sub(me) : 0)
#define Pictures_AndBlock_GET_List_Pictures_Direction(i,me)	(i == 5 ? Pictures_AndBlock_dirs(me) : 0)

#ifndef NEW_Pictures_OrBlock
#define NEW_Pictures_OrBlock(src_info, x, y, w, h, sub, dirs, yyy) Create_Pictures_OrBlock(NO_SRCINFO, x, y, w, h, sub, dirs)
#endif

#define Pictures_OrBlock_GET_Float(i,me)	(i == 0 ? Pictures_Picture_x(me) : i == 1 ? Pictures_Picture_y(me) : i == 2 ? Pictures_Picture_w(me) : i == 3 ? Pictures_Picture_h(me) : 0)
#define Pictures_OrBlock_GET_List_Pictures_Picture(i,me)	(i == 4 ? Pictures_OrBlock_sub(me) : 0)
#define Pictures_OrBlock_GET_List_Pictures_Direction(i,me)	(i == 5 ? Pictures_OrBlock_dirs(me) : 0)

#ifndef NEW_Pictures_Text
#define NEW_Pictures_Text(src_info, x, y, w, h, text, font, yyy) Create_Pictures_Text(NO_SRCINFO, x, y, w, h, text, font)
#endif

#define Pictures_Text_GET_Float(i,me)	(i == 0 ? Pictures_Picture_x(me) : i == 1 ? Pictures_Picture_y(me) : i == 2 ? Pictures_Picture_w(me) : i == 3 ? Pictures_Picture_h(me) : 0)
#define Pictures_Text_GET_String(i,me)	(i == 4 ? Pictures_Text_text(me) : 0)
#define Pictures_Text_GET_Ident(i,me)	(i == 5 ? Pictures_Text_font(me) : 0)

#ifndef NEW_Pictures_Arrow
#define NEW_Pictures_Arrow(src_info, x, y, w, h, dir, yyy) Create_Pictures_Arrow(NO_SRCINFO, x, y, w, h, dir)
#endif

#define Pictures_Arrow_GET_Float(i,me)	(i == 0 ? Pictures_Picture_x(me) : i == 1 ? Pictures_Picture_y(me) : i == 2 ? Pictures_Picture_w(me) : i == 3 ? Pictures_Picture_h(me) : 0)
#define Pictures_Arrow_GET_Pictures_Direction(i,me)	(i == 4 ? Pictures_Arrow_dir(me) : 0)

#ifndef NEW_Pictures_Line
#define NEW_Pictures_Line(src_info, x, y, w, h, yyy) Create_Pictures_Line(NO_SRCINFO, x, y, w, h)
#endif

#define Pictures_Line_GET_Float(i,me)	(i == 0 ? Pictures_Picture_x(me) : i == 1 ? Pictures_Picture_y(me) : i == 2 ? Pictures_Picture_w(me) : i == 3 ? Pictures_Picture_h(me) : 0)

#ifndef NEW_Pictures_Curve
#define NEW_Pictures_Curve(src_info, x, y, w, h, d1, d2, yyy) Create_Pictures_Curve(NO_SRCINFO, x, y, w, h, d1, d2)
#endif

#define Pictures_Curve_GET_Float(i,me)	(i == 0 ? Pictures_Picture_x(me) : i == 1 ? Pictures_Picture_y(me) : i == 2 ? Pictures_Picture_w(me) : i == 3 ? Pictures_Picture_h(me) : 0)
#define Pictures_Curve_GET_Bool(i,me)	(i == 4 ? Pictures_Curve_d1(me) : i == 5 ? Pictures_Curve_d2(me) : 0)

#ifndef NEW_Pictures_Arc
#define NEW_Pictures_Arc(src_info, x, y, w, h, phi_1, phi_2, yyy) Create_Pictures_Arc(NO_SRCINFO, x, y, w, h, phi_1, phi_2)
#endif

#define Pictures_Arc_GET_Float(i,me)	(i == 0 ? Pictures_Picture_x(me) : i == 1 ? Pictures_Picture_y(me) : i == 2 ? Pictures_Picture_w(me) : i == 3 ? Pictures_Picture_h(me) : i == 4 ? Pictures_Arc_phi_1(me) : i == 5 ? Pictures_Arc_phi_2(me) : 0)

#ifndef NEW_Pictures_Circle
#define NEW_Pictures_Circle(src_info, x, y, w, h, yyy) Create_Pictures_Circle(NO_SRCINFO, x, y, w, h)
#endif

#define Pictures_Circle_GET_Float(i,me)	(i == 0 ? Pictures_Picture_x(me) : i == 1 ? Pictures_Picture_y(me) : i == 2 ? Pictures_Picture_w(me) : i == 3 ? Pictures_Picture_h(me) : 0)

#ifndef NEW_Pictures_Box
#define NEW_Pictures_Box(src_info, x, y, w, h, yyy) Create_Pictures_Box(NO_SRCINFO, x, y, w, h)
#endif

#define Pictures_Box_GET_Float(i,me)	(i == 0 ? Pictures_Picture_x(me) : i == 1 ? Pictures_Picture_y(me) : i == 2 ? Pictures_Picture_w(me) : i == 3 ? Pictures_Picture_h(me) : 0)

#ifndef NEW_Pictures_Empty
#define NEW_Pictures_Empty(src_info, x, y, w, h, yyy) Create_Pictures_Empty(NO_SRCINFO, x, y, w, h)
#endif

#define Pictures_Empty_GET_Float(i,me)	(i == 0 ? Pictures_Picture_x(me) : i == 1 ? Pictures_Picture_y(me) : i == 2 ? Pictures_Picture_w(me) : i == 3 ? Pictures_Picture_h(me) : 0)

#ifndef Pictures_Scope_OPERATOR
#define Pictures_Scope_OPERATOR(a) ((a)==NULL?(unsigned)~0:Pictures_Scope_kind)
#endif
#ifndef Pictures_Scope_HAS_OPER
#define Pictures_Scope_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Pictures_Scope_REPLACE 
#define Pictures_Scope_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Pictures_Scope
#define COPY_Pictures_Scope(x) Traverse_copy_Pictures_Scope(x, &Pictures_copy_actions)
#endif

#ifndef NEW_Pictures_Scope
#define NEW_Pictures_Scope(next, yyy) Create_Pictures_Scope(NO_SRCINFO)
#endif


#ifndef List_Pictures_Direction_OPERATOR
#define List_Pictures_Direction_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Pictures_Direction_kind)
#endif
#ifndef List_Pictures_Direction_HAS_OPER
#define List_Pictures_Direction_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Pictures_Direction_REPLACE 
#define List_Pictures_Direction_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Pictures_Direction
#define COPY_List_Pictures_Direction(x) Traverse_copy_List_Pictures_Direction(x, &Pictures_copy_actions)
#endif

#ifndef NEW_List_Pictures_Direction
#define NEW_List_Pictures_Direction(xxx, data, next, yyy) Create_List_Pictures_Direction(data, next)
#endif

#define List_Pictures_Direction_GET_Pictures_Direction(i,me)	(i == 0 ? List_Pictures_Direction_data(me) : 0)
#define List_Pictures_Direction_GET_List_Pictures_Direction(i,me)	(i == 1 ? List_Pictures_Direction_next(me) : 0)

#ifndef List_Pictures_Picture_OPERATOR
#define List_Pictures_Picture_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Pictures_Picture_kind)
#endif
#ifndef List_Pictures_Picture_HAS_OPER
#define List_Pictures_Picture_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Pictures_Picture_REPLACE 
#define List_Pictures_Picture_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Pictures_Picture
#define COPY_List_Pictures_Picture(x) Traverse_copy_List_Pictures_Picture(x, &Pictures_copy_actions)
#endif

#ifndef NEW_List_Pictures_Picture
#define NEW_List_Pictures_Picture(xxx, data, next, yyy) Create_List_Pictures_Picture(data, next)
#endif

#define List_Pictures_Picture_GET_Pictures_Picture(i,me)	(i == 0 ? List_Pictures_Picture_data(me) : 0)
#define List_Pictures_Picture_GET_List_Pictures_Picture(i,me)	(i == 1 ? List_Pictures_Picture_next(me) : 0)

#ifndef Pictures_Direction_OPERATOR
#define Pictures_Direction_OPERATOR(a) (a)
#endif
#ifndef Pictures_Direction_HAS_OPER
#define Pictures_Direction_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef Pictures_Direction_REPLACE 
#define Pictures_Direction_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_Pictures_Direction
#define COPY_Pictures_Direction(x) (x)
#endif

#ifndef NEW_Pictures_Left
#define NEW_Pictures_Left(x,y)	Pictures_Left
#endif
#ifndef NEW_Pictures_Right
#define NEW_Pictures_Right(x,y)	Pictures_Right
#endif
#ifndef NEW_Pictures_Up
#define NEW_Pictures_Up(x,y)	Pictures_Up
#endif
#ifndef NEW_Pictures_Down
#define NEW_Pictures_Down(x,y)	Pictures_Down
#endif
#ifndef NEW_Pictures_Center
#define NEW_Pictures_Center(x,y)	Pictures_Center
#endif
#ifndef Pictures_Picture_tag_OPERATOR
#define Pictures_Picture_tag_OPERATOR(a) (a)
#endif
#ifndef Pictures_Picture_tag_HAS_OPER
#define Pictures_Picture_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef Pictures_Picture_tag_REPLACE 
#define Pictures_Picture_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_Pictures_Picture_tag
#define COPY_Pictures_Picture_tag(x) (x)
#endif

#ifndef NEW_Pictures_Empty_kind
#define NEW_Pictures_Empty_kind(x,y)	Pictures_Empty_kind
#endif
#ifndef NEW_Pictures_Box_kind
#define NEW_Pictures_Box_kind(x,y)	Pictures_Box_kind
#endif
#ifndef NEW_Pictures_Circle_kind
#define NEW_Pictures_Circle_kind(x,y)	Pictures_Circle_kind
#endif
#ifndef NEW_Pictures_Arc_kind
#define NEW_Pictures_Arc_kind(x,y)	Pictures_Arc_kind
#endif
#ifndef NEW_Pictures_Curve_kind
#define NEW_Pictures_Curve_kind(x,y)	Pictures_Curve_kind
#endif
#ifndef NEW_Pictures_Line_kind
#define NEW_Pictures_Line_kind(x,y)	Pictures_Line_kind
#endif
#ifndef NEW_Pictures_Arrow_kind
#define NEW_Pictures_Arrow_kind(x,y)	Pictures_Arrow_kind
#endif
#ifndef NEW_Pictures_Text_kind
#define NEW_Pictures_Text_kind(x,y)	Pictures_Text_kind
#endif
#ifndef NEW_Pictures_OrBlock_kind
#define NEW_Pictures_OrBlock_kind(x,y)	Pictures_OrBlock_kind
#endif
#ifndef NEW_Pictures_AndBlock_kind
#define NEW_Pictures_AndBlock_kind(x,y)	Pictures_AndBlock_kind
#endif
#ifndef NEW_Pictures_AltBlock_kind
#define NEW_Pictures_AltBlock_kind(x,y)	Pictures_AltBlock_kind
#endif
#ifndef NEW_Pictures_Compound_kind
#define NEW_Pictures_Compound_kind(x,y)	Pictures_Compound_kind
#endif
