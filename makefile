CC=gcc
DEPS=classLexica.h
OUT=saida.out
IN=teste

comp:  analisadorLexico.c  lex.yy.c
	$(CC) $^ -o $(OUT)

.l.c: %.l $(DEPS)
	flex $<

run:
	./$(OUT) <$(IN)

.PHONY: run comp
