#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5;
int parent[N];
int group_size[N];
void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
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
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    dsu_initialize(n);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        EdgeList.push_back(Edge(u, v, w));
    }
    sort(EdgeList.begin(), EdgeList.end(), cmp);
    int cnt = 0;
    long long int cost = 0;
    for (Edge child : EdgeList)
    {
        int u = child.u;
        int v = child.v;
        int w = child.w;
        int LeaderA = dsu_find(u);
        int LeaderB = dsu_find(v);
        if (LeaderA == LeaderB)
        {
            continue;
        }
        else
        {
            dsu_union(u, v);
            cnt++;
            cost += w;
        }
    }
    if (cnt == n - 1)
    {
        cout << e - cnt << " " << cost << endl;
    }
    else
    {
        cout << "Not Possible" << endl;
    }
    return 0;
}