///Defintion section
%{
  #include<stdio.h>
  #include<math.h>
int flag=0;
%}
%union           //to define possible symbol types
{double p;}
%token <p>num
%token SIN COS TAN LOG SQRT

//Defining the precedence and associativity
// %left '+''-'        //lowest precedence
%left '+''/''%'         //highest precedence 
%nonassoc uminu ///no associativity
%type<p> exp
%%

///to store the answer
ss: exp {printf("Answer is = %g\n",$1);}


///arithmetic operator

exp : exp'+'exp       {$$=$1+$3; }
     |exp'-'exp      {$$=$1-$3; }
    |exp'*'exp      {$$=$1*$3; }
    |exp'/'exp      {
                          if($3 == 0){
                            printf("Divided by Zero");
                                     }
                             else $$=$1/$3;

                                    }
               |'-'exp      {$$=$2; }
               |SIN'('exp')' {$$=sin($3);}
               |COS'('exp')' {$$=cos($3);}
               |TAN'('exp')' {$$=tan($3);}
               |LOG'('exp')' {$$=LOG($3);}
               |SQRT'('exp')' {$$=sqrt($3);}
               |num;
               |'('exp')'        {$$=$2;}
        ;

%%

void main()
{
           printf("Enter Expression : ");
           yyparse();

        if(flag==0)
               printf("\nValid\n\n");
}

void yyerror()
{
      printf("\nSyntax error\n");
}



