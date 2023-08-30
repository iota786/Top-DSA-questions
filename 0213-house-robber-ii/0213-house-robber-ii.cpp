class Solution {
public:

    int robb(vector<int>& nums,int start,int end) {
 //int n=nums.size();
 
   vector<long long >dp(end+2);
    dp[start]=nums[start]; 
        int neg=0;
        for(int i=start+1;i<end;i++)
        {
            int take=nums[i]+ (i>1 ?dp[i-2]:0);
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[end-1];
    }

    int rob(vector<int>& nums) { int n=nums.size();
    if(nums.size()==0) return 0;
if(nums.size()==1) return nums[0];
        return max(robb(nums,0,n-1),robb(nums,1,n));
    }
};