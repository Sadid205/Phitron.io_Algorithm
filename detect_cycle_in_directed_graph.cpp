//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool vis[100005];
    bool pathVisit[100005];
    bool flag;
    void Cycle(int par,vector<int>adj[])
    {
        vis[par] = true;
        pathVisit[par]=true;
        for(int child:adj[par])
        {
            if(pathVisit[child]==true)
            {
                flag=true;
            }
            if(!vis[child])
            {
                Cycle(child,adj);
            }
        }
        pathVisit[par]=false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        memset(vis,false,sizeof(vis));
        memset(pathVisit,false,sizeof(pathVisit));
        flag = false;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                Cycle(i,adj);
            }
        }
       return flag;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends