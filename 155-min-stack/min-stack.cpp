class MinStack {
public:
    // st    10 7 8 9 7 4 1 15
    // minst 10 7 7 7 7 4 1 1

    stack<pair<int,int>> st;
    
    void push(int val) {
        st.push({val, min(val, st.empty() ? INT_MAX : getMin())});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

class MinStack2stacks {
public:
    // st    10 7 8 9 7 4 1 15
    // minst 10 7 7 4 1
    stack<int> st;
    stack<int> minSt;
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }
    
    void pop() {
        if(minSt.top() == st.top())
            minSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
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