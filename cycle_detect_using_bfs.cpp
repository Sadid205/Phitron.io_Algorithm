#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> A[N];
bool vis[N];
int parent[N];
bool flag;
void bfs(int src)
{
    vis[src] = true;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int child:A[par])
        {
            if(vis[child]==true&&parent[par]!=child)
            {
                flag = true;
            }
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
        A[a].push_back(b);
        A[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    flag=false;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            bfs(i);
        }
    }
    if(flag)
    {
        cout<<"Cycle Detect"<<endl;
    }
    else 
    {
        cout<<"Cycle Not Found"<<endl;
    }
    return 0;
}