//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
         vector<int>ans;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>
        >,greater<pair<int,pair<int,int>>>>p;
        for(int i=0;i<k;i++)
        {  //{element,position,size of array which element belongs}
            // vector<int>temp;
            // temp.push_back(arr[i][0]);//element
            // temp.push_back(0);//position of element
            // temp.push_back(i);//position of list
            p.push({arr[i][0], {0, i}});
        }
       
        while(!p.empty())
        {   
            auto v=p.top();
            int i=v.first,j=v.second.first,l=v.second.second;
          p.pop();
            ans.push_back(i);
            if(j<arr[l].size()-1)
            {
              p.push({arr[l][j + 1], {j + 1, l}});
            }
            
        }
        // return ans;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends