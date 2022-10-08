%option noyywrap
%{
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.c"

extern FILE *yyin;

int lineno = 1; // initialize to 1
void finpr(char *token_type);
void yyerror();
%}


ALPHA     [a-zA-Z]
DIGIT     [0-9]
ALNUM     {ALPHA}|{DIGIT}

ID         {ALPHA}+{ALPHA}*
INT         {DIGIT}{DIGIT}*
FLOAT      {DIGIT}*"."{DIGIT}+
WS      (\'\\[nftrbv]\')
STR      ["].*["]

%%
"char"          { finpr("K_CHAR"); }
"int"            { finpr("K_INT"); }
"float"        { finpr("K_FLOAT"); }
"double"      { finpr("K_DOUBLE"); }
"if"              { finpr("K_IF"); }
"else"          { finpr("K_ELSE"); }
"while"	       { finpr("K_WHILE"); }
"for"	       { finpr("K_FOR"); }
"continue"  { finpr("K_CONTINUE"); }
"break"	       { finpr("K_BREAK"); }
"void"	       { finpr("K_VOID"); }
"return"     { finpr("K_RETURN"); }

"+"|"-"      { finpr("ADDOP"); }
"*"	     { finpr("MULOP"); }
"/"	     { finpr("DIVOP"); }
"++"|"--"    { finpr("INCR"); }
"||"         { finpr("OROP"); }
"&&"	     { finpr("ANDOP"); }
"!"	     { finpr("NOTOP"); }
"=="|"!="    { finpr("EQUOP"); }
">"|"<"|">="|"<="      { finpr("RELOP"); }

{ID}         { insert(yytext,strlen(yytext),UNDEF,lineno);
               finpr("ID"); }
{INT}     { finpr("INT"); }
{FLOAT}     { finpr("FLOAT"); }
{WS}     { finpr("WS"); }
{STR}     { finpr("STRING"); }

"("      { finpr("LPAREN"); }
")"      { finpr("RPAREN"); }
"]"      { finpr("LBRACK"); }
"["      { finpr("RBRACK"); }
"{"      { finpr("LBRACE"); }
"}"      { finpr("RBRACE"); }
";"      { finpr("SEMI"); }
"."      { finpr("DOT"); }
","      { finpr("COMMA"); }
"="      { finpr("ASSIGN"); }
"&"      { finpr("REFER"); }
"\n"		   { lineno += 1; }
[ \t\r\f]+	   /* eat up whitespace */
.		   { yyerror("Unrecognized character"); }

%%
void finpr(char *token_type){
   printf("yytext: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);
}

void yyerror(char *message){
   printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
   exit(1);
}

int main(int argc, char *argv[]){
   init_hash_table();
    yyin = fopen(argv[1], "r");
    yylex();
    fclose(yyin);
    return 0;

}