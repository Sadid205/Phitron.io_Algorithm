#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
char mat[N][N];
bool vis[N][N];
vector<pair<int,int>>v={{0,1},{0,-1},{-1,0},{1,0}};
bool flag = false;
void dfs(int i,int j,int n,int e)
{
   vis[i][j] = true;
   for(pair<int,int>child:v)
   {
        int si = i+child.first;
        int sj = j+child.second;
        if(mat[si][sj]=='B')
        {
            flag = true;
            return;
        }
        if(si>=0&&si<n&&sj>=0&&sj<e&&mat[si][sj]=='.')
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
        mat[i][j] = a;
    }
  }
for(int i=0;i<n;i++)
{
   for(int j=0;j<e;j++)
   {
    if(mat[i][j]=='A')
    {
         dfs(i,j,n,e);
    }
   }
}
if(flag==true)
{
    cout<<"YES"<<endl;
}
else 
{
    cout<<"NO"<<endl;
}

    return 0;
}