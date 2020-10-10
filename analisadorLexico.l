
%{
#include "classLexica.h"
%}
%option nounput yylineno

%%
program					{return 1;} //[PROGRAMA]
";"						{return 1;}
begin					{return 1;} //[CORPO]
end						{return 1;}
const					{return 1;} //[DEF_CONST]
type					{return 1;} //[DEF_TIPOS]
var						{return 1;} //[DEF_VAR]
\"[^\"\n]*\"			{return 1;} //[CONST_VALOR]
[0-9]+[\.]?[0-9]+		{return 1;} //[NUMERO]
integer					{return 1;} //[TIPO_DADO]
real					{return 1;}
array					{return 1;}
of						{return 1;}
record					{return 1;}
function				{return 1;} //[NOME_FUNCAO]
:=						{return 1;} //[COMANDO]
while					{return 1;}
if						{return 1;}
then					{return 1;}
write					{return 1;}
else					{return 1;} //[ELSE]
"("						{return 1;} //[LISTA_PARAM]
")"						{return 1;}
,						{return 1;} //[LISTA_NOME]
"."						{return 1;} //[NOME]
"["						{return 1;}
"]"						{return 1;}
">"						|
"<"						|
=						|
!						{return 1;} //[OP_LOGICO]
"+"						|
"-"						|
"*"						{return 1;} //[OP_MAT]
"/"						{return 1;}
[a-zA-Z]+[a-zA-Z0-9]*	{return 1;} //[ID]

[ \t\n]					;
%%

int yywrap(void)
{
	return 1;
}
