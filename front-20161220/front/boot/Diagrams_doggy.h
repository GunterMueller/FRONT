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
#ifndef Diagrams_Diagrams_OPERATOR
#define Diagrams_Diagrams_OPERATOR(a) ((a)==NULL?(unsigned)~0:Diagrams_Diagrams_kind)
#endif
#ifndef Diagrams_Diagrams_HAS_OPER
#define Diagrams_Diagrams_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Diagrams_Diagrams_REPLACE 
#define Diagrams_Diagrams_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Diagrams_Diagrams
#define COPY_Diagrams_Diagrams(x) Traverse_copy_Diagrams_Diagrams(x, &Diagrams_copy_actions)
#endif

#ifndef NEW_Diagrams_Diagrams
#define NEW_Diagrams_Diagrams(src_info, pics, yyy) Create_Diagrams_Diagrams(NO_SRCINFO, pics)
#endif

#define Diagrams_Diagrams_GET_List_Diagrams_Picture(i,me)	(i == 0 ? Diagrams_Diagrams_pics(me) : 0)

#ifndef Diagrams_Picture_OPERATOR
#define Diagrams_Picture_OPERATOR(a) ((a)==NULL?(unsigned)~0:Diagrams_Picture_tag(a))
#endif
#ifndef Diagrams_Picture_HAS_OPER
#define Diagrams_Picture_HAS_OPER(a,op) ((a) != NULL && Diagrams_Picture_tag(a) == op)
#endif
#ifndef Diagrams_Picture_REPLACE 
#define Diagrams_Picture_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Diagrams_Picture
#define COPY_Diagrams_Picture(x) Traverse_copy_Diagrams_Picture(x, &Diagrams_copy_actions)
#endif

#ifndef NEW_Diagrams_Compound
#define NEW_Diagrams_Compound(src_info, x, y, w, h, sub, yyy) Create_Diagrams_Compound(NO_SRCINFO, x, y, w, h, sub)
#endif

#define Diagrams_Compound_GET_Int(i,me)	(i == 0 ? Diagrams_Picture_x(me) : i == 1 ? Diagrams_Picture_y(me) : i == 2 ? Diagrams_Picture_w(me) : i == 3 ? Diagrams_Picture_h(me) : 0)
#define Diagrams_Compound_GET_List_Diagrams_Picture(i,me)	(i == 4 ? Diagrams_Compound_sub(me) : 0)

#ifndef NEW_Diagrams_AltBlock
#define NEW_Diagrams_AltBlock(src_info, x, y, w, h, a, b, turn_left, yyy) Create_Diagrams_AltBlock(NO_SRCINFO, x, y, w, h, a, b, turn_left)
#endif

#define Diagrams_AltBlock_GET_Int(i,me)	(i == 0 ? Diagrams_Picture_x(me) : i == 1 ? Diagrams_Picture_y(me) : i == 2 ? Diagrams_Picture_w(me) : i == 3 ? Diagrams_Picture_h(me) : 0)
#define Diagrams_AltBlock_GET_Diagrams_Picture(i,me)	(i == 4 ? Diagrams_AltBlock_a(me) : i == 5 ? Diagrams_AltBlock_b(me) : 0)
#define Diagrams_AltBlock_GET_Bool(i,me)	(i == 6 ? Diagrams_AltBlock_turn_left(me) : 0)

#ifndef NEW_Diagrams_AndBlock
#define NEW_Diagrams_AndBlock(src_info, x, y, w, h, sub, dirs, yyy) Create_Diagrams_AndBlock(NO_SRCINFO, x, y, w, h, sub, dirs)
#endif

#define Diagrams_AndBlock_GET_Int(i,me)	(i == 0 ? Diagrams_Picture_x(me) : i == 1 ? Diagrams_Picture_y(me) : i == 2 ? Diagrams_Picture_w(me) : i == 3 ? Diagrams_Picture_h(me) : 0)
#define Diagrams_AndBlock_GET_List_Diagrams_Picture(i,me)	(i == 4 ? Diagrams_AndBlock_sub(me) : 0)
#define Diagrams_AndBlock_GET_List_Diagrams_Direction(i,me)	(i == 5 ? Diagrams_AndBlock_dirs(me) : 0)

#ifndef NEW_Diagrams_OrBlock
#define NEW_Diagrams_OrBlock(src_info, x, y, w, h, sub, dirs, yyy) Create_Diagrams_OrBlock(NO_SRCINFO, x, y, w, h, sub, dirs)
#endif

#define Diagrams_OrBlock_GET_Int(i,me)	(i == 0 ? Diagrams_Picture_x(me) : i == 1 ? Diagrams_Picture_y(me) : i == 2 ? Diagrams_Picture_w(me) : i == 3 ? Diagrams_Picture_h(me) : 0)
#define Diagrams_OrBlock_GET_List_Diagrams_Picture(i,me)	(i == 4 ? Diagrams_OrBlock_sub(me) : 0)
#define Diagrams_OrBlock_GET_List_Diagrams_Direction(i,me)	(i == 5 ? Diagrams_OrBlock_dirs(me) : 0)

#ifndef NEW_Diagrams_Text
#define NEW_Diagrams_Text(src_info, x, y, w, h, text, font, yyy) Create_Diagrams_Text(NO_SRCINFO, x, y, w, h, text, font)
#endif

#define Diagrams_Text_GET_Int(i,me)	(i == 0 ? Diagrams_Picture_x(me) : i == 1 ? Diagrams_Picture_y(me) : i == 2 ? Diagrams_Picture_w(me) : i == 3 ? Diagrams_Picture_h(me) : 0)
#define Diagrams_Text_GET_String(i,me)	(i == 4 ? Diagrams_Text_text(me) : 0)
#define Diagrams_Text_GET_Ident(i,me)	(i == 5 ? Diagrams_Text_font(me) : 0)

#ifndef NEW_Diagrams_Arrow
#define NEW_Diagrams_Arrow(src_info, x, y, w, h, dir, yyy) Create_Diagrams_Arrow(NO_SRCINFO, x, y, w, h, dir)
#endif

#define Diagrams_Arrow_GET_Int(i,me)	(i == 0 ? Diagrams_Picture_x(me) : i == 1 ? Diagrams_Picture_y(me) : i == 2 ? Diagrams_Picture_w(me) : i == 3 ? Diagrams_Picture_h(me) : 0)
#define Diagrams_Arrow_GET_Diagrams_Direction(i,me)	(i == 4 ? Diagrams_Arrow_dir(me) : 0)

#ifndef NEW_Diagrams_Line
#define NEW_Diagrams_Line(src_info, x, y, w, h, yyy) Create_Diagrams_Line(NO_SRCINFO, x, y, w, h)
#endif

#define Diagrams_Line_GET_Int(i,me)	(i == 0 ? Diagrams_Picture_x(me) : i == 1 ? Diagrams_Picture_y(me) : i == 2 ? Diagrams_Picture_w(me) : i == 3 ? Diagrams_Picture_h(me) : 0)

#ifndef NEW_Diagrams_Curve
#define NEW_Diagrams_Curve(src_info, x, y, w, h, d1, d2, yyy) Create_Diagrams_Curve(NO_SRCINFO, x, y, w, h, d1, d2)
#endif

#define Diagrams_Curve_GET_Int(i,me)	(i == 0 ? Diagrams_Picture_x(me) : i == 1 ? Diagrams_Picture_y(me) : i == 2 ? Diagrams_Picture_w(me) : i == 3 ? Diagrams_Picture_h(me) : 0)
#define Diagrams_Curve_GET_Bool(i,me)	(i == 4 ? Diagrams_Curve_d1(me) : i == 5 ? Diagrams_Curve_d2(me) : 0)

#ifndef NEW_Diagrams_Box
#define NEW_Diagrams_Box(src_info, x, y, w, h, yyy) Create_Diagrams_Box(NO_SRCINFO, x, y, w, h)
#endif

#define Diagrams_Box_GET_Int(i,me)	(i == 0 ? Diagrams_Picture_x(me) : i == 1 ? Diagrams_Picture_y(me) : i == 2 ? Diagrams_Picture_w(me) : i == 3 ? Diagrams_Picture_h(me) : 0)

#ifndef NEW_Diagrams_Empty
#define NEW_Diagrams_Empty(src_info, x, y, w, h, yyy) Create_Diagrams_Empty(NO_SRCINFO, x, y, w, h)
#endif

#define Diagrams_Empty_GET_Int(i,me)	(i == 0 ? Diagrams_Picture_x(me) : i == 1 ? Diagrams_Picture_y(me) : i == 2 ? Diagrams_Picture_w(me) : i == 3 ? Diagrams_Picture_h(me) : 0)

#ifndef Diagrams_Scope_OPERATOR
#define Diagrams_Scope_OPERATOR(a) ((a)==NULL?(unsigned)~0:Diagrams_Scope_kind)
#endif
#ifndef Diagrams_Scope_HAS_OPER
#define Diagrams_Scope_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef Diagrams_Scope_REPLACE 
#define Diagrams_Scope_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_Diagrams_Scope
#define COPY_Diagrams_Scope(x) Traverse_copy_Diagrams_Scope(x, &Diagrams_copy_actions)
#endif

#ifndef NEW_Diagrams_Scope
#define NEW_Diagrams_Scope(next, yyy) Create_Diagrams_Scope(NO_SRCINFO)
#endif


#ifndef List_Diagrams_Direction_OPERATOR
#define List_Diagrams_Direction_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Diagrams_Direction_kind)
#endif
#ifndef List_Diagrams_Direction_HAS_OPER
#define List_Diagrams_Direction_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Diagrams_Direction_REPLACE 
#define List_Diagrams_Direction_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Diagrams_Direction
#define COPY_List_Diagrams_Direction(x) Traverse_copy_List_Diagrams_Direction(x, &Diagrams_copy_actions)
#endif

#ifndef NEW_List_Diagrams_Direction
#define NEW_List_Diagrams_Direction(xxx, data, next, yyy) Create_List_Diagrams_Direction(data, next)
#endif

#define List_Diagrams_Direction_GET_Diagrams_Direction(i,me)	(i == 0 ? List_Diagrams_Direction_data(me) : 0)
#define List_Diagrams_Direction_GET_List_Diagrams_Direction(i,me)	(i == 1 ? List_Diagrams_Direction_next(me) : 0)

#ifndef List_Diagrams_Picture_OPERATOR
#define List_Diagrams_Picture_OPERATOR(a) ((a)==NULL?(unsigned)~0:List_Diagrams_Picture_kind)
#endif
#ifndef List_Diagrams_Picture_HAS_OPER
#define List_Diagrams_Picture_HAS_OPER(a,op) ((a) != NULL)
#endif
#ifndef List_Diagrams_Picture_REPLACE 
#define List_Diagrams_Picture_REPLACE(x,y,i) (*(x) = *(y))
#endif 
#ifndef COPY_List_Diagrams_Picture
#define COPY_List_Diagrams_Picture(x) Traverse_copy_List_Diagrams_Picture(x, &Diagrams_copy_actions)
#endif

#ifndef NEW_List_Diagrams_Picture
#define NEW_List_Diagrams_Picture(xxx, data, next, yyy) Create_List_Diagrams_Picture(data, next)
#endif

#define List_Diagrams_Picture_GET_Diagrams_Picture(i,me)	(i == 0 ? List_Diagrams_Picture_data(me) : 0)
#define List_Diagrams_Picture_GET_List_Diagrams_Picture(i,me)	(i == 1 ? List_Diagrams_Picture_next(me) : 0)

#ifndef Diagrams_Direction_OPERATOR
#define Diagrams_Direction_OPERATOR(a) (a)
#endif
#ifndef Diagrams_Direction_HAS_OPER
#define Diagrams_Direction_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef Diagrams_Direction_REPLACE 
#define Diagrams_Direction_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_Diagrams_Direction
#define COPY_Diagrams_Direction(x) (x)
#endif

#ifndef NEW_Diagrams_Left
#define NEW_Diagrams_Left(x,y)	Diagrams_Left
#endif
#ifndef NEW_Diagrams_Right
#define NEW_Diagrams_Right(x,y)	Diagrams_Right
#endif
#ifndef NEW_Diagrams_Up
#define NEW_Diagrams_Up(x,y)	Diagrams_Up
#endif
#ifndef NEW_Diagrams_Down
#define NEW_Diagrams_Down(x,y)	Diagrams_Down
#endif
#ifndef NEW_Diagrams_Center
#define NEW_Diagrams_Center(x,y)	Diagrams_Center
#endif
#ifndef Diagrams_Picture_tag_OPERATOR
#define Diagrams_Picture_tag_OPERATOR(a) (a)
#endif
#ifndef Diagrams_Picture_tag_HAS_OPER
#define Diagrams_Picture_tag_HAS_OPER(a,op) ((a) == op)
#endif
#ifndef Diagrams_Picture_tag_REPLACE 
#define Diagrams_Picture_tag_REPLACE(x,y,i) ((x) = (y))
#endif 
#ifndef COPY_Diagrams_Picture_tag
#define COPY_Diagrams_Picture_tag(x) (x)
#endif

#ifndef NEW_Diagrams_Empty_kind
#define NEW_Diagrams_Empty_kind(x,y)	Diagrams_Empty_kind
#endif
#ifndef NEW_Diagrams_Box_kind
#define NEW_Diagrams_Box_kind(x,y)	Diagrams_Box_kind
#endif
#ifndef NEW_Diagrams_Curve_kind
#define NEW_Diagrams_Curve_kind(x,y)	Diagrams_Curve_kind
#endif
#ifndef NEW_Diagrams_Line_kind
#define NEW_Diagrams_Line_kind(x,y)	Diagrams_Line_kind
#endif
#ifndef NEW_Diagrams_Arrow_kind
#define NEW_Diagrams_Arrow_kind(x,y)	Diagrams_Arrow_kind
#endif
#ifndef NEW_Diagrams_Text_kind
#define NEW_Diagrams_Text_kind(x,y)	Diagrams_Text_kind
#endif
#ifndef NEW_Diagrams_OrBlock_kind
#define NEW_Diagrams_OrBlock_kind(x,y)	Diagrams_OrBlock_kind
#endif
#ifndef NEW_Diagrams_AndBlock_kind
#define NEW_Diagrams_AndBlock_kind(x,y)	Diagrams_AndBlock_kind
#endif
#ifndef NEW_Diagrams_AltBlock_kind
#define NEW_Diagrams_AltBlock_kind(x,y)	Diagrams_AltBlock_kind
#endif
#ifndef NEW_Diagrams_Compound_kind
#define NEW_Diagrams_Compound_kind(x,y)	Diagrams_Compound_kind
#endif
