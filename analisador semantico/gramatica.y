%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
%token INTEGER
%token REAL
%token ARRAY
%token RECORD
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
%token CONST_STRING
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

programa        : PROGRAM IDENTIFICADOR PONTO_E_VIRGULA corpo
{
        printf("programa\n");
}
                | error PONTO_E_VIRGULA corpo  
                ;

corpo           : declaracoes BEGIN_ lista_com END 
                | error END
                ;

declaracoes     : def_const def_tipos def_var lista_func   
                | error lista_func 
                | /* epsilon */                            
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
                | error PONTO_E_VIRGULA
                ;

const_valor     : CONST_STRING    
                | exp_mat      
                | error 
                ;

numero          : NUMERO                          
                ;

lista_tipos     : tipo PONTO_E_VIRGULA lista_tipos
                | tipo PONTO_E_VIRGULA        /*  diferente da regra */
                | error PONTO_E_VIRGULA lista_tipos
                ;

tipo            : IDENTIFICADOR IGUAL tipo_dado
{
        printf("tipo\n");
}
                | error  tipo_dado 
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
{
        //atribFilhoEsc(escAtual, escTemp);
}
                ;

lista_id        : IDENTIFICADOR VIRGULA lista_id
{
}
                | IDENTIFICADOR
{
        printf("a");
}
                | error
                ;

tipo_dado       : INTEGER                       
                | REAL                      
                | ARRAY ABRE_COLCHETES numero FECHA_COLCHETES OF tipo_dado   
                | RECORD lista_def_var END    /*  diferente da regra */
{
}
                | IDENTIFICADOR
{
}
                | error 
                ;

lista_func      : funcao lista_func          
                | /*  epsilon */                 
                | error 
                ;

funcao          : nome_funcao bloco_funcao        
                | error 
                ;

nome_funcao     : FUNCTION IDENTIFICADOR ABRE_PARENTESES lista_var FECHA_PARENTESES DOIS_PONTOS tipo_dado   
                | FUNCTION IDENTIFICADOR ABRE_PARENTESES FECHA_PARENTESES DOIS_PONTOS tipo_dado   
                | error 
                ;

bloco_funcao    : def_var bloco             
                | bloco            
                | error 
                ;

bloco           : BEGIN_ lista_com END          
                | comando                     
                | error 
                ;

lista_com       : comando PONTO_E_VIRGULA lista_com          
                | /*  epsilon */
                | error 
                ;

comando         : nome ATRIBUICAO valor                    
                | WHILE  exp_logica bloco                  
                | IF exp_logica THEN bloco else              
                | WRITE const_valor                   
                | READ nome                              
                | error 
                ;

 else           : ELSE bloco                        
                | /*  epsilon */                       
                | error 
                ;

valor           : exp_mat                                  
                | IDENTIFICADOR lista_param                   
                ;

lista_param     : ABRE_PARENTESES lista_nome FECHA_PARENTESES   
                | error FECHA_PARENTESES
                ;

lista_nome      : parametro VIRGULA lista_nome      
                | parametro                                      
                | /*  epsilon */                                 
                ;

exp_logica      : exp_mat op_logico exp_logica                
                | exp_mat                                      
                ;

exp_mat         : parametro op_mat exp_mat                      
                | parametro                                     
                ;

parametro       : nome                                          
                | numero                                        
                ;

op_logico       : MAIOR_QUE                   
                | MENOR_QUE                   
                | IGUAL                       
                | EXCLAMACAO                  
                ;

op_mat          : SOMA                        
                | SUBTRACAO                   
                | MULT                        
                | BARRA                       
                ;

nome            : IDENTIFICADOR                                            
                | IDENTIFICADOR PONTO nome                                 
                | IDENTIFICADOR ABRE_COLCHETES parametro FECHA_COLCHETES   
                | error            
                ;

%%


int yyerror(char const *s){
        count++;
        printf("\n>> Linha: %d %s\n", yylineno, s);
}
int count = 0;

int main (void) {

        yyparse();
       
        if(count > 0){
                printf("\nErros sintaticos encontrados: %d \n\n", count);
        }else{
                printf("\nNenhum erro econtrado.\n\n");
        }

        return 0;
}


/*
 (eepitch-shell)
 (eepitch-kill)
 (eepitch-shell)
make
make run
 */
