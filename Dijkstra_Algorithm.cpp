#include<bits/stdc++.h>
using namespace std;
const int N = 100+5;
vector<pair<int,int>>v[N];
int arr[N][N];
int dis[N];
void dijkstra(int src)
{
    queue<pair<int,int>>q;
    q.push({src,0});
    dis[src] = 0;
    while(!q.empty())
    {
        pair<int,int> parent = q.front();
        q.pop();
        int node = parent.first;
        int cost = parent.second;
        for(pair<int,int>child:v[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(cost+childCost<dis[childNode])
            {
                dis[childNode] = cost+childCost;
                q.push({childNode,dis[childNode]});
            }
        }
    }

}
int main ()
{
    int n,s,f;
   cin>>n>>s>>f;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int a;
            cin>>a;
            arr[i][j] = a;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j&&arr[i][j]!=-1)
            {
                v[i].push_back({j,arr[i][j]});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(s);
    if(dis[f]==INT_MAX)
    {
        cout<<-1<<endl;
    }
    else 
    {
        cout<<dis[f]<<endl;
    }
    
  
    return 0;
}