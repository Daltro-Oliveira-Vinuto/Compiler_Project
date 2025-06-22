%{
#include "sintatico.tab.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
%}

%option yylineno

%%

[ \t\n\r]+         ; // ignora espaços, tabs, nova linha e '\r'

"print"             { return PRINT; }

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
"*"                 { return TIMES; }
"/"                 { return OVER; }

"<="                { return LE; }
"<"                 { return LT; }
">="                { return GE; }
">"                 { return GT; }
"=="                { return EQ; }
"!="                { return NE; }

";"                 { return SEMI; }
","                 { return COMMA; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"["                 { return LBRACK; }
"]"                 { return RBRACK; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }

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
    return FNUM;
}

"//".*                     ;  // Comentário de linha
"/*"([^*]|\*+[^*/])*"*"+"/"   ;  // Comentário de bloco

.                   { return yytext[0]; }

%%

int yywrap() {
    return 1;
}