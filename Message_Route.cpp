#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>v[N];
bool vis[N];
int parent[N];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
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
            parent[child]= par;
        }
       }
    }
}
int main ()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    bfs(1);
    vector<int>ans;
    int x = n;
    while(x!=-1)
    {
        ans.push_back(x);
        x=parent[x];
    }
    reverse(ans.begin(),ans.end());
    if(vis[n]==false)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        cout<<ans.size()<<endl;
        for(int value:ans)
        {
            cout<<value<<" ";
        }
    }
    return 0;
}