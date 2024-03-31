class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> ahead(2, 0);
        for(int i=n-1; i>=0; i--){
            vector<int> dp(2, 0);
            dp[1] = max(
                ahead[1],
                -fee-prices[i]+ahead[0]
            );
            dp[0] = max(
                ahead[0],
                prices[i]+ahead[1]
            );
            ahead = dp;
        }
        return ahead[1];   
    }
};