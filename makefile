CC=gcc
DEPS=classLexica.h

hellomake:  analisadorLexico.o analisadorLexico.l
	lex analisadorLexico.l
	$(CC) analisadorLexico.o lex.yy.c -o saida

run:
	./saida <teste

.PHONY: run
