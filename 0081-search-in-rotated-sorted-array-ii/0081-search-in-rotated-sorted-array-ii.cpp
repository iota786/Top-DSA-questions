class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int l=0; int h=nums.size()-1; int ans;
        while(l<=h)
        {
          int  mid=(l+h)/2;
            if(nums[mid]==target) return true;
            if(nums[l]==nums[mid] && nums[h]==nums[mid])
            {
                l++,h--;
                continue;
            }
          if(nums[l]<=nums[mid])
          {
              if(target>=nums[l] && target<= nums[mid])
                  h=mid-1;
              else
                  l=mid+1;
          }
            else
            {
                if(target<=nums[h] && target>= nums[mid])
                  l=mid+1; 
              else
                  h=mid-1;
            }
           
        }
        return false;
    }
};