#include <bits/stdc++.h>
using namespace std;
const int max_N = 1000;
const int max_M = 1000;
int dp[max_N][max_M];
int knapsack(int n, int weight[], int value[], int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (weight[n - 1] <= W)
    {
        // duita option
        // nibo
        // nibona
        int opt1 = knapsack(n - 1, weight, value, W - weight[n - 1]) + value[n - 1];
        int opt2 = knapsack(n - 1, weight, value, W);
        return dp[n][W] = max(opt1, opt2);
    }
    else
    {
        // ekta option
        // nibona
        int opt2 = knapsack(n - 1, weight, value, W);
        return dp[n][W] = opt2;
    }
}
int main()
{
    int n;
    cin >> n;
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int W;
    cin >> W;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n, weight, value, W) << endl;

    return 0;
}