#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> A[N];
bool vis[N];
bool pathVisit [N];
bool flag;
void dfs(int par)
{
    vis[par]= true;
    pathVisit[par] = true;
    for(int child:A[par])
    {
        if(pathVisit[child])
        {
            flag = true;
        }
        if(!vis[child])
        {
            dfs(child);
        }
    }
    // kaj shes
    pathVisit[par] = false;

}
int main ()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        A[a].push_back(b);
    }   
    memset(vis,false,sizeof(vis));
    memset(pathVisit,false,sizeof(pathVisit));
    flag = false;
    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    if(flag)
    {
        cout<<"Cycle Detect"<<endl;
    }
    else 
    {
        cout<<"Cycle not found"<<endl;
    }
    return 0;
}