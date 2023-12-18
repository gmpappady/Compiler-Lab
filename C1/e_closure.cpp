#include<bits/stdc++.h>
using namespace std;

struct s
{
    int sno;
    unordered_map <char,unordered_set<int>> transition;
    unordered_set <int> e_closure;
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
    int nostates,notransitions;
    cout<<"Enter number of states: ";
    cin>>nostates;
    vector <s> state(nostates);
    cout<<"Enter number of transitions: ";
    cin>>notransitions;
    printf("DIRECTION:- [Transition is in the form- qno alphabet qno]\n",notransitions);
    printf("\nEnter transitions: \n");
    for(int i=0;i<notransitions;i++)
    {
        int from,to;
        char alpha;
        cin>>from>>alpha>>to;
        state[from].transition[alpha].insert(to);
    }

    for(int i=0;i<nostates;i++)
    {
        findclosure(i,i,state);
    }

    cout<<endl;
    for(int i=0;i<nostates;i++)
    {
        cout<<"e-closure("<<i<<") :";
        for(auto x:state[i].e_closure)
            cout<<x<<" ";
        cout<<endl;
    }
}