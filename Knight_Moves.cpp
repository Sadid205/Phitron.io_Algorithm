#include<bits/stdc++.h>
using namespace std;
int dis[105][105];
bool vis[105][105];
vector<pair<int,int>>v={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
bool valid(int i,int j,int n,int e)
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
void bfs(int i,int j,int di,int dj,int n,int e)
{
    queue<pair<int,int>>q;
    vis[i][j]=true;
    dis[i][j]=0;
    q.push({i,j});
    while(!q.empty())
    {
        pair<int,int>parent = q.front();
        int a = parent.first;
        int b = parent.second;
        q.pop();
        for(int ii=0;ii<8;ii++)
        {
            int ssi = a+v[ii].first;
            int ssj = b+v[ii].second;
            if(valid(ssi,ssj,n,e)==true&&vis[ssi][ssj]==false)
            {
                vis[ssi][ssj]=true;
                dis[ssi][ssj]=dis[a][b]+1;
                q.push({ssi,ssj});
            }
        }
    }
}
int main ()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n,e;
        cin>>n>>e;
        int si,sj;
        cin>>si>>sj;
        int di,dj;
        cin>>di>>dj;
        for(int k=0;k<n;k++)
        {
            for(int l=0;l<e;l++)
            {
                dis[k][l]=-1;
            }
        }
         for(int m=0;m<n;m++)
        {
            for(int r=0;r<e;r++)
            {
                vis[m][r]=false;
            }
        }
        bfs(si,sj,di,dj,n,e);
        cout<<dis[di][dj]<<endl;
    }

    return 0;
}