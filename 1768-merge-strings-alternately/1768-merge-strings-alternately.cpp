class Solution {
public:
    string mergeAlternately(string word1, string word2) {
      // string ans="";
       // int mx=max(word1.size(),word2.size());
        int k=0;
        for(int i=0;i<word1.size();i+=2){
            word1.insert(word1.begin()+i+1,word2[k++]);
            if(k==word2.size()) break;
        }
        if(k<word2.size())
            word1+=word2.substr(k);
        return word1;
    }
};