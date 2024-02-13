#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,e;
    cin>>n>>e;
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
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a][b] = c;
        adj[b][a] = c;
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}