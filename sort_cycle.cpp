#include<bits/stdc++.h>
using namespace std; 

void cyclicsort(vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==v.size())
            continue;
        else{
            while(v[i]<v.size() && v[i] != i)
                swap(v[i],v[v[i]-1]);
        }
    }
    cout<<"F"<<endl;
}

int main()
{
    vector<int> v={7,9,8,1,5,6,4,3,5};
    for(auto i:v)
        cout<<i<<"   ";
    cout<<endl;
    cyclicsort(v);
    for(auto i:v)
        cout<<i<<"   ";
    return 0;
}