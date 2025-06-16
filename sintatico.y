%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token ID NUM
%token PLUS ASSIGN
%token PRINT
%token '{' '}' ';'

%right ASSIGN
%left PLUS

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
    PRINT expression ';'
    | PRINT ';'
    ;

expression:
      ID ASSIGN expression
    | expression PLUS expression
    | PLUS expression
    | ID
    | NUM
    ;

%%

void yyerror(const char *s) {
    printf("Erro de sintaxe\n");
}

int main() {
    if (yyparse() == 0) {
        printf("Sintaticamente correto\n");
    }
    return 0;
}