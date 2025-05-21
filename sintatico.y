%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token ID NUM
%token PLUS ASSIGN
%token PRINT

%%

program:
    compound_stmt
    ;

compound_stmt:
    '{' stmt_list '}'
    ;

stmt_list:
    stmt_list stmt
    | /* vazio */
    ;

stmt:
    expr_stmt
    | print_stmt
    ;

expr_stmt:
    expression ';'
    | ';'
    ;

print_stmt:
    PRINT expression ';' { printf("Comando de impressão com expressão\n"); }
    | PRINT ';'          { printf("Comando de impressão vazio\n"); }
    ;

expression:
    ID ASSIGN expression         { printf("Atribuição\n"); }
    | expression PLUS expression { printf("Soma\n"); }
    | ID                         { printf("Uso de identificador\n"); }
    | NUM                        { printf("Número\n"); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
}

int main() {
    return yyparse();
}
