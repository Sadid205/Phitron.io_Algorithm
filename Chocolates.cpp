#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int ii = 0; ii < T; ii++)
    {
        int n;
        cin >> n;
        int a[n];
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            s += a[j];
        }
        if (s % 2 == 0)
        {
            int ss = s / 2;
            bool dp[n + 1][ss + 1];
            dp[0][0] = true;
            for (int i = 1; i <= ss; i++)
            {
                dp[0][i] = false;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= ss; j++)
                {
                    if (a[i - 1] <= j)
                    {
                        dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            if(dp[n][ss]==true)
            {
                cout<<"YES"<<endl;
            }
            else 
            {
                cout<<"NO"<<endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}