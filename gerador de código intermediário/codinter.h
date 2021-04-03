#ifndef __CODINTER_H_
#define __CODINTER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simbolos.h"


typedef struct inst{
    char op[10]; //operação
    char p[3][50]; //3 parâmetros
    struct inst* next; //próxima instrução
}Instrucao;

/* Variáveis auxiliares  */
#define INTER_VAR_TAM 4 //tamanho em bytes reservado para uma variavel nessa linguagem
Instrucao* raizIn; //Inicio das instruções
Instrucao* atualIn; //Instrução atual
char opIn[10];
float numPar;
int varTam;
int fOffset;
int nFunc;
int lbl;
int fpar;
int ifA;
int whileA;


/* funções de manipulação da lista encadeada de intruções */
void initCodInter(); //Inicializa variáveis auxiliares
Instrucao* novaInstrucao(const char* op,const char* p1,const char* p2,const char* p3); //Instancia nova instrução
Instrucao* addInstrucao(Instrucao* pilha, Instrucao* novo); //Coloca instrução na pilha
Instrucao* avancaInstrucaoN(Instrucao* pilha, int n); //avaça n posições na pilha
Instrucao* avancaInstrucao(Instrucao* pilha); //Retorna proxima instrução
void exibeInstrucoes(Instrucao* i); //Printa lista de instruções
void liberaInstrucoes(Instrucao* i); //Libera memória da lista
void numToString(float n, char* str);
void declaracaoConst(const char* id, const char* val);//LBL id p1 p2
void declaracaoVar(const char* id);
void declaracaoFVar(const char* id, int n, int q);
void declaracaoFunc(const char* id);
void declaraProgram(const char* id);
void declaracaoType(const char* id);
void declaracaoField(const char* idn, int offset);
void blocoIf();
void blocoWhile();
void atribuicao(const char* id);
void chamadaFunc(const char*id);
void parNome1(const char *id);
void parNome2(const char *id);
void parNome3(const char *id);
void resetaId(const char*id);
void parNum();
void expMat(); // parametro
void expLog();
void passaPar();

/*
  Cojunto de instruções do código intermediário de três endereços baseada em MIPS

  ADD dest id1 id2  #dest = id1 + id2
  SUB dest id1 id2  #dest = id1 - id2
  DIV dest id1 id2  #dest = id1 / id2
  MULT dest id1 id2  #dest = id1 * id2
  BEQ label id1 id2  #desvia para label se id1 == id2
  AND dest id1 id2  #dest = id1 & id2
  OR dest id1 id2  #dest = id1 | id2
  ORI dest id1 i  #dest = id1 | i
  NOR dest id1 id2  #dest = ~(id1 | id2)
  SLT dest id1 id2  #dest = ((id1 < id2))? 1 : 0
  SGT dest id1 id2  #dest = ((id1 > id2))? 1 : 0
  J label  #salta para label
  JAL label  #salta para label e salva enderenço em $link
  JR id  #salta para endereço em id
  LW dest i id  #dest = conteúdo de endereço id + i
  SW origem i id  #endereço id + i = origem
  LBL label id1 id2  #declara um label id1 e id2 definem o que o label representa

  Ids que iniciam com '$' são registradores de valores auxiliares
    $t0, $t1...  registradores temporários
    $r recebe o resultado de uma função
    $s recebe código para chamada do syscall
    $io entrada e saida por syscalls
    $p0, $p1...  recebem parâmetros de funções
    $link recebe o endereço de onde a operação JAL foi chamada
    $stack  guarda o topo da pilha de memória do programa
*/

/* Funções de  substituição de código */



#endif // __CODINTER_H_
