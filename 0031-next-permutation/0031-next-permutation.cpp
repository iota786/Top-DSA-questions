class Solution {
public:
    int findDip(vector<int>& nums,int n)
        
    {    int fetch;
        //iterate from second last index to get longest prefix match and find the dip
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                return i;
            
        }
        return -1;
    }
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        int vector_size=nums.size();
        //findind the dip
        ind=findDip(nums,vector_size);
        //find the next smallest and swap
         if(ind!=-1) 
        for(int i=vector_size-1;i>ind;i--)
        {
            if(nums[ind]<nums[i])
            {
                 swap(nums[ind],nums[i]);
                break;
            }
            
        }
        // if(ind==-1) ind++; 
        reverse (nums.begin()+ind+1,nums.end());
       
            
    }
};