%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int debug_semantic = 0;
void emitRO( char *op, int r, int s, int t, char *c);
void emitRM( char *op, int r, int d, int s, char *c);

static int emitLoc = 0;
uint ac = 0;
int gp = 5;
int mp = 6;
extern FILE *yyin;
extern FILE *yyout;

int yylex();
void yyerror(const char *s);
extern int yylineno;

typedef struct Simbolo {
    char* nome;
    char* tipo;     
    char* natureza;
    int usada;
    char** tipos_param; 
    int qtd_param;     
    struct Simbolo* prox;
} Simbolo;

Simbolo* tabela = NULL;
int erros_semanticos = 0;
int warnings_semanticos = 0;

char* tipos_param_tmp[32];
int qtd_param_tmp = 0;

char* tipos_args_tmp[32];
int qtd_args_tmp = 0;

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
%token READ

%token <cadeia> ID
%token <num> NUM
%token <num> FLOATING_NUM

%type <cadeia> type_specifier
%type <cadeia> expression simple_expression additive_expression term factor var
%type <cadeia> call

%token IF ELSE INT FLOAT RETURN VOID WHILE

%right ASSIGN
%left PLUS MINUS
%left MULTIPLICATION DIVISION
%nonassoc SYMBOL_LT SYMBOL_LE SYMBOL_GT SYMBOL_GE SYMBOL_EQ SYMBOL_NE
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%token L_PARENTHESES R_PARENTHESES L_SQUARE_BRACKETS R_SQUARE_BRACKETS L_BRACES R_BRACES
%token SEMICOLON COMMA


%start program

%%

program:
    declaration_list
{        emitRO("HALT", 0, 0, 0, "End of execution.");
}

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
    type_specifier ID SEMICOLON {
        insere($2, $1, "variavel");
        //printf("Declaracao de identificador (variavel): %s do tipo %s na linha %d\n", $2, $1, yylineno);
    }
    | type_specifier ID L_SQUARE_BRACKETS NUM R_SQUARE_BRACKETS SEMICOLON {
        insere($2, $1, "vetor");
        //printf("Declaracao de identificador (vetor): %s do tipo %s na linha %d\n", $2, $1, yylineno);
    }
    ;

type_specifier:
    INT  { $$ = "int"; }
    | VOID { $$ = "void"; }
    | FLOAT { $$ = "float"; }
    ;

fun_declaration:
    type_specifier ID L_PARENTHESES params R_PARENTHESES compound_stmt {
        insere($2, $1, "funcao");
        Simbolo* s = busca($2);
        if (s) {
            s->qtd_param = qtd_param_tmp;
            s->tipos_param = malloc(sizeof(char*) * qtd_param_tmp);
            for (int i = 0; i < qtd_param_tmp; i++)
                s->tipos_param[i] = tipos_param_tmp[i];
        }        qtd_param_tmp = 0; // Limpa para próxima função
        //printf("Declaracao de identificador (funcao): %s na linha %d\n", $2, yylineno);
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
        tipos_param_tmp[qtd_param_tmp++] = $1; 
        printf("Declaracao de identificador (parametro escalar): %s na linha %d\n", $2, yylineno);
    }
    | type_specifier ID L_SQUARE_BRACKETS R_SQUARE_BRACKETS {
        insere($2, $1, "parametro_vetor");
        tipos_param_tmp[qtd_param_tmp++] = $1; 
        printf("Declaracao de identificador (parametro vetor): %s na linha %d\n", $2, yylineno);
    }
    ;

compound_stmt:
    L_BRACES local_declarations statement_list R_BRACES
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
    expression SEMICOLON
    | SEMICOLON
    ;

print_stmt:
    PRINT L_PARENTHESES expression R_PARENTHESES SEMICOLON {emitRO("OUT", ac, 0, 0, "print expression result");
}
    ;

selection_stmt:
      IF L_PARENTHESES expression R_PARENTHESES statement %prec LOWER_THAN_ELSE
    | IF L_PARENTHESES expression R_PARENTHESES statement ELSE statement
    ;

iteration_stmt:
    WHILE L_PARENTHESES expression R_PARENTHESES statement
    ;

return_stmt:
    RETURN SEMICOLON
    | RETURN expression SEMICOLON
    ;

expression:
    var ASSIGN expression {
        char* tipo_var = $1;
        char* tipo_expr = $3;


        //printf("Atribuicao a identificador na linha %d\n", yylineno);

        if (tipo_var && tipo_expr) {
            if (strcmp(tipo_var, "int") == 0 && strcmp(tipo_expr, "float") == 0) {
                //printf("ERRO SEMANTICO: atribuicao de float para int na linha %d\n", yylineno);
                erros_semanticos++;
            }
            if (strcmp(tipo_var, "float") == 0 && strcmp(tipo_expr, "int") == 0) {
                //printf("WARNING: atribuicao de int para float na linha %d (conversao implicita)\n", yylineno);
                warnings_semanticos++;
            }
        }
        $$ = tipo_var;
    }
    | simple_expression { $$ = $1; }
    ;

var:
var:
    ID {
        Simbolo* s = busca($1);
        if (s == NULL) {
            printf("ERRO: identificador %s usado na linha %d mas nao declarado\n", $1, yylineno);
            erros_semanticos++;
            $$ = NULL;
        } else {
            s->usada = 1;
            //printf("Uso de identificador (variavel): %s na linha %d\n", $1, yylineno);
            $$ = strdup(s->tipo); // Retorna o tipo para ser usado nas verificações
        }
    }
    | ID L_SQUARE_BRACKETS expression R_SQUARE_BRACKETS {
        Simbolo* s = busca($1);
        if (s == NULL) {
            printf("ERRO: identificador %s usado como vetor na linha %d mas nao declarado\n", $1, yylineno);
            erros_semanticos++;
            $$ = NULL;
        } else {
            s->usada = 1;
            printf("Uso de identificador (vetor): %s na linha %d\n", $1, yylineno);
            $$ = strdup(s->tipo);
        }
    }
    ;
simple_expression:
    additive_expression relop additive_expression { $$ = "int"; }
    | additive_expression { $$ = $1; }
    ;

relop:
    SYMBOL_LE| SYMBOL_LT | SYMBOL_GT | SYMBOL_GE | SYMBOL_EQ | SYMBOL_NE
    ;

additive_expression:
    additive_expression addop term {
        if ($1 && $3 && (strcmp($1, "float") == 0 || strcmp($3, "float") == 0))
            $$ = "float";
        else
            $$ = "int";
    }
    | term { $$ = $1; }
    ;

addop:
    PLUS | MINUS
    ;

term:
    term mulop factor {
        if ($1 && $3 && (strcmp($1, "float") == 0 || strcmp($3, "float") == 0))
            $$ = "float";
        else
            $$ = "int";
    }
    | factor { $$ = $1; }
    ;

mulop:
    MULTIPLICATION | DIVISION
    ;

factor:
    L_PARENTHESES expression R_PARENTHESES { $$ = $2; }
    | var { $$ = $1; }
    | call { $$ = $1; }
    | NUM { $$ = "int";   
     emitRM("LDC", ac, $1, 0, "load constant into ac");
}
    | FLOATING_NUM { $$ = "float"; }
    | PLUS factor { $$ = $2; }
    | MINUS factor { $$ = $2; }
    ;
call:
    ID L_PARENTHESES args R_PARENTHESES {
        Simbolo* s = busca($1);
        if (s == NULL) {
            printf("ERRO: chamada da funcao %s na linha %d mas nao declarada\n", $1, yylineno);
            erros_semanticos++;
            $$ = NULL;
        } else {
            s->usada = 1;
            if (s->qtd_param != qtd_args_tmp) {
                printf("ERRO SEMANTICO: funcao %s chamada com %d argumento(s), mas espera %d na linha %d\n", $1, qtd_args_tmp, s->qtd_param, yylineno);
                erros_semanticos++;
            } else {
                for (int i = 0; i < s->qtd_param; i++) {
                    if (strcmp(s->tipos_param[i], tipos_args_tmp[i]) != 0) {
                        printf("ERRO SEMANTICO: tipo do argumento %d da funcao %s incorreto (esperado: %s, encontrado: %s) na linha %d\n",
                            i+1, $1, s->tipos_param[i], tipos_args_tmp[i], yylineno);
                        erros_semanticos++;
                    }
                }
            }
            $$ = s->tipo;
        }
    }
    ;

args:
    arg_list
    | /* vazio */ {}
    ;

arg_list:
    arg_list COMMA expression {
        tipos_args_tmp[qtd_args_tmp++] = $3;
    }
    | expression {
        qtd_args_tmp = 0;
        tipos_args_tmp[qtd_args_tmp++] = $1;
    }
    ;

%%


void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", yylineno, s);
}

void emitRO( char *op, int r, int s, int t, char *c)
{
    fprintf(yyout, "%3d:  %5s  %d,%d,%d ", emitLoc++, op, r, s, t);
    //fprintf(yyout, "\t%s\n", c); // Add comment
    fprintf(yyout,"\n") ;

} /* emitRO */

void emitRM( char * op, int r, int d, int s, char *c)
{
    fprintf(yyout, "%3d:  %5s  %d,%d(%d) ", emitLoc++, op, r, d, s);
    //fprintf(yyout, "\t%s\n", c); // Add comment
    fprintf(yyout,"\n") ;

} /* emitRM */



extern int yydebug;

int main(int argc, char *argv[], char *envp[]) {
    ++argv; --argc;        
    if(argc > 0)
        yyin = fopen(argv[0],"rt");
    else
        yyin = stdin;    
    if(argc > 1)
        yyout = fopen(argv[1],"wt");
    else
        yyout = stdout;


//emitComment("Standard prelude:");
    emitRM("LD",mp,0,ac,"load maxaddress from location 0");
    emitRM("ST",ac,0,ac,"clear location 0");
//emitComment("End of standard prelude.");

    yydebug = 0;
    if (yyparse() == 0) {
        //printf("Sintaticamente correto\n");
        if (debug_semantic) {imprime_tabela(); }
        verifica_warnings();

        if (busca("main") == NULL) {
            printf("ERRO SEMANTICO: funcao 'main' nao declarada\n");
            erros_semanticos++;
        }

        if (erros_semanticos == 0) {
            //printf("Programa semanticamente correto");
            if (warnings_semanticos > 0) {
                printf(" com %d warning(s)\n", warnings_semanticos);
            } else {
                //printf(".\n");
            }
        } else {
            printf("Programa contem %d erro(s) semantico(s).\n", erros_semanticos);
        }
    }

    //emitRO("HALT",0,0,0,"");

    fclose(yyin);
    fclose(yyout);

    return 0;
}
