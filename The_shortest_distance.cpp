#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int adj[N][N];
vector<int> v[N];
int dis[N];
bool vis[N];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    dis[src]=0;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int child:v[par])
        {
            if(vis[child]==false)
            {
                q.push(child);
                vis[child]=true;
                dis[child]=dis[par]+1;
            }
        }
    }
}
int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            if (a == 1)
            {
                v[i].push_back(j);
            }
        }
    }
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    vector<int>ans;
    bfs(x);
    for(int i=1;i<=n;i++)
    {
        ans.push_back(dis[i]);
    }
    for(int value:ans)
    {
        cout<<value<<" ";
    }
    return 0;
}