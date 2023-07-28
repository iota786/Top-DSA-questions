//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int num[], int n, int target)
    {
        //Your Code Here
        sort(num,num+n);
         vector<vector<int>> res; 
        //sort(num.begin(), num.end()); 
       // int target=0;
        // moves for a
        for (int i = 0; i < (int)n; i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int lo = i+1, hi = (int)n-1; //sum = 0 - num[i];
                
                while (lo < hi) {
                    long long sum=num[i];
                    sum+=num[lo]+num[hi];
                    if (target==sum) {
                         return true;
                        // vector<int> temp; 
                        // temp.push_back(num[i]); 
                        // temp.push_back(num[lo]); 
                        // temp.push_back(num[hi]); 
                        // res.push_back(temp);
                        
                        // while (lo < hi && num[lo] == num[lo+1]) lo++;
                        // while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        // lo++; hi--;
                    } 
                    else if (sum < target) lo++;
                    else hi--;
               }
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends