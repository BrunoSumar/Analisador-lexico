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

// variáveis de controle e auxiliares
int ind; //indice do proximo espaço vazio da tabela de simbolos
int depth; // auxiliar para definir escopos
int quantP; // quantidade de parametros na função atual
int tam; // tamanho da tabela
int rec; // diz quando dentro do escopo de um record
int func; // diz qunado dentro do escopo de uma função
char tipo[50]; // tipo da expressão atual
char id[50]; // nome da variavel atual
char recNome[50]; // nome do record atual
Escopo *fAux;

// Tabela de Simbolos
Simbolo* tabSim;

// pilha de escopos
Escopo* pilha;

// Funções para manipular a tabela e a pilha
int initTab();
void adicionaSimb(int class, const char* nome, const char* tipo, const char* esc, int qt, int ordem);
Simbolo* procuraNome(const char* nome, const char* esc);
void atribTipo(const char* tipo);
void atribEscopo(const char* esc);
void atribQt(int qt);
Escopo* adicionaEscopoFim(const char* nome);
Escopo* popEscopo();
void debugSim();
void erroSemantico(int cod);
Escopo* escAtual();
void validaTipo(const char* nome, int array);
Simbolo* procuraCampo(const char* nome);
Simbolo* converteTipo(Simbolo* sim);
Escopo* pushEsc(Escopo* esc, const char* nome);
Escopo* popEsc(Escopo* esc);
void verificaPar();

// classificações
enum class{C_VAR, C_CONST, C_TYPE, C_FUNC, C_ARRAY, C_FIELD};

// Tipos
enum tipos{integer, real, record,};

#endif // __SIMBOLOS_H_
