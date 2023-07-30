//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int CountWays(string s){ int m=1e9+7;
		    // Code here
		    int n=s.size();
		    vector<int>dp(s.size()+1,0); dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {   if(s[i]=='0') dp[i]=0;
         else{
            int res=dp[i+1]%m;
            if(i<n-1  && (s[i]=='1'|| (s[i]=='2'&& s[i+1]<'7'))) res=(res%m+dp[i+2]%m)%m;
            dp[i]=res;}
        }
        
        return s.empty() ? 0: dp[0];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends