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
#line 1 "parser.y"

	#include "semantics.c"
	#include "symbol.c"
	#include "code_generation.c"
	#include "ast.h"
	#include "ast.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern FILE *yyin;
	extern FILE *yyout;
	extern int lineno;
	extern int yylex();
	void yyerror();
	
	// for declarations
	void add_to_names(tokens *entry);
	tokens **names;
	int nc = 0;
	
	// for the initializations of arrays
	void add_to_vals(Value val);
	Value *vals;
	int vc = 0;
	
	// for else ifs
	void add_elseif(AST_Node *elsif);
	AST_Node **elsifs;
	int elseif_count = 0;
	
	// for functions
	AST_Node_Func_Decl *temp_function;

#line 105 "parser.tab.c"

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
  YYSYMBOL_CHAR = 3,                       /* CHAR  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 6,                     /* DOUBLE  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_CONTINUE = 11,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 12,                     /* BREAK  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_ADDOP = 15,                     /* ADDOP  */
  YYSYMBOL_MULOP = 16,                     /* MULOP  */
  YYSYMBOL_DIVOP = 17,                     /* DIVOP  */
  YYSYMBOL_INCR = 18,                      /* INCR  */
  YYSYMBOL_OROP = 19,                      /* OROP  */
  YYSYMBOL_ANDOP = 20,                     /* ANDOP  */
  YYSYMBOL_NOTOP = 21,                     /* NOTOP  */
  YYSYMBOL_EQUOP = 22,                     /* EQUOP  */
  YYSYMBOL_RELOP = 23,                     /* RELOP  */
  YYSYMBOL_LPAREN = 24,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 25,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 26,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 27,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 28,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 29,                    /* RBRACE  */
  YYSYMBOL_SEMI = 30,                      /* SEMI  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 32,                    /* ASSIGN  */
  YYSYMBOL_REFER = 33,                     /* REFER  */
  YYSYMBOL_ID = 34,                        /* ID  */
  YYSYMBOL_ICONST = 35,                    /* ICONST  */
  YYSYMBOL_FCONST = 36,                    /* FCONST  */
  YYSYMBOL_CCONST = 37,                    /* CCONST  */
  YYSYMBOL_STRING = 38,                    /* STRING  */
  YYSYMBOL_MINUS = 39,                     /* MINUS  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_43_2 = 43,                      /* $@2  */
  YYSYMBOL_declarations = 44,              /* declarations  */
  YYSYMBOL_declaration = 45,               /* declaration  */
  YYSYMBOL_46_3 = 46,                      /* $@3  */
  YYSYMBOL_47_4 = 47,                      /* $@4  */
  YYSYMBOL_type = 48,                      /* type  */
  YYSYMBOL_names = 49,                     /* names  */
  YYSYMBOL_variable = 50,                  /* variable  */
  YYSYMBOL_pointer = 51,                   /* pointer  */
  YYSYMBOL_array = 52,                     /* array  */
  YYSYMBOL_init = 53,                      /* init  */
  YYSYMBOL_var_init = 54,                  /* var_init  */
  YYSYMBOL_array_init = 55,                /* array_init  */
  YYSYMBOL_values = 56,                    /* values  */
  YYSYMBOL_statements = 57,                /* statements  */
  YYSYMBOL_statement = 58,                 /* statement  */
  YYSYMBOL_if_statement = 59,              /* if_statement  */
  YYSYMBOL_else_if = 60,                   /* else_if  */
  YYSYMBOL_optional_else = 61,             /* optional_else  */
  YYSYMBOL_for_statement = 62,             /* for_statement  */
  YYSYMBOL_while_statement = 63,           /* while_statement  */
  YYSYMBOL_tail = 64,                      /* tail  */
  YYSYMBOL_expression = 65,                /* expression  */
  YYSYMBOL_constant = 66,                  /* constant  */
  YYSYMBOL_assigment = 67,                 /* assigment  */
  YYSYMBOL_var_ref = 68,                   /* var_ref  */
  YYSYMBOL_function_call = 69,             /* function_call  */
  YYSYMBOL_call_params = 70,               /* call_params  */
  YYSYMBOL_call_param = 71,                /* call_param  */
  YYSYMBOL_functions_optional = 72,        /* functions_optional  */
  YYSYMBOL_functions = 73,                 /* functions  */
  YYSYMBOL_function = 74,                  /* function  */
  YYSYMBOL_75_5 = 75,                      /* $@5  */
  YYSYMBOL_function_head = 76,             /* function_head  */
  YYSYMBOL_77_6 = 77,                      /* $@6  */
  YYSYMBOL_78_7 = 78,                      /* $@7  */
  YYSYMBOL_return_type = 79,               /* return_type  */
  YYSYMBOL_parameters_optional = 80,       /* parameters_optional  */
  YYSYMBOL_parameters = 81,                /* parameters  */
  YYSYMBOL_parameter = 82,                 /* parameter  */
  YYSYMBOL_83_8 = 83,                      /* $@8  */
  YYSYMBOL_function_tail = 84,             /* function_tail  */
  YYSYMBOL_declarations_optional = 85,     /* declarations_optional  */
  YYSYMBOL_statements_optional = 86,       /* statements_optional  */
  YYSYMBOL_return_optional = 87            /* return_optional  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   274

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   101,   101,   102,   101,   108,   113,   119,   119,   119,
     145,   146,   147,   148,   149,   152,   156,   160,   164,   170,
     171,   176,   186,   189,   197,   205,   206,   209,   218,   231,
     236,   245,   250,   257,   261,   265,   269,   273,   277,   281,
     285,   295,   308,   314,   321,   326,   334,   340,   346,   362,
     368,   375,   379,   383,   387,   397,   407,   411,   415,   419,
     423,   427,   431,   435,   439,   467,   474,   475,   476,   479,
     529,   533,   539,   597,   601,   607,   617,   622,   630,   635,
     641,   646,   652,   652,   662,   663,   662,   687,   691,   698,
     703,   709,   714,   720,   720,   740,   743,   748,   754,   759,
     765,   770
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
  "\"end of file\"", "error", "\"invalid token\"", "CHAR", "INT", "FLOAT",
  "DOUBLE", "IF", "ELSE", "WHILE", "FOR", "CONTINUE", "BREAK", "VOID",
  "RETURN", "ADDOP", "MULOP", "DIVOP", "INCR", "OROP", "ANDOP", "NOTOP",
  "EQUOP", "RELOP", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE",
  "RBRACE", "SEMI", "COMMA", "ASSIGN", "REFER", "ID", "ICONST", "FCONST",
  "CCONST", "STRING", "MINUS", "$accept", "program", "$@1", "$@2",
  "declarations", "declaration", "$@3", "$@4", "type", "names", "variable",
  "pointer", "array", "init", "var_init", "array_init", "values",
  "statements", "statement", "if_statement", "else_if", "optional_else",
  "for_statement", "while_statement", "tail", "expression", "constant",
  "assigment", "var_ref", "function_call", "call_params", "call_param",
  "functions_optional", "functions", "function", "$@5", "function_head",
  "$@6", "$@7", "return_type", "parameters_optional", "parameters",
  "parameter", "$@8", "function_tail", "declarations_optional",
  "statements_optional", "return_optional", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-91)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     246,  -131,  -131,  -131,  -131,  -131,    10,   246,  -131,  -131,
    -131,    33,  -131,    -5,    29,    49,    64,    66,    70,  -131,
      61,    20,   100,  -131,    69,    33,  -131,  -131,  -131,  -131,
      97,    96,    99,    52,   102,  -131,  -131,  -131,  -131,   101,
     101,     4,  -131,  -131,   113,   104,  -131,   114,    56,   138,
    -131,  -131,   118,  -131,  -131,   101,  -131,   -14,   116,    -5,
     128,   -14,   126,   101,   101,   131,  -131,  -131,  -131,   179,
    -131,  -131,  -131,   190,   133,  -131,  -131,  -131,   238,   136,
     134,   137,   170,   140,   238,  -131,   139,  -131,  -131,  -131,
    -131,  -131,  -131,   201,  -131,   101,   101,   101,   101,   101,
     101,   101,   151,   151,   101,  -131,   101,  -131,  -131,   166,
     -14,  -131,    65,  -131,  -131,   247,    91,   124,     9,    33,
     160,  -131,    82,   238,  -131,   182,  -131,  -131,    54,  -131,
      23,    41,   180,  -131,   169,  -131,   172,   246,  -131,   -14,
    -131,   184,  -131,    48,  -131,   193,   246,  -131,   198,   185,
    -131,   101,   206,   197,   246,    33,  -131,   209,   212,   101,
     151,    33,   211,  -131,   151,   223,  -131,   101,   207,   216,
    -131,   151,   161,  -131,   219,   225,  -131,   246,  -131,  -131,
    -131,  -131,    20,  -131,  -131
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    10,    12,    13,    14,     0,     2,     6,     7,
       1,     0,     5,     0,     0,     0,     0,     0,     0,    22,
       0,     0,    19,    70,     0,     3,    32,    33,    34,    35,
       0,     0,     0,    19,     8,    17,    18,    25,    26,     0,
       0,     0,    37,    38,     0,    19,    71,     0,    75,     0,
      21,    20,     0,    31,    36,     0,    39,     0,    21,     0,
       0,     0,     0,     0,     0,    19,    66,    67,    68,     0,
      63,    62,    65,     0,     0,    41,    40,    74,    77,     0,
      73,    66,     0,     0,    69,    27,     0,    15,    16,     9,
      64,    55,    58,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,     0,    24,    23,    82,
       0,    61,    51,    52,    53,    56,    57,    59,    60,     0,
      47,    49,     0,    76,     4,    82,    81,    84,     0,    30,
       0,     0,    47,    43,     0,    80,     0,     0,    28,     0,
      50,     0,    46,     0,    42,     0,    97,    83,    87,     0,
      29,     0,     0,     0,    96,    99,    88,     0,     0,     0,
       0,    98,   101,    85,     0,     0,    48,     0,     0,    93,
      45,     0,     0,    95,     0,    89,    92,     0,    44,   100,
      86,    93,     0,    91,    94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,  -131,   119,    -4,  -131,  -131,  -130,  -131,
     -13,   120,   214,   213,  -131,  -131,  -131,  -105,   -19,  -131,
    -131,   141,  -131,  -131,   -85,   -36,   -52,   230,   -10,    -9,
    -131,  -131,  -131,  -131,   149,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,    85,  -131,  -131,  -131,  -131,  -131
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,    11,    52,     7,     8,    13,    60,     9,    34,
      23,    24,    50,    36,    37,    38,   128,    25,    26,    27,
     132,   133,    28,    29,   142,    69,    70,    30,    71,    72,
      79,    80,   124,   125,   126,   127,   136,   137,   169,   149,
     174,   175,   176,   177,   147,   155,   162,   168
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    31,    32,    12,    73,    85,    53,   148,    46,    90,
      10,    19,    78,    82,   130,    31,    32,   120,   121,    84,
      19,    66,    67,    68,    95,    96,    97,    92,    93,    33,
      14,    31,    15,    16,    17,    18,    19,    21,    45,    19,
      14,    20,    15,    16,    17,    18,    87,   182,   141,    19,
     161,    20,   140,    39,    45,   152,    21,    22,   129,   112,
     113,   114,   115,   116,   117,   118,    21,    22,   122,   119,
     123,    61,    19,    40,    62,   166,   119,    63,    49,   170,
      64,    96,    97,   138,    57,   139,   178,   150,    41,    21,
      65,    66,    67,    68,    77,    44,    42,    95,    96,    97,
      43,    98,    99,    51,   100,   101,    95,    96,    97,    31,
      32,    53,   134,   100,   101,   158,    61,    19,    47,    62,
      31,    32,    63,   165,    48,    64,    49,    54,    55,    56,
      49,   172,    83,    59,    21,    65,    66,    67,    68,    95,
      96,    97,    53,    75,    76,    31,    32,   101,    86,    94,
      12,    31,    32,    61,    19,    48,    62,    49,    89,    63,
      91,   105,    64,   104,   107,   106,   -79,   110,   131,   184,
     109,    21,    65,    81,    67,    68,    95,    96,    97,   119,
      98,    99,   -78,   100,   101,    95,    96,    97,   143,    98,
      99,   179,   100,   101,    95,    96,    97,   108,    98,    99,
     146,   100,   101,   145,   102,    95,    96,    97,   151,    98,
      99,   153,   100,   101,    19,   103,    95,    96,    97,   157,
      98,    99,   160,   100,   101,   167,   111,    95,    96,    97,
     159,    98,    99,   163,   100,   101,   173,   164,    95,    96,
      97,   -90,    98,    99,   180,   100,   101,    58,   171,     1,
       2,     3,     4,    95,    96,    97,   181,    98,    99,     5,
     100,   101,    95,    96,    97,   154,   183,    99,   156,   100,
     101,    74,    88,   144,   135
};

static const yytype_uint8 yycheck[] =
{
      13,    11,    11,     7,    40,    57,    25,   137,    21,    61,
       0,    16,    48,    49,   119,    25,    25,   102,   103,    55,
      16,    35,    36,    37,    15,    16,    17,    63,    64,    34,
       7,    41,     9,    10,    11,    12,    16,    33,    34,    16,
       7,    18,     9,    10,    11,    12,    59,   177,     7,    16,
     155,    18,    29,    24,    34,     7,    33,    34,   110,    95,
      96,    97,    98,    99,   100,   101,    33,    34,   104,    28,
     106,    15,    16,    24,    18,   160,    28,    21,    26,   164,
      24,    16,    17,    29,    32,    31,   171,   139,    24,    33,
      34,    35,    36,    37,    38,    34,    30,    15,    16,    17,
      30,    19,    20,    34,    22,    23,    15,    16,    17,   119,
     119,   130,    30,    22,    23,   151,    15,    16,    18,    18,
     130,   130,    21,   159,    24,    24,    26,    30,    32,    30,
      26,   167,    14,    31,    33,    34,    35,    36,    37,    15,
      16,    17,   161,    30,    30,   155,   155,    23,    32,    18,
     154,   161,   161,    15,    16,    24,    18,    26,    30,    21,
      34,    25,    24,    30,    27,    31,     0,    28,     8,   182,
      30,    33,    34,    35,    36,    37,    15,    16,    17,    28,
      19,    20,     0,    22,    23,    15,    16,    17,     8,    19,
      20,    30,    22,    23,    15,    16,    17,    27,    19,    20,
      28,    22,    23,    34,    25,    15,    16,    17,    24,    19,
      20,    18,    22,    23,    16,    25,    15,    16,    17,    34,
      19,    20,    25,    22,    23,    14,    25,    15,    16,    17,
      24,    19,    20,    24,    22,    23,    29,    25,    15,    16,
      17,    25,    19,    20,    25,    22,    23,    33,    25,     3,
       4,     5,     6,    15,    16,    17,    31,    19,    20,    13,
      22,    23,    15,    16,    17,   146,   181,    20,   148,    22,
      23,    41,    59,   132,   125
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    13,    41,    44,    45,    48,
       0,    42,    45,    46,     7,     9,    10,    11,    12,    16,
      18,    33,    34,    50,    51,    57,    58,    59,    62,    63,
      67,    68,    69,    34,    49,    50,    53,    54,    55,    24,
      24,    24,    30,    30,    34,    34,    50,    18,    24,    26,
      52,    34,    43,    58,    30,    32,    30,    32,    52,    31,
      47,    15,    18,    21,    24,    34,    35,    36,    37,    65,
      66,    68,    69,    65,    67,    30,    30,    38,    65,    70,
      71,    35,    65,    14,    65,    66,    32,    50,    53,    30,
      66,    34,    65,    65,    18,    15,    16,    17,    19,    20,
      22,    23,    25,    25,    30,    25,    31,    27,    27,    30,
      28,    25,    65,    65,    65,    65,    65,    65,    65,    28,
      64,    64,    65,    65,    72,    73,    74,    75,    56,    66,
      57,     8,    60,    61,    30,    74,    76,    77,    29,    31,
      29,     7,    64,     8,    61,    34,    28,    84,    48,    79,
      66,    24,     7,    18,    44,    85,    51,    34,    65,    24,
      25,    57,    86,    24,    25,    65,    64,    14,    87,    78,
      64,    25,    65,    29,    80,    81,    82,    83,    64,    30,
      25,    31,    48,    82,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    42,    43,    41,    44,    44,    46,    47,    45,
      48,    48,    48,    48,    48,    49,    49,    49,    49,    50,
      50,    50,    51,    52,    52,    53,    53,    54,    55,    56,
      56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    63,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    66,    67,
      68,    68,    69,    70,    70,    70,    71,    71,    72,    72,
      73,    73,    75,    74,    77,    78,    76,    79,    79,    80,
      80,    81,    81,    83,    82,    84,    85,    85,    86,    86,
      87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     7,     2,     1,     0,     0,     5,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     2,     1,     3,     3,     1,     1,     3,     6,     3,
       1,     2,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     3,     7,     6,     7,     6,     2,     0,    10,     5,
       3,     3,     3,     3,     2,     2,     3,     3,     2,     3,
       3,     3,     1,     1,     2,     1,     1,     1,     1,     3,
       1,     2,     4,     1,     1,     0,     3,     1,     1,     0,
       2,     1,     0,     3,     0,     0,     7,     1,     2,     1,
       0,     3,     1,     0,     3,     5,     1,     0,     1,     0,
       3,     0
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
  case 2: /* $@1: %empty  */
#line 101 "parser.y"
                     { ast_traversal((yyvsp[0].node)); }
#line 1328 "parser.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 102 "parser.y"
                     { ast_traversal((yyvsp[0].node)); }
#line 1334 "parser.tab.c"
    break;

  case 4: /* program: declarations $@1 statements $@2 RETURN SEMI functions_optional  */
#line 103 "parser.y"
                                       { ast_traversal((yyvsp[0].node)); }
#line 1340 "parser.tab.c"
    break;

  case 5: /* declarations: declarations declaration  */
#line 109 "parser.y"
        {
		AST_Node_Declarations *temp = (AST_Node_Declarations*) (yyvsp[-1].node);
		(yyval.node) = new_declarations_node(temp->declarations, temp->declaration_count, (yyvsp[0].node));
	}
#line 1349 "parser.tab.c"
    break;

  case 6: /* declarations: declaration  */
#line 114 "parser.y"
        {
		(yyval.node) = new_declarations_node(NULL, 0, (yyvsp[0].node));
	}
#line 1357 "parser.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 119 "parser.y"
                  { declare = 1; }
#line 1363 "parser.tab.c"
    break;

  case 8: /* $@4: %empty  */
#line 119 "parser.y"
                                         { declare = 0; }
#line 1369 "parser.tab.c"
    break;

  case 9: /* declaration: type $@3 names $@4 SEMI  */
#line 120 "parser.y"
        {
		int i;
		(yyval.node) = new_ast_decl_node((yyvsp[-4].data_type), names, nc);
		nc = 0;
		
		AST_Node_Decl *temp = (AST_Node_Decl*) (yyval.node);
		
		// declare types of the names
		for(i=0; i < temp->names_count; i++){
			// variable
			if(temp->names[i]->st_type == UNDEF){
				set_type(temp->names[i]->st_name, temp->data_type, UNDEF);
			}
			// pointer
			else if(temp->names[i]->st_type == POINTER_TYPE){
				set_type(temp->names[i]->st_name, POINTER_TYPE, temp->data_type);
			}
			// array
			else if(temp->names[i]->st_type == ARRAY_TYPE){
				set_type(temp->names[i]->st_name, ARRAY_TYPE, temp->data_type);
			}
		}
	}
#line 1397 "parser.tab.c"
    break;

  case 10: /* type: INT  */
#line 145 "parser.y"
                        { (yyval.data_type) = INT_TYPE;   }
#line 1403 "parser.tab.c"
    break;

  case 11: /* type: CHAR  */
#line 146 "parser.y"
                        { (yyval.data_type) = CHAR_TYPE;  }
#line 1409 "parser.tab.c"
    break;

  case 12: /* type: FLOAT  */
#line 147 "parser.y"
                        { (yyval.data_type) = REAL_TYPE;  }
#line 1415 "parser.tab.c"
    break;

  case 13: /* type: DOUBLE  */
#line 148 "parser.y"
                        { (yyval.data_type) = REAL_TYPE;  }
#line 1421 "parser.tab.c"
    break;

  case 14: /* type: VOID  */
#line 149 "parser.y"
                        { (yyval.data_type) = VOID_TYPE;  }
#line 1427 "parser.tab.c"
    break;

  case 15: /* names: names COMMA variable  */
#line 153 "parser.y"
        {
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1435 "parser.tab.c"
    break;

  case 16: /* names: names COMMA init  */
#line 157 "parser.y"
        {
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1443 "parser.tab.c"
    break;

  case 17: /* names: variable  */
#line 161 "parser.y"
        {
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1451 "parser.tab.c"
    break;

  case 18: /* names: init  */
#line 165 "parser.y"
        { 
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1459 "parser.tab.c"
    break;

  case 19: /* variable: ID  */
#line 170 "parser.y"
             { (yyval.symtab_item) = (yyvsp[0].symtab_item); }
#line 1465 "parser.tab.c"
    break;

  case 20: /* variable: pointer ID  */
#line 172 "parser.y"
        {
		(yyvsp[0].symtab_item)->st_type = POINTER_TYPE;
		(yyval.symtab_item) = (yyvsp[0].symtab_item);
	}
#line 1474 "parser.tab.c"
    break;

  case 21: /* variable: ID array  */
#line 177 "parser.y"
        {
		if(declare == 1){
			(yyvsp[-1].symtab_item)->st_type = ARRAY_TYPE;
			(yyvsp[-1].symtab_item)->array_size = (yyvsp[0].array_size);
			(yyval.symtab_item) = (yyvsp[-1].symtab_item);
		}		
	}
#line 1486 "parser.tab.c"
    break;

  case 23: /* array: LBRACK expression RBRACK  */
#line 190 "parser.y"
        {
		// if declaration then error!
		if(declare == 1){
			fprintf(stderr, "Array declaration at %d contains expression!\n", lineno);
			exit(1);
		}
	}
#line 1498 "parser.tab.c"
    break;

  case 24: /* array: LBRACK ICONST RBRACK  */
#line 198 "parser.y"
        {
		// set array_size for declaration purposes
		(yyval.array_size) = (yyvsp[-1].val).ival;
	}
#line 1507 "parser.tab.c"
    break;

  case 25: /* init: var_init  */
#line 205 "parser.y"
                 { (yyval.symtab_item) = (yyvsp[0].symtab_item); }
#line 1513 "parser.tab.c"
    break;

  case 26: /* init: array_init  */
#line 206 "parser.y"
                     { (yyval.symtab_item) = (yyvsp[0].symtab_item); }
#line 1519 "parser.tab.c"
    break;

  case 27: /* var_init: ID ASSIGN constant  */
#line 210 "parser.y"
{ 
	AST_Node_Const *temp = (AST_Node_Const*) (yyvsp[0].node);
	(yyvsp[-2].symtab_item)->val = temp->val;
	(yyvsp[-2].symtab_item)->st_type = temp->const_type;
	(yyval.symtab_item) = (yyvsp[-2].symtab_item);
}
#line 1530 "parser.tab.c"
    break;

  case 28: /* array_init: ID array ASSIGN LBRACE values RBRACE  */
#line 219 "parser.y"
{
	if((yyvsp[-5].symtab_item)->array_size != vc){
	    fprintf(stderr, "Array init at %d doesn't contain the right amount of values!\n", lineno);
		exit(1);
	}
	(yyvsp[-5].symtab_item)->vals = vals;
	(yyvsp[-5].symtab_item)->array_size = (yyvsp[-4].array_size);
	(yyval.symtab_item) = (yyvsp[-5].symtab_item);
	vc = 0;
}
#line 1545 "parser.tab.c"
    break;

  case 29: /* values: values COMMA constant  */
#line 232 "parser.y"
        {
		AST_Node_Const *temp = (AST_Node_Const*) (yyvsp[0].node);
		add_to_vals(temp->val);
	}
#line 1554 "parser.tab.c"
    break;

  case 30: /* values: constant  */
#line 237 "parser.y"
        {
		AST_Node_Const *temp = (AST_Node_Const*) (yyvsp[0].node);
		add_to_vals(temp->val);
	}
#line 1563 "parser.tab.c"
    break;

  case 31: /* statements: statements statement  */
#line 246 "parser.y"
        {
		AST_Node_Statements *temp = (AST_Node_Statements*) (yyvsp[-1].node);
		(yyval.node) = new_statements_node(temp->statements, temp->statement_count, (yyvsp[0].node));
	}
#line 1572 "parser.tab.c"
    break;

  case 32: /* statements: statement  */
#line 251 "parser.y"
        {
		(yyval.node) = new_statements_node(NULL, 0, (yyvsp[0].node));
	}
#line 1580 "parser.tab.c"
    break;

  case 33: /* statement: if_statement  */
#line 258 "parser.y"
        { 
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1588 "parser.tab.c"
    break;

  case 34: /* statement: for_statement  */
#line 262 "parser.y"
        { 
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1596 "parser.tab.c"
    break;

  case 35: /* statement: while_statement  */
#line 266 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1604 "parser.tab.c"
    break;

  case 36: /* statement: assigment SEMI  */
#line 270 "parser.y"
        {
		(yyval.node) = (yyvsp[-1].node); /* just pass information */
	}
#line 1612 "parser.tab.c"
    break;

  case 37: /* statement: CONTINUE SEMI  */
#line 274 "parser.y"
        { 
		(yyval.node) = new_ast_simple_node(0);
	}
#line 1620 "parser.tab.c"
    break;

  case 38: /* statement: BREAK SEMI  */
#line 278 "parser.y"
        { 
		(yyval.node) = new_ast_simple_node(1);
	}
#line 1628 "parser.tab.c"
    break;

  case 39: /* statement: function_call SEMI  */
#line 282 "parser.y"
        { 
		(yyval.node) = (yyvsp[-1].node); /* just pass information */
	}
#line 1636 "parser.tab.c"
    break;

  case 40: /* statement: ID INCR SEMI  */
#line 286 "parser.y"
        {
		/* increment */
		if((yyvsp[-1].val).ival == INC){
			(yyval.node) = new_ast_incr_node((yyvsp[-2].symtab_item), 0, 0);
		}
		else{
			(yyval.node) = new_ast_incr_node((yyvsp[-2].symtab_item), 1, 0);
		}
	}
#line 1650 "parser.tab.c"
    break;

  case 41: /* statement: INCR ID SEMI  */
#line 296 "parser.y"
        {
		/* increment */
		if((yyvsp[-2].val).ival == INC){
			(yyval.node) = new_ast_incr_node((yyvsp[-1].symtab_item), 0, 1);
		}
		else{
			(yyval.node) = new_ast_incr_node((yyvsp[-1].symtab_item), 1, 1);
		}
	}
#line 1664 "parser.tab.c"
    break;

  case 42: /* if_statement: IF LPAREN expression RPAREN tail else_if optional_else  */
#line 309 "parser.y"
        {
		(yyval.node) = new_ast_if_node((yyvsp[-4].node), (yyvsp[-2].node), elsifs, elseif_count, (yyvsp[0].node));
		elseif_count = 0;
		elsifs = NULL;
	}
#line 1674 "parser.tab.c"
    break;

  case 43: /* if_statement: IF LPAREN expression RPAREN tail optional_else  */
#line 315 "parser.y"
        {
		(yyval.node) = new_ast_if_node((yyvsp[-3].node), (yyvsp[-1].node), NULL, 0, (yyvsp[0].node));
	}
#line 1682 "parser.tab.c"
    break;

  case 44: /* else_if: else_if ELSE IF LPAREN expression RPAREN tail  */
#line 322 "parser.y"
        {
		AST_Node *temp = new_ast_elsif_node((yyvsp[-2].node), (yyvsp[0].node));
		add_elseif(temp);
	}
#line 1691 "parser.tab.c"
    break;

  case 45: /* else_if: ELSE IF LPAREN expression RPAREN tail  */
#line 327 "parser.y"
        {
		AST_Node *temp = new_ast_elsif_node((yyvsp[-2].node), (yyvsp[0].node));
		add_elseif(temp);
	}
#line 1700 "parser.tab.c"
    break;

  case 46: /* optional_else: ELSE tail  */
#line 335 "parser.y"
        {
		/* else exists */
		(yyval.node) = (yyvsp[0].node);
	}
#line 1709 "parser.tab.c"
    break;

  case 47: /* optional_else: %empty  */
#line 340 "parser.y"
        {
		/* no else */
		(yyval.node) = NULL;
	}
#line 1718 "parser.tab.c"
    break;

  case 48: /* for_statement: FOR LPAREN assigment SEMI expression SEMI ID INCR RPAREN tail  */
#line 347 "parser.y"
{
	/* create increment node*/
	AST_Node *incr_node;
	if((yyvsp[-2].val).ival == INC){ /* increment */
		incr_node = new_ast_incr_node((yyvsp[-3].symtab_item), 0, 0);
	}
	else{
		incr_node = new_ast_incr_node((yyvsp[-3].symtab_item), 1, 0);
	}

	(yyval.node) = new_ast_for_node((yyvsp[-7].node), (yyvsp[-5].node), incr_node, (yyvsp[0].node));
	set_loop_counter((yyval.node));
}
#line 1736 "parser.tab.c"
    break;

  case 49: /* while_statement: WHILE LPAREN expression RPAREN tail  */
#line 363 "parser.y"
{
	(yyval.node) = new_ast_while_node((yyvsp[-2].node), (yyvsp[0].node));
}
#line 1744 "parser.tab.c"
    break;

  case 50: /* tail: LBRACE statements RBRACE  */
#line 369 "parser.y"
{ 
	(yyval.node) = (yyvsp[-1].node); /* just pass information */
}
#line 1752 "parser.tab.c"
    break;

  case 51: /* expression: expression ADDOP expression  */
#line 376 "parser.y"
        { 
	    (yyval.node) = new_ast_arithm_node((yyvsp[-1].val).ival, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1760 "parser.tab.c"
    break;

  case 52: /* expression: expression MULOP expression  */
#line 380 "parser.y"
        {
	    (yyval.node) = new_ast_arithm_node(MUL, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1768 "parser.tab.c"
    break;

  case 53: /* expression: expression DIVOP expression  */
#line 384 "parser.y"
        {
		(yyval.node) = new_ast_arithm_node(DIV, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1776 "parser.tab.c"
    break;

  case 54: /* expression: ID INCR  */
#line 388 "parser.y"
        {
		/* increment */
		if((yyvsp[0].val).ival == INC){
			(yyval.node) = new_ast_incr_node((yyvsp[-1].symtab_item), 0, 0);
		}
		else{
			(yyval.node) = new_ast_incr_node((yyvsp[-1].symtab_item), 1, 0);
		}	
	}
#line 1790 "parser.tab.c"
    break;

  case 55: /* expression: INCR ID  */
#line 398 "parser.y"
        {
		/* increment */
		if((yyvsp[-1].val).ival == INC){
			(yyval.node) = new_ast_incr_node((yyvsp[0].symtab_item), 0, 1);
		}
		else{
			(yyval.node) = new_ast_incr_node((yyvsp[0].symtab_item), 1, 1);
		}
	}
#line 1804 "parser.tab.c"
    break;

  case 56: /* expression: expression OROP expression  */
#line 408 "parser.y"
        {
		(yyval.node) = new_ast_bool_node(OR, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1812 "parser.tab.c"
    break;

  case 57: /* expression: expression ANDOP expression  */
#line 412 "parser.y"
        {
		(yyval.node) = new_ast_bool_node(AND, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1820 "parser.tab.c"
    break;

  case 58: /* expression: NOTOP expression  */
#line 416 "parser.y"
        {
	    (yyval.node) = new_ast_bool_node(NOT, (yyvsp[0].node), NULL);
	}
#line 1828 "parser.tab.c"
    break;

  case 59: /* expression: expression EQUOP expression  */
#line 420 "parser.y"
        {
		(yyval.node) = new_ast_equ_node((yyvsp[-1].val).ival, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1836 "parser.tab.c"
    break;

  case 60: /* expression: expression RELOP expression  */
#line 424 "parser.y"
        {
		(yyval.node) = new_ast_rel_node((yyvsp[-1].val).ival, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1844 "parser.tab.c"
    break;

  case 61: /* expression: LPAREN expression RPAREN  */
#line 428 "parser.y"
        {
		(yyval.node) = (yyvsp[-1].node); /* just pass information */
	}
#line 1852 "parser.tab.c"
    break;

  case 62: /* expression: var_ref  */
#line 432 "parser.y"
        { 
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1860 "parser.tab.c"
    break;

  case 63: /* expression: constant  */
#line 436 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node); /* no sign */
	}
#line 1868 "parser.tab.c"
    break;

  case 64: /* expression: ADDOP constant  */
#line 440 "parser.y"
        {
		/* plus sign error */
		if((yyvsp[-1].val).ival == ADD){
			fprintf(stderr, "Error having plus as a sign!\n");
			exit(1);
		}
		else{
			AST_Node_Const *temp = (AST_Node_Const*) (yyvsp[0].node);
		
			/* inverse value depending on the constant type */
			switch(temp->const_type){
				case INT_TYPE:
					temp->val.ival *= -1;
					break;
				case REAL_TYPE:
					temp->val.fval *= -1;
					break;
				case CHAR_TYPE:
					/* sign before char error */
					fprintf(stderr, "Error having sign before character constant!\n");
					exit(1);
					break;
			}
			
			(yyval.node) = (AST_Node*) temp;
		}
	}
#line 1900 "parser.tab.c"
    break;

  case 65: /* expression: function_call  */
#line 468 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1908 "parser.tab.c"
    break;

  case 66: /* constant: ICONST  */
#line 474 "parser.y"
                 { (yyval.node) = new_ast_const_node(INT_TYPE, (yyvsp[0].val));  }
#line 1914 "parser.tab.c"
    break;

  case 67: /* constant: FCONST  */
#line 475 "parser.y"
                 { (yyval.node) = new_ast_const_node(REAL_TYPE, (yyvsp[0].val)); }
#line 1920 "parser.tab.c"
    break;

  case 68: /* constant: CCONST  */
#line 476 "parser.y"
                 { (yyval.node) = new_ast_const_node(CHAR_TYPE, (yyvsp[0].val)); }
#line 1926 "parser.tab.c"
    break;

  case 69: /* assigment: var_ref ASSIGN expression  */
#line 480 "parser.y"
{
	AST_Node_Ref *temp = (AST_Node_Ref*) (yyvsp[-2].node);
	(yyval.node) = new_ast_assign_node(temp->entry, temp->ref, (yyvsp[0].node));
	
	/* find datatypes */
	int type1 = get_type(temp->entry->st_name);
	int type2 = expression_data_type((yyvsp[0].node));
	
	/* the last function will give us information about revisits */
	
	/* contains revisit => add assignment-check to revisit queue */
	if(cont_revisit == 1){	
		/* search if entry exists */
		revisit_queue *q = search_queue(temp->entry->st_name);
		if(q == NULL){
			add_to_queue(temp->entry, temp->entry->st_name, ASSIGN_CHECK);
			q = search_queue(temp->entry->st_name);	
		}
		
		/* setup structures */
		if(q->num_of_assigns == 0){ /* first node */
			q->nodes = (void**) malloc(sizeof(void*));
		}
		else{ /* general case */
			q->nodes = (void**) realloc(q->nodes, (q->num_of_assigns + 1) * sizeof(void*));
		}
		
		/* add info of assignment */
		q->nodes[q->num_of_assigns] = (void*) (yyvsp[0].node);
		
		/* increment number of assignments */
		q->num_of_assigns++;
		
		/* reset revisit flag */
		cont_revisit = 0;
		
		printf("Assignment revisit for %s at line %d\n", temp->entry->st_name, lineno);
	}
	else{ /* no revisit */
		/* check assignment semantics */
		get_result_type(
			type1,       /*  variable datatype  */
			type2,       /* expression datatype */
			NONE  /* checking compatibility only (no operator) */
		);
	}
}
#line 1978 "parser.tab.c"
    break;

  case 70: /* var_ref: variable  */
#line 530 "parser.y"
        {
		(yyval.node) = new_ast_ref_node((yyvsp[0].symtab_item), 0); /* no reference */
	}
#line 1986 "parser.tab.c"
    break;

  case 71: /* var_ref: REFER variable  */
#line 534 "parser.y"
        {
		(yyval.node) = new_ast_ref_node((yyvsp[0].symtab_item), 1); /* reference */
	}
#line 1994 "parser.tab.c"
    break;

  case 72: /* function_call: ID LPAREN call_params RPAREN  */
#line 540 "parser.y"
{
	AST_Node_Call_Params *temp = (AST_Node_Call_Params*) (yyvsp[-1].node);
	(yyval.node) = new_ast_func_call_node((yyvsp[-3].symtab_item), temp->params, temp->num_of_pars);	
	
	/* add information to revisit queue entry (if one exists) */
	revisit_queue *q = search_queue((yyvsp[-3].symtab_item)->st_name);
	if(q != NULL){
		/* setup structures */
		if(q->num_of_calls == 0){ /* first call */
			q->par_types = (int**) malloc(sizeof(int*));
			q->num_of_pars = (int*) malloc(sizeof(int));
		}
		else{ /* general case */
			q->par_types = (int**) realloc(q->par_types, (q->num_of_calls + 1) * sizeof(int*));
			q->num_of_pars = (int*) realloc(q->num_of_pars, (q->num_of_calls + 1) * sizeof(int));
		}
		
		/* add info of function call */
		q->num_of_pars[q->num_of_calls] = temp->num_of_pars;
		q->par_types[q->num_of_calls] = (int*) malloc(temp->num_of_pars * sizeof(int));
		/* get the types of the parameters */
		int i;
		for(i = 0; i < temp->num_of_pars; i++){
			/* get datatype of parameter-expression */
			q->par_types[q->num_of_calls][i] = expression_data_type(temp->params[i]);
		}
		
		/* increment number of calls */
		q->num_of_calls++;
	}
	else{
		/* function declared before call */
		if((yyvsp[-3].symtab_item)->st_type == FUNCTION_TYPE){
			/* check number of parameters */
			if((yyvsp[-3].symtab_item)->num_of_pars != temp->num_of_pars){
				fprintf(stderr, "Function call of %s has wrong num of parameters!\n", (yyvsp[-3].symtab_item)->st_name);
				exit(1);
			}
			/* check if parameters are compatible */
			int i;
			for(i = 0; i < temp->num_of_pars; i++){
				/* type of parameter in function declaration */
				int type_1 = expression_data_type(temp->params[i]);
				
				/* type of parameter in function call*/
				int type_2 = (yyvsp[-3].symtab_item)->parameters[i].par_type;
				
				/* check compatibility for function call */
				get_result_type(type_1, type_2, NONE);
				/* error occurs automatically in the function */
			}
		}
	}
}
#line 2053 "parser.tab.c"
    break;

  case 73: /* call_params: call_param  */
#line 598 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2061 "parser.tab.c"
    break;

  case 74: /* call_params: STRING  */
#line 602 "parser.y"
        {
		AST_Node *temp = new_ast_const_node(STR_TYPE, (yyvsp[0].val));
		(yyval.node) = new_ast_call_params_node(NULL, 0, temp);
	}
#line 2070 "parser.tab.c"
    break;

  case 75: /* call_params: %empty  */
#line 607 "parser.y"
        {
		AST_Node_Call_Params *temp = malloc (sizeof (AST_Node_Call_Params));
		temp->type = CALL_PARAMS;
		temp->params = NULL;
		temp->num_of_pars = 0;
		(yyval.node) = (AST_Node*)temp;
	}
#line 2082 "parser.tab.c"
    break;

  case 76: /* call_param: call_param COMMA expression  */
#line 618 "parser.y"
        {
		AST_Node_Call_Params *temp = (AST_Node_Call_Params*) (yyvsp[-2].node);
		(yyval.node) = new_ast_call_params_node(temp->params, temp->num_of_pars, (yyvsp[0].node));
	}
#line 2091 "parser.tab.c"
    break;

  case 77: /* call_param: expression  */
#line 623 "parser.y"
        {
		(yyval.node) = new_ast_call_params_node(NULL, 0, (yyvsp[0].node));
	}
#line 2099 "parser.tab.c"
    break;

  case 78: /* functions_optional: functions  */
#line 631 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2107 "parser.tab.c"
    break;

  case 79: /* functions_optional: %empty  */
#line 635 "parser.y"
        {
		(yyval.node) = NULL;
	}
#line 2115 "parser.tab.c"
    break;

  case 80: /* functions: functions function  */
#line 642 "parser.y"
        {
		AST_Node_Func_Declarations *temp = (AST_Node_Func_Declarations*) (yyvsp[-1].node);
		(yyval.node) = new_func_declarations_node(temp->func_declarations, temp->func_declaration_count, (yyvsp[0].node));
	}
#line 2124 "parser.tab.c"
    break;

  case 81: /* functions: function  */
#line 647 "parser.y"
        {
		(yyval.node) = new_func_declarations_node(NULL, 0, (yyvsp[0].node));
	}
#line 2132 "parser.tab.c"
    break;

  case 82: /* $@5: %empty  */
#line 652 "parser.y"
          { incr_scope(); }
#line 2138 "parser.tab.c"
    break;

  case 83: /* function: $@5 function_head function_tail  */
#line 653 "parser.y"
{ 
	/* perform revisit */
	revisit(temp_function->entry->st_name);

	hide_scope();
	(yyval.node) = (AST_Node *) temp_function;
}
#line 2150 "parser.tab.c"
    break;

  case 84: /* $@6: %empty  */
#line 662 "parser.y"
               { function_decl = 1; }
#line 2156 "parser.tab.c"
    break;

  case 85: /* $@7: %empty  */
#line 663 "parser.y"
        { 
		function_decl = 0;
		
		AST_Node_Ret_Type *temp = (AST_Node_Ret_Type *) (yyvsp[-2].node);
		temp_function = (AST_Node_Func_Decl *) new_ast_func_decl_node(temp->ret_type, temp->pointer, (yyvsp[-1].symtab_item));
		temp_function->entry->st_type = FUNCTION_TYPE;
		temp_function->entry->inf_type = temp->ret_type;
	}
#line 2169 "parser.tab.c"
    break;

  case 86: /* function_head: $@6 return_type ID LPAREN $@7 parameters_optional RPAREN  */
#line 672 "parser.y"
        {
		if((yyvsp[-1].node) != NULL){
			AST_Node_Decl_Params *temp = (AST_Node_Decl_Params *) (yyvsp[-1].node);
			
			temp_function->entry->parameters = temp->parameters;
			temp_function->entry->num_of_pars = temp->num_of_pars;
		}
		else{
			temp_function->entry->parameters = NULL;
			temp_function->entry->num_of_pars = 0;
		}		
	}
#line 2186 "parser.tab.c"
    break;

  case 87: /* return_type: type  */
#line 688 "parser.y"
        {
		(yyval.node) = new_ast_ret_type_node((yyvsp[0].data_type), 0);
	}
#line 2194 "parser.tab.c"
    break;

  case 88: /* return_type: type pointer  */
#line 692 "parser.y"
        {
		(yyval.node) = new_ast_ret_type_node((yyvsp[-1].data_type), 1);
	}
#line 2202 "parser.tab.c"
    break;

  case 89: /* parameters_optional: parameters  */
#line 699 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2210 "parser.tab.c"
    break;

  case 90: /* parameters_optional: %empty  */
#line 703 "parser.y"
        {
		(yyval.node) = NULL;
	}
#line 2218 "parser.tab.c"
    break;

  case 91: /* parameters: parameters COMMA parameter  */
#line 710 "parser.y"
        {
		AST_Node_Decl_Params *temp = (AST_Node_Decl_Params *) (yyvsp[-2].node);
		(yyval.node) = new_ast_decl_params_node(temp->parameters, temp->num_of_pars, (yyvsp[0].par));
	}
#line 2227 "parser.tab.c"
    break;

  case 92: /* parameters: parameter  */
#line 715 "parser.y"
        {
		(yyval.node) = new_ast_decl_params_node(NULL, 0, (yyvsp[0].par));
	}
#line 2235 "parser.tab.c"
    break;

  case 93: /* $@8: %empty  */
#line 720 "parser.y"
            { declare = 1; }
#line 2241 "parser.tab.c"
    break;

  case 94: /* parameter: $@8 type variable  */
#line 721 "parser.y"
{ 
	declare = 0;
	
	// set type of symbol table entry	
	if((yyvsp[0].symtab_item)->st_type == UNDEF){ /* "simple" type */
		set_type((yyvsp[0].symtab_item)->st_name, (yyvsp[-1].data_type), UNDEF); 
	}
	else if((yyvsp[0].symtab_item)->st_type == POINTER_TYPE){ /* pointer */
		set_type((yyvsp[0].symtab_item)->st_name, POINTER_TYPE, (yyvsp[-1].data_type));
	}
	else if((yyvsp[0].symtab_item)->st_type == ARRAY_TYPE){ /* array  */
		set_type((yyvsp[0].symtab_item)->st_name, ARRAY_TYPE, (yyvsp[-1].data_type));
	}
	
	/* define parameter */
	(yyval.par) = def_param((yyvsp[-1].data_type), (yyvsp[0].symtab_item)->st_name, 0);
}
#line 2263 "parser.tab.c"
    break;

  case 96: /* declarations_optional: declarations  */
#line 744 "parser.y"
        {
		temp_function->declarations = (yyvsp[0].node);
	}
#line 2271 "parser.tab.c"
    break;

  case 97: /* declarations_optional: %empty  */
#line 748 "parser.y"
        {
		temp_function->declarations = NULL;
	}
#line 2279 "parser.tab.c"
    break;

  case 98: /* statements_optional: statements  */
#line 755 "parser.y"
        {
		temp_function->statements = (yyvsp[0].node);
	}
#line 2287 "parser.tab.c"
    break;

  case 99: /* statements_optional: %empty  */
#line 759 "parser.y"
        {
		temp_function->statements = NULL;
	}
#line 2295 "parser.tab.c"
    break;

  case 100: /* return_optional: RETURN expression SEMI  */
#line 766 "parser.y"
        {
		temp_function->return_node = new_ast_return_node(temp_function->ret_type, (yyvsp[-1].node));
	}
#line 2303 "parser.tab.c"
    break;

  case 101: /* return_optional: %empty  */
#line 770 "parser.y"
        {
		temp_function->return_node = NULL;
	}
#line 2311 "parser.tab.c"
    break;


#line 2315 "parser.tab.c"

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

#line 775 "parser.y"


void yyerror ()
{
  fprintf(stderr, "Syntax error at line %d\n", lineno);
  exit(1);
}

void add_to_names(tokens *entry){
	// first entry
	if(nc == 0){
		nc = 1;
		names = (tokens **) malloc( 1 * sizeof(tokens *));
		names[0] = entry;
	}
	// general case
	else{
		nc++;
		names = (tokens **) realloc(names, nc * sizeof(tokens *));
		names[nc - 1] = entry;		
	}
}

void add_to_vals(Value val){
	// first entry
	if(vc == 0){
		vc = 1;
		vals = (Value *) malloc(1 * sizeof(Value));
		vals[0] = val;
	}
	// general case
	else{
		vc++;
		vals = (Value *) realloc(vals, vc * sizeof(Value));
		vals[vc - 1] = val;
	}
}

void add_elseif(AST_Node *elsif){
	// first entry
	if(elseif_count == 0){
		elseif_count = 1;
		elsifs = (AST_Node **) malloc(1 * sizeof(AST_Node));
		elsifs[0] = elsif;
	}
	// general case
	else{
		elseif_count++;
		elsifs = (AST_Node **) realloc(elsifs, elseif_count * sizeof(AST_Node));
		elsifs[elseif_count - 1] = elsif;
	}
}

int main (int argc, char *argv[]){
	
	// initialize symbol table
	init_hash_table();
	
	// initialize revisit queue
	queue = NULL;
	
	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
	
	printf("Parsing finished!\n");
	
	/* remove print from revisit queue */
	revisit_queue *q = search_prev_queue("print");
	if(q == NULL){ /* special case: first entry */
		if(queue != NULL){ /* check if queue not empty */
			queue = queue->next;
		}
	}
	else{
		q->next = q->next->next;
	}
	
	/* perform the remaining checks (assignments) */
	if(queue != NULL){
		revisit_queue *cur;
		cur = queue;
		while(cur != NULL){
			if(cur->revisit_type == ASSIGN_CHECK){
				revisit(cur->st_name);
			}
			cur = cur->next;
		}
	}
	
	/* if still not empty => warning */
	if(queue != NULL){
		printf("Warning! Something in the revisit queue has not been checked yet!\n");
	}
	
	/* declare function type of "print" */
	func_declare("print", VOID_TYPE, 1, NULL);
	
	// symbol table dump
	yyout = fopen("symtab_dump.out", "w");
	symtab_dump(yyout);
	fclose(yyout);
	
	// revisit queue dump
	yyout = fopen("revisit_dump.out", "w");
	revisit_dump(yyout);
	fclose(yyout);
	
	// code generation
	generate_code();
	
	return flag;
}
