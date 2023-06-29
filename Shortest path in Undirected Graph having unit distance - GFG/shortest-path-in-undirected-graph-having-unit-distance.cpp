//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
 private:
    void findShortestPath(vector<int>adj[],int V,int node,vector<int>&vis,vector<int>&dist){
        vis[node] = 1;
        for(auto adjNode:adj[node]){
            if(dist[adjNode]>dist[node]+1)
                dist[adjNode] = dist[node]+1;
            if(!vis[adjNode]){
                findShortestPath(adj,V,adjNode,vis,dist);
            }
        }
        vis[node] = 0;
    return;
    }
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>adj[N];
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(N,0);
        vector<int>dist(N,INT_MAX);
        dist[src] = 0;
        findShortestPath(adj,N,src,vis,dist);
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX){
                dist[i] = -1;
            }
        }
    return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends