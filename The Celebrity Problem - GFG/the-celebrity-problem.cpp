//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool knows(vector<vector<int> >& M,int i,int j)
    {
        if(M[i][j]==1) return true;
        else return false;
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>s;
        for(int i=0;i<n;i++)
        s.push(i);
        while(s.size()>1)
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(knows(M,a,b))
            s.push(b);
            else //if(knows(M,b,a))
            s.push(a);
            
        }
        if(s.empty()) return -1;
        int c=s.top();
        bool row=false; bool col =false;
        int rc=0; int cc=0;
        //for(int i=0;i<n;i++)
        
        for(int i=0;i<n;i++)
        {
            
            if(M[c][i]==0) rc++;
        }
        if(rc==n) row=true;
        for(int i=0;i<n;i++)
        {
            
            if(M[i][c]==1) cc++;
        }
        if(cc==n-1) col=true;
    if((row&col))return c;
    else return -1;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends