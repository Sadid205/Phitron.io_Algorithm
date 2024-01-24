#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
int level[1005];
int parent[1005];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    // bool pici = false;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        // cout<<par<<endl;
        // if(par==des)
        // {
        //     cout<<par<<endl;
        //     pici = true;
        // }
        for(int child:v[par])
        {
           if(vis[child]==false)
           {
            q.push(child);
            vis[child] = true;
            level[child] = level[par]+1;
            parent[child] = par;
           }
        }
    }
    // if(pici==false)
    // {
    //     cout<<-1<<endl;
    // }
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
    int src,des;
    cin>>src>>des;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    bfs(src);
    int x = des;
    vector<int> path;
    while(x!=-1)
    {
        path.push_back(x);
        x = parent[x];
    }
    reverse(path.begin(),path.end());
    for(int val:path)
    {
        cout<<val<<" ";
    }
   
    return 0;
}