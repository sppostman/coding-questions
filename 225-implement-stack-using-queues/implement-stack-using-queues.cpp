class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    }
    
    void push(int x) {
        if(q1.empty())
            q2.push(x);
        else
            q1.push(x);
    }

    int popUtil(queue<int> &from, queue<int> &to){
        while(from.size() > 1){
            to.push(from.front());
            from.pop();
        }
        int el = from.front();
        from.pop();
        return el;
    }
    int pop() {
        if(q1.empty())
            return q2.empty() ? -1 : popUtil(q2, q1);
        return popUtil(q1, q2);
    }
    
    int topUtil(queue<int> &from, queue<int> &to){
        while(from.size() > 1){
            to.push(from.front());
            from.pop();
        }
        int el = from.front();
        to.push(el);
        from.pop();

        return el;
    }
    int top() {
        if(q1.empty())
            return q2.empty() ? -1 : topUtil(q2, q1);
        return topUtil(q1, q2);
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */