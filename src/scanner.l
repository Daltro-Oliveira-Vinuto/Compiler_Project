%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
%}

%option yylineno

%%

[ \t\n\r]+         ; // ignora espaços, tabs, nova linha e '\r'

"print"             { return PRINT; }
"read"              { return READ; }

"if"                { return IF; }
"else"              { return ELSE; }
"int"               { return INT; }
"void"              { return VOID; }
"return"            { return RETURN; }
"while"             { return WHILE; }
"float"             { return FLOAT; }

"="                 { return ASSIGN; }
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MULTIPLICATION; }
"/"                 { return DIVISION; }

"<="                { return SYMBOL_LE; }
"<"                 { return SYMBOL_LT; }
">="                { return SYMBOL_GE; }
">"                 { return SYMBOL_GT; }
"=="                { return SYMBOL_EQ; }
"!="                { return SYMBOL_NE; }

";"                 { return SEMICOLON; }
","                 { return COMMA; }
"("                 { return L_PARENTHESES; }
")"                 { return R_PARENTHESES; }
"["                 { return L_SQUARE_BRACKETS; }
"]"                 { return R_SQUARE_BRACKETS; }
"{"                 { return L_BRACES; }
"}"                 { return R_BRACES; }

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.cadeia = strdup(yytext);
    return ID;
}

[0-9]+              {
    yylval.num = atoi(yytext);
    return NUM;
}

[0-9]+\.[0-9]+([eE][-+]?[0-9]+)?    {
    yylval.num = atof(yytext);
    return FLOATING_NUM;
}

"//".*                     ;  // Comentário de linha
"/*"([^*]|\*+[^*/])*"*"+"/"   ;  // Comentário de bloco

.                   { return yytext[0]; }

%%

int yywrap() {
    return 1;
}