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
    bool check(TreeNode* root,long long l,long long h)
    {   if(root==NULL) return true;
        if(root->val<=l || root->val>=h) return false;
     
         return check(root->left,l,root->val) && check(root->right,root->val,h);
    }
    
    bool isValidBST(TreeNode* root) {
        long long l=LONG_MIN;
        long long h=LONG_MAX;
        return check(root,l,h);
    }
};