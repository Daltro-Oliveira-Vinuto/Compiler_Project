all:
	flex lexico.l
	gcc lex.yy.c -o lexico.exe -lfl

clean:
	rm -f lex.yy.c lexico.exe
