%option nounput yylineno

%%
"abc"               return 3;
.					return 1;

%%

int yywrap(void)
{
	return 1;
}
