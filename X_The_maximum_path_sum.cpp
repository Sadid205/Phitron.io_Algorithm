#include<bits/stdc++.h>
using namespace std;
const int N  = 15;
 int n,m;
long long int dp[N][N];
long long int mat[N][N];
long long int knapsack(int i,int j)
{
    if(i==n-1&&j==m-1) return mat[i][j];
    if(i>=n||j>=m)
    {
        return INT_MIN;
    }
    if(dp[i][j]!=INT_MIN)
    {
        return dp[i][j];
    }
    long long int  opt1 = knapsack(i+1,j);
    long long int opt2 = knapsack(i,j+1);
    return dp[i][j] = max(opt1,opt2)+mat[i][j];
}
int main ()
{
   
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
            dp[i][j]=INT_MIN;
        }
    }
    cout<<knapsack(0,0)<<endl;
    return 0;
}