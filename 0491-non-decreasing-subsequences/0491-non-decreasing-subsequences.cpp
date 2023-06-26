class Solution {
public:
vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    dfs(nums, 0, cur, res);
    return res;
}

void dfs(vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& res) {
    if (cur.size() >= 2) res.push_back(cur);
    unordered_set<int> used;
    for (int i = start; i < nums.size(); i++) {
        if ((cur.empty() || nums[i] >= cur.back()) && used.find(nums[i]) == used.end()) {
            cur.push_back(nums[i]);
            dfs(nums, i + 1, cur, res);
            cur.pop_back();
            used.insert(nums[i]);
        }
    }
}

};