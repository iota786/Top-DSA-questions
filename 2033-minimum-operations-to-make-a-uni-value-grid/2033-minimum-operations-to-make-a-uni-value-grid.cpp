class Solution {
public:
     long long calc(vector<int>&nums, long long median,int x){

        long long ans = 0;

         for(int i=0;i<nums.size();i++)
         {
              if(abs(nums[i]-median)%x!=0) return -1;
         
           ans += (abs(1ll*nums[i]-median)/x);
             }
         return ans;  
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for(int i=0;i<grid.size();i++)
        {
           for(int j=0;j<grid[0].size();j++)
               v.push_back(grid[i][j]);
        }
        //for(int i=0;i<v.size();i++) cout<<v[i];
        sort(v.begin(),v.end());
        int median=v[(v.size()+1)/2-1];
       // cout<<median;
         return calc(v,median,x);
        
    }
};