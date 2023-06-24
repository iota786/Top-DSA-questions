//Optimized Approach - O(n^2 + nlogn) - o(n^2) time and O(n) space
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        int target=0;
        // moves for a
        for (int i = 0; i < (int)(num.size()); i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int lo = i+1, hi = (int)(num.size())-1; //sum = 0 - num[i];
                
                while (lo < hi) {
                    long long sum=num[i];
                    sum+=num[lo]+num[hi];
                    if (target==sum) {
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (sum < target) lo++;
                    else hi--;
               }
            }
        }
        return res;
    }
};    