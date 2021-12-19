
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "lrparser.y"


#include <stdio.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);



/* Line 189 of yacc.c  */
#line 83 "lrparser.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTCONST = 258,
     IDENT = 259,
     BREAK = 260,
     CONST = 261,
     CONTINUE = 262,
     DO = 263,
     ELSE = 264,
     FOR = 265,
     IF = 266,
     INT = 267,
     MAIN = 268,
     RETURN = 269,
     VOID = 270,
     WHILE = 271,
     AND = 272,
     OR = 273,
     EQU_CMP = 274,
     NEQU_CMP = 275,
     LESE_CMP = 276,
     GREE_CMP = 277,
     LOWER_THAN_ELSE = 278
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 10 "lrparser.y"

	int iValue;
	String sValue;
	Bean bean;



/* Line 214 of yacc.c  */
#line 150 "lrparser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 162 "lrparser.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,     2,     2,    38,     2,     2,
      29,    30,    36,    33,    25,    34,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
      39,    26,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    12,    14,    16,    21,
      25,    27,    32,    36,    38,    40,    43,    47,    51,    55,
      57,    62,    65,    69,    71,    73,    76,    80,    86,    92,
      99,   106,   112,   116,   118,   121,   127,   131,   134,   135,
     137,   139,   141,   146,   149,   151,   159,   165,   171,   174,
     177,   180,   184,   189,   190,   192,   194,   197,   201,   203,
     205,   207,   211,   216,   218,   221,   224,   227,   231,   233,
     237,   241,   245,   247,   251,   255,   257,   261,   265,   269,
     273,   275,   279,   283,   285,   289,   291,   295,   297,   302,
     303
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    42,    43,    -1,    43,    -1,    44,    -1,
      55,    -1,    45,    -1,    50,    -1,     6,    12,    46,    24,
      -1,    47,    25,    46,    -1,    47,    -1,     4,    76,    26,
      49,    -1,    49,    25,    48,    -1,    49,    -1,    77,    -1,
      27,    28,    -1,    27,    48,    28,    -1,    12,    51,    24,
      -1,    52,    25,    51,    -1,    52,    -1,     4,    76,    26,
      54,    -1,     4,    76,    -1,    54,    25,    53,    -1,    54,
      -1,    63,    -1,    27,    28,    -1,    27,    53,    28,    -1,
      12,     4,    29,    30,    58,    -1,    15,     4,    29,    30,
      58,    -1,    12,     4,    29,    56,    30,    58,    -1,    15,
       4,    29,    56,    30,    58,    -1,    12,    13,    29,    30,
      58,    -1,    57,    25,    56,    -1,    57,    -1,    12,     4,
      -1,    12,     4,    31,    32,    62,    -1,    27,    59,    28,
      -1,    60,    59,    -1,    -1,    44,    -1,    61,    -1,    24,
      -1,    65,    26,    63,    24,    -1,    63,    24,    -1,    58,
      -1,    11,    29,    64,    30,    61,     9,    61,    -1,    11,
      29,    64,    30,    61,    -1,    16,    29,    64,    30,    61,
      -1,     5,    24,    -1,     7,    24,    -1,    14,    24,    -1,
      14,    63,    24,    -1,    31,    63,    32,    62,    -1,    -1,
      71,    -1,    75,    -1,     4,    62,    -1,    29,    63,    30,
      -1,    65,    -1,    67,    -1,     3,    -1,     4,    29,    30,
      -1,     4,    29,    69,    30,    -1,    66,    -1,    33,    68,
      -1,    34,    68,    -1,    35,    68,    -1,    63,    25,    69,
      -1,    63,    -1,    70,    36,    68,    -1,    70,    37,    68,
      -1,    70,    38,    68,    -1,    68,    -1,    71,    33,    70,
      -1,    71,    34,    70,    -1,    70,    -1,    72,    39,    71,
      -1,    72,    40,    71,    -1,    72,    21,    71,    -1,    72,
      22,    71,    -1,    71,    -1,    73,    19,    72,    -1,    73,
      20,    72,    -1,    72,    -1,    73,    17,    74,    -1,    73,
      -1,    74,    18,    75,    -1,    74,    -1,    31,    77,    32,
      76,    -1,    -1,    71,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    26,    26,    27,    29,    30,    33,    34,    37,    40,
      41,    44,    47,    48,    51,    52,    53,    56,    59,    60,
      63,    64,    67,    68,    71,    72,    73,    76,    77,    78,
      79,    80,    83,    84,    87,    88,    91,    94,    95,    98,
      99,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   115,   116,   119,   122,   125,   128,   129,   130,
     133,   136,   137,   138,   139,   140,   141,   144,   145,   148,
     149,   150,   151,   154,   155,   156,   159,   160,   161,   162,
     163,   166,   167,   168,   171,   172,   175,   176,   179,   180,
     183
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTCONST", "IDENT", "BREAK", "CONST",
  "CONTINUE", "DO", "ELSE", "FOR", "IF", "INT", "MAIN", "RETURN", "VOID",
  "WHILE", "AND", "OR", "EQU_CMP", "NEQU_CMP", "LESE_CMP", "GREE_CMP",
  "LOWER_THAN_ELSE", "';'", "','", "'='", "'{'", "'}'", "'('", "')'",
  "'['", "']'", "'+'", "'-'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'",
  "$accept", "Root", "CompUnit", "Decl", "ConstDecl", "ConstDefs",
  "ConstDef", "ConstInitVals", "ConstInitVal", "VarDecl", "VarDefs",
  "VarDef", "InitVals", "InitVal", "FuncDef", "FuncFParams", "FuncFParam",
  "Block", "BlockItems", "BlockItem", "Stmt", "Exps", "Exp", "Cond",
  "LVal", "PrimaryExp", "Number", "UnaryExp", "FuncRParams", "MulExp",
  "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", "ConstExps",
  "ConstExp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    59,    44,    61,   123,   125,    40,
      41,    91,    93,    43,    45,    33,    42,    47,    37,    60,
      62
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    44,    45,    46,
      46,    47,    48,    48,    49,    49,    49,    50,    51,    51,
      52,    52,    53,    53,    54,    54,    54,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    64,    65,    66,    66,    66,
      67,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      70,    70,    70,    71,    71,    71,    72,    72,    72,    72,
      72,    73,    73,    73,    74,    74,    75,    75,    76,    76,
      77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     4,     3,
       1,     4,     3,     1,     1,     2,     3,     3,     3,     1,
       4,     2,     3,     1,     1,     2,     3,     5,     5,     6,
       6,     5,     3,     1,     2,     5,     3,     2,     0,     1,
       1,     1,     4,     2,     1,     7,     5,     5,     2,     2,
       2,     3,     4,     0,     1,     1,     2,     3,     1,     1,
       1,     3,     4,     1,     2,     2,     2,     3,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     4,     0,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     4,     6,     7,     5,
       0,    89,     0,     0,    19,     0,     1,     2,    89,     0,
      10,     0,     0,    21,     0,    17,     0,     0,     0,     8,
       0,     0,     0,     0,    33,    60,    53,     0,     0,     0,
       0,    58,    63,    59,    72,    75,    90,     0,     0,     0,
      89,    18,     0,     0,     0,     9,    34,    38,    27,     0,
       0,     0,     0,    56,     0,    54,    64,    65,    66,     0,
       0,     0,     0,     0,    89,     0,    20,    24,    31,    28,
       0,     0,    11,    14,     0,     0,     0,     0,     0,     0,
       0,    41,    39,    44,     0,    38,    40,     0,    58,    29,
      32,    61,    68,     0,     0,    57,    69,    70,    71,    73,
      74,    88,    25,     0,    23,    30,    15,     0,    13,    53,
      48,    49,     0,    50,     0,     0,    36,    37,    43,     0,
       0,    62,    53,    26,     0,    16,     0,    35,     0,    80,
      83,    85,    87,    55,    51,     0,     0,    67,    52,    22,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,    46,    78,    79,    76,    77,    84,    81,    82,
      86,    47,     0,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    19,    20,   117,   118,     8,
      13,    14,   113,   114,     9,    33,    34,    93,    94,    95,
      96,    63,    97,   138,    41,    42,    43,    44,   103,    45,
      65,   140,   141,   142,   143,    23,    83
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -140
static const yytype_int16 yypact[] =
{
      68,    -1,    31,    34,    10,  -140,  -140,  -140,  -140,  -140,
      41,    24,   -15,    28,    32,    46,  -140,  -140,    48,    58,
      64,    -6,   171,    59,    72,  -140,   102,     1,    89,  -140,
      41,   106,    93,    91,    97,  -140,    76,   171,   171,   171,
     171,  -140,  -140,  -140,  -140,    29,    60,    92,    43,    93,
      48,  -140,    93,    95,   123,  -140,    98,    57,  -140,    93,
     111,   151,   171,  -140,   113,    60,  -140,  -140,  -140,   171,
     171,   171,   171,   171,    48,    84,  -140,  -140,  -140,  -140,
      93,   144,  -140,  -140,    96,   117,   120,   116,   102,   163,
     124,  -140,  -140,  -140,   132,    57,  -140,   137,   139,  -140,
    -140,  -140,   138,   146,   150,  -140,  -140,  -140,  -140,    29,
      29,  -140,  -140,   155,   164,  -140,  -140,   160,   165,   162,
    -140,  -140,   171,  -140,   167,   171,  -140,  -140,  -140,   171,
     171,  -140,   162,  -140,    43,  -140,   123,  -140,   169,    60,
     -13,    17,   176,  -140,  -140,   172,   177,  -140,  -140,  -140,
    -140,   135,   171,   171,   171,   171,   171,   171,   171,   171,
     135,  -140,   186,    60,    60,    60,    60,  -140,   -13,   -13,
    -140,  -140,   135,  -140
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,   199,   -52,  -140,   178,  -140,    71,   156,  -140,
     183,  -140,    77,   166,  -140,   -20,  -140,   -29,   118,  -140,
    -139,   -78,   -33,    87,   -56,  -140,  -140,   -21,    85,    26,
     -22,   -49,  -140,    61,    62,   -16,   194
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      46,    98,    28,    58,    64,    92,    31,    53,   152,   153,
      16,    10,   162,    31,    24,    77,     1,    66,    67,    68,
      78,   171,     2,    79,    32,     3,   154,   155,   102,   104,
      99,    52,    46,   173,   156,    11,   157,   158,    15,    98,
     100,   137,    77,    92,    12,    18,    35,    36,   106,   107,
     108,   115,    25,    21,   148,    22,   124,    26,   111,    46,
      35,    36,    85,     1,    86,    69,    70,    71,    87,    88,
      75,    89,    37,    90,     1,    27,    38,    39,    40,    22,
       2,    91,    29,     3,    57,    48,    37,    35,    36,    30,
      38,    39,    40,    72,    73,    98,   146,   102,   109,   110,
     139,    77,    49,   139,    98,    61,    50,    62,   168,   169,
      56,    75,   112,    37,    46,    54,    98,    38,    39,    40,
      57,    59,    60,    31,    74,    80,    35,    36,   119,    84,
     163,   164,   165,   166,   139,   139,   139,   139,    35,    36,
      85,   120,    86,   105,   121,   122,    87,    35,    36,    89,
      81,    90,    37,   125,    35,    36,    38,    39,    40,    91,
     126,   128,    57,   130,    37,   129,    35,    36,    38,    39,
      40,    81,   116,    37,    35,    36,   131,    38,    39,    40,
      37,   101,   132,   133,    38,    39,    40,   123,   135,   134,
     136,   144,    37,    62,   159,   172,    38,    39,    40,   151,
      37,   161,   160,    17,    38,    39,    40,   150,    55,    51,
      82,   149,   145,   127,    76,   147,    47,   167,     0,     0,
       0,   170
};

static const yytype_int16 yycheck[] =
{
      22,    57,    18,    32,    37,    57,    12,    27,    21,    22,
       0,    12,   151,    12,    29,    48,     6,    38,    39,    40,
      49,   160,    12,    52,    30,    15,    39,    40,    61,    62,
      59,    30,    54,   172,    17,     4,    19,    20,     4,    95,
      60,   119,    75,    95,    13,     4,     3,     4,    69,    70,
      71,    80,    24,    29,   132,    31,    89,    25,    74,    81,
       3,     4,     5,     6,     7,    36,    37,    38,    11,    12,
      27,    14,    29,    16,     6,    29,    33,    34,    35,    31,
      12,    24,    24,    15,    27,    26,    29,     3,     4,    25,
      33,    34,    35,    33,    34,   151,   129,   130,    72,    73,
     122,   134,    30,   125,   160,    29,     4,    31,   157,   158,
       4,    27,    28,    29,   136,    26,   172,    33,    34,    35,
      27,    30,    25,    12,    32,    30,     3,     4,    32,    31,
     152,   153,   154,   155,   156,   157,   158,   159,     3,     4,
       5,    24,     7,    30,    24,    29,    11,     3,     4,    14,
      27,    16,    29,    29,     3,     4,    33,    34,    35,    24,
      28,    24,    27,    25,    29,    26,     3,     4,    33,    34,
      35,    27,    28,    29,     3,     4,    30,    33,    34,    35,
      29,    30,    32,    28,    33,    34,    35,    24,    28,    25,
      25,    24,    29,    31,    18,     9,    33,    34,    35,    30,
      29,    24,    30,     4,    33,    34,    35,   136,    30,    26,
      54,   134,   125,    95,    48,   130,    22,   156,    -1,    -1,
      -1,   159
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    12,    15,    42,    43,    44,    45,    50,    55,
      12,     4,    13,    51,    52,     4,     0,    43,     4,    46,
      47,    29,    31,    76,    29,    24,    25,    29,    76,    24,
      25,    12,    30,    56,    57,     3,     4,    29,    33,    34,
      35,    65,    66,    67,    68,    70,    71,    77,    26,    30,
       4,    51,    30,    56,    26,    46,     4,    27,    58,    30,
      25,    29,    31,    62,    63,    71,    68,    68,    68,    36,
      37,    38,    33,    34,    32,    27,    54,    63,    58,    58,
      30,    27,    49,    77,    31,     5,     7,    11,    12,    14,
      16,    24,    44,    58,    59,    60,    61,    63,    65,    58,
      56,    30,    63,    69,    63,    30,    68,    68,    68,    70,
      70,    76,    28,    53,    54,    58,    28,    48,    49,    32,
      24,    24,    29,    24,    63,    29,    28,    59,    24,    26,
      25,    30,    32,    28,    25,    28,    25,    62,    64,    71,
      72,    73,    74,    75,    24,    64,    63,    69,    62,    53,
      48,    30,    21,    22,    39,    40,    17,    19,    20,    18,
      30,    24,    61,    71,    71,    71,    71,    74,    72,    72,
      75,    61,     9,    61
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 26 "lrparser.y"
    {addBean(root,(yyvsp[(2) - (2)].bean));;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 27 "lrparser.y"
    {addBean(root,(yyvsp[(1) - (1)].bean));;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 29 "lrparser.y"
    {(yyval.bean) = beanInfo("CompUnit","Decl");addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 30 "lrparser.y"
    {(yyval.bean) = beanInfo("CompUnit","FuncDef");addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 33 "lrparser.y"
    {(yyval.bean) = (yyvsp[(1) - (1)].bean);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 34 "lrparser.y"
    {(yyval.bean) = (yyvsp[(1) - (1)].bean);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 37 "lrparser.y"
    {(yyval.bean) = beanInfo("ConstDecl","int");addBeans((yyval.bean),(yyvsp[(3) - (4)].bean));;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 40 "lrparser.y"
    {(yyval.bean) = beanInfo("ConstDefs",NULL);addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBeans((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 41 "lrparser.y"
    {(yyval.bean) = beanInfo("ConstDefs",NULL);addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 44 "lrparser.y"
    {(yyval.bean) = beanInfo("ConstDef",(yyvsp[(1) - (4)].sValue));addBean((yyval.bean),(yyvsp[(4) - (4)].bean));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 47 "lrparser.y"
    {(yyval.bean) = beanInfo("ConstInitVals",NULL);addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBeans((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 48 "lrparser.y"
    {(yyval.bean) = beanInfo("ConstInitVals",NULL);addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 51 "lrparser.y"
    {(yyval.bean) = beanInfo("ConstInitVal",NULL);addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 52 "lrparser.y"
    {(yyval.bean) = beanInfo("ConstInitVal",NULL);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 53 "lrparser.y"
    {(yyval.bean) = (yyvsp[(2) - (3)].bean);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 56 "lrparser.y"
    {(yyval.bean) = beanInfo("VarDecl","int");addBean((yyval.bean),(yyvsp[(2) - (3)].bean));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 59 "lrparser.y"
    {(yyval.bean) = beanInfo("VarDefs",NULL);addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBeans((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 60 "lrparser.y"
    {(yyval.bean) = beanInfo("VarDefs",NULL);addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 63 "lrparser.y"
    {(yyval.bean) = beanInfo("VarDef",(yyvsp[(1) - (4)].sValue));addBean((yyval.bean),(yyvsp[(2) - (4)].bean));addBean((yyval.bean),(yyvsp[(4) - (4)].bean));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 64 "lrparser.y"
    {(yyval.bean) = beanInfo("VarDef",(yyvsp[(1) - (2)].sValue));addBean((yyval.bean),(yyvsp[(2) - (2)].bean));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 67 "lrparser.y"
    {(yyval.bean) = beanInfo("InitVals",NULL);addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBeans((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 68 "lrparser.y"
    {(yyval.bean) = beanInfo("InitVals",NULL);addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 71 "lrparser.y"
    {(yyval.bean) = beanInfo("InitVal",NULL);addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 72 "lrparser.y"
    {(yyval.bean) = beanInfo("InitVal","{}");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 73 "lrparser.y"
    {(yyval.bean) = beanInfo("InitVal","{}");addBean((yyval.bean),(yyvsp[(2) - (3)].bean));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 76 "lrparser.y"
    {(yyval.bean) = beanInfo("FuncDef-int",(yyvsp[(2) - (5)].sValue));addBean((yyval.bean),(yyvsp[(5) - (5)].bean));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 77 "lrparser.y"
    {(yyval.bean) = beanInfo("FuncDef-void",(yyvsp[(2) - (5)].sValue));addBean((yyval.bean),(yyvsp[(5) - (5)].bean));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 78 "lrparser.y"
    {(yyval.bean) = beanInfo("FuncDef-int",(yyvsp[(2) - (6)].sValue));addBean((yyval.bean),(yyvsp[(4) - (6)].bean));addBean((yyval.bean),(yyvsp[(6) - (6)].bean));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 79 "lrparser.y"
    {(yyval.bean) = beanInfo("FuncDef-void",(yyvsp[(2) - (6)].sValue));addBean((yyval.bean),(yyvsp[(4) - (6)].bean));addBean((yyval.bean),(yyvsp[(6) - (6)].bean));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 80 "lrparser.y"
    {(yyval.bean) = beanInfo("FuncDef-int","main");addBean((yyval.bean),(yyvsp[(5) - (5)].bean));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 83 "lrparser.y"
    {(yyval.bean) = beanInfo("FuncFParams",NULL);addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBeans((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 84 "lrparser.y"
    {(yyval.bean) = beanInfo("FuncFParams",NULL);addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 87 "lrparser.y"
    {(yyval.bean) = beanInfo("FuncFParam-int",(yyvsp[(2) - (2)].sValue));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 88 "lrparser.y"
    {(yyval.bean) = beanInfo("FuncFParam-int[]",(yyvsp[(2) - (5)].sValue));addBean((yyval.bean),(yyvsp[(5) - (5)].bean));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 91 "lrparser.y"
    {(yyval.bean) = beanInfo("Block",NULL);addBean((yyval.bean),(yyvsp[(2) - (3)].bean));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 94 "lrparser.y"
    {(yyval.bean) = beanInfo("BlockItems",NULL);addBean((yyval.bean),(yyvsp[(1) - (2)].bean));addBeans((yyval.bean),(yyvsp[(2) - (2)].bean));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 95 "lrparser.y"
    {(yyval.bean) = beanInfo("BlockItems","empty  ");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 98 "lrparser.y"
    {(yyval.bean) = beanInfo("BlockItem","Decl");addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 99 "lrparser.y"
    {(yyval.bean) = beanInfo("BlockItem","Stmt");addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 102 "lrparser.y"
    {(yyval.bean) = NULL;;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 103 "lrparser.y"
    {(yyval.bean) = beanInfo("Stmt","assign");addBean((yyval.bean),(yyvsp[(1) - (4)].bean));addBean((yyval.bean),(yyvsp[(3) - (4)].bean));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 104 "lrparser.y"
    {(yyval.bean) = beanInfo("Stmt","Exp");addBean((yyval.bean),(yyvsp[(1) - (2)].bean));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 105 "lrparser.y"
    {(yyval.bean) = beanInfo("Stmt","block");addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 106 "lrparser.y"
    {(yyval.bean) = beanInfo("Stmt","if-else");addBean((yyval.bean),(yyvsp[(3) - (7)].bean));addBean((yyval.bean),(yyvsp[(5) - (7)].bean));addBean((yyval.bean),(yyvsp[(7) - (7)].bean));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 107 "lrparser.y"
    {(yyval.bean) = beanInfo("Stmt","if");addBean((yyval.bean),(yyvsp[(3) - (5)].bean));addBean((yyval.bean),(yyvsp[(5) - (5)].bean));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 108 "lrparser.y"
    {(yyval.bean) = beanInfo("Stmt","while");addBean((yyval.bean),(yyvsp[(3) - (5)].bean));addBean((yyval.bean),(yyvsp[(5) - (5)].bean));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 109 "lrparser.y"
    {(yyval.bean) = beanInfo("Stmt","break");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 110 "lrparser.y"
    {(yyval.bean) = beanInfo("Stmt","continue");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 111 "lrparser.y"
    {(yyval.bean) = beanInfo("Stmt","return");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 112 "lrparser.y"
    {(yyval.bean) = beanInfo("Stmt","return");addBean((yyval.bean),(yyvsp[(2) - (3)].bean));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 115 "lrparser.y"
    {(yyval.bean) = beanInfo("Exps",NULL);addBean((yyval.bean),(yyvsp[(2) - (4)].bean));addBeans((yyval.bean),(yyvsp[(4) - (4)].bean));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 116 "lrparser.y"
    {(yyval.bean) = beanInfo("Exps",NULL);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 119 "lrparser.y"
    {(yyval.bean) = (yyvsp[(1) - (1)].bean);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 122 "lrparser.y"
    {(yyval.bean) = beanInfo("Cond",NULL);addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 125 "lrparser.y"
    {(yyval.bean) = beanInfo("LVal",(yyvsp[(1) - (2)].sValue));addBean((yyval.bean),(yyvsp[(2) - (2)].bean));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 128 "lrparser.y"
    {(yyval.bean) = (yyvsp[(2) - (3)].bean);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 129 "lrparser.y"
    {(yyval.bean) = (yyvsp[(1) - (1)].bean);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 130 "lrparser.y"
    {(yyval.bean) = (yyvsp[(1) - (1)].bean);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 133 "lrparser.y"
    {(yyval.bean) = beanInfo("Number",itos((yyvsp[(1) - (1)].iValue)));(yyval.bean)->iValue = (yyvsp[(1) - (1)].iValue);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 136 "lrparser.y"
    {(yyval.bean) = beanInfo("UnaryExp-function",(yyvsp[(1) - (3)].sValue));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 137 "lrparser.y"
    {(yyval.bean) = beanInfo("UnaryExp-function",(yyvsp[(1) - (4)].sValue));addBean((yyval.bean),(yyvsp[(3) - (4)].bean));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 138 "lrparser.y"
    {(yyval.bean) = (yyvsp[(1) - (1)].bean);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 139 "lrparser.y"
    {(yyval.bean) = beanInfo("UnaryExp","+");addBean((yyval.bean),(yyvsp[(2) - (2)].bean));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 140 "lrparser.y"
    {(yyval.bean) = beanInfo("UnaryExp","-");addBean((yyval.bean),(yyvsp[(2) - (2)].bean));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 141 "lrparser.y"
    {(yyval.bean) = beanInfo("UnaryExp","!");addBean((yyval.bean),(yyvsp[(2) - (2)].bean));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 144 "lrparser.y"
    {(yyval.bean) = beanInfo("FuncRParams",NULL);addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBeans((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 145 "lrparser.y"
    {(yyval.bean) = beanInfo("FuncRParams",NULL);addBean((yyval.bean),(yyvsp[(1) - (1)].bean));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 148 "lrparser.y"
    {(yyval.bean) = beanInfo("MulExp","*");addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBean((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 149 "lrparser.y"
    {(yyval.bean) = beanInfo("MulExp","/");addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBean((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 150 "lrparser.y"
    {(yyval.bean) = beanInfo("MulExp","%");addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBean((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 151 "lrparser.y"
    {(yyval.bean) = (yyvsp[(1) - (1)].bean);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 154 "lrparser.y"
    {(yyval.bean) = beanInfo("AddExp","+");addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBean((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 155 "lrparser.y"
    {(yyval.bean) = beanInfo("AddExp","-");addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBean((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 156 "lrparser.y"
    {(yyval.bean) = (yyvsp[(1) - (1)].bean);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 159 "lrparser.y"
    {(yyval.bean) = beanInfo("RelExp","<");addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBean((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 160 "lrparser.y"
    {(yyval.bean) = beanInfo("RelExp",">");addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBean((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 161 "lrparser.y"
    {(yyval.bean) = beanInfo("RelExp","<=");addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBean((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 162 "lrparser.y"
    {(yyval.bean) = beanInfo("RelExp",">= ");addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBean((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 163 "lrparser.y"
    {(yyval.bean) = (yyvsp[(1) - (1)].bean);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 166 "lrparser.y"
    {(yyval.bean) = beanInfo("EqExp","==");addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBean((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 167 "lrparser.y"
    {(yyval.bean) = beanInfo("EqExp","!=");addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBean((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 168 "lrparser.y"
    {(yyval.bean) = (yyvsp[(1) - (1)].bean);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 171 "lrparser.y"
    {(yyval.bean) = beanInfo("LAndExp","&&");addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBean((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 172 "lrparser.y"
    {(yyval.bean) = (yyvsp[(1) - (1)].bean);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 175 "lrparser.y"
    {(yyval.bean) = beanInfo("LOrExp","||");addBean((yyval.bean),(yyvsp[(1) - (3)].bean));addBean((yyval.bean),(yyvsp[(3) - (3)].bean));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 176 "lrparser.y"
    {(yyval.bean) = (yyvsp[(1) - (1)].bean);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 179 "lrparser.y"
    {(yyval.bean) = beanInfo("ConstExps",NULL);addBean((yyval.bean),(yyvsp[(2) - (4)].bean));addBeans((yyval.bean),(yyvsp[(4) - (4)].bean));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 180 "lrparser.y"
    {(yyval.bean) = NULL;;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 183 "lrparser.y"
    {(yyval.bean) = (yyvsp[(1) - (1)].bean);;}
    break;



/* Line 1455 of yacc.c  */
#line 2145 "lrparser.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 187 "lrparser.y"

void yyerror(char *s){
    printf("%s\n", s);
    if(stderr!=NULL)
		fprintf(stderr, "%s\n", s);
}
