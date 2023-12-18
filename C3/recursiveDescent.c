// Construct a recursive descent parser for an expression
// Grammar:  E-> TE'
//           E'->+TE'|e
//           T->FT'
//           T'->*FT'|E
//           F->(E)|i

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char inp[50];
int E(int);
int E_(int);
int T(int);
int T_(int);
int F(int);
void error()
{
    printf("Error in parsing ");
    exit(0);
}

int E(int index)
{
    index=T(index);
    index=E_(index);
    return index;
}

int E_(int index)
{
    if(inp[index]=='+')
    {
        index=T(++index);
        index=E_(index);
    }
    return index;
} 

int T(int index)
{
    index=F(index);
    index=T_(index);
    return index;
}

int T_(int index)
{
    if(inp[index]=='*')
    {
        index=F(++index);
        index=T_(index);
    }
    return index;
}

int F(int index)
{
    //F->(E)
    if(inp[index]=='(')
    {   
        index=E(++index); 
        if(inp[index]==')')
            return ++index;
    }

    //F->id
    if(inp[index]=='i')
        return ++index;

    error();
}

void main()
{
    //printf("Grammar\nS-> cAd\nA-> ab|a");
    printf("\nEnter input for the grammar: ");
    scanf("%s",inp);
    int len=strlen(inp);

    int ans=E(0);
    printf("\n%d %d\n",len,ans);

    if(ans==len)
        printf("Valid syntax for grammar");
    else
        error();
}