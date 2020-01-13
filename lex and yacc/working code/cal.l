%{

#include<stdio.h>

#include "y.tab.h"

extern int yylval;

%}

digit [0-9]
point [.]


%%

({digit}*{digit}) {
          yylval=atoi(yytext);
          return NUMBER;
       }

[\t] ;

[\n] return 0;

. return yytext[0];

%%

int yywrap()

{

return 1;

}
