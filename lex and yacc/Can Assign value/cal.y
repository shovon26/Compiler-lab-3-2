%{
    #include<stdio.h>
    #include<math.h>
   void yyerror(char *);
   int yylex(void);
   int symbol[55];
   int symbolval(char symbol);
   void updateSymbolval(char symbol,int val);
%}

%token number identifier Print
%left '+' '-'
%left '*' '/'  ///highest presedence

%%

Program:
        Program Statement '\n'
        | 
        ;

Statement:
        E             { printf("Result = %d\n", $1); }
        | identifier '=' E     { updateSymbolval($1,$3); }
        ;

E:
        number              
        | identifier        { $$ = symbolval($1); }
        | E '+' E           { $$ = $1 + $3; }
        | E '-' E           { $$ = $1 - $3; }
        | E '*' E           { $$ = $1 * $3; }
        | E '/' E           { $$ = $1 / $3; }
        | '(' E ')'            { $$ = $2; }
        ;

%%

int getsymbolIndex(char ch)
{
	int idx = -1;
	if (islower(ch))
		idx = ch - 'a' + 26;
	else if (isupper(ch))
		idx = ch - 'A';

	return idx;
}

int symbolval(char ch) {
	int idx = getsymbolIndex(ch);
	return symbol[idx];
}
void updateSymbolval(char ch, int val) {
	int idx = getsymbolIndex(ch);
	symbol[idx] = val;
}



void yyerror(char *s) {
    printf("Error\n");
}

int main(void) {

    int i;
    for(i=0;i<=52;i++)symbol[i]=0;

    yyparse();
    return 0;
}
