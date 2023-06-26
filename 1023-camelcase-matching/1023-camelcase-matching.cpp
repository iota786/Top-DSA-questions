class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
      vector<bool>query_ans(queries.size(),0) ; 
        for(int i=0;i<queries.size();i++)
        {    // string flow="";
            int prev=-1;
            bool flag= false; int p=0; int q=0;
             for(int k=0;k<queries[i].size();k++)
            {
                if('A'<= queries[i][k] and queries[i][k]<='Z') q++;
            }
             for(int j=0;j<pattern.size();j++)
        
             {  
                 if('A'<=pattern[j] and pattern[j]<='Z') p++;
                 
                 int ind;
                 if(prev==-1)ind= queries[i].find(pattern[j]);
                    else ind=queries[i].find(pattern[j],prev+1);
                    
             if( ind==-1 )
             {
                query_ans[i]=0; flag= true;break;
             }
             
             else {prev=ind; }
             
             }
           
         if(!flag && q==p) query_ans[i]=1;
        
        }
        return query_ans;
        
    }
};