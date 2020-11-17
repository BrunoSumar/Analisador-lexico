#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "escopo.h"

Var* criaVar(int tipoI, char* nome, char* tipoV){ // criar novo nó da lista de variaveis
  Var* temp = (Var*) malloc(sizeof(Var));
  temp->tipoId = tipoI;
  temp->nome = strdup(nome);
  temp->tipoVar = strdup(tipoV);
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
  filho->next = pai->subVar;
  pai->subVar = filho;
}

void adicionaVar(Escopo* esc, Var* var){
  var->next = esc->simbolos;
  esc->simbolos = var;
}

void adicionaEscopo(Escopo*pai, Escopo* filho){
  filho->pai = pai;
  filho->irmaos = pai->filhos;
  pai->filhos = filho;
}

Var* procuraVar(Escopo* esc, char* nome){
  if(!esc)
    return NULL;//nome não escontrado
  Var* temp = esc->simbolos;
  while(temp){
    if(!strcmp(temp->nome, nome))
      return temp;//variavel econtrada
  }
  return procuraVar(esc->pai, nome);// procura no escopo pai
}

void apagaListaVar(Var* v){
  while (v) {
    if(v->subVar)
      apagaListaVar(v->subVar);
    Var* temp = v->next;
    free(v->nome);
    free(v->tipoVar);
    free(v);
    v = temp;
  }
}

void apagaEscopo(Escopo* e){
  while(e){
    if(e->filhos)
      apagaEscopo(e->filhos);
    Escopo* temp = e->irmaos;
    apagaListaVar(e->simbolos);
    free(e);
    e = temp;
  }
}

Escopo* raizEscopo(Escopo* esc){
  while(esc->pai)
    esc = esc->pai;
  return esc;
}

void atribTipoVar(Var* v, char* tipo){
  while(v){
    if(!v->tipoVar)
      v->tipoVar = strdup(tipo);
    v = v->next;
  }
}
