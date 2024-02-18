#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+5;
vector<int>v[N];
bool vis[N];
int dis[N];
int parent[N];
void bfs(int src)
{
    vis[src]=true;
    queue<int>q;
    q.push(src);
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
                parent[child] = par;
            }
        }
    }
}
int main ()
{
    int n,m;
    cin>>n>>m;
    int a,b;
    cin>>a>>b;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    memset(parent,-1,sizeof(parent));
    bfs(a);
    cout<<dis[b]<<endl;
    vector<int>ans;
    int x = b;
    while(x!=-1)
    {
        ans.push_back(x);
        x = parent[x];
    }
    reverse(ans.begin(),ans.end());
    for(int value:ans)
    {
        cout<<value<<" ";
    }
    return 0;
}