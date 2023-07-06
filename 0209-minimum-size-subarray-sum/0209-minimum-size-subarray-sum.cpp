class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int i=0; int j=0; int len=INT_MAX; int sum=0;
        while(j<nums.size())
        {
            if(sum<target)
            { sum+=nums[j];}
            else if(sum>=target)
                len=min(len,j-i+1);

                while(sum>=target)
                {
                    sum-=nums[i];
                     len=min(len,j-i+1);
                    i++;
                }
           
              j++; 
            }
       
        if(len==INT_MAX) return 0;
        return len;
    }
};