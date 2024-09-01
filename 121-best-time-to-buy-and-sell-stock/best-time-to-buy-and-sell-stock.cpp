class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0];
        int best = 0;
        for(int p : prices){
            lowest = min(lowest, p);
            best = max(best, p-lowest);
        }
        return best;
    }
};