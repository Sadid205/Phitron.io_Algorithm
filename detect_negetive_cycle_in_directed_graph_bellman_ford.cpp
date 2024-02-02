#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
int dis[N];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge child : EdgeList)
        {
            int u, v, c;
            u = child.u;
            v = child.v;
            c = child.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool cycle = false;
    for (Edge child : EdgeList)
    {
        int u, v, c;
        u = child.u;
        v = child.v;
        c = child.c;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "Cycle Detect!No answer found" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "->"
                 << " " << dis[i] << endl;
        }
    }

    return 0;
}