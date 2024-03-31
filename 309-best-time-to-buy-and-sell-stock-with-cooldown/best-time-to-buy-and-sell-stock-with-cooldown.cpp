class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // // buy states => 0-sell, 1-cooldown, 2-buy
        // vector<int> ahead(3, 0);
        // vector<int> dp(3, 0);

        // for(int i=n-1; i>=0; i--){
        //     dp[0] = max(ahead[0], prices[i]+ahead[1]);
        //     dp[1] = ahead[2];
        //     dp[2] = max(ahead[2], -prices[i]+ahead[0]);
        //     ahead = dp;
        // }
        // return max(ahead[1], ahead[2]);


        // buy states => 0-sell, 1-buy
        vector<int> nextAhead(2, 0);
        vector<int> ahead(2, 0);
        vector<int> dp(2, 0);

        for(int i=n-1; i>=0; i--){
            dp[0] = max(ahead[0], prices[i]+nextAhead[1]);
            dp[1] = max(ahead[1], -prices[i]+ahead[0]);
            nextAhead = ahead;
            ahead = dp;
        }
        return ahead[1];
    }
};