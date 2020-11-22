##
# Project Title
#
# @file
# @version 0.1

comp: gramatica.tab.c  lex.yy.c simbolos.c
	gcc -o saida $^

gramatica.tab.c : gramatica.y
	bison -d $<

lex.yy.c : gramatica.l
	flex $<

run :
	./saida <teste
# end
# - Declaração de Id antes do uso

# - Só permite atribuição com tipos iguais

# - Só posso passar parâmetros para funções
# - Quantidade de parametros na chamada da função deve ser igual a da declaração

# - Só pode usar indice ([]) em variaveis do tipo vetor

# - Só pode usar campo (.) em variaveis do tipo registro
# - Só posso acessar campo de registro declarado
#
