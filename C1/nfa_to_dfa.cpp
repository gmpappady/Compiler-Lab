#include<bits/stdc++.h>
using namespace std;

struct s
{
    int sno;
    unordered_map <char,unordered_set<int>> transition;
    unordered_set <int> e_closure;
    bool final;
};

vector <unordered_set<int>> dfastates;//to store newly formed dfa states

void makeDFAState(unordered_set<int> x,vector<s> &nfa,vector<s> &dfa)
{
    //checking if new state is already present
    if(find(dfastates.begin(),dfastates.end(),x)!=dfastates.end())
        return;
    dfastates.push_back(x);
    //creating new dfa state
    s newstate;
    int isfinal=0;
    for(auto i:x)
    {
        if(nfa[i].final)
            isfinal=1;
        for(auto j:nfa[i].transition)
        {
            char sym=j.first;
            for(auto k: j.second)
                newstate.transition[sym].insert(k);
        }
    }
    newstate.final=isfinal;
    dfa.push_back(newstate);
    //recursive call for new states created
    for(auto i: newstate.transition)
        makeDFAState(i.second,nfa,dfa);     
}

int main()
{
    int nostates,notransitions,nofinalstates;
    cout<<"Enter number of states: ";
    cin>>nostates;
    vector <s> nfa(nostates);

    cout<<"Enter the no of final states: ";
    cin>>nofinalstates;
    for(int i=0;i<nofinalstates;i++)
    {
        int x;
        cin>>x;
        nfa[x].final=1;
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
        nfa[from].transition[alpha].insert(to);
    }

    vector <s> dfa;

    makeDFAState({0},nfa,dfa);

    cout<<"\nnewstate\tstatescombined\n";
    for(int i=0;i<dfastates.size();i++)
    {
        cout<<i<<"\t\t";
        for(auto j:dfastates[i])
            cout<<j<<" ";
        cout<<endl;
    }

    cout<<"\nstate\tsymbol\ttransition\n";
    for(int i=0;i<dfa.size();i++)
    {
        for(auto j:dfa[i].transition)
        {   
            cout<<i<<"\t"<<j.first<<"\t";
            for(auto k:j.second)
                cout<<k<<" ";
            cout<<endl;
        }
    }
    cout<<"\nfinal states: ";
    for(int i=0;i<nostates;i++)
        if(dfa[i].final==1)
            cout<<i<<" ";
}