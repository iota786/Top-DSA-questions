class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
         vector<int> sortedArray;
         inorderTraversal(root, sortedArray);
         return sortedArrayToBST(sortedArray, 0, sortedArray.size() - 1);
        }

// Function to traverse the BST in an inorder manner and store elements in a sorted array
    void inorderTraversal(TreeNode* root, vector<int>& sortedArray) {
         if (root == nullptr) {
               return;
             }
         inorderTraversal(root->left, sortedArray);
         sortedArray.push_back(root->val);
         inorderTraversal(root->right, sortedArray);
    }

// Function to convert a sorted array to a balanced BST
    TreeNode* sortedArrayToBST(vector<int>& sortedArray, int left, int right) {
         if (left > right) {
               return nullptr;
              }

          int mid = left + (right - left) / 2;
          TreeNode* root = new TreeNode(sortedArray[mid]);
          root->left = sortedArrayToBST(sortedArray, left, mid - 1);
          root->right = sortedArrayToBST(sortedArray, mid + 1, right);
     return root;
    }
};