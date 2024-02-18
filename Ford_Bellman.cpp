#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int dis[N];
class Edge
{
    public:
    int u,v,w;
    Edge(int u,int v,int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main ()
{
  vector<Edge>EdgeList; 
  int n,e;
  cin>>n>>e;
  while(e--)
  {
    int u,v,w;
    cin>>u>>v>>w;
    EdgeList.push_back(Edge(u,v,w));
  }
  for(int i=1;i<=n;i++)
  {
    dis[i]=30000;
  }
  dis[1]=0;
    for(int i=1;i<=n-1;i++)
    {
        for(Edge child:EdgeList)
        {
            int u = child.u;
            int v = child.v;
            int w = child.w;
            if(dis[u]<30000&&dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }

    return 0;
}