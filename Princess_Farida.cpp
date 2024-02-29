#include<bits/stdc++.h>
using namespace std;
long long int dp[1005];
long long int coins(long long int n,long long int a[])
{
    if(n<0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
   long long int collect = a[n]+coins(n-2,a);
   long long  int skip =coins(n-1,a);
    return dp[n]=max(collect,skip);
}
int main ()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        long long int n;
        cin>>n;
        long long int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        memset(dp,-1,sizeof(dp));
        long long int amount = coins(n-1,a);
        cout<<"Case "<<i<<": "<<amount<<endl;
    }
    return 0;
}