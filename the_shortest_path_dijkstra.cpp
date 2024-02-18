#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
long long int dis[N];
long long int parent[N];
vector<pair<long long int,long long int>>v[N];
class cmp
{
    public:
    bool operator()(pair<long long int,long long int>a,pair<long long int,long long int>b)
    {
        return a.second>b.second;
    }
};
void dijkstra(long long int src)
{
    priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,cmp>pq;
    pq.push({src,0});
    dis[src]=0;
   while(!pq.empty())
   {
    pair<long long int,long long int>par = pq.top();
    pq.pop();
    long long int node = par.first;
    long long int cost = par.second;
    for(pair<long long int,long long int>child:v[node])
    {
        long long int childNode = child.first;
        long long int childCost = child.second;
        if(cost+childCost<dis[childNode])
        {
            dis[childNode] = cost+childCost;
            pq.push({childNode,dis[childNode]});
            parent[childNode] = node;
        }
    }
   }
}
int main ()
{
     long long int n,e;
     cin>>n>>e;
     long long int s,d;
     cin>>s>>d;
     while(e--)
     {
        long long int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
     }
    for(int i=1;i<=n;i++)
    {
        dis[i]=1e18;
        parent[i]=-1;
    }
    dijkstra(s);
    if(dis[d]==1e18)
    {
        cout<<-1<<endl;
    }
    else {
        cout<<dis[d]<<endl;
        vector<long long int>ans;
        long long int x = d;
        while(x!=-1)
        {
            ans.push_back(x);
            x=parent[x];
        }
        reverse(ans.begin(),ans.end());
        for(long long int value:ans)
        {
            cout<<value<<" ";
        }
    }
    return 0;
}