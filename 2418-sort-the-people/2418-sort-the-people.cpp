class Solution {
public:
   static bool comp(pair<string,int> h1,pair<string,int> h2)
{
    return (h1.second > h2.second);
}
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>>v;
        for(int i=0;i<names.size();i++)
            v.push_back({names[i],heights[i]});
        sort(v.begin(),v.end(),comp);
        vector<string>ans;
        for(int i=0;i<names.size();i++)
            ans.push_back(v[i].first);
        return ans;
    }
};