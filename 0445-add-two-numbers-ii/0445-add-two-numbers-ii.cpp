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
     void reverse(ListNode* &head,ListNode* curr,ListNode* prev )
    {
        if(curr==NULL)
        {
            head=prev; 
            return;
        }
        else
            reverse(head,curr->next,curr);
            curr->next=prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        reverse(l1,l1,NULL);
        reverse(l2,l2,NULL);
         int sum=0;int carry=0; int data=0;
        ListNode* prev;  ListNode* ans;
        ans=l1;
        
        while(l1!=NULL && l2!=NULL)
        {
           sum=l1->val + l2->val +carry;
           data=sum%10;
            carry=sum/10;
            l1->val=data;
            prev=l1;
            l1=l1->next;
            l2=l2->next;   
        }
        if(l1==NULL && l2==NULL)
        {
          if(carry>0)
         {
             ListNode* add=new ListNode(carry) ;
             add->next=NULL;
             prev->next=add;
         }   
        }
       else if(l1==NULL)
        { prev->next=l2;
         while(l2!=NULL)
         {
             sum=carry+l2->val;
         data=sum%10;
         carry=sum/10;
             
         l2->val=data;
             prev=prev->next;
         l2=l2->next;
         }
         if(carry>0)
         {
             ListNode* add=new ListNode(carry) ;
             add->next=NULL;
             prev->next=add;
         }
        }
         else
         {
         while(l1!=NULL)
         {
             sum=carry+l1->val;
         data=sum%10;
         carry=sum/10;
         l1->val=data;
           prev=prev->next;   
         l1=l1->next;
         }
          if(carry>0)
         {
             ListNode* add=new ListNode(carry) ;
             add->next=NULL;
             prev->next=add;
         }   
        }
        reverse(ans,ans,NULL);
       return ans ;
    
        
    }
};