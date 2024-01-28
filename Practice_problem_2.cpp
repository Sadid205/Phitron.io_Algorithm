#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
vector<int> V[N];
bool vis[N];
void dfs(int src)
{
    vis[src] = true;
    for(int child:V[src])
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
        V[a].push_back(b);
        V[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}