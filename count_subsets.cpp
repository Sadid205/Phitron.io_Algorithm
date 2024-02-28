long long int dp[1001][1001];
int sub_set(vector<int>&arr,int n,int s)
{
	if(n==0)
	{
		if(s==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(dp[n][s]!=-1)
	{
		return dp[n][s];
	}
	if(arr[n-1]<=s)
	{
		long long int opt1 = sub_set(arr,n-1,s-arr[n-1]);
		long long int opt2 = sub_set(arr,n-1,s);
		return dp[n][s] = (opt1+opt2)%1000000007;
	}
	else
	{
		long long int opt2 = sub_set(arr,n-1,s);
		return dp[n][s]=opt2;
	}
	
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			dp[i][j]=-1;
		}
	}
	return sub_set(arr,n,k);
}
