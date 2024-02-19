#include<bits/stdc++.h>
using namespace std;
const long long int N = 1e5+5;
long long int parent[N];
long long int group_size[N];
void dsu_initialize(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        group_size[i]=1;
    }
}
int dsu_find(int node)
{
    if(parent[node]==-1)
    {
        return node;
    }
    long long int Leader = dsu_find(parent[node]);
    parent[node] = Leader;
    return Leader;
}
void dsu_union(int node1,int node2)
{
    long long int LeaderA = dsu_find(node1);
    long long int LeaderB = dsu_find(node2);
    if(group_size[LeaderA]>group_size[LeaderB])
    {
        parent[LeaderB] = LeaderA;
        group_size[LeaderA]+=group_size[LeaderB];
    }
    else 
    {
        parent[LeaderA]=LeaderB;
        group_size[LeaderB]+=group_size[LeaderA];
    }
}
class Edge
{
    public:
    long long int u,v,w;
    Edge(int u,int v,int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int main ()
{
   
    long long int n,e;
    cin>>n>>e;
    dsu_initialize(n);
    vector<Edge>EdgeList;
    while(e--)
    {
        long long int u,v,w;
        cin>>u>>v>>w;
        EdgeList.push_back(Edge(u,v,w));
    }
    sort(EdgeList.begin(),EdgeList.end(),cmp);
     long long int cost=0;
    long long int cnt = 0;
    for(Edge child:EdgeList)
    {
        long long int u=child.u;
        long long int v=child.v;
        long long int LeaderU = dsu_find(u);
        long long int LeaderV = dsu_find(v);

        if(LeaderU==LeaderV)
        {
            continue;
        }
        else 
        {
            dsu_union(u,v);
            cost+=child.w;
            cnt++;
        }
    }
    if(cnt==n-1)
    {
        cout<<cost<<endl;
    }
    else 
    {
        cout<<-1<<endl;
    }
    return 0;
}