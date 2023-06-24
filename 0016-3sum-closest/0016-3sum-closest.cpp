class Solution {
public:
    int threeSumClosest(vector<int>& num, int target) {
        sort(num.begin(), num.end());  long long clos=LONG_MAX;
       
        int res=0;
        for (int i = 0; i < (int)(num.size()); i++) {
            
             
            {
                
                int lo = i+1, hi = (int)(num.size())-1; 
                
                while (lo < hi) {
                    long long sum=num[i];
                    sum+=num[lo]+num[hi];
                   
                        if(clos>(abs(target-sum))) 
                        {
                            clos=abs(target-sum);
                            res=sum;
                        }
                        
                        
                       
                       
                        if(sum<target)
                        
                        lo++; 
                        else hi--;
                    } 
                    
               }
            }
            return res;
        
    }
};