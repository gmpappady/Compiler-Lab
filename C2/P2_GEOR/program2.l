//Lex program to recognize all strings which 
//do not contain first 4 characters of name(GEOR)

%%
(.*(g|G)(e|E)(o|O)(r|R).*)	printf("Invalid");
.*				printf("Valid");
%%
int yywrap()
{
	return 1;
}
void main()
{
	yylex();
}
