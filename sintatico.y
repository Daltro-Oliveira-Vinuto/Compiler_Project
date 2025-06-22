%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(const char *s);
extern int yylineno;

%}

%union {
    int num;
    char* id;
}

%token PRINT

%token <id> ID
%token <num> NUM

%token IF ELSE INT RETURN VOID WHILE

%right ASSIGN
%left PLUS MINUS
%left TIMES OVER
%nonassoc LT LE GT GE EQ NE
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE
%token SEMI COMMA

%start program

%%

program:
    declaration_list
    ;

declaration_list:
    declaration_list declaration
    | declaration
    ;

declaration:
    var_declaration
    | fun_declaration
    ;

var_declaration:
    type_specifier ID SEMI {
        printf("Declaracao de identificador (variavel): %s na linha %d\n", $2, yylineno);
    }
    | type_specifier ID LBRACK NUM RBRACK SEMI {
        printf("Declaracao de identificador (vetor): %s na linha %d\n", $2, yylineno);
    }
    ;

type_specifier:
    INT
    | VOID
    ;

fun_declaration:
    type_specifier ID LPAREN params RPAREN compound_stmt {
        printf("Declaracao de identificador (funcao): %s na linha %d\n", $2, yylineno);
    }
    ;

params:
    param_list
    | VOID
    | /* vazio */ {}
    ;

param_list:
    param_list COMMA param
    | param
    ;

param:
    type_specifier ID {
        printf("Declaracao de identificador (parametro escalar): %s na linha %d\n", $2, yylineno);
    }
    | type_specifier ID LBRACK RBRACK {
        printf("Declaracao de identificador (parametro vetor): %s na linha %d\n", $2, yylineno);
    }
    ;

compound_stmt:
    LBRACE local_declarations statement_list RBRACE
    ;

local_declarations:
    local_declarations var_declaration
    | /* vazio */ {}
    ;

statement_list:
    statement_list statement
    | /* vazio */ {}
    ;

statement:
    expression_stmt
    | compound_stmt
    | selection_stmt
    | iteration_stmt
    | return_stmt
    | print_stmt
    ;

expression_stmt:
    expression SEMI
    | SEMI
    ;

print_stmt:
    PRINT LPAREN expression RPAREN SEMI
    ;

selection_stmt:
      IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
    | IF LPAREN expression RPAREN statement ELSE statement
    ;

iteration_stmt:
    WHILE LPAREN expression RPAREN statement
    ;

return_stmt:
    RETURN SEMI
    | RETURN expression SEMI
    ;

expression:
    var ASSIGN expression {
        printf("Atribuicao a identificador na linha %d\n", yylineno);
    }
    | simple_expression
    ;

var:
    ID {
        printf("Uso de identificador (variavel): %s na linha %d\n", $1, yylineno);
    }
    | ID LBRACK expression RBRACK {
        printf("Uso de identificador (vetor): %s na linha %d\n", $1, yylineno);
    }
    ;

simple_expression:
    additive_expression relop additive_expression
    | additive_expression
    ;

relop:
    LE | LT | GT | GE | EQ | NE
    ;

additive_expression:
    additive_expression addop term
    | term
    ;

addop:
    PLUS | MINUS
    ;

term:
    term mulop factor
    | factor
    ;

mulop:
    TIMES | OVER
    ;

factor:
    LPAREN expression RPAREN
    | var
    | call
    | NUM
    | PLUS factor
    | MINUS factor
    ;

call:
    ID LPAREN args RPAREN {
        printf("Uso de identificador (chamada de funcao): %s na linha %d\n", $1, yylineno);
    }
    ;

args:
    arg_list
    | /* vazio */ {}
    ;

arg_list:
    arg_list COMMA expression
    | expression
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", yylineno, s);
}

int main() {
    if (yyparse() == 0)
        printf("Sintaticamente correto\n");
    return 0;
}