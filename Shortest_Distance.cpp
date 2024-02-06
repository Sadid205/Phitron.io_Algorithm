#include<bits/stdc++.h>
using namespace std;

int main ()
{
   long long int n,e;
   cin>>n>>e;
    long long int adj[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            adj[i][j]=1e18;
            if(i==j)
            {
                adj[i][j]=0;
            }
        }
    };
    while(e--)
    {
        long long int a,b,c;
        cin>>a>>b>>c;
        if(adj[a][b]>c)
        {
            adj[a][b]=c;
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(adj[i][k]+adj[k][j]<adj[i][j])
                {
                    adj[i][j] = adj[i][k]+adj[k][j];
                }
            }
        }
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
       long long int x,y;
       cin>>x>>y;
       if(adj[x][y]==1e18)
       {
        cout<<-1<<endl;
       }
       else 
       {
        cout<<adj[x][y]<<endl;
       }
    }
    return 0;
}