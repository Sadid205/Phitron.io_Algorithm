#include <bits/stdc++.h>
using namespace std;
const int N = 45;
int n;
char adj[N][N];
bool vis[N][N];

pair<int, int> path[N][N];
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n && vis[i][j] == false);
}
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
void bfs(int ii, int jj)
{
    vis[ii][jj] = true;
    queue<pair<int, int>> q;
    q.push({ii, jj});
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
        for (int i = 0; i < 4; i++)
        {
            int si = a + v[i].first;
            int sj = b + v[i].second;
            if (isValid(si, sj) && adj[si][sj] != 'O')
            {
                q.push({si, sj});
                vis[si][sj] = true;
                path[si][sj] = {v[i].first, v[i].second};
            }
        }
    }
}
int main()
{
    int xi, xj;
    int ei, ej;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            cin >> adj[i][j];
            if (adj[i][j] == '@')
            {
                xi = i;
                xj = j;
            }
            if (adj[i][j] == 'X')
            {
                ei = i;
                ej = j;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vis[i][j] = false;
            path[i][j] = {-1, -1};
        }
    }
    bfs(xi, xj);

    if (vis[ei][ej] == true)
    {
        cout << "Y" << endl;
        vector<pair<int, int>> ans;
        pair<int, int> dis = {ei, ej};
        while (dis.first != xi || dis.second != xj)
        {
            ans.push_back(path[dis.first][dis.second]);
            adj[dis.first][dis.second] = '+';
            dis.first -= ans.back().first;
            dis.second -= ans.back().second;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << "N" << endl;
    }

    return 0;
}