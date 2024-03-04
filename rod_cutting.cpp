#include<bits/stdc++.h>
using namespace std;
int dp[10001][10001];
int unbound_knapsack(int n,int s ,int val[],int w[])
{
    if(n==0||s==0)
    {
        return 0;
    }
    if(dp[n][s]!=-1)
    {
        return dp[n][s];
    }
    if(w[n-1]<=s)
    {
        int opt1 = val[n-1]+unbound_knapsack(n,s-w[n-1],val,w);
        int opt2 = unbound_knapsack(n-1,s,val,w);
        return dp[n][s] = max(opt1,opt2);
    }
    else 
    {
        int opt2 = unbound_knapsack(n-1,s,val,w);
        return dp[n][s]=opt2;
    }
}
int main ()
{
    int n;
    cin>>n;
    int val[n];
    int w[n];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j] = -1;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
        w[i] = i+1;
    }
   
    cout<<unbound_knapsack(n,n,val,w)<<endl;
    
    return 0;
}