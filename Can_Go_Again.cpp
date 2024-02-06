#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
class Edge
{
public:
    long long int u, v, c;
    Edge(long long int u, long long int v, long long int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
long long dis[N];
int main()
{
    long long int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
       long long int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
    }
    int s;
    cin >> s;
    dis[s] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge child : EdgeList)
        {
            long long int u = child.u;
            long long int v = child.v;
            long long int c = child.c;
            if (dis[u] < 1e18 && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool flag = false;
    for (Edge child : EdgeList)
    {
        long long int u = child.u;
        long long int v = child.v;
        long long int c = child.c;
        if (dis[u] < 1e18 && dis[u] + c < dis[v])
        {
            flag = true;
            break;
        }
    }
   long long int q;
    cin >> q;
    if (flag == true)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        for (int i = 1; i <= q; i++)
        {
           long long int x;
            cin >> x;
            if (dis[x] == 1e18)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[x] << endl;
            }
        }
    }
    return 0;
}