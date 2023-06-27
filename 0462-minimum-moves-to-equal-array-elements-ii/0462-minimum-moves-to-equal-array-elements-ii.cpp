class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end()); int n=nums.size();
        int mid=(n+1)/2;
        mid--;
        long long dist=0;
        for(int i=0;i<nums.size();i++)
        {
            dist+=1LL*abs(nums[i]-nums[mid]);
        }
        return dist;
    }
};