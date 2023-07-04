class Solution {
public:
    int minAddToMakeValid(string s) {
         stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(s[i]);
            else
                if(  (st.size()>0 && st.top()=='('))
                    st.pop();
            else
                st.push(')');
        }
        int a=0; int b=0;
        while(st.size()>0)
        {
            char ch=st.top();
            st.pop();
            if(ch==')') a++;
            else
                b++;
        }
        return a+b;
    }
};