#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int T;
    cin>>T;
    for(int k=0;k<T;k++)
    {
        int n;
        cin>>n;
         int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int i=0;
        int j=n-1;
         int ai=0;
        int aj=0;
        int ans = INT_MIN;
        while(i<j)
        {
          if(min(a[i],a[j])>ans)
          {
            ans = min(a[i],a[j]);
            ai = i;
            aj = j;
          }
          if(a[i]<a[j])
          {
            i++;
          }
          else 
          {
            j--;
          }
        }
        cout<<ai<<" "<<aj<<endl;
    }

    return 0;
}