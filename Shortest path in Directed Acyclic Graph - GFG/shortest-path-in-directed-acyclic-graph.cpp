//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
         // code here
             vector<vector<int>>adj[N];
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
           // adj[v].push_back(u);
        }
       // vector<int>vis(N,0);
        vector<int>dist(N,1e9);
        dist[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        while(!q.empty())
        {
            int node=q.top().second;
            int dis=q.top().first;
            
            q.pop();
            for(auto &it:adj[node])
            {  int weight=it[1];
            int nod=it[0];
                if(dist[nod]>dis+weight)
                {q.push({dist[node]+weight,nod});
                dist[nod]=weight+dist[node];}
            }
        }
        for(auto &i:dist)
        if(i==1e9) i=-1;
    return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends