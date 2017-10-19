#ifndef TEST_ANY
#define TEST_ANY
static Bool
test_any (Pointer d, int n, unsigned int mask)
{
  int i;
  
  if (NUM_EDGES(d) != n) return FALSE;
  
  for (i = 0; i < n; i++) {
    if ((mask & (1<<i)) != 0 && IS_NULL(GET_Pointer(i, d))) return FALSE;
  }
  return TRUE;
}
#endif

static Bool contains_type (List_Types_struct_type l, Ident id);
static List_Types_struct_type insert_types (List_Types_struct_type l, List_Types_struct_type t, Ident super);
static List_Types_struct_type insert_type (List_Types_struct_type l, Types_struct_type t, Ident super);
static List_Types_struct_type map_nonterm (front_NonTerminal nt, List_Types_struct_type l);
static List_Types_struct_type sub_types (front_Rhs r);
static Types_struct_type alt_type (front_Alternative a);
static List_Types_struct_type alt_sub_types (List_front_Alternative l);
static List_Types_field alt_fields (front_Alternative a, Ident l, Ident alt);
static List_Types_field alt_sub_fields (List_front_Alternative l, Ident lab, Ident alt);
static List_Types_field sub_fields (front_Rhs r, Ident l, Ident alt);
static Ident get_super (front_Super s);
static front_NonTerminal super_nt (front_Super s);
static Ident type_id (front_NonTerminal nt, Ident id2);
static Ident imported_type_id (front_ImportedNonTerminal imp);
static Types_field make_field (Ident t, Ident id, Ident gram);
static Types_field make_bind_field (Ident t, Ident id);
static List_Types_field append_fields (List_Types_field l, List_Types_field m);
static List_Types_TypeName append_typenames (List_Types_TypeName l, List_Types_TypeName m);
static List_Ident append_idents (List_Ident l, List_Ident m);
static List_Types_field syms_fields (List_front_Symbol l, Ident id, Ident alt);
static Types_field field_fields (front_Field f);
static List_Types_field fields_fields (List_front_Field l, Ident id);
static List_front_FieldInit CONVERT_front_FieldInit_TO_List_front_FieldInit (front_FieldInit i);
static List_Types_TypeName CONVERT_front_Type_TO_List_Types_TypeName (front_Type t);
static List_Types_TypeName CONVERT_List_front_Type_TO_List_Types_TypeName (List_front_Type l);
static List_Types_field _rhs_fields (front_Rhs r, Ident id, Ident alt, Bool pre);
static List_Types_field rhs_fields (front_Rhs r, Ident id, Ident alt, Bool pre);
static List_Types_field defining (List_Types_field l, Ident alt, front_Symbol def);
static List_Types_field set_label (List_Types_field l, Ident lab);
static List_Types_field _sym_fields (front_Symbol s, Ident l, Ident alt);
static List_Types_field sym_fields (front_Symbol s, Ident l, Ident alt);
static List_Types_field Once (List_Types_field l, Ident id);
static List_Types_field Opt (List_Types_field l, Ident id);
static List_Types_field More (List_Types_field l, Ident id);
extern String append_string (String a, String b);
static Types_field ExtendType (Types_field f, String s);
static Ident CONVERT_String_TO_Ident (String s);
static String CONVERT_Ident_TO_String (Ident s);
static Types_EnumType Make_Enum (Types_struct_type t);
static Types_EnumType Make_Tag (Types_struct_type t);
static List_Types_TypeName get_enums (List_Types_struct_type l, String p, Bool e);
static List_Types_TypeName get_enum (Types_struct_type t, String p, Bool e);
static Bool no_fields (Types_struct_type t);
static Bool no_fieldss (List_Types_struct_type l);
static Types_field Overload (Types_field f, Bool o);
static List_Types_field remove_void_fields (List_Types_field f);
static Bool is_void_field (Types_field f);
/* Bool contains_type
  (lList_Types_struct_type({hd}=Types_struct_type(_,_,_,sub,_,_),tl),Ident id)
  -> Types_struct_type_name (hd)==id||contains_type (sub,id)||contains_type (tl,id)

;
*/
static Bool
contains_type (List_Types_struct_type l, Ident id)
{
  if ( List_Types_struct_type_HAS_OPER (l, List_Types_struct_type_kind)
      && Types_struct_type_HAS_OPER (List_Types_struct_type_GET_Types_struct_type (0, l), Types_struct_type_kind)
            ) {
    Types_struct_type hd = List_Types_struct_type_GET_Types_struct_type (0, l);
    List_Types_struct_type sub = Types_struct_type_GET_List_Types_struct_type (3, List_Types_struct_type_GET_Types_struct_type (0, l));
    List_Types_struct_type tl = List_Types_struct_type_GET_List_Types_struct_type (1, l);
    return Types_struct_type_name (hd) == id || contains_type (sub, id) || contains_type (tl, id);
  }
  return FALSE;
}

/* List_Types_struct_type insert_types
  (List_Types_struct_type l,List_Types_struct_type thd::tl,Ident super)
  -> insert_types (insert_type (l,hd,super),tl,super)

  ,(List_Types_struct_type l,List_Types_struct_type tNULL,Ident super)
   -> l

;
*/
static List_Types_struct_type
insert_types (List_Types_struct_type l, List_Types_struct_type t, Ident super)
{
  if (!IS_NULL(t)      ) {
    Types_struct_type hd = List_Types_struct_type_GET_Types_struct_type (0, t);
    List_Types_struct_type tl = List_Types_struct_type_GET_List_Types_struct_type (1, t);
    return insert_types (insert_type (l, hd, super), tl, super);
  }
  if ((t == NULL)      ) {
    return l;
  }
  return NULL;
}

/* List_Types_struct_type insert_type
  (List_Types_struct_type l,Types_struct_type t,Ident super)
  | l==NULL
  -> t::l

  ,(List_Types_struct_type lhd::tl,Types_struct_type t,Ident super)
   | super==NULL
   -> hd::insert_type (tl,t,super)

  ,(lList_Types_struct_type({t0}=Types_struct_type(_,u,f1,sub,f2,id),tl),Types_struct_type t,Ident super)
   | tg==super||contains_type (sub,super)
   -> t2::tl
     WHERE  
              Types_struct_type t1 = Types_struct_type (tg,u,f1,insert_type (sub,t,super),f2,id)
              Types_struct_type t2 = set_type_props (t1,t0)
              Ident tg = Types_struct_type_name (t0)

  ,(List_Types_struct_type lhd::tl,Types_struct_type t,Ident super)
   -> hd::insert_type (tl,t,super)

;
*/
static List_Types_struct_type
insert_type (List_Types_struct_type l, Types_struct_type t, Ident super)
{
  if (TRUE) {
    if (l == NULL) {
      return CREATE_LIST(List_Types_struct_type, t, l);
    }
  }
  if (!IS_NULL(l)      ) {
    Types_struct_type hd = List_Types_struct_type_GET_Types_struct_type (0, l);
    List_Types_struct_type tl = List_Types_struct_type_GET_List_Types_struct_type (1, l);
    if (super == NULL) {
      return CREATE_LIST(List_Types_struct_type, hd, insert_type (tl, t, super));
    }
  }
  if ( List_Types_struct_type_HAS_OPER (l, List_Types_struct_type_kind)
      && Types_struct_type_HAS_OPER (List_Types_struct_type_GET_Types_struct_type (0, l), Types_struct_type_kind)
            ) {
    Types_struct_type t0 = List_Types_struct_type_GET_Types_struct_type (0, l);
    Ident u = Types_struct_type_GET_Ident (1, List_Types_struct_type_GET_Types_struct_type (0, l));
    List_Types_field f1 = Types_struct_type_GET_List_Types_field (2, List_Types_struct_type_GET_Types_struct_type (0, l));
    List_Types_struct_type sub = Types_struct_type_GET_List_Types_struct_type (3, List_Types_struct_type_GET_Types_struct_type (0, l));
    List_Types_field f2 = Types_struct_type_GET_List_Types_field (4, List_Types_struct_type_GET_Types_struct_type (0, l));
    Ident id = Types_struct_type_GET_Ident (5, List_Types_struct_type_GET_Types_struct_type (0, l));
    List_Types_struct_type tl = List_Types_struct_type_GET_List_Types_struct_type (1, l);
    {
      Ident tg = Types_struct_type_name (t0);
      if (tg == super || contains_type (sub, super)) {
        Types_struct_type t1 = NEW_Types_struct_type (Types_struct_type_kind, tg, u, f1, insert_type (sub, t, super), f2, id, ins);
        Types_struct_type t2 = set_type_props (t1, t0);
        return CREATE_LIST(List_Types_struct_type, t2, tl);
      }
    }
  }
  if (!IS_NULL(l)      ) {
    Types_struct_type hd = List_Types_struct_type_GET_Types_struct_type (0, l);
    List_Types_struct_type tl = List_Types_struct_type_GET_List_Types_struct_type (1, l);
    return CREATE_LIST(List_Types_struct_type, hd, insert_type (tl, t, super));
  }
  return NULL;
}

/* List_Types_struct_type map_nonterm
  (ntfront_NonTerminal(_,_,id,_,_,_,_,front_PlainDef(_),_),List_Types_struct_type l)
  | contains_type (l,id)
  -> l

  ,(ntfront_NonTerminal(_,scan,_,s,_,_,_,front_PlainDef(_),_),List_Types_struct_type l)
   | scan==NULL&&!no_nt_type (nt)
   -> insert_type (l2,t,super)
     WHERE  
              front_Alternative alt = front_NonTerminal_alt (nt)
              Types_struct_type t = set_scope (alt_type (alt),alt)
              Ident super = get_super (s)
              List_Types_struct_type l2 = map_nonterm (super_nt (s),l)

  ,(ntfront_NonTerminal(_,scan,_,s,_,_,_,front_PlainDef(_),_),List_Types_struct_type l)
   | scan==NULL&&(!no_nt_type (nt)||sub!=NULL)
   -> insert_types (l2,sub,super)
     WHERE  
              front_Alternative alt = front_NonTerminal_alt (nt)
              Types_struct_type t = alt_type (alt)
              List_Types_struct_type sub = Types_struct_type_sub_types (t)
              Ident super = get_super (s)
              List_Types_struct_type l2 = map_nonterm (super_nt (s),l)

  ,(front_NonTerminal nt,List_Types_struct_type l)
   | nt!=NULL
   -> l
     WHERE  
              front_Alternative alt = front_NonTerminal_alt (nt)
              Types_struct_type t = alt_type (alt)

  ,(front_NonTerminal nt,List_Types_struct_type l)
   -> l

;
*/
static List_Types_struct_type
map_nonterm (front_NonTerminal nt, List_Types_struct_type l)
{
  if ( front_NonTerminal_HAS_OPER (nt, front_NonTerminal_kind)
      && front_Defines_HAS_OPER (front_NonTerminal_GET_front_Defines (7, nt), front_PlainDef_kind)
            ) {
    Ident id = front_NonTerminal_GET_Ident (2, nt);
    if (contains_type (l, id)) {
      return l;
    }
  }
  if ( front_NonTerminal_HAS_OPER (nt, front_NonTerminal_kind)
      && front_Defines_HAS_OPER (front_NonTerminal_GET_front_Defines (7, nt), front_PlainDef_kind)
            ) {
    front_ScanInfo scan = front_NonTerminal_GET_front_ScanInfo (1, nt);
    front_Super s = front_NonTerminal_GET_front_Super (3, nt);
    {
      if (scan == NULL && ! no_nt_type (nt)) {
        front_Alternative alt = front_NonTerminal_alt (nt);
        Types_struct_type t = set_scope (alt_type (alt), alt);
        Ident super = get_super (s);
        List_Types_struct_type l2 = map_nonterm (super_nt (s), l);
        return insert_type (l2, t, super);
      }
    }
  }
  if ( front_NonTerminal_HAS_OPER (nt, front_NonTerminal_kind)
      && front_Defines_HAS_OPER (front_NonTerminal_GET_front_Defines (7, nt), front_PlainDef_kind)
            ) {
    front_ScanInfo scan = front_NonTerminal_GET_front_ScanInfo (1, nt);
    front_Super s = front_NonTerminal_GET_front_Super (3, nt);
    {
      front_Alternative alt = front_NonTerminal_alt (nt);
      Types_struct_type t = alt_type (alt);
      List_Types_struct_type sub = Types_struct_type_sub_types (t);
      if (scan == NULL && (! no_nt_type (nt) || sub != NULL)) {
        Ident super = get_super (s);
        List_Types_struct_type l2 = map_nonterm (super_nt (s), l);
        return insert_types (l2, sub, super);
      }
    }
  }
  if (TRUE) {
    {
      if (nt != NULL) {
        front_Alternative alt = front_NonTerminal_alt (nt);
        Types_struct_type t = alt_type (alt);
        return l;
      }
    }
  }
  if (TRUE) {
    return l;
  }
  return NULL;
}

/* List_Types_struct_type sub_types
  (rfront_Rhs(_,_,_,alts,_,_,_,_))
  -> alt_sub_types (alts)

;
*/
static List_Types_struct_type
sub_types (front_Rhs r)
{
  if ( front_Rhs_HAS_OPER (r, front_Rhs_kind)
            ) {
    List_front_Alternative alts = front_Rhs_GET_List_front_Alternative (3, r);
    return alt_sub_types (alts);
  }
  return NULL;
}

/* Types_struct_type alt_type
  (afront_LabeledAlt(id,_,_,_,rhs))
  -> set_checks (Types_struct_type (id,user (),f1,sub,f2,id),front_Rhs_checklist (rhs))
    WHERE  
             List_Types_struct_type sub = sub_types (rhs)
             List_Types_field f1 = rhs_fields (rhs,NULL,id,TRUE)
             List_Types_field f2 = rhs_fields (rhs,NULL,id,FALSE)

  ,(afront_UnLabeledAlt(syms))
   -> Types_struct_type (NULL,user (),f,NULL,NULL,NULL)
     WHERE  
              List_Types_field f = sym_fields (syms,NULL,NULL)

;
*/
static Types_struct_type
alt_type (front_Alternative a)
{
  if ( front_Alternative_HAS_OPER (a, front_LabeledAlt_kind)
            ) {
    Ident id = front_LabeledAlt_GET_Ident (0, a);
    front_Rhs rhs = front_LabeledAlt_GET_front_Rhs (4, a);
    {
      List_Types_struct_type sub = sub_types (rhs);
      List_Types_field f1 = rhs_fields (rhs, NULL, id, TRUE);
      List_Types_field f2 = rhs_fields (rhs, NULL, id, FALSE);
      return set_checks (NEW_Types_struct_type (Types_struct_type_kind, id, user (), f1, sub, f2, id, ins), front_Rhs_checklist (rhs));
    }
  }
  if ( front_Alternative_HAS_OPER (a, front_UnLabeledAlt_kind)
            ) {
    front_Symbol syms = front_UnLabeledAlt_GET_front_Symbol (0, a);
    {
      List_Types_field f = sym_fields (syms, NULL, NULL);
      return NEW_Types_struct_type (Types_struct_type_kind, NULL, user (), f, NULL, NULL, NULL, ins);
    }
  }
  return NULL;
}

/* List_Types_struct_type alt_sub_types
  (List_front_Alternative lhd::tl)
  | t!=NULL
  -> t::alt_sub_types (tl)
    WHERE  
             Types_struct_type t = set_scope (alt_type (hd),hd)

  ,(List_front_Alternative l_::tl)
   -> alt_sub_types (tl)

;
*/
static List_Types_struct_type
alt_sub_types (List_front_Alternative l)
{
  if (!IS_NULL(l)      ) {
    front_Alternative hd = List_front_Alternative_GET_front_Alternative (0, l);
    List_front_Alternative tl = List_front_Alternative_GET_List_front_Alternative (1, l);
    {
      Types_struct_type t = set_scope (alt_type (hd), hd);
      if (t != NULL) {
        return CREATE_LIST(List_Types_struct_type, t, alt_sub_types (tl));
      }
    }
  }
  if (!IS_NULL(l)      ) {
    List_front_Alternative tl = List_front_Alternative_GET_List_front_Alternative (1, l);
    return alt_sub_types (tl);
  }
  return NULL;
}

/* List_Types_field alt_fields
  (afront_LabeledAlt(id,_,_,_,rhs),Ident l,Ident alt)
  -> append_fields (f1,append_fields (sub,f2))
    WHERE  
             List_Types_field sub = sub_fields (rhs,l,alt)
             List_Types_field f1 = rhs_fields (rhs,NULL,id,TRUE)
             List_Types_field f2 = rhs_fields (rhs,NULL,id,FALSE)

  ,(afront_UnLabeledAlt(syms),Ident l,Ident alt)
   -> sym_fields (syms,l,alt)

;
*/
static List_Types_field
alt_fields (front_Alternative a, Ident l, Ident alt)
{
  if ( front_Alternative_HAS_OPER (a, front_LabeledAlt_kind)
            ) {
    Ident id = front_LabeledAlt_GET_Ident (0, a);
    front_Rhs rhs = front_LabeledAlt_GET_front_Rhs (4, a);
    {
      List_Types_field sub = sub_fields (rhs, l, alt);
      List_Types_field f1 = rhs_fields (rhs, NULL, id, TRUE);
      List_Types_field f2 = rhs_fields (rhs, NULL, id, FALSE);
      return append_fields (f1, append_fields (sub, f2));
    }
  }
  if ( front_Alternative_HAS_OPER (a, front_UnLabeledAlt_kind)
            ) {
    front_Symbol syms = front_UnLabeledAlt_GET_front_Symbol (0, a);
    return sym_fields (syms, l, alt);
  }
  return NULL;
}

/* List_Types_field alt_sub_fields
  (lList_front_Alternative({hd}=front_UnLabeledAlt(_),tl),Ident lab,Ident alt)
  | tl!=NULL
  -> alt_sub_fields (tl,lab,alt)
    WHERE  
             List_Types_field t = alt_fields (hd,lab,alt)

  ,(List_front_Alternative lhd::tl,Ident lab,Ident alt)
   | t!=NULL
   -> append_fields (t,alt_sub_fields (tl,lab,alt))
     WHERE  
              List_Types_field t = alt_fields (hd,lab,alt)

  ,(List_front_Alternative lhd::tl,Ident lab,Ident alt)
   -> alt_sub_fields (tl,lab,alt)
     WHERE  
              List_Types_field t = alt_fields (hd,lab,alt)

;
*/
static List_Types_field
alt_sub_fields (List_front_Alternative l, Ident lab, Ident alt)
{
  if ( List_front_Alternative_HAS_OPER (l, List_front_Alternative_kind)
      && front_Alternative_HAS_OPER (List_front_Alternative_GET_front_Alternative (0, l), front_UnLabeledAlt_kind)
            ) {
    front_Alternative hd = List_front_Alternative_GET_front_Alternative (0, l);
    List_front_Alternative tl = List_front_Alternative_GET_List_front_Alternative (1, l);
    {
      if (tl != NULL) {
        List_Types_field t = alt_fields (hd, lab, alt);
        return alt_sub_fields (tl, lab, alt);
      }
    }
  }
  if (!IS_NULL(l)      ) {
    front_Alternative hd = List_front_Alternative_GET_front_Alternative (0, l);
    List_front_Alternative tl = List_front_Alternative_GET_List_front_Alternative (1, l);
    {
      List_Types_field t = alt_fields (hd, lab, alt);
      if (t != NULL) {
        return append_fields (t, alt_sub_fields (tl, lab, alt));
      }
    }
  }
  if (!IS_NULL(l)      ) {
    front_Alternative hd = List_front_Alternative_GET_front_Alternative (0, l);
    List_front_Alternative tl = List_front_Alternative_GET_List_front_Alternative (1, l);
    {
      List_Types_field t = alt_fields (hd, lab, alt);
      return alt_sub_fields (tl, lab, alt);
    }
  }
  return NULL;
}

/* List_Types_field sub_fields
  (rfront_Rhs(_,_,_,alts,_,_,_,_),Ident l,Ident alt)
  -> alt_sub_fields (alts,l,alt)

;
*/
static List_Types_field
sub_fields (front_Rhs r, Ident l, Ident alt)
{
  if ( front_Rhs_HAS_OPER (r, front_Rhs_kind)
            ) {
    List_front_Alternative alts = front_Rhs_GET_List_front_Alternative (3, r);
    return alt_sub_fields (alts, l, alt);
  }
  return NULL;
}

/* Ident get_super
  (sfront_SubType(_,id))
  -> id

  ,(sfront_NoType(id))
   -> id

;
*/
static Ident
get_super (front_Super s)
{
  if ( front_Super_HAS_OPER (s, front_SubType_kind)
            ) {
    Ident id = front_SubType_GET_Ident (1, s);
    return id;
  }
  if ( front_Super_HAS_OPER (s, front_NoType_kind)
            ) {
    Ident id = front_NoType_GET_Ident (0, s);
    return id;
  }
  return NULL;
}

/* front_NonTerminal super_nt
  (sfront_SubType(_,_))
  -> front_Super_super (s)

;
*/
static front_NonTerminal
super_nt (front_Super s)
{
  if ( front_Super_HAS_OPER (s, front_SubType_kind)
            ) {
    return front_Super_super (s);
  }
  return NULL;
}

/* Ident type_id
  (ntfront_NonTerminal(_,front_ScanInfo(front_Type(id,_),_),_,_,_,_,_,_,_),Ident id2)
  -> id

  ,(ntfront_NonTerminal(_,_,id,s,_,_,_,_,_),Ident id2)
   -> IF super!=NULL THEN super ELSE id FI
     WHERE  
              Ident super = get_super (s)

  ,(front_NonTerminal nt,Ident id2)
   -> id2

;
*/
static Ident
type_id (front_NonTerminal nt, Ident id2)
{
  if ( front_NonTerminal_HAS_OPER (nt, front_NonTerminal_kind)
      && front_ScanInfo_HAS_OPER (front_NonTerminal_GET_front_ScanInfo (1, nt), front_ScanInfo_kind)
      && front_Type_HAS_OPER (front_ScanInfo_GET_front_Type (0, front_NonTerminal_GET_front_ScanInfo (1, nt)), front_Type_kind)
            ) {
    Ident id = front_Type_GET_Ident (0, front_ScanInfo_GET_front_Type (0, front_NonTerminal_GET_front_ScanInfo (1, nt)));
    return id;
  }
  if ( front_NonTerminal_HAS_OPER (nt, front_NonTerminal_kind)
            ) {
    Ident id = front_NonTerminal_GET_Ident (2, nt);
    front_Super s = front_NonTerminal_GET_front_Super (3, nt);
    {
      Ident super = get_super (s);
      return (super != NULL ? super : id);
    }
  }
  if (TRUE) {
    return id2;
  }
  return NULL;
}

/* Ident imported_type_id
  (impfront_ImportedNonTerminal(_,type))
  | type!=NULL
  -> type

  ,(impfront_ImportedNonTerminal(id,_))
   -> id

;
*/
static Ident
imported_type_id (front_ImportedNonTerminal imp)
{
  if ( front_ImportedNonTerminal_HAS_OPER (imp, front_ImportedNonTerminal_kind)
            ) {
    Ident type = front_ImportedNonTerminal_GET_Ident (1, imp);
    if (type != NULL) {
      return type;
    }
  }
  if ( front_ImportedNonTerminal_HAS_OPER (imp, front_ImportedNonTerminal_kind)
            ) {
    Ident id = front_ImportedNonTerminal_GET_Ident (0, imp);
    return id;
  }
  return NULL;
}

/* Types_field make_field
  (Ident t,Ident id,Ident gram)
  -> field_set_grammar (Types_field (make_TypeName (t,prefix_type (t))::NULL,id),gram)

;
*/
static Types_field
make_field (Ident t, Ident id, Ident gram)
{
  if (TRUE) {
    return field_set_grammar (NEW_Types_field (Types_field_kind, CREATE_LIST(List_Types_TypeName, make_TypeName (t, prefix_type (t)), NULL), id, ins), gram);
  }
  return NULL;
}

/* Types_field make_bind_field
  (Ident t,Ident id)
  -> add_expr (field_set_grammar (Types_field (make_TypeName (t,prefix_type (t))::NULL,id),Rootid),NULL,FALSE,FALSE,TRUE)

;
*/
static Types_field
make_bind_field (Ident t, Ident id)
{
  if (TRUE) {
    return add_expr (field_set_grammar (NEW_Types_field (Types_field_kind, CREATE_LIST(List_Types_TypeName, make_TypeName (t, prefix_type (t)), NULL), id, ins), Rootid), NULL, FALSE, FALSE, TRUE);
  }
  return NULL;
}

/* List_Types_field append_fields
  (List_Types_field l,List_Types_field mNULL)
  -> l

  ,(List_Types_field lNULL,List_Types_field m)
   -> m

  ,(List_Types_field lhd::tl,List_Types_field m)
   -> hd::append_fields (tl,m)

;
*/
static List_Types_field
append_fields (List_Types_field l, List_Types_field m)
{
  if ((m == NULL)      ) {
    return l;
  }
  if ((l == NULL)      ) {
    return m;
  }
  if (!IS_NULL(l)      ) {
    Types_field hd = List_Types_field_GET_Types_field (0, l);
    List_Types_field tl = List_Types_field_GET_List_Types_field (1, l);
    return CREATE_LIST(List_Types_field, hd, append_fields (tl, m));
  }
  return NULL;
}

/* List_Types_TypeName append_typenames
  (List_Types_TypeName l,List_Types_TypeName mNULL)
  -> l

  ,(List_Types_TypeName lNULL,List_Types_TypeName m)
   -> m

  ,(List_Types_TypeName lhd::tl,List_Types_TypeName m)
   -> hd::append_typenames (tl,m)

;
*/
static List_Types_TypeName
append_typenames (List_Types_TypeName l, List_Types_TypeName m)
{
  if ((m == NULL)      ) {
    return l;
  }
  if ((l == NULL)      ) {
    return m;
  }
  if (!IS_NULL(l)      ) {
    Types_TypeName hd = List_Types_TypeName_GET_Types_TypeName (0, l);
    List_Types_TypeName tl = List_Types_TypeName_GET_List_Types_TypeName (1, l);
    return CREATE_LIST(List_Types_TypeName, hd, append_typenames (tl, m));
  }
  return NULL;
}

/* List_Ident append_idents
  (List_Ident l,List_Ident mNULL)
  -> l

  ,(List_Ident lNULL,List_Ident m)
   -> m

  ,(List_Ident lhd::tl,List_Ident m)
   -> hd::append_idents (tl,m)

;
*/
static List_Ident
append_idents (List_Ident l, List_Ident m)
{
  if ((m == NULL)      ) {
    return l;
  }
  if ((l == NULL)      ) {
    return m;
  }
  if (!IS_NULL(l)      ) {
    Ident hd = List_Ident_GET_Ident (0, l);
    List_Ident tl = List_Ident_GET_List_Ident (1, l);
    return CREATE_LIST(List_Ident, hd, append_idents (tl, m));
  }
  return NULL;
}

/* List_Types_field syms_fields
  (List_front_Symbol lhd::tl,Ident id,Ident alt)
  -> append_fields (sym_fields (hd,id,alt),syms_fields (tl,id,alt))

;
*/
static List_Types_field
syms_fields (List_front_Symbol l, Ident id, Ident alt)
{
  if (!IS_NULL(l)      ) {
    front_Symbol hd = List_front_Symbol_GET_front_Symbol (0, l);
    List_front_Symbol tl = List_front_Symbol_GET_List_front_Symbol (1, l);
    return append_fields (sym_fields (hd, id, alt), syms_fields (tl, id, alt));
  }
  return NULL;
}

/* Types_field field_fields
  (front_Field ffront_Field(id,t,_,when,trav,clear,dont))
  -> add_expr (field_set_grammar (Types_field (t,id),Rootid),when,trav,clear,dont)

;
*/
static Types_field
field_fields (front_Field f)
{
  if ( front_Field_HAS_OPER (f, front_Field_kind)
            ) {
    Ident id = front_Field_GET_Ident (0, f);
    front_Type t = front_Field_GET_front_Type (1, f);
    List_front_FieldInit when = front_Field_GET_List_front_FieldInit (3, f);
    Bool trav = front_Field_GET_Bool (4, f);
    Bool clear = front_Field_GET_Bool (5, f);
    Bool dont = front_Field_GET_Bool (6, f);
    return add_expr (field_set_grammar (NEW_Types_field (Types_field_kind, CONVERT_front_Type_TO_List_Types_TypeName (t), id, ins), Rootid), when, trav, clear, dont);
  }
  return NULL;
}

/* List_Types_field fields_fields
  (List_front_Field lhd::tl,Ident id)
  | hd==NULL
  -> fields_fields (tl,id)

  ,(List_front_Field lhd::tl,Ident id)
   -> field_fields (hd)::fields_fields (tl,id)

;
*/
static List_Types_field
fields_fields (List_front_Field l, Ident id)
{
  if (!IS_NULL(l)      ) {
    front_Field hd = List_front_Field_GET_front_Field (0, l);
    List_front_Field tl = List_front_Field_GET_List_front_Field (1, l);
    if (hd == NULL) {
      return fields_fields (tl, id);
    }
  }
  if (!IS_NULL(l)      ) {
    front_Field hd = List_front_Field_GET_front_Field (0, l);
    List_front_Field tl = List_front_Field_GET_List_front_Field (1, l);
    return CREATE_LIST(List_Types_field, field_fields (hd), fields_fields (tl, id));
  }
  return NULL;
}

/* List_front_FieldInit CONVERT_front_FieldInit_TO_List_front_FieldInit
  (front_FieldInit i)
  -> i::NULL

;
*/
static List_front_FieldInit
CONVERT_front_FieldInit_TO_List_front_FieldInit (front_FieldInit i)
{
  if (TRUE) {
    return CREATE_LIST(List_front_FieldInit, i, NULL);
  }
  return NULL;
}

/* List_Types_TypeName CONVERT_front_Type_TO_List_Types_TypeName
  (front_Type tfront_Type(id,args))
  | front_Type_nt (t)!=NULL||front_Type_alt (t)!=NULL
  -> make_TypeName (id,prefix_type (id))::CONVERT_List_front_Type_TO_List_Types_TypeName (args)

  ,(front_Type tfront_Type(id,args))
   -> make_TypeName (id,id)::CONVERT_List_front_Type_TO_List_Types_TypeName (args)

;
*/
static List_Types_TypeName
CONVERT_front_Type_TO_List_Types_TypeName (front_Type t)
{
  if ( front_Type_HAS_OPER (t, front_Type_kind)
            ) {
    Ident id = front_Type_GET_Ident (0, t);
    List_front_Type args = front_Type_GET_List_front_Type (1, t);
    if (front_Type_nt (t) != NULL || front_Type_alt (t) != NULL) {
      return CREATE_LIST(List_Types_TypeName, make_TypeName (id, prefix_type (id)), CONVERT_List_front_Type_TO_List_Types_TypeName (args));
    }
  }
  if ( front_Type_HAS_OPER (t, front_Type_kind)
            ) {
    Ident id = front_Type_GET_Ident (0, t);
    List_front_Type args = front_Type_GET_List_front_Type (1, t);
    return CREATE_LIST(List_Types_TypeName, make_TypeName (id, id), CONVERT_List_front_Type_TO_List_Types_TypeName (args));
  }
  return NULL;
}

/* List_Types_TypeName CONVERT_List_front_Type_TO_List_Types_TypeName
  (List_front_Type lhd::tl)
  -> append_typenames (hd,tl)

;
*/
static List_Types_TypeName
CONVERT_List_front_Type_TO_List_Types_TypeName (List_front_Type l)
{
  if (!IS_NULL(l)      ) {
    front_Type hd = List_front_Type_GET_front_Type (0, l);
    List_front_Type tl = List_front_Type_GET_List_front_Type (1, l);
    return append_typenames (CONVERT_front_Type_TO_List_Types_TypeName (hd), CONVERT_List_front_Type_TO_List_Types_TypeName (tl));
  }
  return NULL;
}

/* List_Types_field _rhs_fields
  (rfront_Rhs(_,s1,_,_,_,_,_,_),Ident id,Ident alt,Bool pre)
  | pre
  -> sym_fields (s1,id,alt)

  ,(rfront_Rhs(_,_,_,_,_,_,s2,_),Ident id,Ident alt,Bool pre)
   -> sym_fields (s2,id,alt)

;
*/
static List_Types_field
_rhs_fields (front_Rhs r, Ident id, Ident alt, Bool pre)
{
  if ( front_Rhs_HAS_OPER (r, front_Rhs_kind)
            ) {
    front_Symbol s1 = front_Rhs_GET_front_Symbol (1, r);
    if (pre) {
      return sym_fields (s1, id, alt);
    }
  }
  if ( front_Rhs_HAS_OPER (r, front_Rhs_kind)
            ) {
    front_Symbol s2 = front_Rhs_GET_front_Symbol (6, r);
    return sym_fields (s2, id, alt);
  }
  return NULL;
}

/* List_Types_field rhs_fields
  (front_Rhs r,Ident id,Ident alt,Bool pre)
  -> IF pre THEN set_rhs_fields (r,f) ELSE f FI
    WHERE  
             List_Types_field f = _rhs_fields (r,id,alt,pre)

;
*/
static List_Types_field
rhs_fields (front_Rhs r, Ident id, Ident alt, Bool pre)
{
  if (TRUE) {
    {
      List_Types_field f = _rhs_fields (r, id, alt, pre);
      return (pre ? set_rhs_fields (r, f) : f);
    }
  }
  return NULL;
}

/* List_Types_field defining
  (List_Types_field lhd::tl,Ident alt,front_Symbol def)
  -> add_field_defining (hd,def)::add_create (b,"NULL")::defining (tl,alt,def)
    WHERE  
             Ident bid = bind_id (hd)
             Types_field b1 = ExtendType (make_bind_field (alt,bid),"Bind")
             Types_field b = Overload (b1,is_list_field (hd))

;
*/
static List_Types_field
defining (List_Types_field l, Ident alt, front_Symbol def)
{
  if (!IS_NULL(l)      ) {
    Types_field hd = List_Types_field_GET_Types_field (0, l);
    List_Types_field tl = List_Types_field_GET_List_Types_field (1, l);
    {
      Ident bid = bind_id (hd);
      Types_field b1 = ExtendType (make_bind_field (alt, bid), "Bind");
      Types_field b = Overload (b1, is_list_field (hd));
      return CREATE_LIST(List_Types_field, add_field_defining (hd, def), CREATE_LIST(List_Types_field, add_create (b, "NULL"), defining (tl, alt, def)));
    }
  }
  return NULL;
}

/* List_Types_field set_label
  (List_Types_field lhd::NULL,Ident lab)
  | lab!=NULL
  -> rename_field (hd,lab)::NULL

  ,(List_Types_field l,Ident lab)
   -> l

;
*/
static List_Types_field
set_label (List_Types_field l, Ident lab)
{
  if (!IS_NULL(l)&& (List_Types_field_GET_List_Types_field (1, l) == NULL)      ) {
    Types_field hd = List_Types_field_GET_Types_field (0, l);
    if (lab != NULL) {
      return CREATE_LIST(List_Types_field, rename_field (hd, lab), NULL);
    }
  }
  if (TRUE) {
    return l;
  }
  return NULL;
}

/* List_Types_field _sym_fields
  (sfront_LabeledSym(id,s1),Ident l,Ident alt)
  -> set_label (sym_fields (s1,id,alt),id)

  ,(sfront_CompareSym(s1,c),Ident l,Ident alt)
   -> add_compare (sym_fields (s1,l,alt),c)

  ,(sfront_AppliedSym(n,front_AppliedName(),id,_,_),Ident l,Ident alt)
   -> f::Overload (f2,o)::Overload (f3,o)::NULL
     WHERE  
              Types_field f = make_field (id,Create_Ident (append_string (l,"_id")),Rootid)
              Types_field b = ExtendType (make_field (n,Create_Ident (append_string (l,"_bind")),Rootid),"Bind")
              Types_field a = make_field (n,l,Rootid)
              Types_field f2 = add_field_applied (add_create (b,"NULL"),s,l)
              Types_field f3 = add_create (a,"NULL")
              Bool o = applied_overloaded (s)

  ,(sfront_AppliedSym(n,front_AppliedField(),_,_,_),Ident l,Ident alt)
   -> Overload (f2,o)::Overload (f3,o)::NULL
     WHERE  
              Types_field b = ExtendType (make_field (n,Create_Ident (append_string (l,"_bind")),Rootid),"Bind")
              Types_field a = make_field (n,l,Rootid)
              Types_field f2 = add_field_applied (add_create (b,"NULL"),s,l)
              Types_field f3 = add_create (a,"NULL")
              Bool o = applied_overloaded (s)

  ,(sfront_StringSymbol(_,_,t),Ident l,Ident alt)
   | t!=NULL
   -> field_set_grammar (Types_field (t,l),Rootid)::NULL

  ,(sfront_CharSymbol(_,t),Ident l,Ident alt)
   | t!=NULL
   -> field_set_grammar (Types_field (t,l),Rootid)::NULL

  ,(sfront_KeywordSymbol(_,t),Ident l,Ident alt)
   | t!=NULL
   -> field_set_grammar (Types_field (t,l),Rootid)::NULL

  ,(sfront_SymbolSeq(t,f,_),Ident l,Ident alt)
   -> append_fields (syms_fields (t,l,alt),fields_fields (f,l))

  ,(sfront_IdSym(id,NULL),Ident l,Ident alt)
   -> IF is_macro (nt) THEN remove_void_fields (alt_fields (front_NonTerminal_alt (nt),l,alt)) ELSIF imp!=NULL THEN make_field (imptype,l,front_ImportedNonTerminal_grammar (imp))::NULL ELSIF nt!=NULL||TermType (type) THEN make_field (type,l,Rootid)::NULL ELSE NULL FI
     WHERE  
              front_NonTerminal nt = front_IdSym_nt (s)
              front_ImportedNonTerminal imp = front_IdSym_import (s)
              Ident type = type_id (nt,id)
              Ident imptype = imported_type_id (imp)

  ,(sfront_IdSym(_,t),Ident l,Ident alt)
   -> field_set_grammar (Types_field (t,l),Rootid)::NULL

  ,(sfront_OnceSymbol(alts,_),Ident l,Ident alt)
   -> Once (syms_fields (alts,l,alt),l)

  ,(sfront_OptSymbol(alts,_,i),Ident l,Ident alt)
   -> Opt (syms_fields (alts,l,alt),l)

  ,(sfront_MoreSymbol(alts,_,_),Ident l,Ident alt)
   -> More (syms_fields (alts,l,alt),l)

  ,(sfront_OptMoreSymbol(alts,_),Ident l,Ident alt)
   -> More (syms_fields (alts,l,alt),l)

  ,(sfront_DefiningSym(_,_,front_DefId(s1),_,_),Ident l,Ident alt)
   -> defining (sym_fields (s1,l,alt),alt,s)

  ,(sfront_DefiningSym(_,_,front_DefExpr(e),_,_),Ident l,Ident alt)
   -> defining (g::NULL,alt,s)
     WHERE  
              Types_field f = make_field (Create_Ident ("Ident"),Create_Ident ("_id"),Rootid)
              Types_field g = add_expr (f,front_WhenCreate (TRUE,e),FALSE,FALSE,FALSE)

  ,(sfront_AltSymbol(s1,_,s2),Ident l,Ident alt)
   -> More (append_fields (sym_fields (s1,l,alt),syms_fields (s2,l,alt)),l)

;
*/
static List_Types_field
_sym_fields (front_Symbol s, Ident l, Ident alt)
{
  if ( front_Symbol_HAS_OPER (s, front_LabeledSym_kind)
            ) {
    Ident id = front_LabeledSym_GET_Ident (0, s);
    front_Symbol s1 = front_LabeledSym_GET_front_Symbol (1, s);
    return set_label (sym_fields (s1, id, alt), id);
  }
  if ( front_Symbol_HAS_OPER (s, front_CompareSym_kind)
            ) {
    front_Symbol s1 = front_CompareSym_GET_front_Symbol (0, s);
    Ident c = front_CompareSym_GET_Ident (1, s);
    return add_compare (sym_fields (s1, l, alt), c);
  }
  if ( front_Symbol_HAS_OPER (s, front_AppliedSym_kind)
      && front_NameOrField_HAS_OPER (front_AppliedSym_GET_front_NameOrField (1, s), front_AppliedName)
            ) {
    Ident n = front_AppliedSym_GET_Ident (0, s);
    Ident id = front_AppliedSym_GET_Ident (2, s);
    {
      Types_field f = make_field (id, Create_Ident (append_string (CONVERT_Ident_TO_String (l), "_id")), Rootid);
      Types_field b = ExtendType (make_field (n, Create_Ident (append_string (CONVERT_Ident_TO_String (l), "_bind")), Rootid), "Bind");
      Types_field a = make_field (n, l, Rootid);
      Types_field f2 = add_field_applied (add_create (b, "NULL"), s, l);
      Types_field f3 = add_create (a, "NULL");
      Bool o = applied_overloaded (s);
      return CREATE_LIST(List_Types_field, f, CREATE_LIST(List_Types_field, Overload (f2, o), CREATE_LIST(List_Types_field, Overload (f3, o), NULL)));
    }
  }
  if ( front_Symbol_HAS_OPER (s, front_AppliedSym_kind)
      && front_NameOrField_HAS_OPER (front_AppliedSym_GET_front_NameOrField (1, s), front_AppliedField)
            ) {
    Ident n = front_AppliedSym_GET_Ident (0, s);
    {
      Types_field b = ExtendType (make_field (n, Create_Ident (append_string (CONVERT_Ident_TO_String (l), "_bind")), Rootid), "Bind");
      Types_field a = make_field (n, l, Rootid);
      Types_field f2 = add_field_applied (add_create (b, "NULL"), s, l);
      Types_field f3 = add_create (a, "NULL");
      Bool o = applied_overloaded (s);
      return CREATE_LIST(List_Types_field, Overload (f2, o), CREATE_LIST(List_Types_field, Overload (f3, o), NULL));
    }
  }
  if ( front_Symbol_HAS_OPER (s, front_StringSymbol_kind)
            ) {
    front_Type t = front_StringSymbol_GET_front_Type (2, s);
    if (t != NULL) {
      return CREATE_LIST(List_Types_field, field_set_grammar (NEW_Types_field (Types_field_kind, CONVERT_front_Type_TO_List_Types_TypeName (t), l, ins), Rootid), NULL);
    }
  }
  if ( front_Symbol_HAS_OPER (s, front_CharSymbol_kind)
            ) {
    front_Type t = front_CharSymbol_GET_front_Type (1, s);
    if (t != NULL) {
      return CREATE_LIST(List_Types_field, field_set_grammar (NEW_Types_field (Types_field_kind, CONVERT_front_Type_TO_List_Types_TypeName (t), l, ins), Rootid), NULL);
    }
  }
  if ( front_Symbol_HAS_OPER (s, front_KeywordSymbol_kind)
            ) {
    front_Type t = front_KeywordSymbol_GET_front_Type (1, s);
    if (t != NULL) {
      return CREATE_LIST(List_Types_field, field_set_grammar (NEW_Types_field (Types_field_kind, CONVERT_front_Type_TO_List_Types_TypeName (t), l, ins), Rootid), NULL);
    }
  }
  if ( front_Symbol_HAS_OPER (s, front_SymbolSeq_kind)
            ) {
    List_front_Symbol t = front_SymbolSeq_GET_List_front_Symbol (0, s);
    List_front_Field f = front_SymbolSeq_GET_List_front_Field (1, s);
    return append_fields (syms_fields (t, l, alt), fields_fields (f, l));
  }
  if ( front_Symbol_HAS_OPER (s, front_IdSym_kind)
      && (front_IdSym_GET_front_Type (1, s) == NULL)      ) {
    Ident id = front_IdSym_GET_Ident (0, s);
    {
      front_NonTerminal nt = front_IdSym_nt (s);
      front_ImportedNonTerminal imp = front_IdSym_import (s);
      Ident type = type_id (nt, id);
      Ident imptype = imported_type_id (imp);
      return (is_macro (nt) ? remove_void_fields (alt_fields (front_NonTerminal_alt (nt), l, alt)) : imp != NULL ? CREATE_LIST(List_Types_field, make_field (imptype, l, front_ImportedNonTerminal_grammar (imp)), NULL) : nt != NULL || TermType (type) ? CREATE_LIST(List_Types_field, make_field (type, l, Rootid), NULL) : NULL);
    }
  }
  if ( front_Symbol_HAS_OPER (s, front_IdSym_kind)
            ) {
    front_Type t = front_IdSym_GET_front_Type (1, s);
    return CREATE_LIST(List_Types_field, field_set_grammar (NEW_Types_field (Types_field_kind, CONVERT_front_Type_TO_List_Types_TypeName (t), l, ins), Rootid), NULL);
  }
  if ( front_Symbol_HAS_OPER (s, front_OnceSymbol_kind)
            ) {
    List_front_Symbol alts = front_OnceSymbol_GET_List_front_Symbol (0, s);
    return Once (syms_fields (alts, l, alt), l);
  }
  if ( front_Symbol_HAS_OPER (s, front_OptSymbol_kind)
            ) {
    List_front_Symbol alts = front_OptSymbol_GET_List_front_Symbol (0, s);
    Bool i = front_OptSymbol_GET_Bool (2, s);
    return Opt (syms_fields (alts, l, alt), l);
  }
  if ( front_Symbol_HAS_OPER (s, front_MoreSymbol_kind)
            ) {
    List_front_Symbol alts = front_MoreSymbol_GET_List_front_Symbol (0, s);
    return More (syms_fields (alts, l, alt), l);
  }
  if ( front_Symbol_HAS_OPER (s, front_OptMoreSymbol_kind)
            ) {
    List_front_Symbol alts = front_OptMoreSymbol_GET_List_front_Symbol (0, s);
    return More (syms_fields (alts, l, alt), l);
  }
  if ( front_Symbol_HAS_OPER (s, front_DefiningSym_kind)
      && front_Defining_id_HAS_OPER (front_DefiningSym_GET_front_Defining_id (2, s), front_DefId_kind)
            ) {
    front_Symbol s1 = front_DefId_GET_front_Symbol (0, front_DefiningSym_GET_front_Defining_id (2, s));
    return defining (sym_fields (s1, l, alt), alt, s);
  }
  if ( front_Symbol_HAS_OPER (s, front_DefiningSym_kind)
      && front_Defining_id_HAS_OPER (front_DefiningSym_GET_front_Defining_id (2, s), front_DefExpr_kind)
            ) {
    front_Expr e = front_DefExpr_GET_front_Expr (0, front_DefiningSym_GET_front_Defining_id (2, s));
    {
      Types_field f = make_field (Create_Ident ("Ident"), Create_Ident ("_id"), Rootid);
      Types_field g = add_expr (f, CONVERT_front_FieldInit_TO_List_front_FieldInit (NEW_front_WhenCreate (front_WhenCreate_kind, TRUE, e, ins)), FALSE, FALSE, FALSE);
      return defining (CREATE_LIST(List_Types_field, g, NULL), alt, s);
    }
  }
  if ( front_Symbol_HAS_OPER (s, front_AltSymbol_kind)
            ) {
    front_Symbol s1 = front_AltSymbol_GET_front_Symbol (0, s);
    List_front_Symbol s2 = front_AltSymbol_GET_List_front_Symbol (2, s);
    return More (append_fields (sym_fields (s1, l, alt), syms_fields (s2, l, alt)), l);
  }
  return NULL;
}

/* List_Types_field sym_fields
  (front_Symbol s,Ident l,Ident alt)
  -> set_sym_fields (s,_sym_fields (s,l,alt))

;
*/
static List_Types_field
sym_fields (front_Symbol s, Ident l, Ident alt)
{
  if (TRUE) {
    return set_sym_fields (s, _sym_fields (s, l, alt));
  }
  return NULL;
}

/* List_Types_field Once
  (List_Types_field l_::NULL,Ident id)
  -> l

  ,(List_Types_field l,Ident id)
   -> Opt (l,id)

;
*/
static List_Types_field
Once (List_Types_field l, Ident id)
{
  if (!IS_NULL(l)&& (List_Types_field_GET_List_Types_field (1, l) == NULL)      ) {
    return l;
  }
  if (TRUE) {
    return Opt (l, id);
  }
  return NULL;
}

/* List_Types_field Opt
  (List_Types_field lNULL,Ident id)
  -> make_field (Create_Ident ("Bool"),id,Rootid)::NULL

  ,(List_Types_field lhd::tl,Ident id)
   -> f
     WHERE  
              List_Types_field f = ExtendType (hd,"Optional")::IF tl==NULL THEN NULL ELSE Opt (tl,id) FI

;
*/
static List_Types_field
Opt (List_Types_field l, Ident id)
{
  if ((l == NULL)      ) {
    return CREATE_LIST(List_Types_field, make_field (Create_Ident ("Bool"), id, Rootid), NULL);
  }
  if (!IS_NULL(l)      ) {
    Types_field hd = List_Types_field_GET_Types_field (0, l);
    List_Types_field tl = List_Types_field_GET_List_Types_field (1, l);
    {
      List_Types_field f = CREATE_LIST(List_Types_field, ExtendType (hd, "Optional"), (tl == NULL ? NULL : Opt (tl, id)));
      return f;
    }
  }
  return NULL;
}

/* List_Types_field More
  (List_Types_field lNULL,Ident id)
  -> make_field (Create_Ident ("Int"),id,Rootid)::NULL

  ,(List_Types_field lhd::tl,Ident id)
   -> ExtendType (hd,"List")::IF tl==NULL THEN NULL ELSE More (tl,id) FI

;
*/
static List_Types_field
More (List_Types_field l, Ident id)
{
  if ((l == NULL)      ) {
    return CREATE_LIST(List_Types_field, make_field (Create_Ident ("Int"), id, Rootid), NULL);
  }
  if (!IS_NULL(l)      ) {
    Types_field hd = List_Types_field_GET_Types_field (0, l);
    List_Types_field tl = List_Types_field_GET_List_Types_field (1, l);
    return CREATE_LIST(List_Types_field, ExtendType (hd, "List"), (tl == NULL ? NULL : More (tl, id)));
  }
  return NULL;
}

/* extern String append_string
  (String a,String b)
  -> Front_StrAllocf ("%s%s",a,b)

;
*/
String
append_string (String a, String b)
{
  if (TRUE) {
    return Front_StrAllocf ("%s%s", a, b);
  }
  return NULL;
}

/* Types_field ExtendType
  (fTypes_field(t,_),String s)
  -> retype_field (f,t1)
    WHERE  
             List_Types_TypeName t1 = make_TypeName (s,s)::t

;
*/
static Types_field
ExtendType (Types_field f, String s)
{
  if ( Types_field_HAS_OPER (f, Types_field_kind)
            ) {
    List_Types_TypeName t = Types_field_GET_List_Types_TypeName (0, f);
    {
      List_Types_TypeName t1 = CREATE_LIST(List_Types_TypeName, make_TypeName (CONVERT_String_TO_Ident (s), CONVERT_String_TO_Ident (s)), t);
      return retype_field (f, t1);
    }
  }
  return NULL;
}

/* Ident CONVERT_String_TO_Ident
  (String s)
  -> Create_Ident (s)

;
*/
static Ident
CONVERT_String_TO_Ident (String s)
{
  if (TRUE) {
    return Create_Ident (s);
  }
  return NULL;
}

/* String CONVERT_Ident_TO_String
  (Ident s)
  -> Ident_name (s)

;
*/
static String
CONVERT_Ident_TO_String (Ident s)
{
  if (TRUE) {
    return Ident_name (s);
  }
  return NULL;
}

/* Types_EnumType Make_Enum
  (tTypes_struct_type(_,_,_,u,_,_))
  | no_fields (t)
  -> Types_EnumType (e,id,id,id,List_Types_TypeName_size (e))
    WHERE  
             List_Types_TypeName e = get_enums (u,"",TRUE)
             Ident id = Types_struct_type_name (t)

;
*/
static Types_EnumType
Make_Enum (Types_struct_type t)
{
  if ( Types_struct_type_HAS_OPER (t, Types_struct_type_kind)
            ) {
    List_Types_struct_type u = Types_struct_type_GET_List_Types_struct_type (3, t);
    {
      if (no_fields (t)) {
        List_Types_TypeName e = get_enums (u, "", TRUE);
        Ident id = Types_struct_type_name (t);
        return NEW_Types_EnumType (Types_EnumType_kind, e, id, id, id, List_Types_TypeName_size (e), ins);
      }
    }
  }
  return NULL;
}

/* Types_EnumType Make_Tag
  (tTypes_struct_type(_,_,_,u,_,_))
  | e!=NULL
  -> Types_EnumType (e,id,id,id,List_Types_TypeName_size (e))
    WHERE  
             List_Types_TypeName e = get_enums (u,"_kind",FALSE)
             Ident id1 = Types_struct_type_name (t)
             Ident id = Create_Ident (append_string (id1,"_tag"))

;
*/
static Types_EnumType
Make_Tag (Types_struct_type t)
{
  if ( Types_struct_type_HAS_OPER (t, Types_struct_type_kind)
            ) {
    List_Types_struct_type u = Types_struct_type_GET_List_Types_struct_type (3, t);
    {
      List_Types_TypeName e = get_enums (u, "_kind", FALSE);
      if (e != NULL) {
        Ident id1 = Types_struct_type_name (t);
        Ident id = Create_Ident (append_string (CONVERT_Ident_TO_String (id1), "_tag"));
        return NEW_Types_EnumType (Types_EnumType_kind, e, id, id, id, List_Types_TypeName_size (e), ins);
      }
    }
  }
  return NULL;
}

/* List_Types_TypeName get_enums
  (List_Types_struct_type lhd::tl,String p,Bool e)
  -> append_typenames (get_enum (hd,p,e),get_enums (tl,p,e))

;
*/
static List_Types_TypeName
get_enums (List_Types_struct_type l, String p, Bool e)
{
  if (!IS_NULL(l)      ) {
    Types_struct_type hd = List_Types_struct_type_GET_Types_struct_type (0, l);
    List_Types_struct_type tl = List_Types_struct_type_GET_List_Types_struct_type (1, l);
    return append_typenames (get_enum (hd, p, e), get_enums (tl, p, e));
  }
  return NULL;
}

/* List_Types_TypeName get_enum
  (tTypes_struct_type(_,_,_,NULL,_,_),String p,Bool e)
  | e||!empty_struct (t)
  -> make_TypeName (s,abbreviate_id ("",s,""))::NULL
    WHERE  
             Ident s = Create_Ident (append_string (Types_struct_type_name (t),p))

  ,(tTypes_struct_type(_,_,_,u,_,_),String p,Bool e)
   -> get_enums (u,p,e)

;
*/
static List_Types_TypeName
get_enum (Types_struct_type t, String p, Bool e)
{
  if ( Types_struct_type_HAS_OPER (t, Types_struct_type_kind)
      && (Types_struct_type_GET_List_Types_struct_type (3, t) == NULL)      ) {
    {
      if (e || ! empty_struct (t)) {
        Ident s = Create_Ident (append_string (CONVERT_Ident_TO_String (Types_struct_type_name (t)), p));
        return CREATE_LIST(List_Types_TypeName, make_TypeName (s, abbreviate_id ("", s, "")), NULL);
      }
    }
  }
  if ( Types_struct_type_HAS_OPER (t, Types_struct_type_kind)
            ) {
    List_Types_struct_type u = Types_struct_type_GET_List_Types_struct_type (3, t);
    return get_enums (u, p, e);
  }
  return NULL;
}

/* Bool no_fields
  (tTypes_struct_type(_,_,NULL,NULL,NULL,_))
  -> TRUE

  ,(tTypes_struct_type(_,_,NULL,u,NULL,_))
   -> no_fieldss (u)

;
*/
static Bool
no_fields (Types_struct_type t)
{
  if ( Types_struct_type_HAS_OPER (t, Types_struct_type_kind)
      && (Types_struct_type_GET_List_Types_field (2, t) == NULL)&& (Types_struct_type_GET_List_Types_struct_type (3, t) == NULL)&& (Types_struct_type_GET_List_Types_field (4, t) == NULL)      ) {
    return TRUE;
  }
  if ( Types_struct_type_HAS_OPER (t, Types_struct_type_kind)
      && (Types_struct_type_GET_List_Types_field (2, t) == NULL)&& (Types_struct_type_GET_List_Types_field (4, t) == NULL)      ) {
    List_Types_struct_type u = Types_struct_type_GET_List_Types_struct_type (3, t);
    return no_fieldss (u);
  }
  return FALSE;
}

/* Bool no_fieldss
  (List_Types_struct_type lhd::tl)
  -> no_fields (hd)&&no_fieldss (tl)

  ,(List_Types_struct_type lNULL)
   -> TRUE

;
*/
static Bool
no_fieldss (List_Types_struct_type l)
{
  if (!IS_NULL(l)      ) {
    Types_struct_type hd = List_Types_struct_type_GET_Types_struct_type (0, l);
    List_Types_struct_type tl = List_Types_struct_type_GET_List_Types_struct_type (1, l);
    return no_fields (hd) && no_fieldss (tl);
  }
  if ((l == NULL)      ) {
    return TRUE;
  }
  return FALSE;
}

/* Types_field Overload
  (Types_field f,Bool o)
  | o
  -> ExtendType (f,"List")

  ,(Types_field f,Bool o)
   -> f

;
*/
static Types_field
Overload (Types_field f, Bool o)
{
  if (TRUE) {
    if (o) {
      return ExtendType (f, "List");
    }
  }
  if (TRUE) {
    return f;
  }
  return NULL;
}

/* List_Types_field remove_void_fields
  (List_Types_field fhd::tl)
  | is_void_field (hd)
  -> remove_void_fields (tl)

  ,(List_Types_field fhd::tl)
   -> hd::remove_void_fields (tl)

;
*/
static List_Types_field
remove_void_fields (List_Types_field f)
{
  if (!IS_NULL(f)      ) {
    Types_field hd = List_Types_field_GET_Types_field (0, f);
    List_Types_field tl = List_Types_field_GET_List_Types_field (1, f);
    if (is_void_field (hd)) {
      return remove_void_fields (tl);
    }
  }
  if (!IS_NULL(f)      ) {
    Types_field hd = List_Types_field_GET_Types_field (0, f);
    List_Types_field tl = List_Types_field_GET_List_Types_field (1, f);
    return CREATE_LIST(List_Types_field, hd, remove_void_fields (tl));
  }
  return NULL;
}

/* Bool is_void_field
  (fTypes_field(List_Types_TypeName(Types_TypeName(id),_),_))
  -> id==Create_Ident ("VOID")

;
*/
static Bool
is_void_field (Types_field f)
{
  if ( Types_field_HAS_OPER (f, Types_field_kind)
      && List_Types_TypeName_HAS_OPER (Types_field_GET_List_Types_TypeName (0, f), List_Types_TypeName_kind)
      && Types_TypeName_HAS_OPER (List_Types_TypeName_GET_Types_TypeName (0, Types_field_GET_List_Types_TypeName (0, f)), Types_TypeName_kind)
            ) {
    Ident id = Types_TypeName_GET_Ident (0, List_Types_TypeName_GET_Types_TypeName (0, Types_field_GET_List_Types_TypeName (0, f)));
    return id == Create_Ident ("VOID");
  }
  return FALSE;
}

