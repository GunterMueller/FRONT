#include "Pictures_defs.h"
Pictures_Pictures (List_Pictures_Picture) : Pictures_Pictures		Pictures_Pictures_kind
Pictures_Compound (Float, Float, Float, Float, List_Pictures_Picture) : Pictures_Picture		Pictures_Compound_kind
Pictures_AltBlock (Float, Float, Float, Float, Pictures_Picture, Pictures_Picture, Bool) : Pictures_Picture		Pictures_AltBlock_kind
Pictures_AndBlock (Float, Float, Float, Float, List_Pictures_Picture, List_Pictures_Direction) : Pictures_Picture		Pictures_AndBlock_kind
Pictures_OrBlock (Float, Float, Float, Float, List_Pictures_Picture, List_Pictures_Direction) : Pictures_Picture		Pictures_OrBlock_kind
Pictures_Text (Float, Float, Float, Float, String, Ident) : Pictures_Picture		Pictures_Text_kind
Pictures_Arrow (Float, Float, Float, Float, Pictures_Direction) : Pictures_Picture		Pictures_Arrow_kind
Pictures_Line (Float, Float, Float, Float) : Pictures_Picture		Pictures_Line_kind
Pictures_Curve (Float, Float, Float, Float, Bool, Bool) : Pictures_Picture		Pictures_Curve_kind
Pictures_Arc (Float, Float, Float, Float, Float, Float) : Pictures_Picture		Pictures_Arc_kind
Pictures_Circle (Float, Float, Float, Float) : Pictures_Picture		Pictures_Circle_kind
Pictures_Box (Float, Float, Float, Float) : Pictures_Picture		Pictures_Box_kind
Pictures_Empty (Float, Float, Float, Float) : Pictures_Picture		Pictures_Empty_kind
Pictures_Scope () : Pictures_Scope		Pictures_Scope_kind
List_Pictures_Direction (Pictures_Direction, List_Pictures_Direction) : List_Pictures_Direction		List_Pictures_Direction_kind
List_Pictures_Picture (Pictures_Picture, List_Pictures_Picture) : List_Pictures_Picture		List_Pictures_Picture_kind
Pictures_Left () : Pictures_Direction		Pictures_Left
Pictures_Right () : Pictures_Direction		Pictures_Right
Pictures_Up () : Pictures_Direction		Pictures_Up
Pictures_Down () : Pictures_Direction		Pictures_Down
Pictures_Center () : Pictures_Direction		Pictures_Center
