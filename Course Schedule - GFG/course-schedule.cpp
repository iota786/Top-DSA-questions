//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

// class Solution
// {
//   public:
//     vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
//     {
//         //code here
//     }
// };
class Solution {
public:
     vector<int> toposort(vector<vector<int>>&adj)
    {

    vector<int>indegrees(adj.size());
        for(int i=0;i<adj.size();i++)
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
         if(topo.size()==adj.size())
        return topo;
         else
             return {};
    
    
    }
    vector<int> findOrder(int n, int m,vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        for(auto &i:prerequisites)
        {
            adj[i[1]].push_back(i[0]);
        }
        return toposort(adj);
        
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends