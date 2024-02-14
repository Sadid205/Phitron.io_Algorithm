#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
bool vis[N];
int des[N];
vector<int>v[N];
void bfs(int src)
{
   queue<int>q;
    vis[src]=true;
    des[src]=0;
    q.push(src);
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        for(int child:v[parent])
        {
           if(vis[child]==false)
           {
             vis[child]=true;
            des[child]=des[parent]+1;
            q.push(child);
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
    int x,y,k;
    cin>>x>>y>>k;
    memset(vis,false,sizeof(vis));
    memset(des,-1,sizeof(des));
    bfs(x);
    if(des[y]!=-1&&des[y]<=k*2)
    {
        cout<<"YES"<<endl;
    }
    else 
    {
        cout<<"NO"<<endl;
    }
    return 0;
}