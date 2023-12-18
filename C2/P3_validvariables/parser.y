%{
	#include<stdio.h>
	int yylex(void);
	void yyerror();
	#include<stdlib.h>
%}
%token IDENTIFIER INVALID
%%
S	:S IDENTIFIER '\n'	{printf("Valid\n");}
	|S INVALID '\n'		{printf("Invalid\n");}
	|	
	;	
%%
void yyerror()
{
	printf("error");
}
void main()
{
	yyparse();
}
