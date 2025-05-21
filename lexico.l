%{
#include <stdio.h>
#include "sintatico.tab.h" // importante para reconhecer os tokens do parse
%}

%%

[ \t\n]+               ;  // ignora espaços em branco

"print"                { return PRINT; }

[0-9]+                 { yylval = atoi(yytext); return NUM; }

[a-zA-Z][a-zA-Z0-9]*   { return ID; }

"="                    { return ASSIGN; }
"+"                    { return PLUS; }

";"                    { return ';'; }
"{"                    { return '{'; }
"}"                    { return '}'; }

.                      { return yytext[0]; }

%%
int yywrap() { return 1; }
