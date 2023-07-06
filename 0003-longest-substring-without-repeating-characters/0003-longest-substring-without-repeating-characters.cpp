class Solution {
public:
    int lengthOfLongestSubstring(string S) {
        if(S.size()==0) return 0;
         vector<int>dict(257, -1);
        
        int start = -1;
        int ans = 0;
        for(int j=0; j<S.size(); j++){
            if(dict[(S[j])] > start){
                start = dict[(S[j])];
                
            }
            ans = max(ans, j-start);
            
            dict[(S[j])] = j;
        }
        
        return ans;
    }
};