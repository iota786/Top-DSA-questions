class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     priority_queue<int>p; int x;
        for(int i=0;i<nums.size();i++)
        {
            p.push(nums[i]);
        }
        while(k--)
        {
        x=p.top();
            p.pop();
        
        
        } return x;
    }
};