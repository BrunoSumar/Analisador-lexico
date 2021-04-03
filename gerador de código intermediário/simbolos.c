#include "simbolos.h"


int initTab(){
  ind = 0;
  depth = -1;
  quantP = -1;
  tam = 100;
  rec = 0;
  func = 0;
  funcPar = 0;
  atrib = 0;
  strcpy(tipo, "");
  strcpy(id, "");
  strcpy(recNome, "");
  fAux = NULL;

  tabSim = (Simbolo*) malloc(sizeof(Simbolo)*tam);

  pilha = (Escopo*) malloc(sizeof(Escopo));
  strcpy(pilha->nome, "#global");
  pilha->next = NULL;

  return (tabSim && pilha)?0:1;
}

void adicionaSimb(int class, const char* nome, const char*tipo, const char* esc, int qt, int ordem){
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

Escopo* escopoPai(const char* esc){
  Escopo* aux = pilha;
  while(aux){
    if(!strcmp(aux->nome,esc)){
      return aux->next;
    }
    aux = aux->next;
  }
  return aux;
}

Simbolo* procuraNome(const char* nome, const char* esc){
  int i;
  if(!esc)
    return NULL;
  for(i=0;i<ind;i++){
    if(!strcmp(tabSim[i].nome, nome)&&!strcmp(tabSim[i].escopo,esc)){
      if(!strcmp(tabSim[i].escopo,"#global")||procuraNome(tabSim[i].escopo,escopoPai(esc)->nome))
        return tabSim + i;
    }
  }
  if(strcmp(esc,"#global"))
    return procuraNome(nome, escopoPai(esc)->nome);
  else
    return NULL;

}

Simbolo* procuraCampo(const char* nome){
  Simbolo *temp = procuraNome(recNome, escAtual()->nome);
  if(!temp) return NULL;
  int i;
  for(i=0;i<ind;i++){
    if(tabSim[i].class==C_FIELD && !strcmp(tabSim[i].nome, nome) && !strcmp(tabSim[i].escopo,temp->tipo)){
        return tabSim + i;
    }
  }
  return NULL;
}

void atribTipo(const char* tipo){
  int i;
  for(i=0;i<ind;i++){
    if((tabSim[i].qt==depth) && !strcmp(tabSim[i].tipo,"")){ // no nivel atual e tipo indefinido
      strcpy(tabSim[i].tipo,tipo);
    }
  }
}

void atribEscopo(const char* esc){
  int i;
  for(i=0;i<ind;i++){
    if(tabSim[i].qt==depth && !strcmp(tabSim[i].escopo,"#atual")){ // no nivel atual e escopo indefinido
      strcpy(tabSim[i].escopo,esc);
    }
  }
}

void atribQt(int qt){
  int i;
  for(i=0;i<ind;i++){
    if(tabSim[i].qt==depth && (tabSim[i].class==C_FUNC)){ // no nivel atual e escopo indefinido
      tabSim[i].qt = qt;
    }
  }
}

void atribClass(int a){
 
}

Escopo* adicionaEscopoFim(const char* nome){
  Escopo* temp = (Escopo*) malloc(sizeof(Escopo));
  strcpy(temp->nome, nome);
  temp->next = pilha;
  return temp;
}


Escopo* popEscopo(){
  Escopo* temp = pilha;
  if(temp && temp->next){
    temp = temp->next;
    free(pilha);
  }
  return temp;
}

void debugSim(){
  int i;
  printf("\n----------Tabela de Simbolos-----------\n");
  for(i=0;i<ind;i++){
    printf("\n[ %d\t, %s     \t, %s      \t, %s     \t, %d\t, %d\t]",
           tabSim[i].class, tabSim[i].nome, tabSim[i].tipo, tabSim[i].escopo, tabSim[i].qt, tabSim[i].ordem);
  }
  Escopo *temp = pilha;
  printf("\n----------Pilha de escopos-------------\n\n");
  while(temp){
    printf("> %s ", temp->nome);
    temp = temp->next;
  }
  printf("\n---------------------------------------\n");
}

void erroSemantico(int cod){
  extern int yylineno;
  extern int count;
  count++;
  printf("\n>Erro semantico codigo: %d, linha %d ", cod, yylineno);
  /* debugSim(); */
  /* 1: nome já declarado */
  /* 2: variavel não declarada */
  /* 3: tipos diferentes */
  /* 4: uso de indice em não array */
  /* 5: campo de registro não declarado */
  /* 6: parametros numa variavel que não é função*/
  /* 7: parametro errado*/
  /* 8: quantidade errada de parametros */
}


Escopo* escAtual(){
  return pilha;
}

void validaTipo(const char *nome, int array){
  if(!strcmp(tipo,"#erro"))
    return;

  Simbolo* temp;
  if(strcmp(recNome,"")){
    temp = procuraCampo(nome);
  }else{
    temp = procuraNome(nome, escAtual()->nome);
  }

  if(!temp){
    erroSemantico(2);
    return;
  }

  temp = converteTipo(temp);

  if(!array && temp->qt){
    erroSemantico(4);
    return;
  }

  if(!strcmp(temp->tipo,tipo)||!strcmp(tipo, "")){
    strcpy(tipo, temp->tipo);
  }else{
    strcpy(tipo, "#erro");
  }
}

Simbolo* converteTipo(Simbolo* sim){
  Simbolo* temp = sim;
  if(!temp)
    return NULL;

  if(strcmp(temp->tipo,"integer")&&strcmp(temp->tipo,"real")&&strcmp(temp->tipo,"const_string")&&strcmp(temp->tipo,"record")&&strcmp(temp->tipo,"")){
    temp = procuraNome(temp->tipo, escAtual()->nome);
  }
  return temp;
}

Escopo* pushEsc(Escopo* esc, const char* nome){
  Escopo* temp = (Escopo*) malloc(sizeof(Escopo));
  strcpy(temp->nome, nome);
  temp->next = esc;
  return temp;
}

Escopo* popEsc(Escopo* esc){
  Escopo* temp = esc;
  if(esc){
    temp = esc->next;
    free(esc);
  }
  return temp;
}

void verificaPar(){
  int i;
  Simbolo* temp = NULL;
  for(i=0;i<ind;i++){
    temp = converteTipo(tabSim+i);
    if(tabSim[i].ordem==quantP && !strcmp(fAux->nome,tabSim[i].escopo) && !strcmp(temp->tipo,tipo))
      return;
  }
  erroSemantico(7);
}

void corrigeId(char *id){
  Simbolo* temp = procuraNome(id,"#global");
  if(!temp && (id[0]<'0'||id[0]>'9')){
    extern int nFunc;
    char a[50];
    sprintf(a,"%d",nFunc);
    strcat(a,id);
    strcpy(id,a);
  }
}
