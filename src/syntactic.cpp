/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "syntactic.y" /* yacc.c:339  */

#include <cstdio>
#include <cstdlib>
#include <string>
#include "ast.h"

extern int yylineno;
extern char* yytext;
extern int yylex();

extern Program *program;

void yyerror(std::string s) {
	printf("%d : %s %s\n", yylineno, s.c_str(), yytext );
}

#line 83 "syntactic.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "syntactic.hpp".  */
#ifndef YY_YY_SYNTACTIC_HPP_INCLUDED
# define YY_YY_SYNTACTIC_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    HEXNUM = 259,
    OCTNUM = 260,
    DECNUM = 261,
    PLUS = 262,
    MINUS = 263,
    TIMES = 264,
    DIV = 265,
    MOD = 266,
    NOT = 267,
    LE = 268,
    GE = 269,
    EQ = 270,
    NE = 271,
    LT = 272,
    GT = 273,
    IF = 274,
    ELSE = 275,
    WHILE = 276,
    PRINTF = 277,
    CONTINUE = 278,
    BREAK = 279,
    RETURN = 280,
    INT = 281,
    VOID = 282,
    CONST = 283,
    AND = 284,
    OR = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "syntactic.y" /* yacc.c:355  */

	std::string *string;
	int token;
	
	Program *program;
	FunctionDef *functionDef;
	ConstVarDecl *constVarDecl;
	VarDecl *varDecl;
	TypeDecl *typeDecl;
	ConstVarDef *constVarDef;
	Lval *lval;
	Ident *ident;
	ArrayElement *arrayEle;
	VarDef *varDef;
	DirectDecl *directDecl;
	Expression *exp;
	Operation *operation;
	AddExpression *addExp;
	MulExpression *mulExp;
	LOrExpression *lorExp;
	LAndExpression *landExp;
	EqExpression *eqExp;
	RelExpression *relExp;
	UnaryExp *unaryExp;
	PrimaryExpression *primaryExp;
	FuncParam *funcParam;
	FunctionCall *funcCall;
	Block *block;
	Statement *statement;
	IFStatement *ifStatement;
	WHILEStatement *whileStatement;
	RETURNStatement *returnStatement;
	CONTINUEStatement *continueStatement;
	BREAKStatement *breakStatement;
	InitVal *initVal;
	ArrayDecl *arrayDecl;


	vector<ConstVarDef*> *constVarDefList;
	vector<VarDef*> *varDefList;
	vector<Expression*> *paramList;
	vector<FuncParam*> *funcFParams;
	vector<Statement*> *stmtList;
	vector<InitVal*> *repInitVal;

#line 200 "syntactic.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTACTIC_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 217 "syntactic.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    39,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   119,   120,   121,   122,   123,   126,   129,
     132,   133,   136,   139,   143,   144,   147,   148,   151,   152,
     155,   156,   159,   160,   163,   164,   165,   168,   169,   172,
     173,   174,   177,   178,   181,   182,   183,   186,   189,   192,
     193,   194,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   211,   212,   215,   218,   221,   225,   226,
     230,   233,   238,   239,   240,   243,   246,   247,   248,   251,
     252,   253,   256,   259,   260,   263,   264,   267,   268,   269,
     272,   273,   274,   275,   278,   279,   280,   283,   284,   285,
     286,   287,   290,   291,   292,   295,   296,   299,   300,   303
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "HEXNUM", "OCTNUM", "DECNUM",
  "PLUS", "MINUS", "TIMES", "DIV", "MOD", "NOT", "LE", "GE", "EQ", "NE",
  "LT", "GT", "IF", "ELSE", "WHILE", "PRINTF", "CONTINUE", "BREAK",
  "RETURN", "INT", "VOID", "CONST", "AND", "OR", "'='", "'['", "']'",
  "'{'", "'}'", "';'", "','", "'('", "')'", "$accept", "Program",
  "ConstVarDecl", "BType", "ConstVarDefList", "ConstVarDef", "VarDecl",
  "VarDefList", "Lval", "VarDef", "DirectDecl", "ArrayDecl", "ArrayEle",
  "InitVal", "REPInitVal", "FuncDef", "FuncFParams", "FuncFParam", "Block",
  "Stmts", "Stmt", "IFStmt", "WHILEStmt", "BREAKStmt", "CONTINUEStmt",
  "RETURNStmt", "Exp", "Cond", "PrimaryExp", "Number", "IntConst",
  "UnaryExp", "FuncCall", "ParamList", "FuncRParams", "UnaryOp", "MulExp",
  "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    61,    91,    93,   123,   125,    59,    44,    40,    41
};
# endif

#define YYPACT_NINF -110

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-110)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      63,  -110,     5,   -13,     9,  -110,    27,  -110,  -110,     0,
      49,  -110,  -110,  -110,  -110,    32,    39,  -110,  -110,  -110,
      62,   -13,    24,    64,  -110,    23,    52,   195,    41,   -13,
    -110,    84,    54,   195,    49,   -16,  -110,  -110,    49,    54,
     -20,  -110,  -110,  -110,  -110,  -110,  -110,   195,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,   195,    58,    99,  -110,    99,
      65,    -6,    77,  -110,    54,  -110,  -110,    70,  -110,   -13,
      61,  -110,  -110,   195,    92,  -110,   195,   195,   195,   195,
     195,  -110,    61,  -110,     4,  -110,  -110,   158,  -110,  -110,
      93,    79,  -110,  -110,  -110,  -110,    58,    58,  -110,  -110,
      54,    97,    98,  -110,  -110,   168,  -110,  -110,    84,  -110,
     106,  -110,   122,  -110,  -110,  -110,   102,   103,  -110,   104,
    -110,   195,  -110,   195,   195,  -110,   108,   195,  -110,  -110,
    -110,  -110,  -110,  -110,   110,    99,    68,    95,   123,   121,
     114,  -110,   119,   158,   195,   195,   195,   195,   195,   195,
     195,   195,   158,  -110,   139,    99,    99,    99,    99,    68,
      68,    95,   123,  -110,   158,  -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,     0,     0,     0,     4,     0,     3,     2,     0,
       0,     1,     7,     6,     5,    20,     0,    14,    18,    19,
      22,    34,    16,     0,    10,     0,    17,     0,     0,    34,
      13,     0,     0,     0,     0,     0,    35,     8,     0,     0,
      16,    66,    67,    68,    77,    78,    79,     0,    63,    21,
      69,    62,    65,    80,    70,     0,    84,    60,    24,    99,
       0,     0,    20,    15,    29,    23,    27,     0,    37,     0,
       0,    11,    12,    73,     0,    71,     0,     0,     0,     0,
       0,    25,     0,    30,     0,    26,    36,    39,    33,    75,
       0,    74,    64,    81,    82,    83,    85,    86,    32,    28,
       0,     0,     0,    57,    56,     0,    45,    43,     0,    42,
      63,    47,     0,    40,    48,    49,     0,     0,    52,     0,
      72,     0,    31,     0,     0,    58,     0,     0,    38,    41,
      50,    51,    46,    76,     0,    87,    92,    95,    97,    61,
       0,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    53,    91,    90,    89,    88,    93,
      94,    96,    98,    55,     0,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,    16,    11,  -110,   129,    22,  -110,   -10,   137,
    -110,  -110,    -4,   -35,  -110,   165,   149,   116,   -63,  -110,
    -109,  -110,  -110,  -110,  -110,  -110,   -22,    66,  -110,  -110,
    -110,    -5,  -110,  -110,  -110,  -110,    33,   -27,   -34,    37,
      38,  -110,   155
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,   107,   108,    23,    24,   109,    16,    48,    17,
      18,    19,    26,    65,    84,     8,    35,    36,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   134,    50,    51,
      52,    53,    54,    90,    91,    55,    56,    57,   136,   137,
     138,   139,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    59,    20,   129,    72,    49,    59,    88,     9,    11,
      66,     6,    28,     1,    10,     6,     5,    66,    73,    98,
      12,    69,     7,    70,    68,    74,    13,    20,    25,    83,
      15,    69,    34,    82,   154,     1,     2,     3,    21,    99,
      34,   100,    66,   163,    40,    41,    42,    43,    44,    45,
      75,    89,    22,    46,    39,   165,    28,    40,    41,    42,
      43,    44,    45,    27,    28,   122,    46,    76,    77,    78,
      29,    93,    94,    95,    58,    30,    31,   110,    66,    47,
      34,   144,   145,   126,    33,   146,   147,    62,    64,     1,
       2,     3,    47,    32,    33,    87,   135,   135,    81,   133,
      37,    38,   110,    85,    20,   142,    79,    80,    27,    28,
     148,   149,    96,    97,   159,   160,   121,   155,   156,   157,
     158,   135,   135,   135,   135,    40,    41,    42,    43,    44,
      45,    92,   120,   110,    46,   123,   124,   127,   130,   131,
     132,   101,   110,   102,   141,   103,   104,   105,     1,   143,
       3,   151,   150,   152,   110,   153,    87,   128,   106,   164,
      47,    40,    41,    42,    43,    44,    45,    71,    63,    14,
      46,    40,    41,    42,    43,    44,    45,   101,    61,   102,
      46,   103,   104,   105,     1,    86,     3,   161,    67,   162,
     140,     0,    87,     0,   106,     0,    47,     0,    40,    41,
      42,    43,    44,    45,   125,     0,    47,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47
};

static const yytype_int16 yycheck[] =
{
      10,    28,     6,   112,    39,    27,    33,    70,     3,     0,
      32,     0,    32,    26,     3,     4,     0,    39,    38,    82,
       4,    37,     0,    39,    34,    47,     4,    31,    38,    64,
       3,    37,    21,    39,   143,    26,    27,    28,    38,    35,
      29,    37,    64,   152,     3,     4,     5,     6,     7,     8,
      55,    73,     3,    12,    31,   164,    32,     3,     4,     5,
       6,     7,     8,    31,    32,   100,    12,     9,    10,    11,
      38,    76,    77,    78,    33,    36,    37,    87,   100,    38,
      69,    13,    14,   105,    32,    17,    18,     3,    34,    26,
      27,    28,    38,    31,    32,    34,   123,   124,    33,   121,
      36,    37,   112,    33,   108,   127,     7,     8,    31,    32,
      15,    16,    79,    80,   148,   149,    37,   144,   145,   146,
     147,   148,   149,   150,   151,     3,     4,     5,     6,     7,
       8,    39,    39,   143,    12,    38,    38,    31,    36,    36,
      36,    19,   152,    21,    36,    23,    24,    25,    26,    39,
      28,    30,    29,    39,   164,    36,    34,    35,    36,    20,
      38,     3,     4,     5,     6,     7,     8,    38,    31,     4,
      12,     3,     4,     5,     6,     7,     8,    19,    29,    21,
      12,    23,    24,    25,    26,    69,    28,   150,    33,   151,
     124,    -1,    34,    -1,    36,    -1,    38,    -1,     3,     4,
       5,     6,     7,     8,    36,    -1,    38,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    27,    28,    41,    42,    43,    46,    55,     3,
      43,     0,    42,    46,    55,     3,    47,    49,    50,    51,
      52,    38,     3,    44,    45,    48,    52,    31,    32,    38,
      36,    37,    31,    32,    43,    56,    57,    36,    37,    31,
       3,     4,     5,     6,     7,     8,    12,    38,    48,    66,
      68,    69,    70,    71,    72,    75,    76,    77,    33,    77,
      82,    56,     3,    49,    34,    53,    66,    82,    48,    37,
      39,    45,    53,    38,    66,    71,     9,    10,    11,     7,
       8,    33,    39,    53,    54,    33,    57,    34,    58,    66,
      73,    74,    39,    71,    71,    71,    76,    76,    58,    35,
      37,    19,    21,    23,    24,    25,    36,    42,    43,    46,
      48,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      39,    37,    53,    38,    38,    36,    66,    31,    35,    60,
      36,    36,    36,    66,    67,    77,    78,    79,    80,    81,
      67,    36,    66,    39,    13,    14,    17,    18,    15,    16,
      29,    30,    39,    36,    60,    77,    77,    77,    77,    78,
      78,    79,    80,    60,    20,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    41,    41,    41,    41,    42,    43,
      44,    44,    45,    46,    47,    47,    48,    48,    49,    49,
      50,    50,    51,    51,    52,    52,    52,    53,    53,    54,
      54,    54,    55,    55,    56,    56,    56,    57,    58,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    63,    64,    65,    65,
      66,    67,    68,    68,    68,    69,    70,    70,    70,    71,
      71,    71,    72,    73,    73,    74,    74,    75,    75,    75,
      76,    76,    76,    76,    77,    77,    77,    78,    78,    78,
      78,    78,    79,    79,    79,    80,    80,    81,    81,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     2,     4,     1,
       1,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     3,     3,     4,     4,     1,     3,     0,
       1,     3,     6,     6,     0,     1,     3,     2,     3,     0,
       1,     2,     1,     1,     4,     1,     2,     1,     1,     1,
       2,     2,     1,     5,     7,     5,     1,     1,     2,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     4,     0,     1,     1,     3,     1,     1,     1,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 118 "syntactic.y" /* yacc.c:1646  */
    {(yyval.program) = new Program(); (yyval.program)->addFuncDef((yyvsp[0].functionDef)); program = (yyval.program); }
#line 1427 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 119 "syntactic.y" /* yacc.c:1646  */
    {(yyval.program) = new Program(); (yyval.program)->addVarDecl((yyvsp[0].varDecl));  program = (yyval.program);}
#line 1433 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 120 "syntactic.y" /* yacc.c:1646  */
    {(yyval.program) = new Program(); (yyval.program)->addConstVarDecl((yyvsp[0].constVarDecl));  program = (yyval.program);}
#line 1439 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 121 "syntactic.y" /* yacc.c:1646  */
    {(yyval.program)->addFuncDef((yyvsp[0].functionDef));}
#line 1445 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 122 "syntactic.y" /* yacc.c:1646  */
    {(yyval.program)->addVarDecl((yyvsp[0].varDecl));}
#line 1451 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 123 "syntactic.y" /* yacc.c:1646  */
    {(yyval.program)->addConstVarDecl((yyvsp[0].constVarDecl));}
#line 1457 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "syntactic.y" /* yacc.c:1646  */
    {(yyval.constVarDecl) = new ConstVarDecl((yyvsp[-2].typeDecl),*(yyvsp[-1].constVarDefList));}
#line 1463 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 129 "syntactic.y" /* yacc.c:1646  */
    {(yyval.typeDecl) = new TypeDecl("int");}
#line 1469 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 132 "syntactic.y" /* yacc.c:1646  */
    {(yyval.constVarDefList) = new vector<ConstVarDef*>(); (yyval.constVarDefList)->push_back((yyvsp[0].constVarDef));}
#line 1475 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 133 "syntactic.y" /* yacc.c:1646  */
    {(yyval.constVarDefList)->push_back((yyvsp[0].constVarDef));}
#line 1481 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 136 "syntactic.y" /* yacc.c:1646  */
    {(yyval.constVarDef) = new ConstVarDef((yyvsp[-2].lval),(yyvsp[0].initVal));}
#line 1487 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 139 "syntactic.y" /* yacc.c:1646  */
    {(yyval.varDecl) = new VarDecl((yyvsp[-2].typeDecl), *(yyvsp[-1].varDefList));}
#line 1493 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 143 "syntactic.y" /* yacc.c:1646  */
    {(yyval.varDefList) = new vector<VarDef*>(); (yyval.varDefList)->push_back((yyvsp[0].varDef));}
#line 1499 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 144 "syntactic.y" /* yacc.c:1646  */
    {(yyval.varDefList)->push_back((yyvsp[0].varDef));}
#line 1505 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 147 "syntactic.y" /* yacc.c:1646  */
    {(yyval.lval) = new Ident(*(yyvsp[0].string));}
#line 1511 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 148 "syntactic.y" /* yacc.c:1646  */
    { (yyval.lval) = (yyvsp[0].arrayEle); }
#line 1517 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 151 "syntactic.y" /* yacc.c:1646  */
    {(yyval.varDef) = (yyvsp[0].directDecl);}
#line 1523 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 152 "syntactic.y" /* yacc.c:1646  */
    {(yyval.varDef) = (yyvsp[0].arrayDecl);}
#line 1529 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 155 "syntactic.y" /* yacc.c:1646  */
    {(yyval.directDecl) = new DirectDecl(new Ident(*(yyvsp[0].string)), NULL); }
#line 1535 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 156 "syntactic.y" /* yacc.c:1646  */
    {(yyval.directDecl) = new DirectDecl(new Ident(*(yyvsp[-2].string)), (yyvsp[0].exp)); }
#line 1541 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 159 "syntactic.y" /* yacc.c:1646  */
    {(yyval.arrayDecl) = new ArrayDecl((yyvsp[0].arrayEle),NULL);}
#line 1547 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 160 "syntactic.y" /* yacc.c:1646  */
    {(yyval.arrayDecl) = new ArrayDecl((yyvsp[-2].arrayEle),(yyvsp[0].initVal));}
#line 1553 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 163 "syntactic.y" /* yacc.c:1646  */
    { (yyval.arrayEle) = new ArrayElement(new Ident(*(yyvsp[-2].string)), NULL); }
#line 1559 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 164 "syntactic.y" /* yacc.c:1646  */
    { (yyval.arrayEle) = new ArrayElement(new Ident(*(yyvsp[-3].string)), (yyvsp[-1].addExp)); }
#line 1565 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 165 "syntactic.y" /* yacc.c:1646  */
    { (yyval.arrayEle) = new ArrayElement((yyvsp[-3].arrayEle), (yyvsp[-1].addExp)); }
#line 1571 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 168 "syntactic.y" /* yacc.c:1646  */
    {(yyval.initVal) = new InitVal((yyvsp[0].exp) ,*new vector<InitVal*>());}
#line 1577 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 169 "syntactic.y" /* yacc.c:1646  */
    {(yyval.initVal) = new InitVal(NULL ,*(yyvsp[-1].repInitVal));}
#line 1583 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 172 "syntactic.y" /* yacc.c:1646  */
    { (yyval.repInitVal) = new vector<InitVal*>(); }
#line 1589 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 173 "syntactic.y" /* yacc.c:1646  */
    { (yyval.repInitVal) = new vector<InitVal*>(); (yyval.repInitVal)->push_back((yyvsp[0].initVal)); }
#line 1595 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 174 "syntactic.y" /* yacc.c:1646  */
    { (yyval.repInitVal)->push_back((yyvsp[0].initVal)); }
#line 1601 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 177 "syntactic.y" /* yacc.c:1646  */
    {(yyval.functionDef) = new FunctionDef((yyvsp[-5].typeDecl),new Ident(*(yyvsp[-4].string)),*(yyvsp[-2].funcFParams),(yyvsp[0].block));}
#line 1607 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 178 "syntactic.y" /* yacc.c:1646  */
    {(yyval.functionDef) = new FunctionDef(new TypeDecl("void"),new Ident(*(yyvsp[-4].string)),*(yyvsp[-2].funcFParams),(yyvsp[0].block));}
#line 1613 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 181 "syntactic.y" /* yacc.c:1646  */
    {(yyval.funcFParams) = new vector<FuncParam*>();}
#line 1619 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 182 "syntactic.y" /* yacc.c:1646  */
    {(yyval.funcFParams) = new vector<FuncParam*>(); (yyval.funcFParams)->push_back((yyvsp[0].funcParam));}
#line 1625 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 183 "syntactic.y" /* yacc.c:1646  */
    {(yyval.funcFParams)->push_back((yyvsp[0].funcParam));}
#line 1631 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 186 "syntactic.y" /* yacc.c:1646  */
    {(yyval.funcParam) = new FuncParam((yyvsp[-1].typeDecl),(yyvsp[0].lval));}
#line 1637 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 189 "syntactic.y" /* yacc.c:1646  */
    {(yyval.block) = new Block(*(yyvsp[-1].stmtList));}
#line 1643 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 192 "syntactic.y" /* yacc.c:1646  */
    {(yyval.stmtList) = new vector<Statement*>();}
#line 1649 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 193 "syntactic.y" /* yacc.c:1646  */
    {(yyval.stmtList) = new vector<Statement*>(); (yyval.stmtList)->push_back((yyvsp[0].statement));}
#line 1655 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 194 "syntactic.y" /* yacc.c:1646  */
    {(yyval.stmtList)->push_back((yyvsp[0].statement));}
#line 1661 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 197 "syntactic.y" /* yacc.c:1646  */
    {(yyval.statement) = (yyvsp[0].varDecl);}
#line 1667 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 198 "syntactic.y" /* yacc.c:1646  */
    {(yyval.statement) = (yyvsp[0].constVarDecl);}
#line 1673 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 199 "syntactic.y" /* yacc.c:1646  */
    {(yyval.statement) = new Assignment((yyvsp[-3].lval),(yyvsp[-1].exp));}
#line 1679 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 201 "syntactic.y" /* yacc.c:1646  */
    {(yyval.statement) = new ExpressionStatement((yyvsp[-1].exp));}
#line 1685 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 202 "syntactic.y" /* yacc.c:1646  */
    {(yyval.statement) = new BlockStatement((yyvsp[0].block));}
#line 1691 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 203 "syntactic.y" /* yacc.c:1646  */
    {(yyval.statement) = (yyvsp[0].ifStatement);}
#line 1697 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 204 "syntactic.y" /* yacc.c:1646  */
    {(yyval.statement) = (yyvsp[0].whileStatement);}
#line 1703 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 205 "syntactic.y" /* yacc.c:1646  */
    {(yyval.statement) = new BREAKStatement();}
#line 1709 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 206 "syntactic.y" /* yacc.c:1646  */
    {(yyval.statement) = new CONTINUEStatement();}
#line 1715 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 207 "syntactic.y" /* yacc.c:1646  */
    {(yyval.statement) = (yyvsp[0].returnStatement);}
#line 1721 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 211 "syntactic.y" /* yacc.c:1646  */
    {(yyval.ifStatement) = new IFStatement((yyvsp[-2].lorExp),(yyvsp[0].statement),NULL);}
#line 1727 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 212 "syntactic.y" /* yacc.c:1646  */
    {(yyval.ifStatement) = new IFStatement((yyvsp[-4].lorExp),(yyvsp[-2].statement),(yyvsp[0].statement));}
#line 1733 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 215 "syntactic.y" /* yacc.c:1646  */
    {(yyval.whileStatement) = new WHILEStatement((yyvsp[-2].lorExp),(yyvsp[0].statement));}
#line 1739 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 225 "syntactic.y" /* yacc.c:1646  */
    {(yyval.returnStatement) = new RETURNStatement(NULL);}
#line 1745 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 226 "syntactic.y" /* yacc.c:1646  */
    {(yyval.returnStatement) = new RETURNStatement((yyvsp[-1].exp));}
#line 1751 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 230 "syntactic.y" /* yacc.c:1646  */
    {(yyval.exp) = (yyvsp[0].addExp);}
#line 1757 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 233 "syntactic.y" /* yacc.c:1646  */
    {(yyval.lorExp) = (yyvsp[0].lorExp);}
#line 1763 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 238 "syntactic.y" /* yacc.c:1646  */
    {(yyval.primaryExp) = new PrimaryExpression(*(yyvsp[0].string), NULL, NULL);}
#line 1769 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 239 "syntactic.y" /* yacc.c:1646  */
    {(yyval.primaryExp) = new PrimaryExpression(*new string(), (yyvsp[0].lval), NULL);}
#line 1775 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 240 "syntactic.y" /* yacc.c:1646  */
    {(yyval.primaryExp) = new PrimaryExpression(*new string(), NULL, (AddExpression*)(yyvsp[-1].exp));}
#line 1781 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 243 "syntactic.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1787 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 246 "syntactic.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1793 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 247 "syntactic.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1799 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 248 "syntactic.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1805 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 251 "syntactic.y" /* yacc.c:1646  */
    {(yyval.unaryExp) = new UnaryExp((yyvsp[0].primaryExp), NULL, NULL, NULL);}
#line 1811 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 252 "syntactic.y" /* yacc.c:1646  */
    {(yyval.unaryExp) = new UnaryExp(NULL, (yyvsp[0].funcCall), NULL, NULL);}
#line 1817 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 253 "syntactic.y" /* yacc.c:1646  */
    {(yyval.unaryExp) = new UnaryExp(NULL, NULL, (yyvsp[-1].operation), (yyvsp[0].unaryExp));}
#line 1823 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 256 "syntactic.y" /* yacc.c:1646  */
    { (yyval.funcCall) = new FunctionCall(new Ident(*(yyvsp[-3].string)), *(yyvsp[-1].paramList));  delete (yyvsp[-3].string);}
#line 1829 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 259 "syntactic.y" /* yacc.c:1646  */
    {(yyval.paramList) = new vector<Expression*>();}
#line 1835 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 260 "syntactic.y" /* yacc.c:1646  */
    {(yyval.paramList) = (yyvsp[0].paramList);}
#line 1841 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 263 "syntactic.y" /* yacc.c:1646  */
    {(yyval.paramList) = new vector<Expression*>(); (yyval.paramList)->push_back((yyvsp[0].exp));}
#line 1847 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 264 "syntactic.y" /* yacc.c:1646  */
    {(yyval.paramList)->push_back((yyvsp[0].exp));}
#line 1853 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 267 "syntactic.y" /* yacc.c:1646  */
    {(yyval.operation) = new Operation(*(yyvsp[0].string));}
#line 1859 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 268 "syntactic.y" /* yacc.c:1646  */
    {(yyval.operation) = new Operation(*(yyvsp[0].string));}
#line 1865 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 269 "syntactic.y" /* yacc.c:1646  */
    {(yyval.operation) = new Operation(*(yyvsp[0].string));}
#line 1871 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 272 "syntactic.y" /* yacc.c:1646  */
    {(yyval.mulExp) = new MulExpression((yyvsp[0].unaryExp));}
#line 1877 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 273 "syntactic.y" /* yacc.c:1646  */
    {(yyval.mulExp) = new MulExpression((yyvsp[-2].mulExp),new Operation(*(yyvsp[-1].string)),(yyvsp[0].unaryExp));}
#line 1883 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 274 "syntactic.y" /* yacc.c:1646  */
    {(yyval.mulExp) = new MulExpression((yyvsp[-2].mulExp),new Operation(*(yyvsp[-1].string)),(yyvsp[0].unaryExp));}
#line 1889 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 275 "syntactic.y" /* yacc.c:1646  */
    {(yyval.mulExp) = new MulExpression((yyvsp[-2].mulExp),new Operation(*(yyvsp[-1].string)),(yyvsp[0].unaryExp));}
#line 1895 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 278 "syntactic.y" /* yacc.c:1646  */
    {(yyval.addExp) = new AddExpression((yyvsp[0].mulExp));}
#line 1901 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 279 "syntactic.y" /* yacc.c:1646  */
    {(yyval.addExp) = new AddExpression((yyvsp[-2].addExp),new Operation(*(yyvsp[-1].string)),(yyvsp[0].mulExp));}
#line 1907 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 280 "syntactic.y" /* yacc.c:1646  */
    {(yyval.addExp) = new AddExpression((yyvsp[-2].addExp),new Operation(*(yyvsp[-1].string)),(yyvsp[0].mulExp));}
#line 1913 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 283 "syntactic.y" /* yacc.c:1646  */
    {(yyval.relExp) = new RelExpression((yyvsp[0].addExp));}
#line 1919 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 284 "syntactic.y" /* yacc.c:1646  */
    {(yyval.relExp) = new RelExpression((yyvsp[-2].relExp), new Operation(*(yyvsp[-1].string)), (yyvsp[0].addExp));}
#line 1925 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 285 "syntactic.y" /* yacc.c:1646  */
    {(yyval.relExp) = new RelExpression((yyvsp[-2].relExp), new Operation(*(yyvsp[-1].string)), (yyvsp[0].addExp));}
#line 1931 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 286 "syntactic.y" /* yacc.c:1646  */
    {(yyval.relExp) = new RelExpression((yyvsp[-2].relExp), new Operation(*(yyvsp[-1].string)), (yyvsp[0].addExp));}
#line 1937 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 287 "syntactic.y" /* yacc.c:1646  */
    {(yyval.relExp) = new RelExpression((yyvsp[-2].relExp), new Operation(*(yyvsp[-1].string)), (yyvsp[0].addExp));}
#line 1943 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 290 "syntactic.y" /* yacc.c:1646  */
    {(yyval.eqExp) = new EqExpression((yyvsp[0].relExp));}
#line 1949 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 291 "syntactic.y" /* yacc.c:1646  */
    {(yyval.eqExp) = new EqExpression((yyvsp[-2].eqExp), new Operation(*(yyvsp[-1].string)), (yyvsp[0].relExp));}
#line 1955 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 292 "syntactic.y" /* yacc.c:1646  */
    {(yyval.eqExp) = new EqExpression((yyvsp[-2].eqExp), new Operation(*(yyvsp[-1].string)), (yyvsp[0].relExp));}
#line 1961 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 295 "syntactic.y" /* yacc.c:1646  */
    {(yyval.landExp) = new LAndExpression((yyvsp[0].eqExp));}
#line 1967 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 296 "syntactic.y" /* yacc.c:1646  */
    {(yyval.landExp) = new LAndExpression((yyvsp[-2].landExp), (yyvsp[0].eqExp));}
#line 1973 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 299 "syntactic.y" /* yacc.c:1646  */
    {(yyval.lorExp) = new LOrExpression((yyvsp[0].landExp));}
#line 1979 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 300 "syntactic.y" /* yacc.c:1646  */
    {(yyval.lorExp) = new LOrExpression((yyvsp[-2].lorExp), (yyvsp[0].landExp));}
#line 1985 "syntactic.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 303 "syntactic.y" /* yacc.c:1646  */
    {(yyval.addExp) = (yyvsp[0].addExp);}
#line 1991 "syntactic.cpp" /* yacc.c:1646  */
    break;


#line 1995 "syntactic.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 307 "syntactic.y" /* yacc.c:1906  */


         
