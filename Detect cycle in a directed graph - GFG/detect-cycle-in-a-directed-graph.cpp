//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool topoSort(int v,vector<int>adj[])
    {

    vector<int>indegrees(v);
        for(int i=0;i<v;i++)
        {
            for(auto &node:adj[i])
            {
                indegrees[node]++;
            }
        }
        queue<int>q;
        for(int i=0;i<indegrees.size();i++)
        {
            if(indegrees[i]==0)
                q.push(i);
        }
        vector<int>topo;
        int c=0;
        while(!q.empty())
        {

          int node=q.front();
            q.pop();
            topo.push_back(node);
             //c++;
            for(auto &i:adj[node]){
               indegrees[i]--;
                if(indegrees[i]==0)
                    q.push(i);
            
            }
        
        
        }
         if(topo.size()==v)
        return false;
         else
             return true;
    
    
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        return topoSort(V,adj);
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