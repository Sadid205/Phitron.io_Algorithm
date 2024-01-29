#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int mat[N][N];
int main ()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        mat[a][b] = 1;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int c,d;
        cin>>c>>d;
        if(c==d || mat[c][d]==1)
        {
            cout<<"YES"<<endl;
        }
        else 
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}