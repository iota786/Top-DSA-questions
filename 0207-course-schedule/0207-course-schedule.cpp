class Solution {
public:
  bool toposort(vector<vector<int>>&adj)
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
        //vector<int>topo;
        int c=0;
        while(!q.empty())
        {

          int node=q.front();
            q.pop();
           // topo.push_back(node);
             c++;
            for(auto &i:adj[node]){
               indegrees[i]--;
                if(indegrees[i]==0)
                    q.push(i);
            
            }
        
        
        }
        return c==adj.size();
    
    
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &i:prerequisites)
        {
            adj[i[1]].push_back(i[0]);
        }
        return toposort(adj);
        
    }
};