class Solution {
public:
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int>path;
        
        dfs(graph,res,path,0); //start traversal from 1st node 
        return res;
    }

    void dfs(vector<vector<int>>& graph,vector<vector<int>>&res,vector<int>&path, int currNode)
    {
        path.push_back(currNode);  //push current node to path
        if(currNode==graph.size()-1) res.push_back(path);
        //traverse all neighbours of current node
        else{
            for(auto x: graph[currNode]) dfs(graph,res,path,x);
        }
        //pop currenly added node after each traversal because it has either reached n-1 or it has no neighbours 
        path.pop_back();
    }
};