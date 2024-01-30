#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> A[N];
bool vis[N];
int parent[N];
bool flag;
void dfs(int src)
{
    vis[src] = true;
    for(int child:A[src])
    {
        if(vis[child]==true&&child!=parent[src])
        {
            flag=true;
        }
        if(vis[child]==false)
        {
            parent[child] = src;
            dfs(child);
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
            dfs(i);
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