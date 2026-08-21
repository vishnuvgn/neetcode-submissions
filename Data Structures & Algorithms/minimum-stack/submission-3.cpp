class MinStack {
private:
    stack<int> st;
    stack<int> min_stack;

public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (min_stack.empty() || val <= min_stack.top()) min_stack.push(val);
        else min_stack.push(min_stack.top());
    }
    
    void pop() {
        st.pop();
        min_stack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {  
        return min_stack.top();
    }
};
