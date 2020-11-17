#include <stdlib.h>
#include <string.h>

extern void yyparse();
extern int count;

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

Var* criaVar(int tipoI, char* nome, char* tipoV){ // criar novo nó da lista de variaveis
  Var* temp = (Var*) malloc(sizeof(Var));
  temp->tipoId = tipoI;
  strcpy(temp->nome, nome);
  strcpy(temp->tipoVar, tipoV);
  temp->subVar = NULL;
  temp->next= NULL;
  return temp;
}

Escopo* criaEscopo(Escopo* pai){
  Escopo* temp = (Escopo*) malloc(sizeof(Escopo));
  temp->pai = pai;
  temp->simbolos = NULL;
  temp->filhos = NULL;
  temp->irmaos = NULL;
  return temp;
}

void adicionaSubvar(Var* pai, Var* filho){
 
}
void adicionaVar(Escopo* esc, Var* var){
  var->next = esc->simbolos;
  esc->simbolos = var;
}
