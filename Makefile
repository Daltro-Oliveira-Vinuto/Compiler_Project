CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LEX = flex
YACC = bison

# Arquivos do compilador
SCANNER = src/scanner.l
PARSER = src/parser.y
OPTIMIZER_SRC = src/optimizer.c
OPTIMIZER_EXAMPLE = src/optimizer_example.c

# Arquivos gerados
SCANNER_C = lex.yy.c
PARSER_C = parser.tab.c
PARSER_H = parser.tab.h

# Executáveis
COMPILER = compiler
OPTIMIZER_DEMO = optimizer_demo

# Regra principal
all: $(COMPILER) $(OPTIMIZER_DEMO)

# Compila o compilador principal
$(COMPILER): $(SCANNER_C) $(PARSER_C) $(OPTIMIZER_SRC)
	$(CC) $(CFLAGS) -o $@ $^ -lfl

# Compila o exemplo do otimizador
$(OPTIMIZER_DEMO): $(OPTIMIZER_EXAMPLE) $(OPTIMIZER_SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Gera o scanner
$(SCANNER_C): $(SCANNER) $(PARSER_H)
	$(LEX) -o $@ $(SCANNER)

# Gera o parser
$(PARSER_C) $(PARSER_H): $(PARSER)
	$(YACC) -d -o $(PARSER_C) $(PARSER)

# Testa o compilador
test: $(COMPILER)
	./$(COMPILER) tests/test_print.ddd output.tm

# Testa o otimizador
test_optimizer: $(OPTIMIZER_DEMO)
	./$(OPTIMIZER_DEMO)

# Limpa arquivos gerados
clean:
	rm -f $(SCANNER_C) $(PARSER_C) $(PARSER_H) $(COMPILER) $(OPTIMIZER_DEMO) output.tm
	rm -f *.o

# Mostra ajuda
help:
	@echo "Comandos disponíveis:"
	@echo "  make          - Compila o compilador e o exemplo do otimizador"
	@echo "  make test     - Testa o compilador com o arquivo de teste"
	@echo "  make test_optimizer - Executa o exemplo do otimizador"
	@echo "  make clean    - Remove arquivos gerados"
	@echo "  make help     - Mostra esta ajuda"

.PHONY: all test test_optimizer clean help 