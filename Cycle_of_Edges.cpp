#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
int group_size[N];
void dsu_initialize(int n)
{
    for(int i=0;i<n;i++)
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
    int Leader = dsu_find(parent[node]);
    return Leader;
}
void dsu_union(int node1,int node2)
{
    int LeaderA = dsu_find(node1);
    int LeaderB = dsu_find(node2);
    if(group_size[LeaderA]>group_size[LeaderB])
    {
        parent[LeaderB]=LeaderA;
        group_size[LeaderA]+=group_size[LeaderB];
    }
    else 
    {
        parent[LeaderA] = LeaderB;
        group_size[LeaderB]+=group_size[LeaderA];
    }
}
int main ()
{
    int n,e;
    cin>>n>>e;
    int cnt=0;
    dsu_initialize(n);
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        int LeaderA = dsu_find(a);
        int LeaderB = dsu_find(b);
        if(LeaderA==LeaderB)
        {
            cnt++;
        }
        else 
        {
            dsu_union(a,b);
        }
    }
    cout<<cnt<<endl;
    return 0;
}