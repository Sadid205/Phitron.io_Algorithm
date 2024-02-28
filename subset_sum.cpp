//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

long long int dp[1001][1001];
bool isTrue(long long int n,long long int s,vector<int>arr)
{
    if(n==0)
    {
        if(s==0)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    if(dp[n][s]!=-1)
    {
        return dp[n][s];
    }
    if(arr[n-1]<=s)
    {
         bool opt1 = isTrue(n-1,s-arr[n-1],arr);
        bool opt2 = isTrue(n-1,s,arr);
        return dp[n][s] = opt1||opt2;
    }
    else 
    {
        bool opt2 = isTrue(n-1,s,arr);
        return dp[n][s] = opt2;
    }
    
}
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        long long int n = arr.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                dp[i][j]=-1;
            }
        }
        return isTrue(n,sum,arr);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends