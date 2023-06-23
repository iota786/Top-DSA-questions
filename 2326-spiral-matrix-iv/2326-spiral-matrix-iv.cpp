/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

  void spiralOrder(vector<vector<int>> &matrix,ListNode* head)
    {
        int m = matrix.size();
        int n = matrix[0].size();
       // vector<int> v(m * n, 0);
        int r, c, i, j;
        i = j = r = c = 0;
        while (i < m * n)
        {
            // left to right
            while (c < n && matrix[r][c] ==-1)
            {
                matrix[r][c]=head->val;
                head=head->next;
                if(head==NULL) return;
               // matrix[r][c] = -101;
                c++;
                i++;
            }
            r++;
            c--;

            // top to down
            while (r < m && matrix[r][c] ==-1)
            {
                 matrix[r][c]=head->val;
                head=head->next; if(head==NULL) return;
                r++;
                i++;
            }
            r--;
            c--;

            // right to left
            while (c >= 0 && matrix[r][c] ==-1)
            {
                matrix[r][c]=head->val;
                head=head->next; if(head==NULL) return;
                c--;
                i++;
            }
            r--;
            c++;

            // down to top
            while (r >= 0 && matrix[r][c] ==-1)
            {
                 matrix[r][c]=head->val;
                head=head->next;  if(head==NULL) return;
              
                r--;
                i++;
            }
            r++;
            c++;
        }
        //return v;
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int>(n,-1));
        if(head==NULL) return matrix;
         spiralOrder(matrix,head);
        return matrix;
        
    }
};