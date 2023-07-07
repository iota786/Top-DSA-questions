class Solution {
public:
    int numberOfSubstrings(string s) {
//unordered_map<char,int>m;
        int n=s.size();
        int l=0,r=0;
         
       int i=0,j=0,count=0;

        unordered_map<char, int> mp;

        while(j<n)
        {
            mp[s[j]]++;

            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1)
            {
                count += (n - j);

                mp[s[i]]--;
                i++;
            }
            j++;
        }
return count;
                
        
        
    }
};