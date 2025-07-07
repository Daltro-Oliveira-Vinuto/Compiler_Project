/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "../src/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int debug_semantic = 0;
void emitRO( char *op, int r, int s, int t, char *c);
void emitRM( char *op, int r, int d, int s, char *c);

static int emitLoc = 0;
uint ac = 0;
uint ac1 = 1;
uint gp = 5;
uint mp = 6;
uint pc = 7;
int variable_offset_global = 0;

extern FILE *yyin;
extern FILE *yyout;

int yylex();
void yyerror(const char *s);
extern int yylineno;

typedef struct Simbolo {
    char* nome;
    char* tipo;     
    char* natureza;
    int usada;
    char** tipos_param; 
    int qtd_param;
    int variable_offset;
    struct Simbolo* prox;
} Simbolo;

Simbolo* tabela = NULL;
Simbolo* simbolo_atual = NULL;
int erros_semanticos = 0;
int warnings_semanticos = 0;

char* tipos_param_tmp[32];
int qtd_param_tmp = 0;

char* tipos_args_tmp[32];
int qtd_args_tmp = 0;

Simbolo* busca(char* nome) {
    Simbolo* atual = tabela;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void insere(char* nome, char* tipo, char* natureza, int offset) {
    if (busca(nome) != NULL) {
        return;
    }
    Simbolo* novo = malloc(sizeof(Simbolo));
    novo->nome = strdup(nome);
    novo->tipo = strdup(tipo);
    novo->natureza = strdup(natureza);
    novo->usada = 0;
    novo->variable_offset = offset;

    novo->prox = tabela;

    tabela = novo;
}

void verifica_warnings() {
    Simbolo* atual = tabela;
    while (atual != NULL) {
        if (atual->usada == 0 && strcmp(atual->nome, "main") != 0) {
            printf("WARNING: identificador %s (%s) declarado mas nao usado\n", atual->nome, atual->tipo);
            warnings_semanticos++;
        }
        atual = atual->prox;
    }
}

void imprime_tabela() {
    printf("\n______________________________________________________________\n");
    printf("\n\t\t\tTABELA DE SIMBOLOS:\t\t\n");
    printf("______________________________________________________________\n\n");
    printf("%-20s %-10s %-15s %-5s %-20s\n", "NOME", "TIPO", "NATUREZA", "USADA", "MEMORY OFFSET");

    Simbolo* atual = tabela;
    while (atual != NULL) {
        printf("%-20s %-10s %-15s %-5s %-20d \n",
               atual->nome,
               atual->tipo,
               atual->natureza,
               atual->usada ? "sim" : "nao",
               atual->variable_offset);
        atual = atual->prox;
    }
    printf("______________________________________________________________\n \n");
}


#line 176 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PRINT = 3,                      /* PRINT  */
  YYSYMBOL_READ = 4,                       /* READ  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_NUM = 6,                        /* NUM  */
  YYSYMBOL_FLOATING_NUM = 7,               /* FLOATING_NUM  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_INT = 10,                       /* INT  */
  YYSYMBOL_FLOAT = 11,                     /* FLOAT  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_ASSIGN = 15,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_MINUS = 17,                     /* MINUS  */
  YYSYMBOL_MULTIPLICATION = 18,            /* MULTIPLICATION  */
  YYSYMBOL_DIVISION = 19,                  /* DIVISION  */
  YYSYMBOL_SYMBOL_LT = 20,                 /* SYMBOL_LT  */
  YYSYMBOL_SYMBOL_LE = 21,                 /* SYMBOL_LE  */
  YYSYMBOL_SYMBOL_GT = 22,                 /* SYMBOL_GT  */
  YYSYMBOL_SYMBOL_GE = 23,                 /* SYMBOL_GE  */
  YYSYMBOL_SYMBOL_EQ = 24,                 /* SYMBOL_EQ  */
  YYSYMBOL_SYMBOL_NE = 25,                 /* SYMBOL_NE  */
  YYSYMBOL_LOWER_THAN_ELSE = 26,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_L_PARENTHESES = 27,             /* L_PARENTHESES  */
  YYSYMBOL_R_PARENTHESES = 28,             /* R_PARENTHESES  */
  YYSYMBOL_L_SQUARE_BRACKETS = 29,         /* L_SQUARE_BRACKETS  */
  YYSYMBOL_R_SQUARE_BRACKETS = 30,         /* R_SQUARE_BRACKETS  */
  YYSYMBOL_L_BRACES = 31,                  /* L_BRACES  */
  YYSYMBOL_R_BRACES = 32,                  /* R_BRACES  */
  YYSYMBOL_SEMICOLON = 33,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_declaration_list = 37,          /* declaration_list  */
  YYSYMBOL_declaration = 38,               /* declaration  */
  YYSYMBOL_var_declaration = 39,           /* var_declaration  */
  YYSYMBOL_type_specifier = 40,            /* type_specifier  */
  YYSYMBOL_fun_declaration = 41,           /* fun_declaration  */
  YYSYMBOL_params = 42,                    /* params  */
  YYSYMBOL_param_list = 43,                /* param_list  */
  YYSYMBOL_param = 44,                     /* param  */
  YYSYMBOL_compound_stmt = 45,             /* compound_stmt  */
  YYSYMBOL_local_declarations = 46,        /* local_declarations  */
  YYSYMBOL_statement_list = 47,            /* statement_list  */
  YYSYMBOL_statement = 48,                 /* statement  */
  YYSYMBOL_expression_stmt = 49,           /* expression_stmt  */
  YYSYMBOL_print_stmt = 50,                /* print_stmt  */
  YYSYMBOL_selection_stmt = 51,            /* selection_stmt  */
  YYSYMBOL_iteration_stmt = 52,            /* iteration_stmt  */
  YYSYMBOL_return_stmt = 53,               /* return_stmt  */
  YYSYMBOL_expression = 54,                /* expression  */
  YYSYMBOL_var = 55,                       /* var  */
  YYSYMBOL_simple_expression = 56,         /* simple_expression  */
  YYSYMBOL_relational_operation = 57,      /* relational_operation  */
  YYSYMBOL_additive_expression = 58,       /* additive_expression  */
  YYSYMBOL_addop = 59,                     /* addop  */
  YYSYMBOL_term = 60,                      /* term  */
  YYSYMBOL_mulop = 61,                     /* mulop  */
  YYSYMBOL_factor = 62,                    /* factor  */
  YYSYMBOL_call = 63,                      /* call  */
  YYSYMBOL_args = 64,                      /* args  */
  YYSYMBOL_arg_list = 65                   /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   121

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   140,   140,   146,   147,   151,   152,   156,   161,   169,
     170,   171,   175,   190,   191,   192,   196,   197,   201,   207,
     216,   220,   221,   225,   226,   230,   231,   232,   233,   234,
     235,   239,   240,   244,   251,   252,   256,   260,   261,   265,
     285,   290,   292,   308,   322,   323,   327,   327,   327,   327,
     327,   327,   331,   337,   341,   341,   345,   351,   355,   355,
     359,   360,   365,   366,   369,   370,   371,   375,   401,   402,
     406,   409
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PRINT", "READ", "ID",
  "NUM", "FLOATING_NUM", "IF", "ELSE", "INT", "FLOAT", "RETURN", "VOID",
  "WHILE", "ASSIGN", "PLUS", "MINUS", "MULTIPLICATION", "DIVISION",
  "SYMBOL_LT", "SYMBOL_LE", "SYMBOL_GT", "SYMBOL_GE", "SYMBOL_EQ",
  "SYMBOL_NE", "LOWER_THAN_ELSE", "L_PARENTHESES", "R_PARENTHESES",
  "L_SQUARE_BRACKETS", "R_SQUARE_BRACKETS", "L_BRACES", "R_BRACES",
  "SEMICOLON", "COMMA", "$accept", "program", "declaration_list",
  "declaration", "var_declaration", "type_specifier", "fun_declaration",
  "params", "param_list", "param", "compound_stmt", "local_declarations",
  "statement_list", "statement", "expression_stmt", "print_stmt",
  "selection_stmt", "iteration_stmt", "return_stmt", "expression", "var",
  "simple_expression", "relational_operation", "additive_expression",
  "addop", "term", "mulop", "factor", "call", "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-15)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,   -44,   -44,   -44,     3,     7,   -44,   -44,    14,   -44,
     -44,   -44,     5,    82,    37,   -44,    31,    47,    32,    35,
     -44,    43,    50,    53,     7,    57,    66,   -44,   -44,   -44,
     -44,   -44,     7,   -44,    89,    23,    38,    70,    24,   -44,
     -44,    72,    71,    73,    41,    41,    41,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,    68,    87,   -44,    -9,
      64,   -44,   -44,    41,    41,    41,    41,   -44,    74,    41,
     -44,   -44,   -44,    75,   -44,    41,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,    41,    41,   -44,   -44,    41,    77,
     -44,    78,    76,    79,    80,   -44,    83,   -44,   -44,    -7,
      64,   -44,    81,   -44,    41,   -44,    58,    58,   -44,   -44,
     103,   -44,    58,   -44
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    11,    10,     0,     2,     4,     5,     0,     6,
       1,     3,     0,    15,     0,     7,    10,     0,     0,    13,
      17,     0,    18,     0,     0,     0,     0,    22,    12,    16,
       8,    19,    24,    21,     0,    41,     0,     0,    42,    63,
      64,     0,    41,     0,    41,    41,    41,    20,    32,    26,
      23,    25,    30,    27,    28,    29,     0,    61,    40,    45,
      53,    57,    62,    41,    41,    41,    41,    37,     0,    41,
      61,    65,    66,     0,    31,    41,    54,    55,    47,    46,
      48,    49,    50,    51,    41,    41,    58,    59,    41,     0,
      71,     0,    68,     0,     0,    38,     0,    60,    39,    44,
      52,    56,     0,    67,    41,    43,    41,    41,    33,    70,
      34,    36,    41,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,   -44,   108,    84,    12,   -44,   -44,   -44,    91,
      94,   -44,   -44,   -26,   -44,   -44,   -44,   -44,   -44,   -42,
     -43,   -44,   -44,    34,   -44,    36,   -44,   -39,   -44,   -44,
     -44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,     9,    18,    19,    20,
      49,    32,    35,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    84,    59,    85,    60,    88,    61,    62,    91,
      92
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      68,    70,    70,    10,    73,    71,    72,    76,    77,    76,
      77,    78,    79,    80,    81,    82,    83,     1,     2,    12,
       3,    89,    90,    93,    94,    17,    37,    96,    38,    39,
      40,    41,    13,    98,    14,    42,    17,    43,    15,    44,
      45,    70,    70,    21,    34,    70,    38,    39,    40,   101,
      46,    64,    22,    65,    27,    47,    48,    44,    45,   -14,
      23,    37,   109,    38,    39,    40,    41,    14,    46,    24,
      42,    15,    43,    25,    44,    45,    38,    39,    40,    26,
     110,   111,    86,    87,    27,    46,   113,    44,    45,    27,
      30,    48,     1,     2,    36,    16,    31,    63,    46,    66,
      69,    74,    75,    97,    67,   102,   103,    95,   106,   105,
     104,   107,   112,    11,   108,    29,    33,    28,    99,     0,
       0,   100
};

static const yytype_int8 yycheck[] =
{
      42,    44,    45,     0,    46,    44,    45,    16,    17,    16,
      17,    20,    21,    22,    23,    24,    25,    10,    11,     5,
      13,    63,    64,    65,    66,    13,     3,    69,     5,     6,
       7,     8,    27,    75,    29,    12,    24,    14,    33,    16,
      17,    84,    85,     6,    32,    88,     5,     6,     7,    88,
      27,    27,     5,    29,    31,    32,    33,    16,    17,    28,
      28,     3,   104,     5,     6,     7,     8,    29,    27,    34,
      12,    33,    14,    30,    16,    17,     5,     6,     7,    29,
     106,   107,    18,    19,    31,    27,   112,    16,    17,    31,
      33,    33,    10,    11,     5,    13,    30,    27,    27,    27,
      27,    33,    15,    28,    33,    28,    28,    33,    28,    30,
      34,    28,     9,     5,    33,    24,    32,    23,    84,    -1,
      -1,    85
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    11,    13,    36,    37,    38,    39,    40,    41,
       0,    38,     5,    27,    29,    33,    13,    40,    42,    43,
      44,     6,     5,    28,    34,    30,    29,    31,    45,    44,
      33,    30,    46,    39,    40,    47,     5,     3,     5,     6,
       7,     8,    12,    14,    16,    17,    27,    32,    33,    45,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    58,
      60,    62,    63,    27,    27,    29,    27,    33,    54,    27,
      55,    62,    62,    54,    33,    15,    16,    17,    20,    21,
      22,    23,    24,    25,    57,    59,    18,    19,    61,    54,
      54,    64,    65,    54,    54,    33,    54,    28,    54,    58,
      60,    62,    28,    28,    34,    30,    28,    28,    33,    54,
      48,    48,     9,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    39,    39,    40,
      40,    40,    41,    42,    42,    42,    43,    43,    44,    44,
      45,    46,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    49,    49,    50,    51,    51,    52,    53,    53,    54,
      54,    55,    55,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    58,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    63,    64,    64,
      65,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     1,     6,     1,     1,     0,     3,     1,     2,     4,
       4,     2,     0,     2,     0,     1,     1,     1,     1,     1,
       1,     2,     1,     5,     5,     7,     5,     2,     3,     3,
       1,     0,     1,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     2,     2,     4,     1,     0,
       3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 2: /* program: declaration_list  */
#line 140 "../src/parser.y"
                     { emitRO("HALT", 0, 0, 0, "End of execution.");
}
#line 1313 "parser.tab.c"
    break;

  case 7: /* var_declaration: type_specifier ID SEMICOLON  */
#line 156 "../src/parser.y"
                                {
        insere((yyvsp[-1].cadeia), (yyvsp[-2].cadeia), "variavel", variable_offset_global);
        variable_offset_global += 1;
        // printf("Declaracao de identificador (variavel): %s do tipo %s na linha %d\n", $2, $1, yylineno);
    }
#line 1323 "parser.tab.c"
    break;

  case 8: /* var_declaration: type_specifier ID L_SQUARE_BRACKETS NUM R_SQUARE_BRACKETS SEMICOLON  */
#line 161 "../src/parser.y"
                                                                          {
        insere((yyvsp[-4].cadeia), (yyvsp[-5].cadeia), "vetor", variable_offset_global);
        variable_offset_global += 1;
        // printf("Declaracao de identificador (vetor): %s do tipo %s na linha %d\n", $2, $1, yylineno);
    }
#line 1333 "parser.tab.c"
    break;

  case 9: /* type_specifier: INT  */
#line 169 "../src/parser.y"
         { (yyval.cadeia) = "int"; }
#line 1339 "parser.tab.c"
    break;

  case 10: /* type_specifier: VOID  */
#line 170 "../src/parser.y"
           { (yyval.cadeia) = "void"; }
#line 1345 "parser.tab.c"
    break;

  case 11: /* type_specifier: FLOAT  */
#line 171 "../src/parser.y"
            { (yyval.cadeia) = "float"; }
#line 1351 "parser.tab.c"
    break;

  case 12: /* fun_declaration: type_specifier ID L_PARENTHESES params R_PARENTHESES compound_stmt  */
#line 175 "../src/parser.y"
                                                                       {
        insere((yyvsp[-4].cadeia), (yyvsp[-5].cadeia), "funcao", variable_offset_global);
        variable_offset_global +=1;
        Simbolo* s = busca((yyvsp[-4].cadeia));
        if (s) {
            s->qtd_param = qtd_param_tmp;
            s->tipos_param = malloc(sizeof(char*) * qtd_param_tmp);
            for (int i = 0; i < qtd_param_tmp; i++)
                s->tipos_param[i] = tipos_param_tmp[i];
        }        qtd_param_tmp = 0; // Limpa para próxima função
        //printf("Declaracao de identificador (funcao): %s na linha %d\n", $2, yylineno);
    }
#line 1368 "parser.tab.c"
    break;

  case 15: /* params: %empty  */
#line 192 "../src/parser.y"
                  {}
#line 1374 "parser.tab.c"
    break;

  case 18: /* param: type_specifier ID  */
#line 201 "../src/parser.y"
                      {
        insere((yyvsp[0].cadeia), (yyvsp[-1].cadeia), "parametro", variable_offset_global);
        variable_offset_global += 1;
        tipos_param_tmp[qtd_param_tmp++] = (yyvsp[-1].cadeia); 
        printf("Declaracao de identificador (parametro escalar): %s na linha %d\n", (yyvsp[0].cadeia), yylineno);
    }
#line 1385 "parser.tab.c"
    break;

  case 19: /* param: type_specifier ID L_SQUARE_BRACKETS R_SQUARE_BRACKETS  */
#line 207 "../src/parser.y"
                                                            {
        insere((yyvsp[-2].cadeia), (yyvsp[-3].cadeia), "parametro_vetor", variable_offset_global);
        variable_offset_global += 1;
        tipos_param_tmp[qtd_param_tmp++] = (yyvsp[-3].cadeia); 
        printf("Declaracao de identificador (parametro vetor): %s na linha %d\n", (yyvsp[-2].cadeia), yylineno);
    }
#line 1396 "parser.tab.c"
    break;

  case 22: /* local_declarations: %empty  */
#line 221 "../src/parser.y"
                  {}
#line 1402 "parser.tab.c"
    break;

  case 24: /* statement_list: %empty  */
#line 226 "../src/parser.y"
                  {}
#line 1408 "parser.tab.c"
    break;

  case 33: /* print_stmt: PRINT L_PARENTHESES expression R_PARENTHESES SEMICOLON  */
#line 244 "../src/parser.y"
                                                           {
        //printf("========> expression is %s\n", $3);
        emitRO("OUT", ac, 0, 0, "print expression result");
}
#line 1417 "parser.tab.c"
    break;

  case 39: /* expression: var ASSIGN expression  */
#line 265 "../src/parser.y"
                          {
        char* tipo_var = (yyvsp[-2].cadeia);
        char* tipo_expr = (yyvsp[0].cadeia);

        // s->variable_offset
        emitRM("ST", ac, simbolo_atual->variable_offset , gp, "; store the value of ac in offset(gp)");
        //printf("Atribuicao a identificador na linha %d\n", yylineno);

        if (tipo_var && tipo_expr) {
            if (strcmp(tipo_var, "int") == 0 && strcmp(tipo_expr, "float") == 0) {
                //printf("ERRO SEMANTICO: atribuicao de float para int na linha %d\n", yylineno);
                erros_semanticos++;
            }
            if (strcmp(tipo_var, "float") == 0 && strcmp(tipo_expr, "int") == 0) {
                //printf("WARNING: atribuicao de int para float na linha %d (conversao implicita)\n", yylineno);
                warnings_semanticos++;
            }
        }
        (yyval.cadeia) = tipo_var;
    }
#line 1442 "parser.tab.c"
    break;

  case 40: /* expression: simple_expression  */
#line 285 "../src/parser.y"
                        { (yyval.cadeia) = (yyvsp[0].cadeia); 
                         //printf("=========> simple expression is %s\n", $1);
                     }
#line 1450 "parser.tab.c"
    break;

  case 42: /* var: ID  */
#line 292 "../src/parser.y"
       {
        // printf("==========> variable ID : %s\n", $1);

        Simbolo* s = busca((yyvsp[0].cadeia));
        simbolo_atual = s;
        if (s == NULL) {
            printf("ERRO: identificador %s usado na linha %d mas nao declarado\n", (yyvsp[0].cadeia), yylineno);
            erros_semanticos++;
            (yyval.cadeia) = NULL;
        } else {
            s->usada = 1;

            //printf("Uso de identificador (variavel): %s na linha %d\n", $1, yylineno);
            (yyval.cadeia) = strdup(s->tipo); // Retorna o tipo para ser usado nas verificações
        }
    }
#line 1471 "parser.tab.c"
    break;

  case 43: /* var: ID L_SQUARE_BRACKETS expression R_SQUARE_BRACKETS  */
#line 308 "../src/parser.y"
                                                        {
        Simbolo* s = busca((yyvsp[-3].cadeia));
        if (s == NULL) {
            printf("ERRO: identificador %s usado como vetor na linha %d mas nao declarado\n", (yyvsp[-3].cadeia), yylineno);
            erros_semanticos++;
            (yyval.cadeia) = NULL;
        } else {
            s->usada = 1;
            printf("Uso de identificador (vetor): %s na linha %d\n", (yyvsp[-3].cadeia), yylineno);
            (yyval.cadeia) = strdup(s->tipo);
        }
    }
#line 1488 "parser.tab.c"
    break;

  case 44: /* simple_expression: additive_expression relational_operation additive_expression  */
#line 322 "../src/parser.y"
                                                                 { (yyval.cadeia) = "int"; }
#line 1494 "parser.tab.c"
    break;

  case 45: /* simple_expression: additive_expression  */
#line 323 "../src/parser.y"
                          { (yyval.cadeia) = (yyvsp[0].cadeia); }
#line 1500 "parser.tab.c"
    break;

  case 52: /* additive_expression: additive_expression addop term  */
#line 331 "../src/parser.y"
                                   {
        if ((yyvsp[-2].cadeia) && (yyvsp[0].cadeia) && (strcmp((yyvsp[-2].cadeia), "float") == 0 || strcmp((yyvsp[0].cadeia), "float") == 0))
            (yyval.cadeia) = "float";
        else
            (yyval.cadeia) = "int";
    }
#line 1511 "parser.tab.c"
    break;

  case 53: /* additive_expression: term  */
#line 337 "../src/parser.y"
           { (yyval.cadeia) = (yyvsp[0].cadeia); }
#line 1517 "parser.tab.c"
    break;

  case 56: /* term: term mulop factor  */
#line 345 "../src/parser.y"
                      {
        if ((yyvsp[-2].cadeia) && (yyvsp[0].cadeia) && (strcmp((yyvsp[-2].cadeia), "float") == 0 || strcmp((yyvsp[0].cadeia), "float") == 0))
            (yyval.cadeia) = "float";
        else
            (yyval.cadeia) = "int";
    }
#line 1528 "parser.tab.c"
    break;

  case 57: /* term: factor  */
#line 351 "../src/parser.y"
             { (yyval.cadeia) = (yyvsp[0].cadeia); }
#line 1534 "parser.tab.c"
    break;

  case 60: /* factor: L_PARENTHESES expression R_PARENTHESES  */
#line 359 "../src/parser.y"
                                           { (yyval.cadeia) = (yyvsp[-1].cadeia); }
#line 1540 "parser.tab.c"
    break;

  case 61: /* factor: var  */
#line 360 "../src/parser.y"
          { 
        (yyval.cadeia) = (yyvsp[0].cadeia); 
        // printf("======> var is %s\n", $1);
        emitRM("LD", ac, simbolo_atual->variable_offset , gp, "load from offset(gp)");
    }
#line 1550 "parser.tab.c"
    break;

  case 62: /* factor: call  */
#line 365 "../src/parser.y"
           { (yyval.cadeia) = (yyvsp[0].cadeia); }
#line 1556 "parser.tab.c"
    break;

  case 63: /* factor: NUM  */
#line 366 "../src/parser.y"
          { (yyval.cadeia) = "int";   
            emitRM("LDC", ac, (yyvsp[0].num), 0, "load constant into ac");
    }
#line 1564 "parser.tab.c"
    break;

  case 64: /* factor: FLOATING_NUM  */
#line 369 "../src/parser.y"
                   { (yyval.cadeia) = "float"; }
#line 1570 "parser.tab.c"
    break;

  case 65: /* factor: PLUS factor  */
#line 370 "../src/parser.y"
                  { (yyval.cadeia) = (yyvsp[0].cadeia); }
#line 1576 "parser.tab.c"
    break;

  case 66: /* factor: MINUS factor  */
#line 371 "../src/parser.y"
                   { (yyval.cadeia) = (yyvsp[0].cadeia); }
#line 1582 "parser.tab.c"
    break;

  case 67: /* call: ID L_PARENTHESES args R_PARENTHESES  */
#line 375 "../src/parser.y"
                                        {
        Simbolo* s = busca((yyvsp[-3].cadeia));
        if (s == NULL) {
            printf("ERRO: chamada da funcao %s na linha %d mas nao declarada\n", (yyvsp[-3].cadeia), yylineno);
            erros_semanticos++;
            (yyval.cadeia) = NULL;
        } else {
            s->usada = 1;
            if (s->qtd_param != qtd_args_tmp) {
                printf("ERRO SEMANTICO: funcao %s chamada com %d argumento(s), mas espera %d na linha %d\n", (yyvsp[-3].cadeia), qtd_args_tmp, s->qtd_param, yylineno);
                erros_semanticos++;
            } else {
                for (int i = 0; i < s->qtd_param; i++) {
                    if (strcmp(s->tipos_param[i], tipos_args_tmp[i]) != 0) {
                        printf("ERRO SEMANTICO: tipo do argumento %d da funcao %s incorreto (esperado: %s, encontrado: %s) na linha %d\n",
                            i+1, (yyvsp[-3].cadeia), s->tipos_param[i], tipos_args_tmp[i], yylineno);
                        erros_semanticos++;
                    }
                }
            }
            (yyval.cadeia) = s->tipo;
        }
    }
#line 1610 "parser.tab.c"
    break;

  case 69: /* args: %empty  */
#line 402 "../src/parser.y"
                  {}
#line 1616 "parser.tab.c"
    break;

  case 70: /* arg_list: arg_list COMMA expression  */
#line 406 "../src/parser.y"
                              {
        tipos_args_tmp[qtd_args_tmp++] = (yyvsp[0].cadeia);
    }
#line 1624 "parser.tab.c"
    break;

  case 71: /* arg_list: expression  */
#line 409 "../src/parser.y"
                 {
        qtd_args_tmp = 0;
        tipos_args_tmp[qtd_args_tmp++] = (yyvsp[0].cadeia);
    }
#line 1633 "parser.tab.c"
    break;


#line 1637 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 415 "../src/parser.y"



void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", yylineno, s);
}

void emitRO( char *op, int r, int s, int t, char *c) {
    fprintf(yyout, "%3d:  %5s  %d,%d,%d ", emitLoc++, op, r, s, t);
    //fprintf(yyout, "\t%s\n", c); // Add comment
    fprintf(yyout,"\n") ;
} /* emitRO */

void emitRM( char * op, int r, int d, int s, char *c) {
    fprintf(yyout, "%3d:  %5s  %d,%d(%d) ", emitLoc++, op, r, d, s);
    //fprintf(yyout, "\t%s\n", c); // Add comment
    fprintf(yyout,"\n") ;
} /* emitRM */



extern int yydebug;

int main(int argc, char *argv[], char *envp[]) {
    ++argv; --argc;        
    if(argc > 0)
        yyin = fopen(argv[0],"rt");
    else
        yyin = stdin;    
    if(argc > 1)
        yyout = fopen(argv[1],"wt");
    else
        yyout = stdout;


//emitComment("Standard prelude:");
    emitRM("LD",mp,0,ac,"load maxaddress from location 0");
    emitRM("ST",ac,0,ac,"clear location 0");
//emitComment("End of standard prelude.");

    yydebug = 0;
    if (yyparse() == 0) {
        //printf("Sintaticamente correto\n");
        if (debug_semantic) {imprime_tabela(); }
        verifica_warnings();

        if (busca("main") == NULL) {
            printf("ERRO SEMANTICO: funcao 'main' nao declarada\n");
            erros_semanticos++;
        }

        if (erros_semanticos == 0) {
            //printf("Programa semanticamente correto");
            if (warnings_semanticos > 0) {
                printf(" com %d warning(s)\n", warnings_semanticos);
            } else {
                //printf(".\n");
            }
        } else {
            printf("Programa contem %d erro(s) semantico(s).\n", erros_semanticos);
        }
    }

    //emitRO("HALT",0,0,0,"");

    fclose(yyin);
    fclose(yyout);

    return 0;
}
