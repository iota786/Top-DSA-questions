class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s={}; bool flag=false;
        int n=strs.size();
        for(int i=0;i<strs[0].length();i++){
        for(int j=0;j<n;j++)
        {
            if(i>strs[j].length()) break;
            else { if(strs[0][i]==strs[j][i])
                flag=true;
                  else return s;
                 }
        }
            if(flag)
            {
                s+=strs[0][i]; flag=false;
            }
            
        }
            
            
            
        
    
        return s;
    }
};