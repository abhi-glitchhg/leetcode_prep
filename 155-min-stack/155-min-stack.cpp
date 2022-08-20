class MinStack {
public:
    
    stack<int> stack1;
    stack<int> stack2;
     MinStack() {
        
    }
    
    void push(int val) {
    stack1.push(val);
    if (stack2.empty())
        stack2.push(val);
    else
        stack2.push(min(val,stack2.top()));
    }
    
    void pop() {
        stack1.pop();
        stack2.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stack2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */