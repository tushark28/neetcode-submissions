class MinStack {
public:
    MinStack() {
    }

    stack<int> st;
        stack<int> minPrefix;
    
    void push(int val) {
        st.push(val);
        if (minPrefix.empty()){
            minPrefix.push(val);
        }else {
            minPrefix.push(min(minPrefix.top(), val));
        }
    }
    
    void pop() {
        st.pop();
        minPrefix.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minPrefix.top();
    }
};
