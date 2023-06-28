class Solution {
public:
    bool bfs(int sv,vector<vector<int>> graph, vector<int>&color, vector<bool>&vis){
    
    queue<int>q;
    q.push(sv);
    vis[sv]=true; //marked as visited
    color[sv]=1;  //markes color of sv as 1  
    //colors available are 1 and 0 and initially it is -1
    
    while(!q.empty()){
        
        int curr=q.front();
        q.pop();
        
        for(int x:graph[curr]){
            
            if(color[x]==-1){  //if color == -1 i.e. not visisted 
                vis[x]=true;
                color[x]=!color[curr];  //complement of curr i.e. 0
                q.push(x);
            }
            
            else if(color[x]==color[curr]){
                return false;
            }
            
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    
    vector<bool>vis(graph.size(),false);  //visited array
    vector<int> color(graph.size(),-1);  //color array
    
    for(int i=0;i<graph.size();i++){  //tarversing all the nodes
        if(!vis[i]){
            bool ans=bfs(i,graph,color,vis);
            if(!ans){
                return false;
            }
        }
    }
    return true;
    }
};