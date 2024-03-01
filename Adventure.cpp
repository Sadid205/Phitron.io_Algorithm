#include<bits/stdc++.h>
using namespace std;
long long int dp[1005][1005];
long long int knapsack(long long int n,long long int W, long long int weight[],long long int value[])
{
    if(n==0||W==0)
    {
        return 0;
    }
    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }
    if(weight[n-1]<=W)
    {
        int opt1 = knapsack(n-1,W-weight[n-1],weight,value)+value[n-1];
        int opt2 = knapsack(n-1,W,weight,value);
        return dp[n][W]=max(opt1,opt2);
    }
    else 
    {
        int opt2 = knapsack(n-1,W,weight,value);
        return dp[n][W] = opt2;
    }
}
int main ()
{
    long long int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        long long int n,W;
        cin>>n>>W;
        long long int weight[n];
        long long int value[n];
        for(int j=0;j<n;j++)
        {
            cin>>weight[j];
        }
        for(int j=0;j<n;j++)
        {
            cin>>value[j];
        }
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=W;k++)
            {
                dp[j][k] = -1;
            }
        }
        cout<<knapsack(n,W,weight,value)<<endl;
    }

    return 0;
}