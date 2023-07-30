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
         void tr(TreeNode* root,vector<int>&a){
    if(root == NULL){
        return ;
    }
    tr(root->left,a);
    a.push_back(root->val);
    tr(root->right,a);
    
}

void arrange(TreeNode* root,vector<int>&a){
    if(root == NULL){
        return ;
    }
    arrange(root->left,a);
    root->val = a[a.size()-1];
    a.pop_back();
    arrange(root->right,a);
}

void recoverTree(TreeNode* root) {
    vector<int>a;
    tr(root,a);

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    arrange(root,a);
    
}
};