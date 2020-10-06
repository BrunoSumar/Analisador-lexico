#include <stdio.h>

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(void){

    int token = 0;
    token = yylex();
    while(token){
        printf("[%s]", yytext);
        token = yylex();
    }
    getchar();
    return 0;
}
