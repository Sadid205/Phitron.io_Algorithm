#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
 int n,e;
char a[N][N];
bool vis[N][N];
bool valid(int i,int j)
{
    if(i<0||i>=n||j<0||j>=e)
    {
        return false;
    }
    else
    {
        return true;
    }
}
vector<pair<int,int>>v={{0,1},{0,-1},{-1,0},{1,0}};
bool flag;
void dfs(int si,int sj,int di,int dj)
{
    vis[si][sj] = true;
    if(si==di&&sj==dj)
    {
        flag=true;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int ssi = si+v[i].first;
        int ssj = sj+v[i].second;
        if(valid(ssi,ssj)==true&&vis[ssi][ssj]==false&&a[ssi][ssj]=='.')
        {
            dfs(ssi,ssj,di,dj);
        }
    }
}
int main ()
{
   
    cin>>n>>e;
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<e;j++)
    {
        char x;
        cin>>x;
        a[i][j]=x;
    }
   }
   int si,sj;
   int di,dj;
    cin>>si>>sj;
    cin>>di>>dj;
    memset(vis,false,sizeof(vis));
    flag=false;
    dfs(si,sj,di,dj);
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