class Solution {
public:
TreeNode *build(int start, int end, vector<int> &inorder){
    if(start>end) return NULL;
    int mid = start - (start-end)/2;

    TreeNode *node = new TreeNode(inorder[mid]);

    node->left = build(start, mid-1, inorder);
    node->right = build(mid+1, end, inorder);
    return node;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode *node = root;
        while(true){
            if(node!=NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        TreeNode *ans = build(0, inorder.size()-1, inorder);

        return ans;
    }
};