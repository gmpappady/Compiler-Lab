%{
    #include<stdio.h>
    #include "treenode.h"
    //#define YYSTYPE struct Node*
    int flag=0;
    int yylex();
    void yyerror();
%}

%union
{
	struct Node *n;
}

%type <n> NUMBER expr calc

%token NUMBER
%left '+' '-'
%left '*' '/'
%left '(' ')'


%%
calc : expr 		{ printf("Result = %d\n", $1->val); 
			  print2DTree($1,0);
			  return 0;
			};

expr : expr'+'expr	{ struct Node *ptr=createNode('+',0,$1,$3);
		  	  ptr->val=$1->val + $3->val;
			  $$=ptr;
			}
     | expr'-'expr	{ struct Node *ptr=createNode('-',0,$1,$3);
			  ptr->val=$1->val - $3->val;
			  $$=ptr; 
			}
     | expr'/'expr 	{ struct Node *ptr=createNode('/',0,$1,$3);
			  ptr->val=$1->val / $3->val;
			  $$=ptr; 
			}
     | expr'*'expr 	{ struct Node *ptr=createNode('*',0,$1,$3);
			  ptr->val=$1->val * $3->val;
			  $$=ptr; 
			}
     | '(' expr ')'	{ $$=$2;
     			}
     | NUMBER  		{ $$=$1;
			}
     ;

%%

void main()
{
    printf("\nEnter Expression : ");
    yyparse();
}

void yyerror()
{
    printf("\nEntered arithmetic expression is Invalid\n\n");
}


