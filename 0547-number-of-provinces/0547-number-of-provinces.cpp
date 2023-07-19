class Solution {
public:
    void dfs(int i,vector<int>&vis,vector<int>adj[])
    {
       vis[i]=1;
        for(auto &node :adj[i])
        {   if(!vis[node])
            dfs(node,vis,adj);
        }
    
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                if(isConnected[i][j]==1 & i!=j)
                {

                 adj[i].push_back(j);
                    adj[j].push_back(i);
                
                }
}
        }
            vector<int>vis(n); int c=0;
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    c++;
                    dfs(i,vis,adj);
                }
                
            }
        return c;
        
    }
};