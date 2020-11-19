#include "simbolos.h"


int initTab(){
  ind = 0;
  depth = -1;
  qt = 0;
  tam = 500;
  tabSim = (Simbolo*) malloc(sizeof(Simbolo)*tam);
  return (tabSim)?0:1;
}

void adicionaSimb(int class, const char* nome, const char*tipo, const char* esc, int qt, int ordem, int dp){
  if(ind>=tam){ // tabela cheia
    tam *= 2;
    tabSim = (Simbolo*) realloc(tabSim, tam);
    if(!tabSim)
      printf("\nErro no reajuste da tabela\n");
  }

  tabSim[ind].class = class;
  strcpy(tabSim[ind].nome, nome);
  strcpy(tabSim[ind].tipo, tipo);
  strcpy(tabSim[ind].escopo, esc);
  tabSim[ind].qt = qt;
  tabSim[ind].ordem = ordem;

  ind++;
}

Simbolo* procuraNome(const char* nome, const char* esc){
  int i;
  for(i=0;i<ind;i++){
    if(tabSim[i].dp>depth || (!strcmp(tabSim[i].escopo,esc)&&tabSim[i].dp==depth)){
      // escopo de nivel menor ou igual
      if(!strcmp(tabSim[i].nome, nome))
        return tabSim+i;
    }
  }
  reuturn NULL;
}

void atribTipo(const char* tipo){
  int i;
  for(i=0;i<ind;i++){
    if(tabSim[i].qt==depth && !strcmp(tabSim[i].tipo,"")){ // no nivel atual e tipo indefinido
      strcpy(tabSim[i].tipo,tipo);
    }
  }
}

void atribEscopo(const char* esc){
  int i;
  for(i=0;i<ind;i++){
    if(tabSim[i].qt==depth && !strcmp(tabSim[i].escopo,"")){ // no nivel atual e escopo indefinido
      strcpy(tabSim[i].escopo,esc);
    }
  }
}
