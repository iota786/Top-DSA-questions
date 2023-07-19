class Solution {
public:
    
     void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis,int & maxi,int & mx){
        int n=grid.size(),m=grid[0].size();
      //int mx=1;
         mx++;
        vis[row][col]=1;
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(auto ele:dir){
            int nr=row+ele.first,nc=col+ele.second;
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1&&!vis[nr][nc]){
          // mx++;
                
            dfs(nr,nc,grid,vis,maxi,mx);
        }
           
    }  maxi=max(mx,maxi);
        
     }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        int maxi=0; 
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]==1){
                    int mx=0;
                    dfs(i,j,grid,vis,maxi,mx);
                }
            }
        }
        return maxi;
    }
};