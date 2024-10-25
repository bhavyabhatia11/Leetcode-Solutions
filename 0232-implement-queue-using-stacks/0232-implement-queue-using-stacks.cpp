class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);        
    }
    
    int pop() {
        int top;
        int ans;
        while(!s1.empty()){
            top = s1.top();
            s1.pop();
            if(!s1.empty()) s2.push(top);
        }

        ans = top;
        s1 = stack<int>();

        while(!s2.empty()){
            top = s2.top();
            s2.pop();
            s1.push(top);
        }

        return ans;

        return top;
    }
    
    int peek() {

        int top;
        int ans;
        while(!s1.empty()){
            top = s1.top();
            s1.pop();
            s2.push(top);
        }
        ans = top;
        s1 = stack<int>();

        while(!s2.empty()){
            top = s2.top();
            s2.pop();
            s1.push(top);
        }

        return ans;
        
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */