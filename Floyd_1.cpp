#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    long long int adj[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adj[i][j] = INT_MAX;
            if(i==j)
            {
                adj[i][j] = 0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            adj[i][j]=x;
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj[i][k]+adj[k][j]<adj[i][j])
                {
                    adj[i][j] = adj[i][k]+adj[k][j];
                }
            }
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

    return 0;
}