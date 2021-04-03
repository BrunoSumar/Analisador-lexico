##
# Project Title
#
# @file
# @version 0.1

comp: gramatica.tab.c  lex.yy.c simbolos.c codinter.c
	gcc -o saida $^

gramatica.tab.c : gramatica.y
	bison -d $<

lex.yy.c : gramatica.l
	flex $<

run :
	./saida <teste >final
# end
