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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
           queue<TreeNode*>q;
        if(root==NULL) return {};
        q.push(root); vector<vector<int>>ans;
        while(!q.empty())
        {
            int sz=q.size(); vector<int>v;
            for(int i=0;i<sz;i++)
            {
  TreeNode* data=q.front();
                q.pop();
                v.push_back(data->val);
                if(data->left!=NULL)q.push(data->left);
                if(data->right!=NULL)q.push(data->right);
            
            }
            ans.push_back(v);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};