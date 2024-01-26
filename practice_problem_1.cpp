#include<bits/stdc++.h>
using namespace std;
vector<int> v[10005];
int level[10005];
bool vis[10005];
int parent[10005];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    level[src] = 0;
    vis[src] = true;
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
            level[child] = level[par]+1;
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
    
   
   int q;
   cin>>q;
   for(int i=0;i<q;i++)
   {
    int src,des;
    cin>>src>>des;
    memset(level,-1,sizeof(level));
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    bfs(src);
    cout<<level[des]<<endl;
   }
    

    return 0;
}