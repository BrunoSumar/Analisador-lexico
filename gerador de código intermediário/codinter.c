#include "codinter.h"

Instrucao* novaInstrucao(const char* op,const char* p1,const char* p2,const char* p3){
    Instrucao *temp = (Instrucao*) malloc(sizeof(Instrucao));
    strcpy(temp->op, op);
    strcpy(temp->p[0], p1);
    strcpy(temp->p[1], p2);
    strcpy(temp->p[2], p3);
    temp->next = NULL;
    if(!temp){
        printf("\nErro ao criar instrução.\n");
        exit(1);
    }
    return temp;
}

Instrucao* addInstrucao(Instrucao* pilha, Instrucao* novo){
    if(pilha && novo){
        novo->next = pilha->next;
        pilha->next = novo;
    }
    return novo;
}

Instrucao* avancaInstrucao(Instrucao* pilha){
    if(!pilha)
        return NULL;
    return pilha->next;
}

Instrucao* avancaInstrucaoN(Instrucao* pilha, int n){
    for(int i=0;i<n;i++){
        pilha = avancaInstrucao(pilha);
    }
    return pilha;
}

void liberaInstrucoes(Instrucao* i){
    if(i){
        Instrucao* temp = i->next;
        free(i);
        liberaInstrucoes(temp);
    }
}

void exibeInstrucoes(Instrucao* i){
    if(i){
        printf("%s    \t%s       \t%s      \t%s\n",i->op, i->p[0], i->p[1], i->p[2]);
        exibeInstrucoes(i->next);
    }
}

void initCodInter(){
    strcpy(opIn, "");
    raizIn = NULL;
    atualIn = NULL;
    fpar = 1;
    ifA = 0;
    whileA = 0;
}

void numToString(float n, char* str){
    int i = n;
    if((i-n) == 0){
        sprintf(str,"%d", i);
    }else{
        sprintf(str,"%f", n);
    }
}

void declaracaoConst(const char* id, const char* val){//LBL id p1 p2
    Instrucao *temp = novaInstrucao("LBL", id, "const", "");
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("Sw", "t$1", "$zero", id);
    atualIn = addInstrucao(atualIn, temp);
}

void declaracaoType(const char* id){//LBL id p1 p2
    Instrucao *temp = novaInstrucao("LBL", id, "type", "");
    atualIn = addInstrucao(atualIn, temp);
}

void declaracaoField(const char* id, int offset){//LBL id p1 p2
    char off[50];
    numToString(offset*INTER_VAR_TAM, off);
    Instrucao *temp = novaInstrucao("LBL", id, "field", off);
    addInstrucao(atualIn, temp);
}

void declaracaoVar(const char* id){
    Instrucao *temp = novaInstrucao("LBL", id, "var", "");
    atualIn = addInstrucao(atualIn, temp);
}

void declaracaoFVar(const char* id, int n, int q){
    char l[50], p[10], pa[10];
    numToString(n, l);
    strcat(l,id);
    Instrucao *temp = novaInstrucao("LBL", l, "var", "");
    atualIn = addInstrucao(atualIn, temp);
    if(q>0){
        strcpy(p,"$p");
        numToString(q, pa);
        strcat(p,pa);
        temp = novaInstrucao("SW", p, "$zero", l);
        atualIn = addInstrucao(atualIn, temp);
    }
}

void declaraProgram(const char* p){
    raizIn = novaInstrucao("LBL", p, "program", "");
    atualIn = raizIn;
}

void declaracaoFunc(const char* id){
    Instrucao *temp = novaInstrucao("LBL", id, "", "");
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("SW", "$link", "$zero", "$stack");//salva o retorno na pilha de memoria e avança
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("ADD", "$stack", "$stack", "4");
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("JR", "$t0", "", "");
    addInstrucao(atualIn, temp);
    temp = novaInstrucao("LW", "$t0", "$zero", "$stack");
    addInstrucao(atualIn, temp);
    temp = novaInstrucao("SUB", "$stack", "$tack", id);//retaura a pilha e o endereço de retorno
    addInstrucao(atualIn, temp);
}

void expMat(){ // parametro
    Instrucao *temp;
    if(!strcmp(opIn,"")){
        temp = novaInstrucao("OR", "$t0", "$zero", "$t1");
        atualIn = addInstrucao(atualIn, temp);
    }else {
        temp = novaInstrucao(opIn, "$t0", "$t0", "$t1");
        atualIn = addInstrucao(atualIn, temp);
        strcpy(opIn, "");
    }
}

void expLog(){
    Instrucao *temp;
    if(!strcmp(opIn,"")){
        temp = novaInstrucao("OR", "$t4", "$zero", "$t0");
        atualIn = addInstrucao(atualIn, temp);
    }else {
        if(!strcmp(opIn,"NOR")){
            temp = novaInstrucao(opIn, "$t4", "$t4", "$zero");
            atualIn = addInstrucao(atualIn, temp);
            strcpy(opIn,"SUB");
        }
        temp = novaInstrucao(opIn, "$t4", "$t4", "$t0");
        atualIn = addInstrucao(atualIn, temp);
        strcpy(opIn, "");
    }
}

void blocoIf(){
    char l1[50], l2[50], aux[10];
    numToString(lbl++,aux);
    strcpy(l1,"#lbl");
    strcat(l1,aux);
    numToString(lbl++,aux);
    strcpy(l2,"#lbl");
    strcat(l2,aux);
    Instrucao *temp = novaInstrucao("BEQ", l1, "$zero", "$t4");//$t4 é o t temporario que guarda o resultado da expressão condicional
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("LBL", l2, "","");
    addInstrucao(atualIn, temp);
    temp = novaInstrucao("LBL", l1, "","");
    addInstrucao(atualIn, temp);
    temp = novaInstrucao("J", l2, "", "");
    addInstrucao(atualIn, temp);

}

void blocoWhile(){
    char l1[50], l2[50], aux[10];
    numToString(lbl++,aux);
    strcpy(l1,"#lbl");
    strcat(l1,aux);
    numToString(lbl++,aux);
    strcpy(l2,"#lbl");
    strcat(l2,aux);
    Instrucao *temp = novaInstrucao("LBL", l1, "", "");
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("LBL", l2, "","");
    addInstrucao(atualIn, temp);
    temp = novaInstrucao("J", l1, "","");
    addInstrucao(atualIn, temp);
    temp = novaInstrucao("BEQ", l2, "$zero", "$t4");
    addInstrucao(atualIn, temp);
}

void atribuicao(const char* id){
    Instrucao *temp = novaInstrucao("OR", id, "$zero", "$t0");//t0 registrdor temporario para quardar 'valor'
    addInstrucao(atualIn, temp);
}

void chamadaFunc(const char*id){
    Instrucao *temp = novaInstrucao("OR", "$t0", "$zero", "$r");
    addInstrucao(atualIn, temp);
    temp = novaInstrucao("JAL", id, "", "");
    addInstrucao(atualIn, temp);
}

void passaPar(int ord){
    char a[50] = "$p", n[50];
    numToString(ord, n);
    strcat(a,n);
    Instrucao *temp = novaInstrucao("OR", a, "$zero", "$t1");
    atualIn = addInstrucao(atualIn, temp);

}



void parNum(){
    char n[50];
    numToString(num, n);
    Instrucao *temp = novaInstrucao("ORI", "$t1", "$zero", n);
    atualIn = addInstrucao(atualIn, temp);
}

void parNome1(const char *id){
    Instrucao *temp = novaInstrucao("ADD", "$t4", "$zero", id);
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("LW", "$t1", "$zero", "$t4");
    atualIn = addInstrucao(atualIn, temp);
}

void parNome2(const char *id){
    Instrucao *temp = novaInstrucao("ADD", "$t4", "$t4", id);
    atualIn = addInstrucao(atualIn, temp);
}
void parNome3(const char *id){
    Instrucao *temp = novaInstrucao("MULT", "$t1", "$t1", "4");
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("ADD", "$t4", "$t4", id);
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("ADD", "$t4", "$t4", "$t1");
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("LW", "$t1", "$zero", "$t4");
    atualIn = addInstrucao(atualIn, temp);
}

void resetaId(const char*id){
    Instrucao *temp = novaInstrucao("OR", id, "$zero", "$zero");
    atualIn = addInstrucao(atualIn, temp);
}

void write(const char* c){
    Instrucao *temp = novaInstrucao("ORI", "$s", "$zero", "1");
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("ORI", "$io", "$zero", c);
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("syscall", "", "", "");
    atualIn = addInstrucao(atualIn, temp);
}

void read(const char* c){
    Instrucao *temp = novaInstrucao("ORI", "$s", "$zero", "0");
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("syscall", "", "", "");
    atualIn = addInstrucao(atualIn, temp);
    temp = novaInstrucao("OR", c,"$zero", "$io");
    atualIn = addInstrucao(atualIn, temp);
}


void calculaTam(){}//calcula o tam de uma variavel
void calculaOffset(){}//somo o tam dos fields q vem antes
