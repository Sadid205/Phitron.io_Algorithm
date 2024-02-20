#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int bp[n];
    bp[0] = 0;
    bp[1] = 1;
    for(int i=2;i<=n;i++)
    {
        bp[i]=bp[i-1]+bp[i-2];
    }
    cout<<bp[n]<<endl;

    return 0;
}