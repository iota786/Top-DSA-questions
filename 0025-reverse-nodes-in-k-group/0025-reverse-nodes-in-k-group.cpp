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
#define Node ListNode
class Solution {
public:
    Node* reverse(Node* head, int k,int &c)
{
    // base case
    if (!head)
        return NULL;
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
  
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k ) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++; c--;
    }
  
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL && c>0)
        head->next = reverse(next, k,c);
        else  head->next=next; 
  
    /* prev is new head of the input list */
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        Node *curr=head; int c=0; 
        while(curr!=NULL)
        {
            curr=curr->next; c++;
        }c= c-c%k;
        return reverse(head,k,c);
        
    }
};