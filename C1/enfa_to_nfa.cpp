#include<bits/stdc++.h>
using namespace std;

struct s
{
    int sno;
    unordered_map <char,unordered_set<int>> transition;
    unordered_set <int> e_closure;
    bool final;
};

void findclosure(int sno,int current,vector <s> &state)
{
    if(state[current].e_closure.find(sno)!=state[current].e_closure.end())
        return;
    state[current].e_closure.insert(sno);
    for(auto i:state[sno].transition['e'])
    {
        findclosure(i,current,state);
    }
}

int main()
{
    int nostates,notransitions,nofinalstates;
    cout<<"Enter number of states: ";
    cin>>nostates;
    vector <s> enfa(nostates);

    cout<<"Enter the no of final states: ";
    cin>>nofinalstates;
    for(int i=0;i<nofinalstates;i++)
    {
        int x;
        cin>>x;
        enfa[x].final=1;
    }
    
    cout<<"Enter number of transitions: ";
    cin>>notransitions;
    printf("DIRECTION:- [Transition is in the form- qno alphabet qno]\n",notransitions);
    printf("\nEnter transitions: \n");
    for(int i=0;i<notransitions;i++)
    {
        int from,to;
        char alpha;
        cin>>from>>alpha>>to;
        enfa[from].transition[alpha].insert(to);
    }
    
    for(int i=0;i<nostates;i++)
    {
        findclosure(i,i,enfa);
    }

    vector <s> nfa(nostates);
    for(int i=0;i<nostates;i++)
    {
        for(auto j:enfa[i].e_closure)
        {
            for(auto k:enfa[j].transition)
            {
                char c=k.first;
                if(c!='e')
                    for(auto l: k.second)
                    {
                        for(auto m: enfa[l].e_closure)
                            nfa[i].transition[c].insert(m);
                    }
            }
        }
    }

    for(int i=0;i<nostates;i++)
        for(auto j: enfa[i].e_closure)
            if(enfa[j].final==1)
                nfa[i].final=1;
    
    cout<<"\nstate\tsymbol\ttransitions\n";
    for(int i=0;i<nostates;i++)
    {
        for(auto j:nfa[i].transition)
        {   
            cout<<i<<"\t"<<j.first<<"\t";
            for(auto k:j.second)
                cout<<k<<" ";
            cout<<endl;
        }
    }
    cout<<"\nfinal states: ";
    for(int i=0;i<nostates;i++)
        if(nfa[i].final==1)
            cout<<i<<" ";
}