//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int nums[], int n)
    {
        //Your code here
        unordered_map<int,int>m; int pre=0; int c=0;
        int j=0; int i=0;
        while(j<n)
        {

        pre+=nums[j];
            if(pre==0) return 1;
            if(m.find(pre)!=m.end()) return 1;
            m[pre]++;
        j++;
        }
        return 0;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends