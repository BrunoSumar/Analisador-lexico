
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
(.)+					return 100;
%%

int yywrap(void)
{
	return 1;
}
