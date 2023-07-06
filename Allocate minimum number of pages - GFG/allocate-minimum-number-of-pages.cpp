//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

// 
//User function template in C++

class Solution 
{
    public:
    int ispossible(int a[],long long pages,int n)
    {
        int c=1; long long allot=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]+allot<=pages) allot+=a[i];
            else
            {
                c++; allot=a[i];
            }
        }
        return c;
        
    }
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //code here
        if(m>n) return -1;
        long long low=*max_element(a,a+n);
        long long high=accumulate(a,a+n,0);
        long long ans=0;
        while(low<=high)
        {
            long long mid=(high+low)/2;
           //cout<<mid<<endl;
            //if(ispossible(a,mid,n)==m) 
            //{ans=mid; high=mid-1;}
           if(ispossible(a,mid,n)>m)
            low=mid+1;
            else 
            {ans=mid,high =mid-1;}
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends