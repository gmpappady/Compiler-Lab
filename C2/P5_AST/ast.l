%{
#include "y.tab.h"
#include"treenode.h"
void yyerror();
//#define YYSTYPE struct Node*
%}

%%
[0-9]+          { struct Node *ptr=createNode('N',atoi(yytext),NULL,NULL);
		  yylval.n = ptr;
		  return NUMBER;
		} 
[-+*/()]     	{ return *yytext; }
[\n] 		{ return 0;	}
[\t]		{ }
.               { yyerror();
		  exit(0); 
		}

%%

int yywrap() {
    return 1;
}

