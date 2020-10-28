
%{
#include "gramatica.tab.h"
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
[0-9]+([\.][0-9]*)?		{return NUMERO;} 	//Número
:						{return DOIS_PONTOS;} 	//Dois pontos
integer					{return TIPO_DE_DADO;} 	//Palavra reservada; tipo de dado
real					{return TIPO_DE_DADO;} 	//Palavra reservada; tipo de dado
array					{return TIPO_DE_DADO;} 	//Palavra reservada; tipo de dado
of						{return OF;} 	//Palavra reservada
record					{return TIPO_DE_DADO;} 	//Palavra reservada; tipo de dado
function				{return FUNCTION;} 	//Palavra reservada
:=						{return ATRIBUICAO;} 	//Atribuição
while					{return WHILE;} 	//Palavra reservada
if						{return IF;} 	//Palavra reservada
then					{return THEN;} 	//Palavra reservada
write					{return WRITE;} 	//Palavra reservada
else					{return ELSE;} 	//Palavra reservada
"("						{return ABRE_PARENTESES;} 	//Abre parenteses
")"						{return FECHA_PARENTESES;} 	//Fecha parenteses
,						{return VIRGULA;} 	//Vírgula
"."						{return PONTO;} 	//Ponto
"["						{return ABRE_COLCHETES;} 	//Abre colchetes
"]"						{return FECHA_COLCHETES;} 	//Fecha colchetes
">"						|
"<"						|
=						|
!						{return OPERADOR_LOGICO;} 	//Operador lógico
"+"						|
"-"						|
"*"						|
"/"						{return OPERADOR_MATEMATICO;} 	//Operador matemático
[a-zA-Z]+[a-zA-Z0-9]*	{return IDENTIFICADOR;} 	//Identificador

"{"[^"}"]*"}"		  	;	//Comentario
[ \t\n]				;				//Espaço, tabulação e quebra de linha(ignorados)
.				{return ERRO;} 	//carácter inesperado
%%

int yywrap(void)
{
	return 1;
}
