#include<bits/stdc++.h>
using namespace std;
long long int dp[100005];
long long int knapsack(int N,int n)
{
    if(N==n)
    {
        return n;
    }
    if(n>N)
    {
        return 0;
    }
     if(dp[n]!=-1)
    {
        return dp[n];
    }
    long long int opt1 = knapsack(N,n+3);
    long long int opt2 = knapsack(N,n*2);
    return dp[n] = opt1||opt2;
}
int main ()
{
    long long int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        long long int N;
        cin>>N;
        memset(dp,-1,sizeof(dp));
        if(knapsack(N,1)==1)
        {
            cout<<"YES"<<endl;
        }
        else 
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}