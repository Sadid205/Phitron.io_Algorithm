#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
char A[N][N];
bool vis[N][N];
int cnt = 0;
vector<pair<int,int>> v= {{0,1},{0,-1},{-1,0},{1,0}};
void dfs(int i,int j,int n,int e)
{
    vis[i][j] = true;
    for(pair<int,int>child:v)
    {
        int si = i+child.first;
        int sj = j+child.second;
        if(si>=0&&si<e&&sj>=0&&sj<e&&A[si][sj]=='.')
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
                cnt++;
                dfs(i,j,n,e);
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}