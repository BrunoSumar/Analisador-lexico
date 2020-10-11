#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classLexica.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern int yyleng;

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
    char *text=NULL;

    printf("Inicio analise\n");
    tokenId = yylex();
    while(tokenId){
        temp = (Token*) calloc(1, sizeof(Token));
        temp->id = tokenId;
        text = (char*) calloc(yyleng, sizeof(char));
        strncpy(text, yytext, yyleng);
        temp->str = text;
        temp->next = NULL;
        if(!tokenIni){
            tokenIni = temp;
            tokenFin = temp;
        }else{
            tokenFin->next = temp;
            tokenFin = temp;
        }
        tokenId = yylex();
    }
    printf("\nfim analise\n");

    //imprime a lista de tokens
    temp = tokenIni;
    while(temp){
        printf("%d:  [%s]\n", temp->id, temp->str);
        temp = temp->next;
    }

    //Libera as variaveis alocadas
    temp = tokenIni;
    while(temp){
        temp=tokenIni->next;
        free(tokenIni);
        tokenIni = temp;
    }

    return 0;
}
