#include<bits/stdc++.h>
using namespace std;
const int N = 20;
vector<int> V[N];
bool vis[N];
vector<int>CntNodes;
int cnt = 0;
void dfs(int src)
{
    vis[src] = true;
    cnt++;
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
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            dfs(i);
            CntNodes.push_back(cnt);
            cnt=0;
        }
    }
    sort(CntNodes.begin(),CntNodes.end());
    for(int value:CntNodes)
    {
        cout<<value<<" ";
    }
    return 0;
}