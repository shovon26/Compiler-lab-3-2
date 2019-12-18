%{
int cnt_key=0;
int cnt_Number=0;
int cnt_float=0;
int cnt_iden=0;
int cnt_logical=0;
int cnt_rel=0;
int cnt_arith=0;
%}
op [+-*/]
letter [a-zA-Z]
digit [0-9]
point [.]
rlop [><=!]
logop [|&!]

Number ({digit}*{digit})
Float ({point}*{digit})|({digit}*{point})|({digit}*{point}*{digit})
Identifier ({letter})|({letter}*{digit})|({letter}*{letter})
Notidentifier ({digit}{letter})
Relop  ({rlop})|({rlop}*{rlop})
Arithop ({op})+
Logical ({logop})|({logop}*{logop})
%%
[\t\n]+
("int")|("char")|("float")|("if")|("then")|("printf")|("else")|("for")|("switch")|("case")|("return") {printf("Keywords : %s\n",yytext);cnt_key++;}

{Number} {printf("Number : %s\n",yytext);cnt_Number++;}
{Float} {printf("Floating Number : %s\n",yytext);cnt_float++;}
{Identifier} {printf("Identifier : %s\n",yytext);cnt_iden++;}
{Notidentifier} {printf("Not Identifier : %s\n",yytext);}
{Logical} {printf("Logical Operator : %s\n",yytext);cnt_logical++;}
{Relop} {printf("Relational Operator : %s\n",yytext);cnt_rel++;}

("+")|("-")|("*")|("/")|("%") {printf("Arithmetic Operator : %s\n",yytext);cnt_arith++;}
.|\n {printf("Invalid : %s\n",yytext);}
%%
int main()
{
      extern FILE* yyin; 
      yyin = fopen("input.txt", "r");
      yylex();
      
     printf("Total keywords %d\n",cnt_key);
printf("Total Number %d\n",cnt_Number);
printf("Total Float %d\n",cnt_float);
printf("Total Identifier %d\n",cnt_iden);
printf("Total Logical Operator %d\n",cnt_logical);
printf("Total Relational Operator %d\n",cnt_rel);
printf("Total Arithmetic Operator %d\n",cnt_arith);
      
      return 0;
}
