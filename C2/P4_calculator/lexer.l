%{
	#include<stdlib.h>
	#include"y.tab.h"
%}

%%

[0-9]+		{	yylval=atoi(yytext);
				return INTEGER;}
[-+/*()]	{	return *yytext;}
[\n]		{	return END;}
[\t]		{;}
.		{	yyerror("Invalid character found");}
	
%%

int yywrap()
{
	return 1;
}
