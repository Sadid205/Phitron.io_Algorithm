#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int adj[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
           if(x==-1)
           {
            adj[i][j]=INT_MAX;
           }
           else 
           {
             adj[i][j]=x;
           }
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
              if(i!=j&&i!=k&&k!=j&&adj[i][k]!=INT_MAX&&adj[k][j]!=INT_MAX)
              {
                 if(adj[i][k]+adj[k][j]<adj[i][j])
                {
                    adj[i][j]= adj[i][k]+adj[k][j];
                }
              }
            }
        }
    }
    long long int Shortest = INT_MIN;
       for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           if(adj[i][j]!=INT_MAX && adj[i][j]>Shortest)
           {
            Shortest = adj[i][j];
           }
        }
    }
    if(Shortest==INT_MAX)
    {
        Shortest=0;
    }
    cout<<Shortest<<endl;
    return 0;
}