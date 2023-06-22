class Solution {
public:
int stock(int n,int d ,vector<int>& prices,vector<vector<int>>&dp,int fee)
{
    if(n==prices.size()) return 0;
    int profit=0;
    if(dp[n][d]!=-1) return dp[n][d];
  if(d==1)
  {
     return dp[n][d]=max(-prices[n]-fee + stock( n+1,0,prices,dp,fee),stock(n+1,1,prices,dp,fee));
  }
  else
  {
     return dp[n][d]= max(prices[n] + stock( n+1,1,prices,dp,fee),stock(n+1,0,prices,dp,fee));
  }
  //return profit;
}
    int maxProfit(vector<int>& prices, int fee) { int n=prices.size();
         vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=0; dp[n][1]=0;
     return stock(0,1,prices,dp,fee);
     
    }
};