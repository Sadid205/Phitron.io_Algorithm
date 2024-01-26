#include<bits/stdc++.h>
using namespace std;
vector<int> v[1004];
bool vis[1004];
vector<int>levelValue;
void bfs(int src,int L)
{
    queue<pair<int,int>>q;
    q.push({src,0});
    vis[src] = true;
    while(!q.empty())
    {
       pair<int,int> p = q.front();
        int data = p.first;
        int level = p.second;
        if(level==L)
        {
           levelValue.push_back(data);
        }
        q.pop();
        for(int child:v[data])
        {
            if(vis[child]==false)
            {
                q.push({child,level+1});
                vis[child] = true;
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
    int L;
    cin>>L;
    memset(vis,false,sizeof(vis));
    bfs(0,L);
    reverse(levelValue.begin(),levelValue.end());
    for(int l:levelValue)
    {
        cout<<l<<" ";
    }
    
    return 0;
}