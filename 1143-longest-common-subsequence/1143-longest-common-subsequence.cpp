class Solution {
public:
 int longest(int i,int j, string &s,string &t,vector<vector<int>>&dp)
 {
     if(i==0 || j==0) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     if(s[i-1]==t[j-1]) return dp[i][j]=1+longest(i-1,j-1,s,t,dp);
     return dp[i][j]=max(longest(i-1,j,s,t,dp),longest(i,j-1,s,t,dp));
 }
    int longestCommonSubsequence(string text1, string text2) {
        int i=text1.size();
        int j=text2.size();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        
        return longest(i,j,text1,text2,dp);
    }
};