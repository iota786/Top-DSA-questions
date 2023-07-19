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
   int bottomleft = 0, lowestlvl = -1;
    void dfs(TreeNode* s,  int lvl){
        if(lvl > lowestlvl) {
            lowestlvl = lvl;
            bottomleft = s->val; 
        }
        if(s->left) dfs(s->left, lvl+1);
        if(s->right) dfs(s->right, lvl+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return bottomleft;
        
    }
};