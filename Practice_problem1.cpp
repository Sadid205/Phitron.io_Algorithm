#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
vector<int> Adj[N];
bool vis[N];
int cnt =0;
void dfs(int Node)
{
    vis[Node] = true;
    cnt++;
    for(int child:Adj[Node])
    {
        if(vis[child]==false)
        {
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
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    int Node;
    cin>>Node;
    memset(vis,false,sizeof(vis));
    dfs(Node);
    cout<<cnt<<endl;
    return 0;
}