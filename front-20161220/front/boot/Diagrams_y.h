#ifndef BISON_DIAGRAMS_Y_H
# define BISON_DIAGRAMS_Y_H

#ifndef YYSTYPE
typedef union {
Bool Boolsym_type;
Int Intsym_type;
String Stringsym_type;
Ident Identsym_type;
Diagrams_Diagrams Diagrams_type;
Diagrams_Direction Direction_type;
Diagrams_Picture Picture_type;
List_Diagrams_Picture OPTMORE_Picture_type;
struct {
  List_Diagrams_Picture f1;
  List_Diagrams_Direction f2;
} ALT_ORspacesym_Picture_SEP_Direction_ENDORsym_type;
struct {
  List_Diagrams_Picture f1;
  List_Diagrams_Direction f2;
} ALT_ANDspacesym_Picture_SEP_Direction_ENDANDsym_type;
List_Diagrams_Picture MORE_Picture_type;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif

#ifndef YYLTYPE
typedef struct yyltype
{
  int first_line;
  int first_column;

  int last_line;
  int last_column;
} yyltype;

# define YYLTYPE yyltype
# define YYLTYPE_IS_TRIVIAL 1
#endif

# define	NONSENSE	257
# define	rectanglesym	258
# define	arctopopsym	259
# define	linesym	260
# define	trianglesym	261
# define	eofillsym	262
# define	Lsym	263
# define	Rsym	264
# define	Usym	265
# define	Dsym	266
# define	Csym	267
# define	openparsym	268
# define	closeparsym	269
# define	ORspacesym	270
# define	ENDORsym	271
# define	ANDspacesym	272
# define	ENDANDsym	273
# define	ALTspacesym	274
# define	ENDALTsym	275
# define	Boolsym	276
# define	Intsym	277
# define	Stringsym	278
# define	Identsym	279
# define	hole_Diagrams	280
# define	start_Diagrams	281
# define	hole_Direction	282
# define	start_Direction	283
# define	hole_Picture	284
# define	start_Picture	285
# define	hole_OPTMORE_Picture	286
# define	start_OPTMORE_Picture	287
# define	hole_MORE_Picture	288
# define	start_MORE_Picture	289


extern YYSTYPE Diagrams_lval;

#endif /* not BISON_DIAGRAMS_Y_H */
