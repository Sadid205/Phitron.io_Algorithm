#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int parent[N];
int group_size[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }
    int Leader = dsu_find(parent[node]);
    parent[node] = Leader;
    return Leader;
}
void dsu_union(int node1, int node2)
{
    int LeaderA = dsu_find(node1);
    int LeaderB = dsu_find(node2);
    if (group_size[LeaderA] > group_size[LeaderB])
    {
        parent[LeaderB] = LeaderA;
        group_size[LeaderA] += group_size[LeaderB];
    }
    else
    {
        parent[LeaderA] = LeaderB;
        group_size[LeaderB] += group_size[LeaderA];
    }
}
int main()
{
    bool flag = true;
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int LeaderA = dsu_find(a);
        int LeaderB = dsu_find(b);
        if (LeaderA != LeaderB)
        {
            dsu_union(a, b);
        }
    }
    for(int i=0;i<n;i++)
    {
        int LeaderA = dsu_find(1);
        int LeaderB = dsu_find(i);
        if(LeaderA!=LeaderB)
        {
            flag=false;
            break;
        }
    }
    if(flag==true)
    {
        cout<<"YES"<<endl;
    }
    else 
    {
        cout<<"NO"<<endl;
    }

    return 0;
}