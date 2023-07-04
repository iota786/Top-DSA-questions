class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push({s[i],i});
            else
                if( s[i]==')' &&(st.size()>0 && st.top().first=='('))
                    st.pop();
            else if(s[i]==')')
                st.push({')',i});
        }
       
        while(st.size()>0)
        {
            int x=st.top().second;
            st.pop();
            s[x]=' ';
           
        } 
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ') ans+=s[i];
        }
        return ans;
    }
};