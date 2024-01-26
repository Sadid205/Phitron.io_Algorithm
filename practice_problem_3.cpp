#include<bits/stdc++.h>
using namespace std;
vector<int> v[1004];
int main ()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int N;
    cin>>N;
    int count = 0;
   for(int child:v[N])
   {
         count++;   
   }
   cout<<count<<endl;

    return 0;
}