%{
	#include<stdio.h>
	int yylex(void);
	void yyerror(char *);
%}
%token INTEGER
%token END
//decreasing order of precedence
%left '-'
%left '+'
%left '*'
%left '/'


%%

S:	
	S E END	{printf("%d\n",$2);}
	|E END	{printf("%d\n",$1);}
	;
		

E:
	INTEGER		{$$=$1;}
	|E '+' E	{$$=$1+$3;}
	|E '-' E	{$$=$1-$3;}
	|E '/' E	{$$=$1/$3;}
	|E '*' E	{$$=$1*$3;}
	|'(' E ')'	{$$=$2;}
	;

%%
void yyerror(char *s)
{
	printf("%s",s);
}

void main()
{
	yyparse();
}

