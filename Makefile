all:
	bison -d sintatico.y
	flex lexico.l
	gcc sintatico.tab.c lex.yy.c -o analisador

clean:
	rm -f *.o *.tab.* lex.yy.c analisador