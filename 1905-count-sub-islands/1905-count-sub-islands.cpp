class Solution {
public:
  void dfs(int row,int col,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>& vis, bool & flag)
    {   vis[row][col]=1;
     if(grid1[row][col]!=1) 
         flag=false;
      int n=grid1.size(),m=grid1[0].size();
      // vis[row][col]=1;
      vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(auto ele:dir){
            int nr=row+ele.first,nc=col+ele.second;
            if(nr>=0 &&  nr<n && nc>=0 && nc< m && grid2[nr][nc]==1 && !vis[nr][nc]){
            
            dfs(nr,nc,grid1,grid2,vis,flag);
        }
        
        }
    
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
         int n=grid1.size();
        int m=grid1[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]==1 && grid2[i][j]==grid1[i][j]){
                     bool flag=true;
                    dfs(i,j,grid1,grid2,vis,flag); 
                    if(flag) cnt++;
                }
            }
        }
        return cnt;
    }
};