#ifndef __ESCOPO_H_
#define __ESCOPO_H_

typedef struct var{
  int tipoId; // tipo do identificador (e.g função, variavel)
  char* nome; // nome do indetificador
  char* tipoVar; // tipo do dado(e.g. integer, char)
  struct var* subVar; // lista com campos ou parametros
  struct var* next; // ponteiro para uma proxima variavel na lista encadeada
} Var;

typedef struct escopo{
  struct escopo* pai; // pai do nó atual
  Var* simbolos; // tabela de simbolos do escopo atual
  struct escopo* filhos; // ponteiro para escopo filho
  struct escopo* irmaos; // ponteiro para escopo de mesmo nivel
}Escopo;

Var* criaVar(int tipoI, char* nome, char* tipoV); // criar novo nó da lista de variaveis
Escopo* criaEscopo(Escopo* pai);
void adicionaSubvar(Var* pai, Var* filho);
void adicionaVar(Escopo* esc, Var* var);
void adicionaEscopo(Escopo*pai, Escopo* filho);
Var* procuraVar(Escopo* esc, char* nome);
void apagaListaVar(Var* v);
void apagaEscopo(Escopo* e);
Escopo* raizEscopo(Escopo* esc);

#endif
