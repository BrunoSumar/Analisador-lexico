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
    int lineno;
    struct erro* next;
}Erro;

int main(void){

    Token *tokenIni = NULL, *tokenFin = NULL, *temp = NULL;
    Erro *erroIni = NULL, *erroFin = NULL, *erroAux = NULL;
    int tokenId = 0;
    char *text=NULL;

    printf("\nInicio analise lexica\n");
    tokenId = yylex();
    while(tokenId){
        // Gera token
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
        // Se token não puder ser classificado ele é adicionado a lista de erros
        if(tokenId==ERRO){
            erroAux = (Erro*) calloc(1, sizeof(Erro));
            erroAux->tk = temp;
            erroAux->lineno = yylineno;
            erroAux->next = NULL;
            if(!erroIni){
                erroIni = erroAux;
                erroFin = erroAux;
            }else{
                erroFin->next = erroAux;
                erroFin = erroAux;
            }
        }
        // Procura o token seguinte
        tokenId = yylex();
    }
    printf("\nFim analise\n\n");

    //imprime a lista de tokens
    printf("Tokens encontrados:\n");
    temp = tokenIni;
    while(temp){
        printf("Classificacao: %d  Conteudo[%s]\n", temp->id, temp->str);
        temp = temp->next;
    }
    //imprime lista de erros
    printf("%s\n", erroIni?"Erros encontrados:":"Nenhum erro léxico encontrado.");
    erroAux = erroIni;
    while(erroAux){
        printf("ERRO: [%s] linha: %d\n", erroAux->tk->str, erroAux->lineno);
        erroAux = erroAux->next;
    }

    //Libera as variaveis alocadas
    temp = tokenIni;
    while(temp){
        temp=tokenIni->next;
        free(tokenIni->str);
        free(tokenIni);
        tokenIni = temp;
    }
    erroAux = erroIni;
    while(erroAux){
        erroAux = erroIni->next;
        free(erroIni);
        erroIni = erroAux;
    }

    return 0;
}
