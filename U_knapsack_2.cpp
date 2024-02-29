#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int knapsack(int n,int value[],int weight[],int W)
{
    if(n<0||W==0)
    {
        return 0;
    }
    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }
    if(weight[n]<=W)
    {
        //duita option
        int opt1 = knapsack(n-1,value,weight,W-weight[n])+value[n];
        int opt2 = knapsack(n-1,value,weight,W);
        return dp[n][W] = max(opt1,opt2);
    }
    else 
    {
        int opt2 = knapsack(n-1,value,weight,W);
        return dp[n][W]=opt2;
    }
}
int main ()
{
    int n,W;
    cin>>n>>W;
    int weight[n],value[n];
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
        cin>>value[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<knapsack(n-1,value,weight,W)<<endl;

    return 0;
}