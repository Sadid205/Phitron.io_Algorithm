//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool vis[100005];
    int cnt;
    int parent [100005];
    void Cycle(int src,vector<int>adj[])
    {
        vis[src] = true;
        for(int child:adj[src])
        {
            if(vis[child]==true&&parent[src]!=child)
            {
                cnt++;
            }
            if(!vis[child])
            {
                parent[child] = src;
                Cycle(child,adj);
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        cnt=0;
        memset(vis,false,sizeof(vis));
        memset(parent,-1,sizeof(parent));
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                Cycle(i,adj);
            }
        }
        if(cnt>0)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends