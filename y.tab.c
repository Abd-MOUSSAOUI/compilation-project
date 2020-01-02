/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     MAIN = 259,
     NUMBER = 260,
     IF = 261,
     ELSE = 262,
     FOR = 263,
     WHILE = 264,
     RET = 265,
     INT = 266,
     VOID = 267,
     INCR = 268,
     DECR = 269,
     EQ = 270,
     GE = 271,
     LE = 272,
     OR = 273,
     AND = 274,
     NOT = 275,
     NEQ = 276
   };
#endif
/* Tokens.  */
#define ID 258
#define MAIN 259
#define NUMBER 260
#define IF 261
#define ELSE 262
#define FOR 263
#define WHILE 264
#define RET 265
#define INT 266
#define VOID 267
#define INCR 268
#define DECR 269
#define EQ 270
#define GE 271
#define LE 272
#define OR 273
#define AND 274
#define NOT 275
#define NEQ 276




/* Copy the first part of user declarations.  */
#line 1 "blaster.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include "ast.h"
  #include "sym_tab.h"
  #include "gen_code.h"

  int yylex();
  int counter = 0, dim = 0;
  FILE* yyin;
  void yyerror(char*);
  void lex_free();
  struct sym_tab* symbol_tab = NULL;
  struct ast* parser_ast = NULL;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 17 "blaster.y"
{
  char* string;
  int value;
  struct ast* ast;
}
/* Line 193 of yacc.c.  */
#line 160 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 173 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      26,    27,    24,    22,    28,    23,     2,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      36,    32,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    20,    26,
      33,    40,    43,    48,    51,    55,    58,    60,    62,    64,
      66,    68,    70,    72,    74,    77,    83,    91,    97,   107,
     110,   114,   118,   124,   129,   134,   136,   138,   142,   146,
     148,   151,   154,   156,   159,   162,   164,   166,   169,   173,
     177,   181,   185,   189,   193,   197,   201,   203,   207,   211,
     214,   216,   220,   224,   228,   230,   232,   234,   237,   241,
     244,   248,   253,   257,   262,   264
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    39,    -1,    40,    -1,    39,    40,    -1,
      51,    -1,    41,    -1,    11,     3,    26,    27,    43,    -1,
      12,     3,    26,    27,    43,    -1,    11,     3,    26,    42,
      27,    43,    -1,    12,     3,    26,    42,    27,    43,    -1,
      11,     3,    -1,    11,     3,    28,    42,    -1,    29,    30,
      -1,    29,    44,    30,    -1,    45,    44,    -1,    45,    -1,
      51,    -1,    46,    -1,    47,    -1,    48,    -1,    49,    -1,
      50,    -1,    31,    -1,    52,    31,    -1,     6,    26,    52,
      27,    43,    -1,     6,    26,    52,    27,    43,     7,    43,
      -1,     9,    26,    52,    27,    43,    -1,     8,    26,    53,
      31,    57,    31,    54,    27,    43,    -1,    10,    31,    -1,
      10,    52,    31,    -1,    11,     3,    31,    -1,    11,     3,
      32,    52,    31,    -1,    11,     3,    33,    34,    -1,    11,
       3,    62,    31,    -1,    53,    -1,    56,    -1,     3,    32,
      52,    -1,    61,    32,    52,    -1,    54,    -1,    13,     3,
      -1,    14,     3,    -1,    55,    -1,     3,    13,    -1,     3,
      14,    -1,    58,    -1,    57,    -1,    20,    58,    -1,    58,
      35,    58,    -1,    58,    36,    58,    -1,    58,    16,    58,
      -1,    58,    17,    58,    -1,    58,    15,    58,    -1,    58,
      18,    58,    -1,    58,    21,    58,    -1,    58,    19,    58,
      -1,    59,    -1,    58,    22,    59,    -1,    58,    23,    59,
      -1,    23,    58,    -1,    60,    -1,    59,    24,    59,    -1,
      59,    25,    59,    -1,    26,    52,    27,    -1,     3,    -1,
       5,    -1,    63,    -1,     3,    62,    -1,     3,    33,    34,
      -1,     3,    62,    -1,    33,    52,    34,    -1,    33,    52,
      34,    62,    -1,     3,    26,    27,    -1,     3,    26,    64,
      27,    -1,    52,    -1,    52,    28,    64,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    35,    35,    39,    40,    43,    44,    48,    59,    70,
      87,   107,   118,   132,   133,   137,   138,   142,   143,   144,
     145,   146,   147,   151,   152,   156,   157,   161,   165,   169,
     170,   174,   186,   197,   208,   223,   224,   228,   230,   237,
     241,   243,   245,   249,   251,   256,   257,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   273,   274,   275,   276,
     280,   281,   282,   286,   287,   294,   295,   296,   300,   307,
     317,   320,   326,   333,   348,   351
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "MAIN", "NUMBER", "IF", "ELSE",
  "FOR", "WHILE", "RET", "INT", "VOID", "INCR", "DECR", "EQ", "GE", "LE",
  "OR", "AND", "NOT", "NEQ", "'+'", "'-'", "'*'", "'/'", "'('", "')'",
  "','", "'{'", "'}'", "';'", "'='", "'['", "']'", "'>'", "'<'", "$accept",
  "axiom", "prog", "external_decl", "func_decl", "param_l", "block",
  "stmt_l", "stmt", "expr_st", "if_st", "wh_st", "for_st", "ret_st",
  "var_decl", "expr", "assign_expr", "unar_expr", "postfix_inc",
  "simp_expr", "cond_expr", "add_expr", "term", "factor", "arr_acs", "dim",
  "func_call", "args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    43,    45,    42,    47,    40,    41,    44,   123,
     125,    59,    61,    91,    93,    62,    60
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    41,
      41,    42,    42,    43,    43,    44,    44,    45,    45,    45,
      45,    45,    45,    46,    46,    47,    47,    48,    49,    50,
      50,    51,    51,    51,    51,    52,    52,    53,    53,    53,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    58,    58,    58,
      59,    59,    59,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    63,    64,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     5,     5,     6,
       6,     2,     4,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     7,     5,     9,     2,
       3,     3,     5,     4,     4,     1,     1,     3,     3,     1,
       2,     2,     1,     2,     2,     1,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     2,
       1,     3,     3,     3,     1,     1,     1,     2,     3,     2,
       3,     4,     3,     4,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     6,     5,     0,     0,
       1,     4,     0,    31,     0,     0,     0,     0,     0,     0,
       0,    64,    65,     0,     0,     0,     0,     0,     0,    35,
      39,    42,    36,    46,    45,    56,    60,     0,    66,    33,
       0,    34,     0,     0,    11,     0,     7,     0,    43,    44,
       0,     0,     0,    67,    40,    41,    64,    47,    59,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     8,     0,     0,     0,     0,
       0,     0,     0,    13,    23,     0,    16,    18,    19,    20,
      21,    22,    17,     0,     9,    72,    74,     0,    37,    68,
       0,    67,    63,    52,    50,    51,    53,    55,    54,    57,
      58,    48,    49,    61,    62,    38,    71,    10,    12,     0,
       0,     0,    29,     0,     0,    14,    15,    24,     0,    73,
       0,     0,     0,     0,    30,    75,     0,    69,     0,     0,
      25,     0,     0,    27,     0,     0,    26,     0,     0,     0,
      28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    20,    46,    85,    86,    87,
      88,    89,    90,    91,     7,    40,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    16,    38,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -42
static const yytype_int16 yypact[] =
{
      76,     2,     8,    14,    76,   -42,   -42,   -42,    23,   -18,
     -42,   -42,     5,   -42,   174,    55,    -8,    39,    16,    24,
     -10,   160,   -42,    54,    73,    74,    74,   174,    30,   -42,
     -42,   -42,   -42,   -42,   186,    68,   -42,    50,   -42,   -42,
      51,   -42,    24,    63,    71,   115,   -42,    24,   -42,   -42,
       7,   174,    60,    64,   -42,   -42,    58,    79,   -42,    77,
     -42,    74,    74,    74,    74,    74,    74,    19,    19,    74,
      74,    19,    19,   174,    78,   -42,    24,    95,    83,    87,
      96,   158,   128,   -42,   -42,   102,   144,   -42,   -42,   -42,
     -42,   -42,   -42,   105,   -42,   -42,   106,   110,   -42,   -42,
     174,   -42,   -42,    79,    79,    79,    79,    79,    79,    68,
      68,    79,    79,   -42,   -42,   -42,   -42,   -42,   -42,   174,
      12,   174,   -42,   111,   179,   -42,   -42,   -42,   174,   -42,
     121,    38,   120,   129,   -42,   -42,    24,   -42,   107,    24,
     152,   131,   186,   -42,    24,    15,   -42,   103,   133,    24,
     -42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -42,   -42,   -42,   161,   -42,   -13,   -41,    80,   -42,   -42,
     -42,   -42,   -42,   -42,   -38,   -14,    48,    31,   -42,   -42,
      42,   -23,    72,   -42,   -42,   -12,   -42,    41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -70
static const yytype_int16 yytable[] =
{
      28,    75,    57,    58,    43,     8,    94,    92,    17,    53,
      21,     9,    22,    59,    10,   131,    18,    47,   147,    44,
      23,    24,    56,    41,    22,    23,    24,    25,    23,    24,
      26,    93,    19,    27,    95,   117,    96,    98,   103,   104,
     105,   106,   107,   108,   101,    27,   111,   112,    92,    12,
      18,    48,    49,    45,    13,    14,    15,    54,    21,   115,
      22,    60,   116,    21,   118,    22,    42,   123,    23,    24,
      51,    52,    93,    23,    24,    25,    55,    56,    26,    22,
      25,    27,    73,    26,    50,    74,    27,     1,     2,    39,
      76,   100,    71,    72,    99,   140,   -69,    26,   143,    77,
      27,    67,    68,   146,   102,   130,    18,   133,   150,   119,
      56,   100,    22,   120,    96,   142,    48,    49,    21,   137,
      22,    78,   121,    79,    80,    81,    82,    25,    23,    24,
      26,   124,   125,    27,   128,    25,   127,   129,    26,   109,
     110,    27,   134,   113,   114,    83,    84,    21,   136,    22,
      78,   138,    79,    80,    81,    82,   139,    23,    24,   144,
     149,    21,   145,    22,    25,    11,   126,    26,   132,   135,
      27,    23,    24,    48,    49,    84,   148,    21,    25,    22,
     141,    26,     0,     0,    27,     0,    50,    23,    24,   122,
       0,     0,    51,    52,    25,     0,     0,    26,     0,     0,
      27,    61,    62,    63,    64,    65,     0,    66,    67,    68,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70
};

static const yytype_int16 yycheck[] =
{
      14,    42,    25,    26,    17,     3,    47,    45,    26,    21,
       3,     3,     5,    27,     0,     3,    11,    27,     3,     3,
      13,    14,     3,    31,     5,    13,    14,    20,    13,    14,
      23,    45,    27,    26,    27,    76,    50,    51,    61,    62,
      63,    64,    65,    66,    56,    26,    69,    70,    86,    26,
      11,    13,    14,    29,    31,    32,    33,     3,     3,    73,
       5,    31,    74,     3,    77,     5,    27,    81,    13,    14,
      32,    33,    86,    13,    14,    20,     3,     3,    23,     5,
      20,    26,    32,    23,    26,    34,    26,    11,    12,    34,
      27,    33,    24,    25,    34,   136,    32,    23,   139,    28,
      26,    22,    23,   144,    27,   119,    11,   121,   149,    26,
       3,    33,     5,    26,   128,   138,    13,    14,     3,   131,
       5,     6,    26,     8,     9,    10,    11,    20,    13,    14,
      23,     3,    30,    26,    28,    20,    31,    27,    23,    67,
      68,    26,    31,    71,    72,    30,    31,     3,    27,     5,
       6,    31,     8,     9,    10,    11,    27,    13,    14,     7,
      27,     3,    31,     5,    20,     4,    86,    23,   120,   128,
      26,    13,    14,    13,    14,    31,   145,     3,    20,     5,
     138,    23,    -1,    -1,    26,    -1,    26,    13,    14,    31,
      -1,    -1,    32,    33,    20,    -1,    -1,    23,    -1,    -1,
      26,    15,    16,    17,    18,    19,    -1,    21,    22,    23,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    38,    39,    40,    41,    51,     3,     3,
       0,    40,    26,    31,    32,    33,    62,    26,    11,    27,
      42,     3,     5,    13,    14,    20,    23,    26,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    63,    34,
      52,    31,    27,    42,     3,    29,    43,    27,    13,    14,
      26,    32,    33,    62,     3,     3,     3,    58,    58,    52,
      31,    15,    16,    17,    18,    19,    21,    22,    23,    35,
      36,    24,    25,    32,    34,    43,    27,    28,     6,     8,
       9,    10,    11,    30,    31,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    43,    27,    52,    64,    52,    34,
      33,    62,    27,    58,    58,    58,    58,    58,    58,    59,
      59,    58,    58,    59,    59,    52,    62,    43,    42,    26,
      26,    26,    31,    52,     3,    30,    44,    31,    28,    27,
      52,     3,    53,    52,    31,    64,    27,    62,    31,    27,
      43,    57,    58,    43,     7,    31,    43,     3,    54,    27,
      43
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 35 "blaster.y"
    { parser_ast = (yyvsp[(1) - (1)].ast); return 0; }
    break;

  case 3:
#line 39 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 4:
#line 40 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_PROG, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast)); }
    break;

  case 5:
#line 43 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 6:
#line 44 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 7:
#line 48 "blaster.y"
    { (yyval.ast) = ast_new_trenary(AST_FUNC, ast_new_id((yyvsp[(2) - (5)].string)), 0, (yyvsp[(5) - (5)].ast));
                                      if (sym_search(symbol_tab,FUNC, (yyvsp[(2) - (5)].string)) != NULL)
                                      {
                                        fprintf(stderr, "ERROR: %s function allready exist\n", (yyvsp[(2) - (5)].string));
                                        exit(1);
                                      }
                                      else
                                      {
                                        sym_add_func(FUNC, INT_T, &symbol_tab, (yyvsp[(2) - (5)].string), 0);
                                      }
                                    }
    break;

  case 8:
#line 59 "blaster.y"
    { (yyval.ast) = ast_new_trenary(AST_FUNC, ast_new_id((yyvsp[(2) - (5)].string)), 0, (yyvsp[(5) - (5)].ast));
                                      if (sym_search(symbol_tab,FUNC, (yyvsp[(2) - (5)].string)) != NULL)
                                      {
                                        fprintf(stderr, "ERROR: %s function allready exist\n", (yyvsp[(2) - (5)].string));
                                        exit(1);
                                      }
                                      else
                                      {
                                        sym_add_func(FUNC, VOID_T, &symbol_tab, (yyvsp[(2) - (5)].string), 0);
                                      }
                                    }
    break;

  case 9:
#line 70 "blaster.y"
    { (yyval.ast) = ast_new_trenary(AST_FUNC, ast_new_id((yyvsp[(2) - (6)].string)), (yyvsp[(4) - (6)].ast), (yyvsp[(6) - (6)].ast));
                                      if (sym_search(symbol_tab, FUNC, (yyvsp[(2) - (6)].string)) != NULL)
                                      {
                                        fprintf(stderr, "ERROR: %s function allready exist\n", (yyvsp[(2) - (6)].string));
                                        exit(1);
                                      }
                                      else
                                      {
                                        int i = 1; ast* tab = (yyvsp[(4) - (6)].ast);
                                        while(tab->op.right != NULL)
                                        {
                                          i++;
                                          tab = tab->op.right;
                                        }
                                        sym_add_func(FUNC, INT_T, &symbol_tab, (yyvsp[(2) - (6)].string), i);
                                      }
                                    }
    break;

  case 10:
#line 87 "blaster.y"
    { (yyval.ast) = ast_new_trenary(AST_FUNC, ast_new_id((yyvsp[(2) - (6)].string)), (yyvsp[(4) - (6)].ast), (yyvsp[(6) - (6)].ast));
                                      if (sym_search(symbol_tab, FUNC, (yyvsp[(2) - (6)].string)) != NULL)
                                      {
                                        fprintf(stderr, "ERROR: %s function allready exist\n", (yyvsp[(2) - (6)].string));
                                        exit(1);
                                      }
                                      else
                                      {
                                        int i = 1; ast* tab = (yyvsp[(4) - (6)].ast);
                                        while(tab->op.right != NULL)
                                        {
                                          i++;
                                          tab = tab->op.right;
                                        }
                                        sym_add_func(FUNC, VOID_T, &symbol_tab, (yyvsp[(2) - (6)].string), i);
                                      }
                                    }
    break;

  case 11:
#line 107 "blaster.y"
    { (yyval.ast) = ast_new_id((yyvsp[(2) - (2)].string));
                          if (sym_search(symbol_tab, INT_F, (yyvsp[(2) - (2)].string)) != NULL)
                           {
                              fprintf(stderr, "ERROR: Re-definition of %s\n", (yyvsp[(2) - (2)].string));
	                            exit(1);
                           }
                           else
                           {
                              sym_add_var(INT_F, &symbol_tab, (yyvsp[(2) - (2)].string), 0, 0);
                           }
                        }
    break;

  case 12:
#line 118 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_PARAML, ast_new_id((yyvsp[(2) - (4)].string)), (yyvsp[(4) - (4)].ast));
                          if (sym_search(symbol_tab, INT_F, (yyvsp[(2) - (4)].string)) != NULL)
                           {
                              fprintf(stderr, "ERROR: Re-definition of %s\n", (yyvsp[(2) - (4)].string));
	                            exit(1);
                           }
                           else
                           {
                              sym_add_var(INT_F, &symbol_tab, (yyvsp[(2) - (4)].string), 0, 0);
                           }
                        }
    break;

  case 13:
#line 132 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_BLOCK, 0, 0);}
    break;

  case 14:
#line 133 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_BLOCK, (yyvsp[(2) - (3)].ast), 0); }
    break;

  case 15:
#line 137 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_STMTL, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast)); }
    break;

  case 16:
#line 138 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 17:
#line 142 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 18:
#line 143 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 19:
#line 144 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 20:
#line 145 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 21:
#line 146 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 22:
#line 147 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 23:
#line 151 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_EXPST, 0, 0); }
    break;

  case 24:
#line 152 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_EXPST, (yyvsp[(1) - (2)].ast), 0); }
    break;

  case 25:
#line 156 "blaster.y"
    { (yyval.ast) = ast_new_trenary(AST_IF, (yyvsp[(3) - (5)].ast), (yyvsp[(5) - (5)].ast), 0); }
    break;

  case 26:
#line 157 "blaster.y"
    { (yyval.ast) = ast_new_trenary(AST_IF_ELSE, (yyvsp[(3) - (7)].ast), (yyvsp[(5) - (7)].ast), (yyvsp[(7) - (7)].ast)); }
    break;

  case 27:
#line 161 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_WHILE, (yyvsp[(3) - (5)].ast), (yyvsp[(5) - (5)].ast)); }
    break;

  case 28:
#line 165 "blaster.y"
    { (yyval.ast) = ast_new_fornary(AST_FOR, (yyvsp[(3) - (9)].ast), (yyvsp[(5) - (9)].ast), (yyvsp[(7) - (9)].ast), (yyvsp[(9) - (9)].ast)); }
    break;

  case 29:
#line 169 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_RET, 0, 0); }
    break;

  case 30:
#line 170 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_RET, (yyvsp[(2) - (3)].ast), 0); }
    break;

  case 31:
#line 174 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_DECL, ast_new_id((yyvsp[(2) - (3)].string)), 0);

                           if (sym_search(symbol_tab, INT_V, (yyvsp[(2) - (3)].string)) != NULL)
                           {
                              fprintf(stderr, "ERROR: Re-definition of %s\n", (yyvsp[(2) - (3)].string));
	                            exit(1);
                           }
                           else
                           {
                              sym_add_var(INT_V, &symbol_tab, (yyvsp[(2) - (3)].string), -1, 0);
                           }
                          }
    break;

  case 32:
#line 186 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_DECL, ast_new_id((yyvsp[(2) - (5)].string)), (yyvsp[(4) - (5)].ast));
                           if (sym_search(symbol_tab, INT_V, (yyvsp[(2) - (5)].string)) != NULL)
                           {
                              fprintf(stderr, "ERROR: Re-definition of %s\n", (yyvsp[(2) - (5)].string));
	                            exit(1);
                           }
                           else
                           {
                              sym_add_var(INT_V, &symbol_tab, (yyvsp[(2) - (5)].string), (yyvsp[(4) - (5)].ast)->number, 0);
                           }
                          }
    break;

  case 33:
#line 197 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_ARR_DECL, ast_new_id((yyvsp[(2) - (4)].string)), 0); 
                            if (sym_search(symbol_tab, TAB_INT, (yyvsp[(2) - (4)].string)) != NULL)
                            {
                              fprintf(stderr, "ERROR: Re-definition of %s\n", (yyvsp[(2) - (4)].string));
                              exit(1);
                            }
                            else
                            {
                              sym_add_tab(TAB_INT, &symbol_tab, (yyvsp[(2) - (4)].string), 1);
                            }
                          }
    break;

  case 34:
#line 208 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_ARR_DECL, ast_new_id((yyvsp[(2) - (4)].string)), (yyvsp[(3) - (4)].ast)); 
                            if (sym_search(symbol_tab, TAB_INT, (yyvsp[(2) - (4)].string)) != NULL)
                            {
                              fprintf(stderr, "ERROR: Re-definition of %s\n", (yyvsp[(2) - (4)].string));
                              exit(1);
                            }
                            else
                            {
                              sym_add_tab(TAB_INT, &symbol_tab, (yyvsp[(2) - (4)].string), dim);
                              dim = 0;
                            }
                          }
    break;

  case 35:
#line 223 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 36:
#line 224 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 37:
#line 228 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_ASIGN, ast_new_id((yyvsp[(1) - (3)].string)), (yyvsp[(3) - (3)].ast));
                          sym_mod(&symbol_tab, (yyvsp[(1) - (3)].string), AS_VAL, (yyvsp[(3) - (3)].ast)->number); }
    break;

  case 38:
#line 230 "blaster.y"
    {  if(!(yyvsp[(1) - (3)].ast)->op.right)
                            {
                              fprintf(stderr, "ERROR: invalid assignment\n");
                              exit(1);
                            }
                            (yyval.ast) = ast_new_operation(AST_ASIGN, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
                          }
    break;

  case 39:
#line 237 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 40:
#line 241 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_INCR, ast_new_id((yyvsp[(2) - (2)].string)), NULL);
                           sym_mod(&symbol_tab, (yyvsp[(2) - (2)].string), INCR_VAL, 1); }
    break;

  case 41:
#line 243 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_DECR, ast_new_id((yyvsp[(2) - (2)].string)), NULL);
                           sym_mod(&symbol_tab, (yyvsp[(2) - (2)].string), DECR_VAL, 1); }
    break;

  case 42:
#line 245 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 43:
#line 249 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_INCR, ast_new_id((yyvsp[(1) - (2)].string)), NULL);
                           sym_mod(&symbol_tab, (yyvsp[(1) - (2)].string), INCR_VAL, 1); }
    break;

  case 44:
#line 251 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_DECR, ast_new_id((yyvsp[(1) - (2)].string)), NULL);
                           sym_mod(&symbol_tab, (yyvsp[(1) - (2)].string), DECR_VAL, 1); }
    break;

  case 45:
#line 256 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 46:
#line 257 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 47:
#line 261 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_NOT, (yyvsp[(2) - (2)].ast), 0); }
    break;

  case 48:
#line 262 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_GT, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 49:
#line 263 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_LT, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 50:
#line 264 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_GE, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 51:
#line 265 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_LE, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 52:
#line 266 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_EQ, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 53:
#line 267 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_OR, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 54:
#line 268 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_NEQ, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 55:
#line 269 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_AND, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 56:
#line 273 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 57:
#line 274 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_ADD, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 58:
#line 275 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_MIN, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 59:
#line 276 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_NEG, (yyvsp[(2) - (2)].ast), NULL); }
    break;

  case 60:
#line 280 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 61:
#line 281 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_MUL, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 62:
#line 282 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_DIV, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 63:
#line 286 "blaster.y"
    { (yyval.ast) = (yyvsp[(2) - (3)].ast); }
    break;

  case 64:
#line 287 "blaster.y"
    { (yyval.ast) = ast_new_id((yyvsp[(1) - (1)].string));
                            if (sym_search(symbol_tab, INT_V, (yyvsp[(1) - (1)].string)) == NULL)
                            {
                              fprintf(stderr, "ERROR: %s is not initialized\n", (yyvsp[(1) - (1)].string));
                              exit(1);
                            }
                          }
    break;

  case 65:
#line 294 "blaster.y"
    { (yyval.ast) = ast_new_number((yyvsp[(1) - (1)].value)); }
    break;

  case 66:
#line 295 "blaster.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 67:
#line 296 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_ARRAY,ast_new_id((yyvsp[(1) - (2)].string)),(yyvsp[(2) - (2)].ast)); }
    break;

  case 68:
#line 300 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_ARRAY, ast_new_id((yyvsp[(1) - (3)].string)), 0);
                            if (sym_search(symbol_tab, TAB_INT, (yyvsp[(1) - (3)].string)) == NULL)
                            {
                              fprintf(stderr, "ERROR: %s doesn't exist\n", (yyvsp[(1) - (3)].string));
                              exit(1);
                            }
                          }
    break;

  case 69:
#line 307 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_ARRAY, ast_new_id((yyvsp[(1) - (2)].string)), (yyvsp[(2) - (2)].ast));
                            if (sym_search(symbol_tab, TAB_INT, (yyvsp[(1) - (2)].string)) == NULL)
                            {
                              fprintf(stderr, "ERROR: %s doesn't exist\n", (yyvsp[(1) - (2)].string));
                              exit(1);
                            }
                          }
    break;

  case 70:
#line 317 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_DIM, (yyvsp[(2) - (3)].ast), 0);
                              dim++;
                            }
    break;

  case 71:
#line 320 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_DIM, (yyvsp[(2) - (4)].ast), (yyvsp[(4) - (4)].ast));
                              dim++;
                            }
    break;

  case 72:
#line 326 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_CALL, ast_new_id((yyvsp[(1) - (3)].string)), 0);
                          if (sym_search(symbol_tab, FUNC, (yyvsp[(1) - (3)].string)) == NULL)
                          {
                            fprintf(stderr, "ERROR: %s function doesn't exist\n", (yyvsp[(1) - (3)].string));
                            exit(1);
                          }
                        }
    break;

  case 73:
#line 333 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_CALL, ast_new_id((yyvsp[(1) - (4)].string)), (yyvsp[(3) - (4)].ast));
                          if (sym_search(symbol_tab, FUNC, (yyvsp[(1) - (4)].string)) == NULL)
                          {
                            fprintf(stderr, "ERROR: %s function doesn't exist\n", (yyvsp[(1) - (4)].string));
                            exit(1);
                          }
                          if (check_args_nbr(symbol_tab, (yyvsp[(1) - (4)].string), counter) != 1)
                          {
                            fprintf(stderr, "ERROR: %s   Incorrect number of args\n",(yyvsp[(1) - (4)].string));
                            exit(1);
                          }
                        }
    break;

  case 74:
#line 348 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_ARG, (yyvsp[(1) - (1)].ast), 0);
                          counter ++;
                        }
    break;

  case 75:
#line 351 "blaster.y"
    { (yyval.ast) = ast_new_operation(AST_ARG, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
                          counter ++;
                        }
    break;


/* Line 1267 of yacc.c.  */
#line 2049 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 356 "blaster.y"


int main(int argc, char** argv) {

  FILE* input = fopen(argv[1], "r");
  if(input == 0) {
    perror("error while opening file");
    exit(-1);
  }

  yyin = input;

  if (yyparse() == 0)
  //  ast_print(parser_ast, 0);
  //printf("\n");
  sym_print(symbol_tab);
  printf("\n");
  gencode(parser_ast);
  fclose(input);

  // Be clean.
  lex_free();
  ast_free(parser_ast);
  sym_free(symbol_tab);
  return 0;
}

