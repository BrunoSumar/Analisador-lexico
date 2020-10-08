CC=gcc
DEPS=classLexica.h teste

comp:  analisadorLexico.c  lex.yy.c
	$(CC) $^ -o saida

.l.c: %.l $(DEPS)
	flex $<

run:
	./saida <teste

.PHONY: run comp
