
%{
#include "classLexica.h"
%}
%option yylineno

%%
program					{return 1;} 	//Palavra reservada
";"						{return 1;} 	//ponto e virgula
begin					{return 1;} 	//Palavra reservada
end						{return 1;} 	//Palavra reservada
const					{return 1;} 	//Palavra reservada
type					{return 1;} 	//Palavra reservada
var						{return 1;} 	//Palavra reservada
\"[^\"\n]*\"			|				//XXXXXXXXXXXXXXXXXXXXXXxRevisar depois
\“[^\”\n]*\”			{return 1;} 	//String
[0-9]+([\.][0-9]*)?		{return 7;} 	//Número
:						{return 1;} 	//Ponto e vírgula
integer					{return 1;} 	//Palavra reservada; tipo de dado
real					{return 1;} 	//Palavra reservada; tipo de dado
array					{return 1;} 	//Palavra reservada; tipo de dado
of						{return 1;} 	//Palavra reservada
record					{return 1;} 	//Palavra reservada; tipo de dado
function				{return 1;} 	//Palavra reservada
:=						{return 1;} 	//Atribuição
while					{return 1;} 	//Palavra reservada
if						{return 1;} 	//Palavra reservada
then					{return 1;} 	//Palavra reservada
write					{return 1;} 	//Palavra reservada
else					{return 1;} 	//Palavra reservada
"("						{return 1;} 	//Abre parenteses
")"						{return 1;} 	//Fecha parenteses
,						{return 1;} 	//Vírgula
"."						{return 1;} 	//Ponto
"["						{return 1;} 	//Abre colchetes
"]"						{return 1;} 	//Fecha colchetes
">"						|
"<"						|
=						|
!						{return 1;} 	//Operador lógico
"+"						|
"-"						|
"*"						{return 1;} 	//Operador matemático
"/"						{return 1;} 	//Barra
[a-zA-Z]+[a-zA-Z0-9]*	{return 1;} 	//Identificador

[ \t\n]					;				//Espaço, tabulação e quebra de linha(ignorados)
.						{return ERRO;} 	//carácter inesperado
%%

int yywrap(void)
{
	return 1;
}
