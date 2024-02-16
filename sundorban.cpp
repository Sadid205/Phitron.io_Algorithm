#include <bits/stdc++.h>
using namespace std;
bool vis[35][35];
char adj[35][35];
int dis[35][35];
int n;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n && (adj[i][j] == 'P' || adj[i][j] == 'E'));
}
vector<pair<int, int> > v;
void bfs(int i, int j)
{
    queue<pair<int, int> > q;
    vis[i][j] = true;
    dis[i][j] = 0;
    q.push({i, j});
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        int a = parent.first;
        int b = parent.second;
        if (adj[a][b] == 'E')
        {
            cout << dis[a][b] << endl;
        }
        q.pop();
        for (int i=0;i<4;i++)
        {
            int si = a+v[i].first;
            int sj = b+v[i].second;
            if (isValid(si, sj) && vis[si][sj] == false)
            {
                q.push({si, sj});
                vis[si][sj] = true;
                dis[si][sj] = dis[a][b] + 1;
            }
        }
    }
}
int main()
{
    v.push_back({0, 1});
    v.push_back({0,-1});
    v.push_back({-1,0});
    v.push_back({1, 0});
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char a;
                cin >> a;
                adj[i][j] = a;
            }
        }
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] == 'S')
                {
                    bfs(i, j);
                }
            }
        }
    }

    return 0;
}