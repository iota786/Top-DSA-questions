class cmp{
    public:
    bool operator() (ListNode* top, ListNode* btm){
        return top->val > btm->val; 
        //True - Swaps - So True when incorrect - when top is bigger guy.
        //as we need min heap and small guy needs to be at top
        //If u find any guy bigger at top, swap and bring it to bottom
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0) return NULL;
        
        ListNode* ans = new ListNode(-1);
        ListNode* tail = ans;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> qu;
        int K = lists.size();
        
        //first insert all the heads 
        for(int i=0; i<K; i++){
            if(lists[i]!=NULL) qu.push(lists[i]);
        }
        
        //now take min and append it.
        while(!qu.empty()){
            ListNode* tmp = qu.top(); // got the min
            qu.pop(); // takes log K
            
            tail->next = tmp;
            tail = tmp;
            
            if(tmp->next != NULL)qu.push(tmp->next);
            
        }
        
        return ans->next; // to by pass dummy i return the next one

        
    }
};