class Solution {
public:

    int rob(vector<int>& nums) {
 int n=nums.size();
 
   vector<int>dp(n);
    dp[0]=nums[0]; 
        int neg=0;
        for(int i=1;i<n;i++)
        {
            int take=nums[i]+ (i-2>=0 ?dp[i-2]:0);
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[n-1];
    }
};