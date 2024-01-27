#include<bits/stdc++.h>
using namespace std;
char a[20][20];
bool vis[20][20];
int dis[20][20];
    int n,m;

vector<pair<int,int>>v = {{0,1},{0,-1},{-1,0},{1,0}};
bool valid(int si,int sj)
{
    if(si<0||si>=n||sj<0||sj>=m) return false;
    return true;
}
void bfs(int ci,int cj)
{
    queue<pair<int,int>>q;
    q.push({ci,cj});
    vis[ci][cj] = true;
    dis[ci][cj] = 0;
    while(!q.empty())
    {
        pair<int,int> par = q.front();
        int a = par.first;
        int b = par.second;
         q.pop();
        // cout<<a<<" "<< b << endl;
       for(int i=0;i<4;i++)
       {
        int si = a+v[i].first;
        int sj = b+v[i].second;
        if(valid(si,sj)==true && vis[si][sj]==false)
        {
            q.push({si,sj});
            vis[si][sj]= true;
            dis[si][sj] = dis[a][b]+1; 
        }
       }

    }
}
int main ()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int si,sj;
    cin>>si>>sj;
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
     bfs(si,sj);
    cout<<dis[2][3];
    return 0;
}