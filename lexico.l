%{
#include "sintatico.tab.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
%}

%option yylineno

%%

[ \t]+              ;
\n                  ;

"if"                { return IF; }
"else"              { return ELSE; }
"int"               { return INT; }
"void"              { return VOID; }
"return"            { return RETURN; }
"while"             { return WHILE; }

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

[0-9]+              { yylval.num = atoi(yytext); return NUM; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.id = strdup(yytext); return ID; }

.                   { return yytext[0]; }

%%

int yywrap() {
    return 1;
}