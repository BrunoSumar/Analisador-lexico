#ifndef __SIMBOLOS_H_
#define __SIMBOLOS_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct simbolo{
  int class; // classificação do simbolo(e.g. var, função, record...)
  char nome[50]; // identificador do simbolo
  char tipo[50]; // tipo de dado
  char escopo[50]; // escopo ao qual o simbolo pertence
  int qt; // quantidade de parametros em caso de função (auxiliar para o restante)
  int ordem; // ordem do parametro em função (apenas para parametros de funções)
}Simbolo;

typedef struct escopo{
  char nome[50];
  struct escopo* next;
}Escopo;

// variáveis de controle
int ind; //indice do proximo espaço vazio da tabela de simbolos
int depth; // auxiliar para definir escopos
int quantP; // quantidade de parametros na função atual
int tam; // tamanho da tabela

// Tabela de Simbolos
Simbolo* tabSim;

// pilha

// Funções para manipular a tabela
int initTab();
void adicionaSimb(int class, const char* nome, const char*tipo, const char* esc, int qt, int ordem, int dp);
Simbolo* procuraNome(const char* nome);
void atribTipo(const char* tipo);
void atribEscopo(const char* esc);

#endif // __SIMBOLOS_H_
