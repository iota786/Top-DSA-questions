class Solution {
public:
    int lis(int i,int prev,vector<int>& nums,vector< vector<int >>&dp,int n)
    {
        if(i>=nums.size()) return 0;
        if(dp[i][prev+1] !=-1) return dp[i][prev+1] ;
        int nott=lis(i+1,prev,nums,dp,n);
        int take=INT_MIN;
        if(prev==-1 

|| nums[i]>nums[prev])
        {
             take=1+lis(i+1,i,nums,dp,n);
        }
        return dp[i][prev+1] =max(take,nott);
    }
    int lengthOfLIS(vector<int>& nums) { int n=nums.size();
       vector< vector<int >>dp(n+1,vector<int>(n+1,-1));
      return  lis(0,-1,nums,dp,n);
        
    }
};