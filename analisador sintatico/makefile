##
# Project Title
#
# @file
# @version 0.1

comp: gramatica.tab.c  lex.yy.c
	gcc -o saida lex.yy.c gramatica.tab.c

gramatica.tab.c : gramatica.y
	bison -d $<

lex.yy.c : gramatica.l
	flex $<

run :
	./saida <teste
# end
