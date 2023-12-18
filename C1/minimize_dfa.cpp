#include<bits/stdc++.h>
using namespace std;

struct s
{
    int sno;
    unordered_map <char,int> transition;
    bool final;
};

int main()
{
    int nostates,notransitions,nofinalstates;
    cout<<"Enter number of states: ";
    cin>>nostates;
    vector <s> dfa(nostates);

    cout<<"Enter the no of final states: ";
    cin>>nofinalstates;
    cout<<"Enter the final state(s): ";
    for(int i=0;i<nofinalstates;i++)
    {
        int x;
        cin>>x;
        dfa[x].final=1;
    }
    
    cout<<"Enter number of transitions: ";
    cin>>notransitions;
    printf("\nDIRECTION:- [Transition is in the form- qno alphabet qno]\n",notransitions);
    printf("Enter transitions: \n");
    for(int i=0;i<notransitions;i++)
    {
        int from,to;
        char alpha;
        cin>>from>>alpha>>to;
        dfa[from].transition[alpha]=to;
    }

    int table[nostates][nostates]={0};
    for(int i=0;i<dfa.size();i++)
        for(int j=0;j<i;j++)
            if(dfa[i].final!=dfa[j].final)
                table[i][j]=1;

    bool isChange=true;
    while(isChange)
    {
        isChange=false;
        for(int i=0;i<dfa.size();i++)
            for(int j=0;j<i;j++)
                if(table[i][j]!=1)
                    for(auto k:dfa[i].transition)
                    {
                        int iTransition=dfa[i].transition[k.first];
                        int jTransition=dfa[j].transition[k.first];
                        if(iTransition>jTransition)
                            if(table[iTransition][jTransition]==1)
                            {
                                table[i][j]=1;
                                isChange=true;
                                break;
                            }
                        else if(iTransition<jTransition)
                            if(table[jTransition][iTransition]==1)
                            {
                                table[i][j]=1;
                                isChange=true;
                                break;
                            }
                    }
    }
    // printing table
    // for(int i=0;i<dfa.size();i++)
    // {
    //     for(int j=0;j<i;j++)
    //         cout<<table[i][j];
    //     cout<<endl;
    // }
    cout<<"\nStates in minimized dfa"<<endl;
    int done[nostates]={0};
    for(int i=nostates-1;i>=0;i--)
    {    
        if(done[i]==0)
        {
            cout<<"{ q"<<i;
            for(int j=i-1;j>=0;j--)
            {
                if(table[i][j]==0)
                {
                    cout<<" q"<<j;  
                    done[j]=1;  
                }
            }
            cout<<" }\n";
        }
        done[i]=1;
    }
}