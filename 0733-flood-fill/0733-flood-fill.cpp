class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& vis,int color,
             int row,int col,int iniColor,int delRow[],int delCol[])
    {
        vis[row][col]=color;
        int n=image.size();int m=image[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
            image[nrow][ncol] == iniColor && vis[nrow][ncol] != color)
            {
                dfs(image,vis,color, nrow,ncol,iniColor,delRow,delCol);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        int iniColor = image[sr][sc]; 
        vector<vector<int>>vis=image;
        dfs(image,vis,color,sr,sc,iniColor,delRow,delCol);
        return vis;

    }
};