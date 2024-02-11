#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>v[N];
bool vis[N];
void dfs(int src)
{
    vis[src]=true;
    for(int child:v[src])
    {
        if(vis[child]==false)
        {
            dfs(child);
        }
    }
}
int cnt;
int main ()
{
    int n,e;
    cin>>n>>e;
    vector<int>ans;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            ans.push_back(i);
            cnt++;
            dfs(i);
        }
    }
    cout << cnt - 1 << endl;
    for(int i=0;i<ans.size()-1;i++)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    return 0;
}