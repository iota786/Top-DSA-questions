class Solution {
public:
    
        vector<int> found(vector<vector<int>>& land , int start_r , int start_c)
    {
        int end_r=start_r , end_c;
        while(end_r<land.size() && land[end_r][start_c]==1)
        {
             end_c=start_c;
            while(end_c<land[0].size() && land[end_r][end_c]==1)
            {
                land[end_r][end_c]=0;
                end_c++;
            }
            end_r++;
        }
        return {start_r, start_c , end_r-1 ,end_c-1};
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int rows=land.size(),columns=land[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(land[i][j]==1) ans.emplace_back(found(land,i,j));
            }
        }
        return ans;
    
    }
};