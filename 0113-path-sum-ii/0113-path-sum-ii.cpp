/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// we had to pop/backtreck path if we've sent it by reference
    void solve(TreeNode* &root, int &targetSum,int currSum,vector<int>&path,vector<vector<int>> &ans){
        //base case 1
        if(root == NULL)    return;
        //2 leaf node
        if(root->left == NULL && root->right ==NULL){
            path.push_back(root->val);
            currSum += root->val;
            if(currSum == targetSum)
                ans.push_back(path);
                 path.pop_back();
            
            return;
        }
        // one case - include current node;
        path.push_back(root->val);
        currSum += root->val;

        solve(root->left,targetSum,currSum,path,ans);

        solve(root->right,targetSum,currSum,path,ans);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>path;
        int currSum = 0;
        solve(root,targetSum,currSum,path,ans);
        return ans;
    }
};