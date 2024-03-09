#include<bits/stdc++.h>
using namespace std;
void marge(int a[],int n,int m,int r)
{
    int leftSize = m-n+1;
    int rightSize = r-m;
    int l[leftSize];
    int R[rightSize];
    int k = 0;
    for(int i=n;i<=m;i++)
    {
        l[k] = a[i];
        k++;
    }
    k=0;
    for(int i=m+1;i<=r;i++)
    {
        R[k]=a[i];
        k++;
    }
    int i=0;
    int j=0;
    int curr = n;
    while(i<leftSize&&j<rightSize)
    {
        if(l[i]<=R[j])
        {
            a[curr] = l[i];
            i++;
        }
        else 
        {
            a[curr] = R[j];
            j++;
        }
        curr++;
    } 
    while(i<leftSize)
    {
        a[curr] = l[i];
        i++;
        curr++;
    }
    while(j<rightSize)
    {
        a[curr] = R[j];
        j++;
        curr++;
    }
   
}
int main ()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    marge(a,0,3,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}