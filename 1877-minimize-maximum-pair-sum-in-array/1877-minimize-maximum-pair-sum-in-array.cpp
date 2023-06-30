class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mx=INT_MIN;
       int h=nums.size()-1;
      int l=0;
      while(l<h)
      {
          mx=max(nums[l++]+nums[h--],mx);
      }
       
           
        
        return mx;
    }
};