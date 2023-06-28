class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       string ans="";
        int mx=max(word1.size(),word2.size());
        for(int i=0;i<mx;i++){
            if(i<word1.size())ans+=word1[i];
            if(i<word2.size())ans+=word2[i];
        }
        return ans;
    }
};