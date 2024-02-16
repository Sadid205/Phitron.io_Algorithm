#include<bits/stdc++.h>
using namespace std;
int n,m;
char adj[25][25];
bool vis[25][25];
bool isValid(int i,int j)
{
    return(i>=0&&i<n&&j>=0&&j<m&&vis[i][j]==false&&adj[i][j]!='#');
}
vector<pair<int,int>>v={{0,1},{0,-1},{-1,0},{1,0}};
int step;
void dfs(int i,int j)
{
    vis[i][j]=true;
    step++;
    for(pair<int,int>child:v)
    {
        int ci = i+child.first;
        int cj = j+child.second;
        if(isValid(ci,cj))
        {
            dfs(ci,cj);
        }
    }
}
int main ()
{
    int t;
    cin>>t;
     int cs=1;
    while(t--)
    {
        
        cin>>m>>n;
        int si,sj;
        step=0;
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char a;
                cin>>a;
                adj[i][j]=a;
                if(a=='@')
                {
                    si=i;
                    sj=j;
                }
            }
        }
        memset(vis,false,sizeof(vis));
        dfs(si,sj);
        cout<<"Case "<<cs++<<": "<<step<<endl;
    }

    return 0;
}