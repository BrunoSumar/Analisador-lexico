CC=gcc
DEPS=classLexica.h teste

hellomake:  analisadorLexico.c analisadorLexico.l $(DEPS)
	lex analisadorLexico.l
	$(CC) analisadorLexico.c lex.yy.c -o saida

run:
	./saida <teste

.PHONY: run
