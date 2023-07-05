class Solution {
public:
vector<string>topo(queue<string>&q,unordered_map<string,int>&indegrees,unordered_map<string,vector<string>>&graph)
{ vector<string>ans;
    while(!q.empty())
    {
      auto node=q.front();
        q.pop();
        if(indegrees.find(node)!=indegrees.end())
        ans.push_back(node);
        for(auto &i :graph[node] )
        {
            indegrees[i]--;
            if(indegrees[i]==0)
            {
                q.push(i);
            }
        }
    }
    return ans;
}
   void buildGraph(vector<string>& recipes, vector<vector<string>>& ingredients,unordered_map<string,vector<string>>&graph,
        unordered_map<string,int>&indegrees)
   {
       for(int i=0;i<ingredients.size();i++)
        {
           for(auto &j:ingredients[i])
           {
              graph[j].push_back(recipes[i]);
              indegrees[recipes[i]]++;
           }
        }
   }
   void zeroIndegrees(queue<string>&q,vector<string>& supplies)
   {
       for(auto &i :supplies)
        q.push(i);
   }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string,vector<string>>graph;
        unordered_map<string,int>indegrees;
        buildGraph(recipes,ingredients,graph,indegrees);
        queue<string>q;
        zeroIndegrees(q,supplies);
        return topo(q,indegrees,graph);
        
    }
};