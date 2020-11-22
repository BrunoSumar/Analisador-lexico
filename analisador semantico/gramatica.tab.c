/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "gramatica.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simbolos.h"

int yyerror();
int yylex();

extern int yylineno;
extern int count;


#line 84 "gramatica.tab.c"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_GRAMATICA_TAB_H_INCLUDED
# define YY_YY_GRAMATICA_TAB_H_INCLUDED
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
    PROGRAM = 258,
    BEGIN_ = 259,
    END = 260,
    CONST = 261,
    TYPE = 262,
    VAR = 263,
    INTEGER = 264,
    REAL = 265,
    ARRAY = 266,
    RECORD = 267,
    OF = 268,
    FUNCTION = 269,
    WHILE = 270,
    IF = 271,
    THEN = 272,
    ELSE = 273,
    WRITE = 274,
    READ = 275,
    ATRIBUICAO = 276,
    ABRE_PARENTESES = 277,
    FECHA_PARENTESES = 278,
    VIRGULA = 279,
    PONTO = 280,
    ABRE_COLCHETES = 281,
    FECHA_COLCHETES = 282,
    IDENTIFICADOR = 283,
    PONTO_E_VIRGULA = 284,
    DOIS_PONTOS = 285,
    CONST_STRING = 286,
    NUMERO = 287,
    MAIOR_QUE = 288,
    MENOR_QUE = 289,
    IGUAL = 290,
    SOMA = 291,
    SUBTRACAO = 292,
    MULT = 293,
    EXCLAMACAO = 294,
    BARRA = 295,
    ERRO = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "gramatica.y"
char *str;double fl;char* nome; char* tipo;

#line 172 "gramatica.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMATICA_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   232

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

#define YYUNDEFTOK  2
#define YYMAXUTOK   296

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    65,    68,    69,    72,    73,    74,    77,
      83,    84,    85,    88,    89,    90,    93,    94,    95,    98,
      99,   102,   112,   115,   119,   120,   123,   140,   141,   142,
     145,   146,   149,   158,   159,   160,   163,   164,   165,   168,
     171,   178,   185,   188,   192,   196,   201,   208,   218,   221,
     228,   229,   230,   233,   238,   241,   250,   259,   262,   276,
     283,   289,   290,   291,   294,   295,   299,   302,   303,   304,
     307,   308,   309,   310,   311,   312,   315,   321,   322,   323,
     326,   327,   340,   352,   353,   356,   357,   358,   361,   367,
     375,   376,   379,   380,   383,   384,   387,   388,   389,   390,
     393,   394,   395,   396,   399,   404,   405,   409,   412,   437
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "BEGIN_", "END", "CONST",
  "TYPE", "VAR", "INTEGER", "REAL", "ARRAY", "RECORD", "OF", "FUNCTION",
  "WHILE", "IF", "THEN", "ELSE", "WRITE", "READ", "ATRIBUICAO",
  "ABRE_PARENTESES", "FECHA_PARENTESES", "VIRGULA", "PONTO",
  "ABRE_COLCHETES", "FECHA_COLCHETES", "IDENTIFICADOR", "PONTO_E_VIRGULA",
  "DOIS_PONTOS", "CONST_STRING", "NUMERO", "MAIOR_QUE", "MENOR_QUE",
  "IGUAL", "SOMA", "SUBTRACAO", "MULT", "EXCLAMACAO", "BARRA", "ERRO",
  "$accept", "programa", "corpo", "declaracoes", "lista_def", "def_const",
  "def_tipos", "def_var", "lista_const", "constante", "const_valor",
  "numero", "lista_tipos", "tipo", "id_tipo", "lista_var", "lista_def_var",
  "variavel", "lista_id", "tipo_dado", "record", "lista_func", "funcao",
  "nome_funcao", "escopo_funcao", "dp_funcao", "tipo_funcao",
  "bloco_funcao", "bloco", "lista_com", "comando", "condicao", "else",
  "valor", "id_func", "lista_param", "lista_nome", "func_par",
  "exp_logica", "exp_mat", "parametro", "op_logico", "op_mat", "nome",
  "id_record", "id_array", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -124

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-124)))

#define YYTABLE_NINF -108

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,     2,    50,    85,   150,    80,  -124,   164,    38,  -124,
      75,   138,   166,   150,   139,  -124,    82,  -124,   138,    96,
     128,   126,    73,  -124,    68,    86,  -124,  -124,    40,   175,
    -124,  -124,  -124,     8,    86,    42,    26,    26,    16,   102,
      37,   116,  -124,  -124,  -124,   145,   102,    26,    36,  -124,
      16,  -124,    -6,   170,   131,    23,  -124,  -124,   148,   146,
    -124,  -124,   177,   158,   179,  -124,   159,   171,  -124,  -124,
    -124,   116,  -124,   151,   155,  -124,   187,   160,  -124,  -124,
    -124,  -124,  -124,  -124,   173,  -124,    29,  -124,   178,   180,
     176,   184,   181,   182,  -124,    86,  -124,  -124,  -124,   186,
    -124,  -124,    40,  -124,    42,   133,   117,  -124,  -124,   120,
      79,   117,  -124,  -124,  -124,  -124,  -124,    26,  -124,  -124,
    -124,  -124,    26,   116,   137,  -124,   124,  -124,  -124,  -124,
    -124,   117,   176,   121,  -124,  -124,   183,  -124,   203,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,    24,   190,    17,
    -124,  -124,  -124,   117,  -124,   189,  -124,  -124,   116,  -124,
    -124,  -124,   191,   193,  -124,  -124,   205,  -124,  -124,    17,
     117,  -124,  -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     1,     0,     0,     3,
       0,     0,     0,     0,    57,     5,     0,     7,     0,     0,
       0,     0,     0,    10,     0,     0,     6,    14,     0,     0,
       2,    58,    50,    17,     0,     0,     0,     0,     0,     0,
     104,     0,    53,    62,    65,     0,     0,     0,     0,    22,
       0,    19,    69,     0,     0,     0,    32,    13,     0,     0,
      17,     9,     0,    42,    41,    16,     0,     0,   107,    26,
      95,     0,    76,    91,    93,    94,     0,    25,    23,    73,
      24,    74,   108,   109,    66,    61,     0,   105,     0,    42,
       0,     0,    34,     0,     4,     0,    48,    43,    44,     0,
      49,    47,     0,    31,     0,     0,     0,    64,    38,     0,
       0,     0,    71,    96,    97,    98,    99,     0,   100,   101,
     102,   103,     0,     0,   104,    70,     0,    80,   106,    35,
      59,     0,     0,     0,    21,    67,     0,    29,     0,    27,
      30,    42,    40,    36,    39,    90,    92,     0,     0,     0,
      81,    60,    56,     0,    33,     0,    46,    79,     0,    72,
      84,    89,     0,    86,    88,    55,     0,    77,    83,     0,
       0,    85,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,   206,  -124,  -124,  -124,  -124,   192,   196,  -124,
     172,  -123,    97,  -124,  -124,    90,   -39,   -43,   115,   -51,
    -124,    56,  -124,  -124,  -124,    93,    74,  -124,   -35,   -22,
     -18,  -124,  -124,  -124,  -124,  -124,    57,  -124,   -28,   -30,
     185,  -124,  -124,   -36,  -124,  -124
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     9,    10,    11,    12,    29,    41,    23,    24,
      79,    70,    57,    58,    59,    91,    65,    66,    67,   151,
     104,    17,    18,    19,    20,   131,   152,    42,    43,    53,
      44,    71,   159,   125,   126,   150,   162,   163,    72,    73,
      74,   117,   122,    45,    46,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    75,    75,    81,   103,    92,    85,    54,    80,    76,
      87,    75,    62,   155,    75,  -107,    54,    77,    68,     1,
      80,     2,   -63,   -75,    96,   157,   161,    68,   -78,  -107,
      68,     4,    97,    98,    99,   100,   112,    89,   -78,    21,
     -87,    55,   158,    63,    40,    40,   161,    78,    69,    69,
      75,   101,   102,   -78,    40,   140,   127,   124,    69,    90,
     144,    69,    82,    83,    64,   138,    22,    26,    56,    21,
      64,   143,   -20,   135,    32,   -20,   -20,    54,     5,    25,
      63,    75,   -20,   -37,   -37,     6,    75,    52,   147,   145,
      92,   -68,   146,   -37,   -37,   -37,    22,    33,   -37,   -37,
      34,    36,    37,    68,    35,    38,    39,    64,    50,    13,
      31,    36,    37,   164,    40,    38,    39,    84,    96,   172,
      34,   141,    89,   167,    40,   148,    97,    98,    99,   100,
      40,    36,    37,   164,    55,    38,    39,   -28,   -82,    14,
     -54,   -28,   -51,   -52,    40,   101,   149,   -28,    64,    64,
      48,     7,    16,   -54,    -8,    49,     8,   -12,   -12,   -82,
      95,    56,    82,    83,   -12,    14,    86,    27,   -11,    15,
     -15,   -11,   -11,    28,   -15,    94,    60,   105,    16,   -18,
     -15,   106,   107,    35,   113,   114,   115,   108,   110,   -18,
     116,   118,   119,   120,  -107,   121,  -107,  -107,  -107,   137,
    -107,   111,   139,   109,   123,   128,   130,   132,   156,   129,
     133,   134,   136,   160,   168,    69,   166,   169,   170,    30,
      51,    61,    93,   154,   142,   153,   171,   165,     0,     0,
       0,     0,    88
};

static const yytype_int16 yycheck[] =
{
      36,    37,    38,    39,    55,    48,    41,    25,    38,    37,
      46,    47,    34,   136,    50,    21,    34,     1,     1,     1,
      50,     3,    14,    29,     1,     1,   149,     1,     4,    21,
       1,    29,     9,    10,    11,    12,    71,     1,    14,     1,
      23,     1,    18,     1,    28,    28,   169,    31,    32,    32,
      86,    28,    29,    29,    28,   106,    86,    28,    32,    23,
     111,    32,    25,    26,    28,   104,    28,    11,    28,     1,
      28,   110,     4,    95,    18,     7,     8,    95,    28,     4,
       1,   117,    14,     4,     5,     0,   122,     1,   123,   117,
     133,     5,   122,    14,    15,    16,    28,     1,    19,    20,
       4,    15,    16,     1,     8,    19,    20,    28,    35,    29,
      28,    15,    16,   149,    28,    19,    20,     1,     1,   170,
       4,     1,     1,   158,    28,     1,     9,    10,    11,    12,
      28,    15,    16,   169,     1,    19,    20,     4,     1,     1,
       1,     8,     4,     4,    28,    28,    22,    14,    28,    28,
      22,     1,    14,    14,     4,    29,     6,     7,     8,    22,
      29,    28,    25,    26,    14,     1,    21,     1,     4,     5,
       4,     7,     8,     7,     8,     5,     1,    29,    14,     4,
      14,    35,     5,     8,    33,    34,    35,    29,    29,    14,
      39,    36,    37,    38,    21,    40,    36,    37,    38,   102,
      40,    30,   105,    24,    17,    27,    30,    23,     5,    29,
      29,    29,    26,    23,    23,    32,    27,    24,    13,    13,
      24,    29,    50,   133,   109,   132,   169,   153,    -1,    -1,
      -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    43,    29,    28,     0,     1,     6,    44,
      45,    46,    47,    29,     1,     5,    14,    63,    64,    65,
      66,     1,    28,    50,    51,     4,    63,     1,     7,    48,
      44,    28,    63,     1,     4,     8,    15,    16,    19,    20,
      28,    49,    69,    70,    72,    85,    86,    87,    22,    29,
      35,    50,     1,    71,    72,     1,    28,    54,    55,    56,
       1,    49,    71,     1,    28,    58,    59,    60,     1,    32,
      53,    73,    80,    81,    82,    85,    80,     1,    31,    52,
      81,    85,    25,    26,     1,    70,    21,    85,    82,     1,
      23,    57,    59,    52,     5,    29,     1,     9,    10,    11,
      12,    28,    29,    61,    62,    29,    35,     5,    29,    24,
      29,    30,    70,    33,    34,    35,    39,    83,    36,    37,
      38,    40,    84,    17,    28,    75,    76,    81,    27,    29,
      30,    67,    23,    29,    29,    71,    26,    54,    58,    54,
      61,     1,    60,    58,    61,    80,    81,    70,     1,    22,
      77,    61,    68,    67,    57,    53,     5,     1,    18,    74,
      23,    53,    78,    79,    85,    68,    27,    70,    23,    24,
      13,    78,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    45,    46,
      47,    47,    47,    48,    48,    48,    49,    49,    49,    50,
      50,    51,    51,    52,    52,    52,    53,    54,    54,    54,
      55,    55,    56,    57,    57,    57,    58,    58,    58,    59,
      60,    60,    60,    61,    61,    61,    61,    61,    61,    62,
      63,    63,    63,    64,    64,    65,    65,    65,    66,    67,
      68,    69,    69,    69,    70,    70,    70,    71,    71,    71,
      72,    72,    72,    72,    72,    72,    73,    74,    74,    74,
      75,    75,    76,    77,    77,    78,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    83,    83,
      84,    84,    84,    84,    85,    85,    85,    85,    86,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     4,     2,     2,     2,     0,     3,
       2,     1,     0,     2,     1,     0,     2,     1,     0,     2,
       1,     4,     2,     1,     1,     1,     1,     3,     2,     3,
       3,     2,     1,     3,     1,     2,     3,     2,     2,     3,
       3,     1,     1,     1,     1,     6,     3,     1,     1,     1,
       2,     0,     1,     2,     1,     6,     5,     1,     2,     1,
       1,     2,     1,     1,     3,     1,     1,     3,     0,     1,
       3,     3,     5,     2,     2,     1,     1,     2,     0,     1,
       1,     2,     1,     3,     2,     3,     1,     0,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
  case 9:
#line 78 "gramatica.y"
    {
        atribEscopo("#global");
}
#line 1412 "gramatica.tab.c"
    break;

  case 21:
#line 103 "gramatica.y"
    {
        if(!procuraNome((yyvsp[-3].str), escAtual()->nome)){
                adicionaSimb(C_CONST, (yyvsp[-3].str), tipo, escAtual()->nome, depth, -1);
                strcpy(tipo, "");
        }
        else
                erroSemantico(1);
        //tipo = 0;
}
#line 1426 "gramatica.tab.c"
    break;

  case 23:
#line 116 "gramatica.y"
    {
        strcpy(tipo, "const_string");
}
#line 1434 "gramatica.tab.c"
    break;

  case 26:
#line 124 "gramatica.y"
    {
        int aux = (yyvsp[0].fl);
        if(aux-(yyvsp[0].fl)==0){
                if(!strcmp(tipo,""))
                        strcpy(tipo,"integer");
                else if(strcmp(tipo, "integer") && strcmp(tipo, "real"))
                                erroSemantico(3);
        }else{
                if(!strcmp(tipo,"")||!strcmp(tipo,"real")||!strcmp(tipo,"integer"))
                                strcpy(tipo, "real");
                else
                        erroSemantico(3);
        }
}
#line 1453 "gramatica.tab.c"
    break;

  case 32:
#line 150 "gramatica.y"
    {
        if(!procuraNome((yyvsp[0].str), escAtual()->nome))
                adicionaSimb(C_TYPE, (yyvsp[0].str), "", escAtual()->nome, depth, -1);
        else
                erroSemantico(1);
}
#line 1464 "gramatica.tab.c"
    break;

  case 40:
#line 172 "gramatica.y"
    {
        if(!procuraNome((yyvsp[-2].str), escAtual()->nome))
                adicionaSimb(rec?C_FIELD:C_VAR, (yyvsp[-2].str), "",escAtual()->nome,depth,!func?-1:++quantP);
        else
                erroSemantico(1);
}
#line 1475 "gramatica.tab.c"
    break;

  case 41:
#line 179 "gramatica.y"
    {
        if(!procuraNome((yyvsp[0].str), escAtual()->nome))
                adicionaSimb(rec?C_FIELD:C_VAR, (yyvsp[0].str), "",escAtual()->nome,depth,!func?-1:++quantP);
        else
                erroSemantico(1);
}
#line 1486 "gramatica.tab.c"
    break;

  case 43:
#line 189 "gramatica.y"
    {
        atribTipo((yyvsp[0].tipo));
}
#line 1494 "gramatica.tab.c"
    break;

  case 44:
#line 193 "gramatica.y"
    {
        atribTipo((yyvsp[0].tipo));
}
#line 1502 "gramatica.tab.c"
    break;

  case 45:
#line 197 "gramatica.y"
    {
        tabSim[ind-1].qt = 0;
        atribTipo(yylval.tipo);
}
#line 1511 "gramatica.tab.c"
    break;

  case 46:
#line 202 "gramatica.y"
    {
        rec--;
        depth++;
        atribTipo("record");
        pilha = popEscopo();
}
#line 1522 "gramatica.tab.c"
    break;

  case 47:
#line 209 "gramatica.y"
    {
        Simbolo* temp = procuraNome((yyvsp[0].str), escAtual()->nome);
        if(temp && temp->class==C_TYPE)
                atribTipo((yyvsp[0].str));
        else{
                erroSemantico(2);
                atribTipo("#erro");
        }
}
#line 1536 "gramatica.tab.c"
    break;

  case 49:
#line 222 "gramatica.y"
    {
        rec++;
        pilha = adicionaEscopoFim(tabSim[ind-1].nome);
}
#line 1545 "gramatica.tab.c"
    break;

  case 53:
#line 234 "gramatica.y"
    {
        atribEscopo(escAtual()->nome);
        pilha = popEscopo();
}
#line 1554 "gramatica.tab.c"
    break;

  case 55:
#line 242 "gramatica.y"
    {
        depth--;
        atribQt(quantP);
        quantP = -1;
        func--;
        depth++;
        depth++;
}
#line 1567 "gramatica.tab.c"
    break;

  case 56:
#line 251 "gramatica.y"
    {
        depth--;
        atribQt(0);
        quantP = -1;
        func--;
        depth++;
        depth++;
}
#line 1580 "gramatica.tab.c"
    break;

  case 58:
#line 263 "gramatica.y"
    {
        quantP = 0;
        func++;
        if(!procuraNome((yyvsp[0].str), escAtual()->nome)){
                depth--;
                adicionaSimb(C_FUNC,(yyvsp[0].str),"",escAtual()->nome,depth, -1);
                depth++;
                pilha = adicionaEscopoFim((yyvsp[0].str));
        }else
                erroSemantico(1);
}
#line 1596 "gramatica.tab.c"
    break;

  case 59:
#line 277 "gramatica.y"
    {
        depth--;
}
#line 1604 "gramatica.tab.c"
    break;

  case 60:
#line 284 "gramatica.y"
    {
        depth++;
}
#line 1612 "gramatica.tab.c"
    break;

  case 65:
#line 296 "gramatica.y"
    {
        strcpy(tipo, "");
}
#line 1620 "gramatica.tab.c"
    break;

  case 76:
#line 316 "gramatica.y"
    {
        strcpy(tipo, "");
}
#line 1628 "gramatica.tab.c"
    break;

  case 81:
#line 328 "gramatica.y"
    {
        Simbolo* temp = procuraNome(fAux->nome, escAtual()->nome);
        if(!temp)
                erroSemantico(6);
        if(temp && quantP!=temp->qt)
                erroSemantico(8);
        fAux = popEsc(fAux);
        func--;
        quantP = -1;
}
#line 1643 "gramatica.tab.c"
    break;

  case 82:
#line 341 "gramatica.y"
    {
        Simbolo* temp = procuraNome((yyvsp[0].str), escAtual()->nome);
        if(temp && temp->class==C_FUNC){
                fAux = pushEsc(fAux, (yyvsp[0].str));
                quantP=0;
        }else
                erroSemantico(6);
        func++;
}
#line 1657 "gramatica.tab.c"
    break;

  case 88:
#line 362 "gramatica.y"
    {
        quantP++;
        verificaPar();
        strcpy(tipo,"");
}
#line 1667 "gramatica.tab.c"
    break;

  case 89:
#line 368 "gramatica.y"
    {
        quantP++;
        verificaPar();
        strcpy(tipo,"");
}
#line 1677 "gramatica.tab.c"
    break;

  case 104:
#line 400 "gramatica.y"
    {
        validaTipo((yyvsp[0].str), 1);
        strcpy(recNome, "");
}
#line 1686 "gramatica.tab.c"
    break;

  case 106:
#line 406 "gramatica.y"
    {
        strcpy(tipo,id);
}
#line 1694 "gramatica.tab.c"
    break;

  case 108:
#line 413 "gramatica.y"
    {
        Simbolo* temp;
        if(!strcmp(recNome, "")){
                 temp = procuraNome((yyvsp[-1].str), escAtual()->nome);
                 temp = converteTipo(temp);
                 if(temp && !strcmp(temp->tipo, "record"))
                         strcpy(recNome, (yyvsp[-1].str));
                 else{
                         strcpy(tipo,"#erro");
                         erroSemantico(5);
                 }
        }else{
                 temp = procuraCampo((yyvsp[-1].str));
                 temp = converteTipo(temp);
                 if(temp && !strcmp(temp->tipo, "record"))
                         strcpy(recNome, (yyvsp[-1].str));
                 else{
                         strcpy(tipo,"#erro");
                         erroSemantico(5);
                 }
        }
}
#line 1721 "gramatica.tab.c"
    break;

  case 109:
#line 438 "gramatica.y"
    {
        validaTipo((yyvsp[-1].str), 0);
        strcpy(id,tipo);
        strcpy(tipo, "integer");
}
#line 1731 "gramatica.tab.c"
    break;


#line 1735 "gramatica.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 446 "gramatica.y"



int yyerror(char const *s){
        count++;
        printf("\n>> Linha: %d %s\n", yylineno, s);
}
int count = 0;

int main (void) {
        initTab();

        yyparse();

        printf("\n\nFim da análise");

        return 0;
}


/*
 (eepitch-shell)
 (eepitch-kill)
 (eepitch-shell)
make
make run
 */
