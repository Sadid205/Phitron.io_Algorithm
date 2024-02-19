#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
char adj[N][N];
bool vis[N][N];
int n,e;
vector<pair<int,int>>v={{-1,0},{1,0},{0,-1},{0,1}};
bool isValid(int i,int j)
{
    return (i>=0&&i<n&&j>=0&&j<e&&adj[i][j]=='.'&&vis[i][j]==false);
}
int cnt;
int min_steps = INT_MAX;
void bfs(int i,int j)
{
    vis[i][j]=true;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty())
    {
        pair<int,int> par = q.front();
        int a = par.first;
        int b = par.second;
        cnt++;
        q.pop();
       for(pair<int,int>child:v)
       {
        int si = a+child.first;
        int sj = b+child.second;
        if(isValid(si,sj))
        {
            vis[si][sj]=true;
            q.push({si,sj});
        }
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
            cin>>adj[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<e;j++)
        {
            if(vis[i][j]==false && adj[i][j]=='.')
            {
                cnt=0;
                bfs(i,j);
                min_steps = min(cnt,min_steps);
            }
        }
    }
    if(cnt==0)
    {
        cout<<-1<<endl;
    }
    else 
    {
        cout<<min_steps<<endl;
    }

    return 0;
}