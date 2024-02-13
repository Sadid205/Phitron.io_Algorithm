#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int adj[n][n];
    vector<int>v[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           cin>>adj[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(adj[i][j]==1&&i!=j)
            {
                v[i].push_back(j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
       for(int child:v[i])
       {
        cout<<child<<" ";
       }
       cout<<endl;
    }
    

    return 0;
}