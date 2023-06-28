class Solution {
public:
     void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis){
        int n=grid.size(),m=grid[0].size();
       /* if(row<0||row>=n||col<0||col>=m||grid[row][col]=='0'||vis[row][col]){
            return;
        }*/
        vis[row][col]=1;
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(auto ele:dir){
            int nr=row+ele.first,nc=col+ele.second;
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1&&!vis[nr][nc]){
            
            dfs(nr,nc,grid,vis);
        }}
    }
    int numEnclaves(vector<vector<int>>& grid) {
         int n = grid.size(); 
        int m = grid[0].size(); 
        vector<vector<int>>vis(n,vector<int>(m,0));
      for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // first row, first col, last row, last col 
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    // if it is a land then store it in queue
                    if(grid[i][j] == 1 && vis[i][j] ==0) {
                       
                         dfs(i,j,grid,vis);
                    }
                }
            }
      }
         int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // check for unvisited land cell
                if(grid[i][j] == 1 & vis[i][j] == 0) 
                    cnt++; 
            }
        }
        return cnt; 
    }
};