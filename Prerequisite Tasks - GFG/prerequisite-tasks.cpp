//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool toposort(int n,vector<vector<int>>&adj)
    {

    vector<int>indegrees(adj.size());
        for(int i=0;i<adj.size();i++)
        {
            for(auto &node:adj[i])
            {
                indegrees[node]++;
            }
        }
        queue<int>q;
        for(int i=0;i<indegrees.size();i++)
        {
            if(indegrees[i]==0)
                q.push(i);
        }
        vector<int>topo;
        int c=0;
        while(!q.empty())
        {

          int node=q.front();
            q.pop();
            topo.push_back(node);
             //c++;
            for(auto &i:adj[node]){
               indegrees[i]--;
                if(indegrees[i]==0)
                    q.push(i);
            
            }
        
        
        }
         if(topo.size()==adj.size())
        return true;
         else
             return false;
    
    
    }
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>>adj(n);
        for(auto &i:prerequisites)
        {
            adj[i.second].push_back(i.first);
        }
        return toposort(n,adj);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends