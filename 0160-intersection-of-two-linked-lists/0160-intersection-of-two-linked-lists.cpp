/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node=new ListNode(-1); node->next=NULL;
        int a=0;int b=0;
        ListNode *cur1,*cur2; cur1=headA,cur2=headB;
        while(cur1)
        {

          a++; cur1=cur1->next;
        //headA=headA->next;
            //headB=headB->next;
        
        }
        while(cur2)
        {

          b++; cur2=cur2->next;
       // headB=headB->next;
            //headB=headB->next;
        
        }
       // headA=cur1,headB=cur2;
        if(a>b)
        {
            while(a>b)  {headA=headA->next; a--;}
                
        }
        else if(b>a) 
        {
           while(b>a)    {headB=headB->next;
               
               b--;}
        
        }
        while(headA && headB)
        {

        if(headA==headB)
        { node->next=headA; break;

        }
headB=headB->next;
        headA=headA->next; 
        
        }
        return node->next;
    }
};