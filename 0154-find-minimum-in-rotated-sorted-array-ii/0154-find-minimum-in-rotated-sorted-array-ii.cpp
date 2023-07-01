class Solution {
public:
    int findMin(vector<int>& nums) {
       
        int ans=INT_MAX;
       int l=0; int h=nums.size()-1; 
        while(l<h)
        {
          int  mid=(l+h)/2;
            //if(nums[mid]==target) return mid;
            if(nums[l]==nums[mid] && nums[h]==nums[mid])
            {
                l++,h--;
                continue;
            }
          if(nums[mid]<=nums[h])
          {    ans=min(ans,nums[mid]);
                  h=mid-1;
              
          }
            else
            {
               ans=min(nums[mid],ans);
                  l=mid+1; 
             
            }
           
        }
        return min(nums[l],ans);
    }
};