%{
#include <stdio.h>
%}

%%

[ \t\n]+               ;  // ignora espaços em branco

[0-9]+                 { printf("Numérico: %s\n", yytext); }

[a-zA-Z][a-zA-Z0-9]*   { printf("Identificador: %s\n", yytext); }

"//".* {printf("Comentário: %s\n", yytext); }

"/*"([^*]|\*+[^*/])*\*+"/" {printf("Comentário: %s\n", yytext); }

"+"                    { printf("Operador: %s\n", yytext); }
"-"                    { printf("Operador: %s\n", yytext); }
"*"                    { printf("Operador: %s\n", yytext); }
"/"                    { printf("Operador: %s\n", yytext); }
"%"                    { printf("Operador: %s\n", yytext); }

.                      { printf("Outro: %s\n", yytext); }

%%

int yywrap() { return 1; }
