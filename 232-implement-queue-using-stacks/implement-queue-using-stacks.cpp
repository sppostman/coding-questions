class MyQueue {
public:
    stack<int> q;
    stack<int> deQ;

    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int el = peek();
        if(el == -1)
            return el;
        deQ.pop();
        return el;
    }
    
    int peek() {
        if(deQ.empty()){
            while(!q.empty()){
                deQ.push(q.top());
                q.pop();
            }
        }
        if(deQ.empty())
            return -1;
        return deQ.top();
    }
    
    bool empty() {
        return deQ.empty() && q.empty();
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