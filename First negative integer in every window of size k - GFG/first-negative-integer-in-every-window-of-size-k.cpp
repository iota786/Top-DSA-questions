//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int nums[],
                                             long long int n, long long int k) {
                                                 
                                                 
                                                 
             deque<long long>dq;
        //long lon n=nums.size();
        vector<long long>ans;
        for(int i=0;i<n;i++)
        {
            if(dq.size()>0 && dq.front()==i-k)
                dq.pop_front();
           if(nums[i]<0)
            dq.push_back(i);
            if(i>=k-1)
            if(dq.size()==0) ans.push_back(0);
            else
                ans.push_back(nums[dq.front()]);
            
        }
        return ans;
                                                 
 }