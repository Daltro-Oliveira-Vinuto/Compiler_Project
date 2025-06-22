/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PRINT = 258,
     ID = 259,
     NUM = 260,
     FNUM = 261,
     IF = 262,
     ELSE = 263,
     INT = 264,
     FLOAT = 265,
     RETURN = 266,
     VOID = 267,
     WHILE = 268,
     ASSIGN = 269,
     MINUS = 270,
     PLUS = 271,
     OVER = 272,
     TIMES = 273,
     NE = 274,
     EQ = 275,
     GE = 276,
     GT = 277,
     LE = 278,
     LT = 279,
     LOWER_THAN_ELSE = 280,
     LPAREN = 281,
     RPAREN = 282,
     LBRACK = 283,
     RBRACK = 284,
     LBRACE = 285,
     RBRACE = 286,
     SEMI = 287,
     COMMA = 288
   };
#endif
/* Tokens.  */
#define PRINT 258
#define ID 259
#define NUM 260
#define FNUM 261
#define IF 262
#define ELSE 263
#define INT 264
#define FLOAT 265
#define RETURN 266
#define VOID 267
#define WHILE 268
#define ASSIGN 269
#define MINUS 270
#define PLUS 271
#define OVER 272
#define TIMES 273
#define NE 274
#define EQ 275
#define GE 276
#define GT 277
#define LE 278
#define LT 279
#define LOWER_THAN_ELSE 280
#define LPAREN 281
#define RPAREN 282
#define LBRACK 283
#define RBRACK 284
#define LBRACE 285
#define RBRACE 286
#define SEMI 287
#define COMMA 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 74 "sintatico.y"
{
    char* cadeia;
    int num;
}
/* Line 1529 of yacc.c.  */
#line 120 "sintatico.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

