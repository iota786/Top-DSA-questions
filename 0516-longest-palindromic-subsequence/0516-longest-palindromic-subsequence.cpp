class Solution {
public:
int longest(int i,int j, string &s,string &t,vector<vector<int>>&dp)
 {
     if(i==0 || j==0) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     if(s[i-1]==t[j-1]) return dp[i][j]=1+longest(i-1,j-1,s,t,dp);
     return dp[i][j]=max(longest(i-1,j,s,t,dp),longest(i,j-1,s,t,dp));
 }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<t.size();i++) dp[i][0]=0;
        for(int j=0;j<t.size();j++) dp[0][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                
            if(s[i-1]==t[j-1]) 
                dp[i][j]=1+dp[i-1][j-1];
     else
         dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            
            
            }
        }
                      return dp[n][m];
    }
};