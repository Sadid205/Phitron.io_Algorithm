#include<bits/stdc++.h>
using namespace std;
bool flag;
long long int knapsack(long long int N,int long long n)
{
    if(n==N)
    {
        flag = true;
        return n;
    }
    if(n>N)
    {
        return n;
    }
    long long int opt1 =  knapsack(N,n*10);
    long long int opt2 = knapsack(N,n*20);
}
int main ()
{
     int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        long long int N;
        cin>>N;
        flag = false;
       long long int value = knapsack(N,1);
      
       if(flag==true)
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