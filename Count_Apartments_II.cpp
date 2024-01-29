#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int A[N][N];
bool vis[N][N];
int cnt = 0;
vector<int>Apt;
bool flag = false;
vector<pair<int,int>>v = {{0,1},{0,-1},{-1,0},{1,0}};
void dfs(int i,int j, int n,int e)
{
    vis[i][j] = true;
    cnt++;
    for(pair<int,int>child:v)
    {
        int si = i+child.first;
        int sj = j+child.second;
        if(si>=0&&si<n&&sj>=0&&sj<e&&A[si][sj]=='.')
        {
            if(vis[si][sj]==false)
            {
                 dfs(si,sj,n,e);
            }
        }
    }
}
int main ()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<e;j++)
        {
            char a;
            cin>>a;
            A[i][j] = a;
        }
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<e;j++)
        {
            if(A[i][j]=='.'&&vis[i][j]==false)
            {
                flag = true;
                dfs(i,j,n,e);
                Apt.push_back(cnt);
                cnt=0;
            }
        }
    }
    sort(Apt.begin(),Apt.end());
   if(flag==true)
   {
     for(int value:Apt)
    {
        cout<<value<<" ";
    }
   }
   else 
   {
    cout<<0<<endl;
   }
    return 0;
}