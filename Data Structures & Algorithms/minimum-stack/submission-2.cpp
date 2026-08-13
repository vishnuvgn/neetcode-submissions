class MinStack {

private:
    std::stack<int> min_stack;
    std::stack<int> real_stack;

public:
    MinStack() {}
    
    void push(int val) {
        real_stack.push(val);
        if (min_stack.empty()) min_stack.push(val);
        else {
            if (min_stack.top() < val) min_stack.push(min_stack.top());
            else min_stack.push(val);
        }
    }
    
    void pop() {
        min_stack.pop();
        real_stack.pop();
    }
    
    int top() {
        return real_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
