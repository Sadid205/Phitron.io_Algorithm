#include<bits/stdc++.h>
using namespace std;
void convert(int n,vector<int>v[])
{
    int adj[n][n];
    
    for(int i=0;i<n;i++)
    {
        for(int child:v[i])
        {
            adj[i][child]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main ()
{
    int n,e;
    cin>>n>>e;
    vector<int>v[n];
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    convert(n,v);

    return 0;
}