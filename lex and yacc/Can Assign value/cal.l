%{

#include<stdio.h>

#include "y.tab.h"

extern int yylval;

int yylex();
void yyerror(char *s);
%}

digit [0-9]
point [.]
letter [a-zA-Z]

%%

"Print"    { return Print;}

({digit}*{digit}) {
          yylval=atoi(yytext);
          return number;
       }

({letter})|({letter}*{digit})|({letter}*{letter}) {

         yylval = yytext[0]; return identifier;
       }

[-+()=/*\n] {return *yytext; }

[ \t]    ;     ///skip whitespace


. yyerror("Invalid Character");

%%

int yywrap()
{
      return 1;
}
