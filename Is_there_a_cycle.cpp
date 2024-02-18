#include<bits/stdc++.h>
using namespace std;
const int N = 55;
vector<int>v[N];
bool vis[N];
bool pathVisit[N];
bool flag = false;
void dfs(int src)
{
    vis[src]=true;
    pathVisit[src]=true;
    for(int child:v[src])
    {
        if(pathVisit[child])
        {
            flag=true;
        }
        if(!vis[child])
        {
            dfs(child);
        }
    }
    pathVisit[src]=false;
}
int main ()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            if(i!=j&&a==1)
            {
                v[i].push_back(j);
            }
        }
    }
    memset(vis,false,sizeof(vis));
    memset(pathVisit,false,sizeof(pathVisit));
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    if(flag==true)
    {
        cout<<1<<endl;
    }
    else 
    {
        cout<<0<<endl;
    }
    return 0;
}