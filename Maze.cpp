#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
 int n,e;
char adj[N][N];
pair<int,int>path[N][N];
bool vis[N][N];
vector<pair<int,int>>v={{0,1},{0,-1},{-1,0},{1,0}};
int si,sj;
int di,dj;
bool isValid(int i,int j)
{
    return (i>=0&&i<n&&j>=0&&j<e&&adj[i][j]!='#'&&vis[i][j]==false);
}
void bfs(int i,int j)
{
    vis[i][j]=true;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty())
    {
        pair<int,int>par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
        for(pair<int,int>child:v)
        {
            int si = a+child.first;
            int sj = b+child.second;
            if(isValid(si,sj))
            {
                q.push({si,sj});
                vis[si][sj]=true;
                path[si][sj] = {child.first,child.second};
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
           char x;
           cin>>x;
           adj[i][j]=x;
           if(x=='R')
           {
            si=i;
            sj=j;
           }
           if(x=='D')
           {
            di=i;
            dj=j;
           }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<e;j++)
        {
            vis[i][j]=false;
            path[i][j]={-1,-1};
        }
    }
    bfs(si,sj);
    if(vis[di][dj]==true)
    {
        vector<pair<int,int>>ans;
        pair<int,int>dis = {di,dj};
        while(dis.first!=si||dis.second!=sj)
        {
            ans.push_back(path[dis.first][dis.second]);
            if(adj[dis.first][dis.second]!='D')
            {
                adj[dis.first][dis.second] = 'X';
            }
            dis.first-=ans.back().first;
            dis.second-=ans.back().second;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<e;j++)
            {
                cout<<adj[i][j];
            }
            cout<<endl;
        }
    }
    else 
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<e;j++)
            {
                cout<<adj[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}