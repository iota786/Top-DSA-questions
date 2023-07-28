/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
         queue<Node*>q;
        if(root==NULL) return root;
        q.push(root);
        while(!q.empty())
        {//vector<int>v
            int sz=q.size(); 
            for(int i=0;i<sz-1;i++)
            {
  Node* data=q.front();
                q.pop();
                data->next=q.front();
               // v.push_back(data->val);
                if(data->left!=NULL)q.push(data->left);
                if(data->right!=NULL)q.push(data->right);
            
            }
            
           Node* data1=q.front();
                q.pop();
                //data1->next=q.front();
                //v.push_back(data1->val);
                if(data1->left!=NULL)q.push(data1->left);
                if(data1->right!=NULL)q.push(data1->right);
            
        }
        return root;
        
    }
};