class MinStack {
    stack<int> s;
    stack<int> min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push(val);
            min.push(val);
            return;
        }

        s.push(val);
        if (val <= min.top()) min.push(val);
    }
    
    void pop() {
        if (s.empty() || min.empty()) return;

        if (min.top() == s.top()) min.pop();
        s.pop();
    }
    
    int top() {
        if (!s.empty()) return s.top();
        return 0;
    }
    
    int getMin() {
        if (!min.empty()) return min.top();
        return INT_MAX;
    }
};
