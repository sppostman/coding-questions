class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestProfit = 0;
        int minimumPriceYet = prices[0];
        for(int currentPrice : prices){
            minimumPriceYet = min(minimumPriceYet, currentPrice);
            bestProfit = max(bestProfit, currentPrice-minimumPriceYet);
        }
        return bestProfit;
    }
};