#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int T;
    cin>>T;
    for(int k=0;k<T;k++)
    {
        int n,m;
        cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int target = 1000-m;
        bool dp[n+1][target+1];
        dp[0][0] = true;
        for(int i=1;i<=target;i++)
        {
            dp[0][i] = false;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(a[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
                }
                else 
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][target])
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