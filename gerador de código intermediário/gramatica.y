%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simbolos.h"
#include "codinter.h"

int yyerror();
int yylex();

extern int yylineno;
extern int count;

%}

%union {char *str;double fl;char* nome; char* tipo;}
%define parse.error verbose

%token PROGRAM
%token BEGIN_
%token END
%token CONST
%token TYPE
%token VAR
%token <tipo> INTEGER
%token <tipo> REAL
%token <tipo> ARRAY
%token <tipo> RECORD
%token OF
%token FUNCTION
%token WHILE
%token IF
%token THEN
%token ELSE
%token WRITE
%token READ

// Valores, indetificadores e simbolos
%token ATRIBUICAO
%token ABRE_PARENTESES
%token FECHA_PARENTESES
%token VIRGULA
%token PONTO
%token ABRE_COLCHETES
%token FECHA_COLCHETES
%token <str> IDENTIFICADOR
%token PONTO_E_VIRGULA
%token DOIS_PONTOS
%token <str> CONST_STRING
%token <fl> NUMERO
%token MAIOR_QUE
%token MENOR_QUE
%token IGUAL
%token SOMA
%token SUBTRACAO
%token MULT
%token EXCLAMACAO
%token BARRA

//Token sem classificação
%token ERRO

%%

programa        : id_program PONTO_E_VIRGULA corpo
                | error PONTO_E_VIRGULA corpo
                ;

id_program      : PROGRAM IDENTIFICADOR
{
        declaraProgram($2);
}
                ;

corpo           : declaracoes BEGIN_ lista_com END 
                | error END
                ;

declaracoes     : lista_def lista_func
                | error lista_func
                | /* epsilon */                            
                ;

lista_def       : def_const def_tipos def_var
{
        atribEscopo("#global");
}
                ;

def_const       : CONST lista_const
                | error
                | /* epsilon */                                       
                ;

def_tipos       : TYPE lista_tipos
                | error
                | /* epsilon */        
                ;

def_var         : VAR lista_def_var /*  diferente da regra */
                | error
                | /* epsilon */            
                ;

lista_const     : constante lista_const   
                | constante             
                ;

constante       : IDENTIFICADOR IGUAL const_valor PONTO_E_VIRGULA
{
        if(!procuraNome($1, escAtual()->nome)){
                adicionaSimb(C_CONST, $1, tipo, escAtual()->nome, depth, -1);
                if(strcmp(tipo,"const_string")){
                   numToString(num,id);
                }
                declaracaoConst($1, id);
        }
        else
                erroSemantico(1);
        strcpy(tipo, "");
}
                | error PONTO_E_VIRGULA
                ;

const_valor     : CONST_STRING
{
        strcpy(id, $1);
        strcpy(tipo, "const_string");
}
                | exp_mat
                | error 
                ;

numero          : NUMERO
{
        int aux = $1;
        num = $1;
        if(aux-$1==0){
                if(!strcmp(tipo,""))
                        strcpy(tipo,"integer");
                else if(strcmp(tipo, "integer") && strcmp(tipo, "real"))
                                erroSemantico(3);
        }else{
                if(!strcmp(tipo,"")||!strcmp(tipo,"real")||!strcmp(tipo,"integer"))
                                strcpy(tipo, "real");
                else
                        erroSemantico(3);
        }
}
                ;

lista_tipos     : tipo PONTO_E_VIRGULA lista_tipos
                | tipo PONTO_E_VIRGULA        /*  diferente da regra */
                | error PONTO_E_VIRGULA lista_tipos
                ;

tipo            : id_tipo IGUAL tipo_dado
{
        declaracaoType(id);
        while(atualIn && atualIn->next)
                atualIn = avancaInstrucao(atualIn);
        strcpy(id,"");
        varTam = 0;
}
                | error  tipo_dado
                ;

id_tipo         : IDENTIFICADOR
{
        if(!procuraNome($1, escAtual()->nome))
                adicionaSimb(C_TYPE, $1, "", escAtual()->nome, depth, -1);
        else
                erroSemantico(1);
        strcpy(id,$1);
}
                ;

lista_var       : variavel PONTO_E_VIRGULA lista_var
                | variavel
                | error PONTO_E_VIRGULA
                ;

lista_def_var   : variavel PONTO_E_VIRGULA lista_def_var
                | variavel PONTO_E_VIRGULA                                
                | error PONTO_E_VIRGULA
                ;

variavel        : lista_id DOIS_PONTOS tipo_dado
                ;

lista_id        : IDENTIFICADOR VIRGULA lista_id
{
        if(!procuraNome($1, escAtual()->nome))
                adicionaSimb(rec?C_FIELD:(funcPar?C_PAR:C_VAR), $1, "",escAtual()->nome,depth,!funcPar?-1:++quantP);
        else
                erroSemantico(1);
        if(rec){
                declaracaoField($1, fOffset);
                fOffset++;
        }else if(!func){
                declaracaoVar($1);
        }else {
                declaracaoFVar($1, nFunc, quantP);
        }
}
                | IDENTIFICADOR
{
        if(!procuraNome($1, escAtual()->nome))
                adicionaSimb(rec?C_FIELD:(funcPar?C_PAR:C_VAR), $1, "",escAtual()->nome,depth,!funcPar?-1:++quantP);
        else
                erroSemantico(1);
        if(rec){
                declaracaoField($1, fOffset);
                fOffset++;
        }else if(!func){
                declaracaoVar($1);
        }else {
                declaracaoFVar($1, nFunc, quantP);
        }
}
                | error
                ;

tipo_dado       : INTEGER
{
        atribTipo($1);
}
                | REAL
{
        atribTipo($1);
}
                | ARRAY ABRE_COLCHETES numero FECHA_COLCHETES OF tipo_dado
{
        tabSim[ind-1].qt = 0;
        atribTipo(yylval.tipo);
        varTam+=INTER_VAR_TAM*(num-1);
}
                | record lista_def_var END    /*  diferente da regra */
{
        rec--;
        depth++;
        atribTipo("record");
        pilha = popEscopo();
}
                | IDENTIFICADOR
{
        Simbolo* temp = procuraNome($1, escAtual()->nome);
        if(temp && temp->class==C_TYPE)
                atribTipo($1);
        else{
                erroSemantico(2);
                atribTipo("#erro");
        }
}
                | error 
                ;

record          : RECORD
{
        rec++;
        fOffset = 0;
        pilha = adicionaEscopoFim(tabSim[ind-1].nome);
}
                ;

lista_func      : funcao lista_func          
                | /*  epsilon */                 
                | error 
                ;

funcao          : nome_funcao bloco_funcao
{
        func--;
        atribEscopo(escAtual()->nome);
        pilha = popEscopo();
        atualIn = avancaInstrucaoN(atualIn,3);
}
                | error 
                ;

nome_funcao     : escopo_funcao ABRE_PARENTESES lista_var FECHA_PARENTESES dp_funcao tipo_funcao
{
        depth--;
        atribQt(quantP);
        quantP = -1;
        depth++;
        depth++;
        funcPar = 0;
}
                | escopo_funcao ABRE_PARENTESES FECHA_PARENTESES dp_funcao tipo_funcao
{
        depth--;
        atribQt(0);
        quantP = -1;
        depth++;
        depth++;
        funcPar = 0;
}
                | error 
                ;

escopo_funcao   : FUNCTION IDENTIFICADOR
{
        declaracaoFunc($2);
        nFunc++;
        quantP = 0;
        func++;
        funcPar = 1;
        if(!procuraNome($2, escAtual()->nome)){
                depth--;
                adicionaSimb(C_FUNC,$2,"",escAtual()->nome,depth, -1);
                depth++;
                pilha = adicionaEscopoFim($2);
        }else
                erroSemantico(1);
}
                ;

dp_funcao         : DOIS_PONTOS
{
        depth--;
}
                ;


tipo_funcao     : tipo_dado
{
        depth++;
}
                ;

bloco_funcao    : def_var bloco             
                | bloco            
                | error 
                ;

bloco           : BEGIN_ lista_com END
{
        if(ifA){
                ifA--;
                atualIn = avancaInstrucaoN(atualIn, 2);
        }
}
                | comando
{
        strcpy(tipo, "");
}
                | error 
                ;

lista_com       : comando PONTO_E_VIRGULA lista_com          
                | /*  epsilon */
                | error 
                ;

comando         : ini_atrib nome_atrib valor
{
        if(!strcmp(tipo,"#erro"))
                erroSemantico(3);
        strcpy(tipo,"");
        atualIn = avancaInstrucao(atualIn);
}

                | while  condicao bloco
{
        strcpy(tipo,"");
        atualIn = avancaInstrucaoN(atualIn, 2);
}
                | _if exp_logica then bloco else
{
        strcpy(tipo,"");
}
                | WRITE const_valor
{
        write(id);
        strcpy(tipo,"");
}
               | READ nome
{
        read(id);
        strcpy(tipo,"");
}
                | error
{
        strcpy(tipo,"");
}
                ;

ini_atrib       : %empty
{
        atrib = 1;
}
                ;

nome_atrib      : nome ATRIBUICAO
{
        corrigeId(id);
        atribuicao(id);
        resetaId("$t4");
        atrib = 0;
}
                ;

_if              : IF
{
        ifA++;
}
                ;


while           : WHILE
{
        whileA++;
        blocoWhile();
}

then            : THEN
{
        blocoIf();
        strcpy(id,"");
}
                ;

condicao        : exp_logica
{
        strcpy(tipo, "");
        if(whileA){
                atualIn = avancaInstrucaoN(atualIn,1);
                whileA--;
        }
}
                ;

else           : ELSE bloco
{
        atualIn = avancaInstrucaoN(atualIn,1);
}
                | /*  epsilon */
{
        atualIn = avancaInstrucaoN(atualIn,1);
}
                | error
                ;

valor           : exp_mat                                  
                | id_func lista_param
{
        Simbolo* temp = fAux? procuraNome(fAux->nome, escAtual()->nome):NULL;
        if(!temp)
                erroSemantico(6);
        if(temp && quantP!=temp->qt)
                erroSemantico(8);
        fAux = popEsc(fAux);
        func--;
        quantP = -1;
        strcpy(id,"");
        atualIn = avancaInstrucaoN(atualIn,2);
}
                ;

id_func         : IDENTIFICADOR
{
        Simbolo* temp = procuraNome($1, escAtual()->nome);
        if(temp && temp->class==C_FUNC){
                fAux = pushEsc(fAux, $1);
                quantP=0;
        }else
                erroSemantico(6);
        func++;
        strcpy(id,$1);
        chamadaFunc(id);
}
                ;

lista_param     : ABRE_PARENTESES lista_nome FECHA_PARENTESES   
                | error FECHA_PARENTESES
                ;

lista_nome      : func_par VIRGULA lista_nome
{
        passaPar(quantP);
}
                | func_par
{
        passaPar(quantP);
}
                | /*  epsilon */                                 
                ;

func_par        : nome
{
        quantP++;
        verificaPar();
        strcpy(tipo,"");
}
                | numero
{
        quantP++;
        verificaPar();
        strcpy(tipo,"");
}
                ;

exp_logica      : exp_mat op_logico exp_logica
{
        expLog();
}
                | exp_mat
{
        expLog();
}
                ;

exp_mat         : parametro op_mat exp_mat                      
                | parametro                                     
                ;

parametro       : nome
{
        expMat();
}
                | numero
{
        parNum();
        expMat();
}
                ;

reset_nome      : /*  epsilon */
{
        //resetaId("$t4");
}
                ;

op_logico       : MAIOR_QUE
{
        strcpy(opIn,"SLT");
}
                | MENOR_QUE
{
        strcpy(opIn,"SGT");
}
                | IGUAL
{
        strcpy(opIn,"NOR");
}
                | EXCLAMACAO
{
        strcpy(opIn,"SUB");
}
                ;

op_mat          : SOMA
{
        strcpy(opIn,"ADD");
}
                | SUBTRACAO
{
        strcpy(opIn,"SUB");
}
                | MULT
{
        strcpy(opIn,"MULT");
}
                | BARRA
{
        strcpy(opIn,"DIV");
}
                ;

nome            : IDENTIFICADOR
{
        validaTipo($1, 1);
        strcpy(recNome, "");
        strcpy(id, $1);
        corrigeId(id);
        if(!atrib) parNome1(id);
}
                | id_record nome
                | id_array parametro FECHA_COLCHETES
{
        strcpy(tipo,id);
        corrigeId(array);
        if(!atrib) parNome2(array);
}
                | error
                ;

id_record       : IDENTIFICADOR PONTO
{
        Simbolo* temp;
        if(!strcmp(recNome, "")){
                 temp = procuraNome($1, escAtual()->nome);
                 temp = converteTipo(temp);
                 if(temp && !strcmp(temp->tipo, "record"))
                         strcpy(recNome, $1);
                 else{
                         strcpy(tipo,"#erro");
                         erroSemantico(5);
                 }
        }else{
                 temp = procuraCampo($1);
                 temp = converteTipo(temp);
                 if(temp && !strcmp(temp->tipo, "record"))
                         strcpy(recNome, $1);
                 else{
                         strcpy(tipo,"#erro");
                         erroSemantico(5);
                 }
        }
        strcpy(id,$1);
        corrigeId(id);
        if(!atrib) parNome2(id);
}
                ;

id_array        : IDENTIFICADOR ABRE_COLCHETES
{
        validaTipo($1, 0);
        strcpy(id,tipo);
        strcpy(tipo, "integer");
        strcpy(array, $1);
}
                ;


%%


int yyerror(char const *s){
        count++;
        printf("\n>> Linha: %d %s\n", yylineno, s);
}
int count = 0;

int main (void) {
        initTab();
        initCodInter();

        yyparse();
        /* debugSim(); */

        if(!count)
                exibeInstrucoes(raizIn);
        else
                printf("\n\nErro ao gerar código Intermediário.\n");

        liberaInstrucoes(raizIn);
        return 0;
}


/*
 (eepitch-shell)
 (eepitch-kill)
 (eepitch-shell)
make
make run
*/
