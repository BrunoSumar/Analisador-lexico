/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 13 "gramatica.y"
char *str;double fl;

#line 102 "gramatica.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMATICA_TAB_H_INCLUDED  */
