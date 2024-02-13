#include<bits/stdc++.h>
using namespace std;
void convert(int n,vector<pair<int,int>>v[])
{
    int adj[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adj[i][j]=-1;
            if(i==j)
            {
                adj[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(pair<int,int>child:v[i])
        {
            int a = child.first;
            int c = child.second;
            adj[i][a]=c;
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
    vector<pair<int,int>>v[n];
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    convert(n,v);

    return 0;
}