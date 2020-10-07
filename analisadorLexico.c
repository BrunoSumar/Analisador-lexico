#include <stdio.h>
#include <stdlib.h>
#include "classLexica.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

typedef struct token{
    int id;
    char* str;
    struct token* next;
}Token;

typedef struct erro{
    struct token* tk;
    struct erro* next;
}Erro;

int main(void){

    Token *tokenIni = NULL, *tokenFin = NULL, *temp = NULL;
    Erro* erros = NULL;
    int tokenId = 0;

    tokenId = yylex();
    printf("inicio analise\n\n");
    printf("2\n\n");
    printf("1\n\n");
    while(tokenId){
        temp = (Token*) calloc(1, sizeof(Token));
        temp->id = tokenId;
        temp->str = yytext;
        temp->next = NULL;
        if(!tokenIni){
            tokenIni = temp;
            tokenFin = temp;
        }
        tokenFin->next = temp;
        tokenFin = temp;
        tokenId = yylex();
    }
    printf("fim analise\n\n");

    temp = tokenIni;
    while(temp){
        printf(". %d  %s\n", temp->id, temp->str);
        temp = temp->next;
    }

    temp = tokenIni;
    while(temp){
        temp=tokenIni->next;
        free(tokenIni);
        tokenIni = temp;
    }

    return 0;
}
