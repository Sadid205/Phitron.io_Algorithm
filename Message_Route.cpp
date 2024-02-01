#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<int>v[N];
bool vis[N];
int parent[N];
void bfs(int src)
{
    queue<int>q;
    vis[src] = true;
    q.push(src);
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
       for(int child:v[par])
       {
        if(vis[child]==false)
        {
            q.push(child);
            vis[child] = true;
            parent[child] = par;
        }
       }
    }
}
int main ()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    bfs(1);
    int x = n;
    vector<int>path;
    while(x!=-1)
    {
        path.push_back(x);
        x=parent[x];
    }
    reverse(path.begin(),path.end());
   
   if(vis[n]==false)
   {
    cout<<"IMPOSSIBLE"<<endl;
   }
   else 
   {
     cout<<path.size()<<endl;
     for(int value:path)
    {
        cout<<value<<" ";
    }
   }
    return 0;
}