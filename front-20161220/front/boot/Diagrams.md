#include "Diagrams_defs.h"
Diagrams_Diagrams (List_Diagrams_Picture) : Diagrams_Diagrams		Diagrams_Diagrams_kind
Diagrams_Compound (Int, Int, Int, Int, List_Diagrams_Picture) : Diagrams_Picture		Diagrams_Compound_kind
Diagrams_AltBlock (Int, Int, Int, Int, Diagrams_Picture, Diagrams_Picture, Bool) : Diagrams_Picture		Diagrams_AltBlock_kind
Diagrams_AndBlock (Int, Int, Int, Int, List_Diagrams_Picture, List_Diagrams_Direction) : Diagrams_Picture		Diagrams_AndBlock_kind
Diagrams_OrBlock (Int, Int, Int, Int, List_Diagrams_Picture, List_Diagrams_Direction) : Diagrams_Picture		Diagrams_OrBlock_kind
Diagrams_Text (Int, Int, Int, Int, String, Ident) : Diagrams_Picture		Diagrams_Text_kind
Diagrams_Arrow (Int, Int, Int, Int, Diagrams_Direction) : Diagrams_Picture		Diagrams_Arrow_kind
Diagrams_Line (Int, Int, Int, Int) : Diagrams_Picture		Diagrams_Line_kind
Diagrams_Curve (Int, Int, Int, Int, Bool, Bool) : Diagrams_Picture		Diagrams_Curve_kind
Diagrams_Box (Int, Int, Int, Int) : Diagrams_Picture		Diagrams_Box_kind
Diagrams_Empty (Int, Int, Int, Int) : Diagrams_Picture		Diagrams_Empty_kind
Diagrams_Scope () : Diagrams_Scope		Diagrams_Scope_kind
List_Diagrams_Direction (Diagrams_Direction, List_Diagrams_Direction) : List_Diagrams_Direction		List_Diagrams_Direction_kind
List_Diagrams_Picture (Diagrams_Picture, List_Diagrams_Picture) : List_Diagrams_Picture		List_Diagrams_Picture_kind
Diagrams_Left () : Diagrams_Direction		Diagrams_Left
Diagrams_Right () : Diagrams_Direction		Diagrams_Right
Diagrams_Up () : Diagrams_Direction		Diagrams_Up
Diagrams_Down () : Diagrams_Direction		Diagrams_Down
Diagrams_Center () : Diagrams_Direction		Diagrams_Center
