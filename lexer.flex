%option noyywrap
%{
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int lineno = 1; // initialize to 1

void ret_print(char *token_type);
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
"char"          { ret_print("K_CHAR"); }
"int"            { ret_print("K_INT"); }
"float"        { ret_print("K_FLOAT"); }
"double"      { ret_print("K_DOUBLE"); }
"if"              { ret_print("K_IF"); }
"else"          { ret_print("K_ELSE"); }
"while"	       { ret_print("K_WHILE"); }
"for"	       { ret_print("K_FOR"); }
"continue"  { ret_print("K_CONTINUE"); }
"break"	       { ret_print("K_BREAK"); }
"void"	       { ret_print("K_VOID"); }
"return"     { ret_print("K_RETURN"); }

"+"|"-"      { ret_print("ADDOP"); }
"*"	     { ret_print("MULOP"); }
"/"	     { ret_print("DIVOP"); }
"++"|"--"    { ret_print("INCR"); }
"||"         { ret_print("OROP"); }
"&&"	     { ret_print("ANDOP"); }
"!"	     { ret_print("NOTOP"); }
"=="|"!="    { ret_print("EQUOP"); }
">"|"<"|">="|"<="      { ret_print("RELOP"); }

{ID}         { ret_print("ID"); }
{INT}     { ret_print("INT"); }
{FLOAT}     { ret_print("FLOAT"); }
{WS}     { ret_print("WS"); }
{STR}     { ret_print("STRING"); }

"("      { ret_print("LPAREN"); }
")"      { ret_print("RPAREN"); }
"]"      { ret_print("LBRACK"); }
"["      { ret_print("RBRACK"); }
"{"      { ret_print("LBRACE"); }
"}"      { ret_print("RBRACE"); }
";"      { ret_print("SEMI"); }
"."      { ret_print("DOT"); }
","      { ret_print("COMMA"); }
"="      { ret_print("ASSIGN"); }
"&"      { ret_print("REFER"); }
"\n"		   { lineno += 1; }
[ \t\r\f]+	   /* eat up whitespace */
.		   { yyerror("Unrecognized character"); }

%%
void ret_print(char *token_type){
   printf("yytext: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);
}

void yyerror(char *message){
   printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
   exit(1);
}

int main(int argc, char *argv[]){
    yyin = fopen(argv[1], "r");
    yylex();
    fclose(yyin);
    return 0;

}