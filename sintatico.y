%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(const char *s);
extern int yylineno;

typedef struct Simbolo {
    char* nome;
    char* tipo;     
    char* natureza;
    int usada;
    struct Simbolo* prox;
} Simbolo;

Simbolo* tabela = NULL;
int erros_semanticos = 0;
int warnings_semanticos = 0;

Simbolo* busca(char* nome) {
    Simbolo* atual = tabela;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void insere(char* nome, char* tipo, char* natureza) {
    if (busca(nome) != NULL) {
        return;
    }
    Simbolo* novo = malloc(sizeof(Simbolo));
    novo->nome = strdup(nome);
    novo->tipo = strdup(tipo);
    novo->natureza = strdup(natureza);
    novo->usada = 0;
    novo->prox = tabela;
    tabela = novo;
}

void verifica_warnings() {
    Simbolo* atual = tabela;
    while (atual != NULL) {
        if (atual->usada == 0 && strcmp(atual->nome, "main") != 0) {
            printf("WARNING: identificador %s (%s) declarado mas nao usado\n", atual->nome, atual->tipo);
            warnings_semanticos++;
        }
        atual = atual->prox;
    }
}

void imprime_tabela() {
    printf("\n______________________________________________________________\n");
    printf("\n\t\t\tTABELA DE SIMBOLOS:\t\t\n");
    printf("______________________________________________________________\n\n");
    printf("%-20s %-10s %-15s %-5s\n", "NOME", "TIPO", "NATUREZA", "USADA");

    Simbolo* atual = tabela;
    while (atual != NULL) {
        printf("%-20s %-10s %-15s %-5s\n",
               atual->nome,
               atual->tipo,
               atual->natureza,
               atual->usada ? "sim" : "nao");
        atual = atual->prox;
    }
    printf("______________________________________________________________\n \n");
}

%}

%union {
    char* cadeia;
    int num;
}

%token PRINT

%token <cadeia> ID
%token <num> NUM
%token <num> FNUM

%type <cadeia> type_specifier

%token IF ELSE INT FLOAT RETURN VOID WHILE

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
        insere($2, $1, "variavel");
        printf("Declaracao de identificador (variavel): %s do tipo %s na linha %d\n", $2, $1, yylineno);
    }
    | type_specifier ID LBRACK NUM RBRACK SEMI {
        insere($2, $1, "vetor");
        printf("Declaracao de identificador (vetor): %s do tipo %s na linha %d\n", $2, $1, yylineno);
    }
    ;

type_specifier:
    INT  { $$ = "int"; }
    | VOID { $$ = "void"; }
    | FLOAT { $$ = "float"; }
    ;

fun_declaration:
    type_specifier ID LPAREN params RPAREN compound_stmt {
        insere($2, $1, "funcao");
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
        insere($2, $1, "parametro");
        printf("Declaracao de identificador (parametro escalar): %s na linha %d\n", $2, yylineno);
    }
    | type_specifier ID LBRACK RBRACK {
        insere($2, $1, "parametro_vetor");
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
        Simbolo* s = busca($1);
        if (s == NULL) {
            printf("ERRO: identificador %s usado na linha %d mas nao declarado\n", $1, yylineno);
            erros_semanticos++;
        } else {
            s->usada = 1;
            printf("Uso de identificador (variavel): %s na linha %d\n", $1, yylineno);
        }
    }
    | ID LBRACK expression RBRACK {
        Simbolo* s = busca($1);
        if (s == NULL) {
            printf("ERRO: identificador %s usado como vetor na linha %d mas nao declarado\n", $1, yylineno);
            erros_semanticos++;
        } else {
            s->usada = 1;
            printf("Uso de identificador (vetor): %s na linha %d\n", $1, yylineno);
        }
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
    | FNUM
    | PLUS factor
    | MINUS factor
    ;

call:
    ID LPAREN args RPAREN {
        Simbolo* s = busca($1);
        if (s == NULL) {
            printf("ERRO: chamada da funcao %s na linha %d mas nao declarada\n", $1, yylineno);
            erros_semanticos++;
        } else {
            s->usada = 1;
            printf("Uso de identificador (chamada de funcao): %s na linha %d\n", $1, yylineno);
        }
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
    if (yyparse() == 0) {
        printf("Sintaticamente correto\n");
        imprime_tabela();
        verifica_warnings();

        if (erros_semanticos == 0) {
            printf("Programa semanticamente correto");
            if (warnings_semanticos > 0) {
                printf(" com %d warning(s)\n", warnings_semanticos);
            } else {
                printf(".\n");
            }
        } else {
            printf("Programa contem %d erro(s) semantico(s).\n", erros_semanticos);
        }
    }

    return 0;
}
