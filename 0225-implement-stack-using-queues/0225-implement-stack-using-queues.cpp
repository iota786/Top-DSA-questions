class MyStack {
    
public:
    MyStack() {
    
    }
    queue<int>q; int x,y,s;
    void push(int x) {
    
        s=q.size();
        q.push(x);
        for(int i=0;i<s;++i)
        { q.push(q.front());
         q.pop();
        }
    }
    
    int pop() {
      
        x= q.front(); 
       q.pop();
        return x;
    }
    
    int top() {
        y=q.front();
        return y;
    }
    
    bool empty() {
        if(q.size()==0)
            return true;
        else return false;}
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */