class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int i=0;int j=0; int n=s.size(); int len1=-1; int len2=-1;
        unordered_map<char,int>m;
        while(j<n)
        {
            m[s[j]]++;
            //if(m['F']==k) len1=max(len1,j-i+1);
             if(m['F']>k)
            {
                while(m['F']>k)
                { m[s[i]]--;
                    i++;}
                
               
            }
             len1=max(len1,j-i+1);
            j++;
        }
        cout<<len1;
        i=0; j=0; m.clear();
         while(j<n)
        {
            m[s[j]]++;
           // if(m['T']==k) len2=max(len2,j-i+1);
            if(m['T']>k)
            {     while(m['T']>k)
               
            { m[s[i]]--;
                    i++;}
                
               
            }
             len2=max(len2,j-i+1);
            j++;
        }
        cout<<len2;
        return max(len1,len2);
    }
};