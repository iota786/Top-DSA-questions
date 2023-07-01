class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int ans=0;
        while(l<h)
        {
            int mid=(l+h)/2;
            if(nums[mid]<=nums[h])
            {
                ans=nums[mid];
            
            h=mid;
            }
            else
                l=mid+1;
        }
        return nums[h];
        
    }
};