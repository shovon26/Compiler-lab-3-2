%{
 
  #include<stdio.h>   

%}
op [+-*/]
letter [a-zA-Z]
digit [0-9]
point [.]
logop [><=!]

 
Number ({digit}*{digit})|({point}*{digit})|({digit}*{point})|({digit}*{point}*{digit})
Identifier ({letter})|({letter}*{digit})|({letter}*{letter})
Notidentifier ({digit}{letter})
Relop  ({rlop})|({rlop}*{rlop})
Arithop ({op})+
Logical ({logop})|({logop}*{logop})
%%
[\t\n]+
("int")|("char")|("float")|("if")|("then")|("printf")|("else")|("for")|("switch")|("case")|("return") {printf("Keywords : %s\n",yytext);}

{Number} {printf("Number : %s\n",yytext);}
{Identifier} {printf("Identifier : %s\n",yytext);}
{Logical} {printf("Logical Operator : %s\n",yytext);}

("+")|("-")|("*")|("/")|("%") {printf("Math Operator : %s\n",yytext);}
.|\n {printf("Others : %s\n",yytext);}
%%
int main()
{
     // extern FILE* yyin; 
     // yyin = fopen("input.c", "r");
      yylex();
       
      return 0;
}
