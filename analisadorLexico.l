
%{
#include "classLexica.h"
%}
%option nounput yylineno

%%
"lorem"				return lorem;
"ipsum"				return ipsum;
"dolor"				return dolor;
"sit"				return sit;
"amet"				return amet;
"sint"				return sint;
"occaecat"			return occaecat;
"cupidatat"			return cupidatat;
[ \t\n]				return 9;
%%

int yywrap(void)
{
	return 1;
}
