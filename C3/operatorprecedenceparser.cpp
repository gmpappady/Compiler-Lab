#include<bits/stdc++.h>
using namespace std;

unordered_map <char,int> terminals;
stack <char> opstack;
string expr;

void printState()
{
    cout<<"\n"<<"\t"<<"\t";
}

void parse()
{
    int i=0;
    while(i<expr.size())
    {   
        printState();
        if(terminals.find(expr[i])==terminals.end())
        {
            cout<<"Invalid character\n";
            return;
        }
        else if(opstack.top()=='$'&&expr[i]=='$')
        {
            cout<<"Accepted\n";
            return;
        }
        else if(terminals[opstack.top()]<=terminals[expr[i]])
        {  
            opstack.push('<');
            opstack.push(expr[i++]);
            cout<<"shift";
        }
        else if(terminals[opstack.top()]>terminals[expr[i]])
        {
            while(opstack.top()!='<')
                opstack.pop();
            opstack.pop();
            cout<<"reduce";
        }
    }
}
int main()
{
    int n;
    printf("Enter number of terminals: ");
    scanf("%d",&n);
    terminals['$']=0;
    printf("Enter the terminals in increasing order of precedence: \n");
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        terminals[c]=i;
    }
    //initialize stack
    opstack.push('$');
    //initialize i/p string
    cout<<"Enter input expression: ";
    cin>>expr;
    expr.push_back('$');
    //parse the string
    cout<<"STACK\tINPUT\tACTION";
    parse();
    return 1;
}