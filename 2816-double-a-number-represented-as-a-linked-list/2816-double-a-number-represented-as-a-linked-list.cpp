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
    void change(ListNode* head, int &carry)
    {
        if(head==NULL) return;
        change(head->next,carry);
        int x=(head->val*2+carry);
        head->val=(head->val*2+carry)%10;
        carry=x/10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry=0;
        change(head,carry);
        if(carry!=0)
        {
            ListNode* dum=new ListNode(carry);
                    dum->next=head;
               return dum;
        }
        return head;
    }
};