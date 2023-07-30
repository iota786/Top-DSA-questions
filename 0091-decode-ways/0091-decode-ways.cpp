class Solution {
public:
    int numDecodings(string s) { int n=s.size();
        vector<int>dp(s.size()+1,0); dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {   if(s[i]=='0') dp[i]=0;
         else{
            int res=dp[i+1];
            if(i<n-1  && (s[i]=='1'|| (s[i]=='2'&& s[i+1]<'7'))) res+=dp[i+2];
            dp[i]=res;}
        }
        
        return s.empty() ? 0: dp[0];
    }
    int numDecodings(int p, string& s,vector<int>&dp) {
        int n = s.size();
        if( p==n) return 1;
        if(dp[p]!=-1) return dp[p];
        if(s[p] == '0') return 0; // sub string starting with 0 is not a valid encoding  
      //  if(dp[p]!=-1) return dp[p];
        int res = numDecodings(p+1,s,dp);
        if( p < n-1 && (s[p]=='1'|| (s[p]=='2'&& s[p+1]<'7'))) res += numDecodings(p+2,s,dp);
        return dp[p]= res;
    }
};