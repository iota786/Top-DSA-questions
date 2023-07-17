class Solution {
public:
    int ispossible(vector<int> &a,long long pages,int n)
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
    int splitArray(vector<int>& a, int k) {
        long long low=*max_element(a.begin(),a.end());
        long long ans=0;
        long long high=accumulate(a.begin(),a.end(),0);
        while(low<=high)
        {
            long long mid=(high+low)/2;
            int r=ispossible(a,mid,a.size());
            //if(r==A){ans=mid; high=mid-1;}
             if(r>k)
            low=mid+1;
            else 
            {ans=mid,high =mid-1;}
            
        }
        return (ans );
    }
};