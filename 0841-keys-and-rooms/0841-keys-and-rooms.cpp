class Solution {
public:
    void dfs(int node,vector<vector<int>>&graph,vector<int>&vis)
    {
             vis[node]=1;
        for(auto &i : graph[node])
        {
           if(!vis[i]) dfs(i,graph,vis);
        }
    
    }
    bool canVisitAllRooms(vector<vector<int>>& graph) {
        //vector<vector<int>>graph=rooms;
        int n=graph.size();
        vector<int>vis(n);
        dfs(0,graph,vis);
        for(int i=0;i<n;i++) if(vis[i]==0) return false;
        return true;
    }
};