class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        long long i, j, res = 0;
i = j = 0;

unordered_map<char, int> Mp;

while(j<str.length())

{

Mp[str[j]]++;

if(Mp[str[j]] == 1)

res= max(res, j-i+1); 

else if(Mp[str[j]]> 1 )

{ while(Mp[str[j]]> 1 )

{

Mp[str[i]]--; if(Mp[str[i]]==0) Mp.erase(str[i]);

++i;



}
if(Mp[str[j]] ==1)

res= max(res, j-i+1);
}

++j;

} return res;  
    }
};