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
%token INTEGER
%token REAL
%token ARRAY
%token RECORD
%token OF
%token FUNCTION
%token WHILE
%token IF
%token THEN
%token ELSE
%token WRITE
%token READ

// Valores, indetificadores e simbolos
%token ATRIBUICAO
%token ABRE_PARENTESES
%token FECHA_PARENTESES
%token VIRGULA
%token PONTO
%token ABRE_COLCHETES
%token FECHA_COLCHETES
%token IDENTIFICADOR
%token PONTO_E_VIRGULA
%token DOIS_PONTOS
%token CONST_STRING
%token NUMERO
%token MAIOR_QUE
%token MENOR_QUE
%token IGUAL
%token SOMA
%token SUBTRACAO
%token MULT
%token EXCLAMACAO
%token BARRA

//Token sem classificação
%token ERRO

%%

programa        : PROGRAM IDENTIFICADOR PONTO_E_VIRGULA corpo {printf("prog");}
                ;

corpo           : declaracoes BEGIN_ lista_com END corpo  {printf(" corpo ");}
                | /*  epsilon */              {;}
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

lista_const     : constante lista_const  {;}
                | constante            {;}
                ;

constante       : IDENTIFICADOR IGUAL const_valor PONTO_E_VIRGULA  {;}
                ;

const_valor     : CONST_STRING   {;}
                | exp_mat     {;}
                ;

numero          : NUMERO                         {;}
                ;

lista_tipos     : tipo PONTO_E_VIRGULA lista_tipos        {;}
                | tipo                                {;}
                ;

tipo            : IDENTIFICADOR IGUAL tipo_dado          {;}
                ;

lista_var       : variavel PONTO_E_VIRGULA lista_var     {;}
                | variavel                    {;}
                ;

variavel        : lista_id DOIS_PONTOS tipo_dado         {;}
                ;

lista_id        : IDENTIFICADOR VIRGULA lista_id              {;}
                | IDENTIFICADOR
                ;

tipo_dado       : INTEGER                      {;}
                | REAL                     {;}
                | ARRAY ABRE_COLCHETES numero FECHA_COLCHETES OF tipo_dado  {;}
                | RECORD lista_var END                           {;}
                | IDENTIFICADOR                  {;}
                ;

lista_func      : funcao lista_func         {;}
                | /*  epsilon */                {;}
                ;

funcao          : nome_funcao bloco_funcao       {;}
                ;

nome_funcao     : FUNCTION IDENTIFICADOR ABRE_PARENTESES lista_var FECHA_PARENTESES DOIS_PONTOS tipo_dado  {;}
                ;

bloco_funcao    : def_var bloco            {;}
                | bloco           {;}
                ;

bloco           : BEGIN_ lista_com END         {;}
                | comando                    {;}
                ;

lista_com       : comando PONTO_E_VIRGULA lista_com         {;}
                | /*  epsilon */                             {;}
                ;

comando         : nome ATRIBUICAO valor                   {;}
                | WHILE  exp_logica bloco                 {;}
                | IF exp_logica THEN bloco else             {;}
                | WRITE const_valor                  {;}
                | READ nome                             {;}
                ;

 else           : ELSE bloco                       {;}
                | /*  epsilon */                      {;}
                ;

valor           : exp_mat                                 {;}
                | IDENTIFICADOR lista_param                  {;}
                ;

lista_param     : ABRE_PARENTESES lista_nome FECHA_PARENTESES  {;}
                ;

lista_nome      : parametro VIRGULA lista_nome     {;}
                | parametro                                     {;}
                | /*  epsilon */                                {;}
                ;

exp_logica      : exp_mat op_logico exp_logica               {;}
                | exp_mat                                     {;}
                ;

exp_mat         : parametro op_mat exp_mat                     {;}
                | parametro                                    {;}
                ;

parametro       : nome                                         {;}
                | numero                                       {;}
                ;

op_logico       : MAIOR_QUE                  {;}
                | MENOR_QUE                  {;}
                | IGUAL                      {;}
                | EXCLAMACAO                 {;}
                ;

op_mat          : SOMA                       {;}
                | SUBTRACAO                  {;}
                | MULT                       {;}
                | BARRA                      {;}
                ;

nome            : IDENTIFICADOR                                           {;}
                | IDENTIFICADOR PONTO nome                                {;}
                | IDENTIFICADOR ABRE_COLCHETES parametro FECHA_COLCHETES  {;}
                ;

%%


int yyerror(char const *s){
  printf(" erro sintatico: %s\n", s);
}


int main (void) {
  return yyparse( );
}
