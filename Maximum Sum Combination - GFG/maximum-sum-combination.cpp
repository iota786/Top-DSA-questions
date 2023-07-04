//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int k, vector<int> &v1, vector<int> &v2) {
        // code here
        sort(v1.rbegin(),v1.rend());
        sort(v2.rbegin(),v2.rend());
        
         vector<int > ans;

    priority_queue<pair<int, pair<int, int> > > pq;

    int n = v1.size(), m = v2.size();
    
    for(int i=0;i<min(n,k);i++) 
        pq.push({v1[i] + v2[0], {i, 0}});
    
    while(!pq.empty() && k--) {
        int sum=pq.top().first;
        //auto [i, j] = pq.top().second;
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        pq.pop();
        ans.push_back(sum);
        
        if (j <m-1) 
            pq.push({v1[i] + v2[j+1], {i, j+1}});
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends