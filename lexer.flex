%{
#include<stdio.h>
int countno = 0;
%}

%option yylineno

DIGIT     [0-9]
ALPHA     [a-zA-Z]

%%

"int"    printf("INT");
"float"  printf("FLOAT");
"if"     printf("IF");
"else"   printf("ELSE");
"for"    printf("FOR");
"print"  printf("PRINT");
"scan"   printf("SCAN");
"char"   printf("CHAR");
"void"   printf("VOID");
^"#include"[ ]*<.+\.h>   printf("INCLUDE");
"true"   printf("TRUE");
"false"  printf("FALSE");
{ALPHA}({ALPHA}|{DIGIT})*    printf("ID");
";"      printf("SEMI");
{DIGIT}+ printf("DIGIT");
"("      printf("lparen");
")"      printf("rparen");
"["      printf("lbrak");
"]"      printf("rbrak");
"{"      printf("lbrace");
"}"      printf("rbrace");
"="      printf("equals");


%%
int main(int argc, char *argv[]){

    yyin = fopen(argv[1], "r");
    yylex();
    return 0;
}
int yywrap(){return(1);}