%{
#include "gramatica.tab.h"
#include "simbolos.h"

//extern YYTYPE yylval;
%}
%option yylineno

%%
program					{return PROGRAM;} 	//Palavra reservada
";"						{return PONTO_E_VIRGULA;} 	//ponto e virgula
begin					{return BEGIN_;} 	//Palavra reservada
end						{return END;} 	//Palavra reservada
const					{return CONST;} 	//Palavra reservada
type					{return TYPE;} 	//Palavra reservada
var						{return VAR;} 	//Palavra reservada
\"[^\"\n]*\"			{return CONST_STRING;} 	//String
[0-9]+([\.][0-9]*)?		{yylval.fl = atof(yytext); return NUMERO;} 	//Número
":"						{return DOIS_PONTOS;} 	//Dois pontos
integer					{yylval.tipo = strdup(yytext);return INTEGER;} 	//Palavra reservada; tipo de dado
real					{yylval.tipo = strdup(yytext);return REAL;} 	//Palavra reservada; tipo de dado
array					{yylval.tipo = strdup(yytext);return ARRAY;} 	//Palavra reservada; tipo de dado
of						{return OF;} 	//Palavra reservada
record					{yylval.tipo = strdup(yytext);depth--;return RECORD;} 	//Palavra reservada; tipo de dado
function				{yylval.tipo = strdup(yytext);depth--;return FUNCTION;} 	//Palavra reservada
":="					{return ATRIBUICAO;} 	//Atribuição
while					{return WHILE;} 	//Palavra reservada
if						{return IF;} 	//Palavra reservada
then					{return THEN;} 	//Palavra reservada
write					{return WRITE;} 	//Palavra reservada
else					{return ELSE;} 	//Palavra reservada
read                    {return READ;}  //Palavra reservada
"("						{return ABRE_PARENTESES;} 	//Abre parenteses
")"						{return FECHA_PARENTESES;} 	//Fecha parenteses
","						{return VIRGULA;} 	//Vírgula
"."						{return PONTO;} 	//Ponto
"["						{return ABRE_COLCHETES;} 	//Abre colchetes
"]"						{return FECHA_COLCHETES;} 	//Fecha colchetes
">"						{return MAIOR_QUE;}
"<"						{return MENOR_QUE;}
=						{return IGUAL;}
!						{return EXCLAMACAO;} 	//Operador lógico
"+"						{return SOMA;}
"-"						{return SUBTRACAO;}
"*"						{return MULT;}
"/"						{return BARRA;} 	//Operador matemático
[a-zA-Z]+[a-zA-Z0-9]*	{yylval.nome = strdup(yytext);return IDENTIFICADOR;} 	//Identificador

"{"[^"}"]*"}"		  	;	//Comentario
[" "\t\n]				;				//Espaço, tabulação e quebra de linha(ignorados)
.						{printf("Erro lexico, linha: %d \n",  yylineno); return ERRO;} 	//carácter inesperado
%%

int yywrap(void)
{
	return 1;
}
