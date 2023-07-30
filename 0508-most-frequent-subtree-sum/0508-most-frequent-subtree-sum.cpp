class Solution {
public:
int maxi=0;
int post(TreeNode* root,unordered_map<int,int> &mp){
    if(root==NULL){
        return 0;
    }
    int x=post(root->left,mp);
    int y=post(root->right,mp);
    root->val=root->val+x+y;
    mp[root->val]++;
    maxi=max(maxi,mp[root->val]);
    return root->val;
}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        int rt=post(root,mp);
        vector<int> ans;
        for(auto it: mp){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};