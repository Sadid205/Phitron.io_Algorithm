#include<bits/stdc++.h>
using namespace std;
int main ()
{
    vector<pair<int,int>>v;
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    // for(int i=0;i<v.size();i++)
    // {
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    // for(pair<int,int>value:v)
    // {
    //     cout<<value.first<<" "<<value.second<<endl;
    // }
     for(auto value:v)
    {
        cout<<value.first<<" "<<value.second<<endl;
    }
    return 0;
}