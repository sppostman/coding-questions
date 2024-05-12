class StockSpanner {
public:
    stack<pair<int,int>> incr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(incr.size() && incr.top().first <= price){
            span += incr.top().second;
            incr.pop();
        }
        incr.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */