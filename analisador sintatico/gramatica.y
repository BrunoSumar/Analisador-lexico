%{
#include <stdio.h>
#include <stdlib.h>

int yyerror();
int yylex();

%}

%token PROGRAM
%token BEGIN_
%token END
%token CONST
%token TYPE
%token VAR
%token TIPO_DE_DADO
%token OF
%token FUNCTION
%token WHILE
%token IF
%token THEN
%token ELSE
%token WRITE

// Valores, indetificadores e simbolos
%token ATRIBUICAO
%token ABRE_PARENTESES
%token FECHA_PARENTESES
%token VIRGULA
%token PONTO
%token ABRE_COLCHETES
%token FECHA_COLCHETES
%token OPERADOR_LOGICO
%token OPERADOR_MATEMATICO
%token IDENTIFICADOR
%token PONTO_E_VIRGULA
%token DOIS_PONTOS
%token CONST_STRING
%token NUMERO

//Token sem classificação
%token ERRO

%%

programa        : PROGRAM IDENTIFICADOR PONTO_E_VIRGULA  {printf("prog");}
                ;

corpo           : declaracoes BEGIN_ comandos END   {;}
                | BEGIN_ comandos END              {;}
                ;

declaracoes     : def_const def_tipos def_var lista_func  {;}
                | /* epsilon */                           {;}
                ;

def_const       : CONST lista_const                     {;}
                | /* epsilon */                                      {;}
                ;

def_tipos       : TYPE lista_tipos     {;}
                | /* epsilon */       {;}
                ;

def_var         : VAR lista_var        {;}
                | /* epsilon */           {;}

lista_const     : constante lista_cont  {;}
                | constante            {;}
                ;

constante       : IDENTIFICADOR



%%


int yyerror(char const *s){
  printf(" erro sintatico: %s\n", s);
}


int main (void) {
  return yyparse( );
}
