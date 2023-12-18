//Construct a recursive descent parser for an expression
//Grammar:  S-> cAd
//          A-> ab|a             
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char inp[50];

void error()
{
    printf("Invalid syntax");
    exit(0);
}

int A(int index)
{   
    int temp=index;

    ab://A-> ab
    index=temp;
    if(inp[index]=='a')
        ++index;
    else 
        goto a;
    if(inp[index]=='b')
        return ++index;
    else goto a;

    a://A->a
    index=temp;
    if(inp[index]=='a')
        return ++index;

    error(); 
}

int S(int index)
{
    if(inp[index]=='c')
        ++index;
    else
        error();
    index=A(index);
    if(inp[index]=='d')
        ++index;
    else
        error();
    return index;
}

void main()
{
    printf("Grammar\nS-> cAd\nA-> ab|a");
    printf("\nEnter input for the grammar: ");
    scanf("%s",inp);
    int ans=S(0);
    int len=strlen(inp);
    if(ans==len)
        printf("Valid syntax for grammar");
    else
        error();
}