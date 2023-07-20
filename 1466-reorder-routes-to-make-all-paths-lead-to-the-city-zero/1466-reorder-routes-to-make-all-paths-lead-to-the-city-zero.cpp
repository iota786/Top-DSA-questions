class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it: connections){
             adj[it[0]].push_back({it[1],1});
             adj[it[1]].push_back({it[0],0});
        }

        queue<pair<int,int>>q;
        vector<int>vis(n,-1);
        q.push({0,0});
        int ans=0;

        while(!q.empty()){
            int node=q.front().first;
            int wt=q.front().second;
            q.pop();
            vis[node]=1;
           
            ans+=wt;

            for(auto it: adj[node]){
                if(vis[it.first]==-1) q.push(it);
                else continue;
            }
        }
        return ans;
    }
};