class MinStack {
    std::stack<int> min_stack;
    std::stack<int> min_values;

public:
    MinStack() {

    }
    
    void push(int val) {
        min_stack.push(val);
        if (min_values.empty() || min_values.top() > val) min_values.push(val);
        else (min_values.push(min_values.top()));
    }
    
    void pop() {
        min_stack.pop();
        min_values.pop();
    }
    
    int top() {
        return min_stack.top();
    }
    
    int getMin() {
        return min_values.top();
    }
};
