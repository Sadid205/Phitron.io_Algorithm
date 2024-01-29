#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> A[N];
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if (A[x].empty())
        {
            cout << -1 << endl;
        }
        else
        {
            sort(A[x].begin(), A[x].end(), greater<int>());
            for (int value : A[x])
            {
                cout << value << " ";
            }
              cout << endl;
        }
      
    }
    return 0;
}