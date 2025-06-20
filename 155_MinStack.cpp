class MinStack {
private:
    stack<int> st;
    stack<int> st2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        int v = st2.empty() ? val : min(st2.top(),val);
        st2.push(v);
    }
    
    void pop() {
        st.pop();
        st2.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st2.top();
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