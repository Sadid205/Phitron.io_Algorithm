#include<bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int>v[N];
int source_to_dis[N];
int dis_to_source[N];
bool vis[N];
void bfs(int src,int track)
{
     queue<int>q;
     q.push(src);
    if(track==1)
    {
        source_to_dis[src]=0;
    }
    else 
    {
        dis_to_source[src]=0;
    }
     vis[src]=true;
    while(!q.empty())
    {
        int par = q.front();
       q.pop();
       for(int child:v[par])
       {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=true;
                if(track==1)
                {
                    source_to_dis[child]=source_to_dis[par]+1;
                }
                else 
                {
                    dis_to_source[child]=dis_to_source[par]+1;
                }
            }
       }
    }
}
int main ()
{
    int t;
    cin>>t;
    int cs=1;
    while(t--)
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
        int s,d;
        cin>>s>>d;
        for(int i=0;i<n;i++)
        {
            vis[i]=false;
            source_to_dis[i]=-1;
        }
        bfs(s,1);
        for(int i=0;i<n;i++)
        {
            vis[i]=false;
            dis_to_source[i]=-1;
        }
        bfs(d,2);
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int val = source_to_dis[i]+dis_to_source[i];
            ans=max(ans,val);
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;
        for(int i=0;i<n;i++)
        {
            v[i].clear();
        }
    }

    return 0;
}