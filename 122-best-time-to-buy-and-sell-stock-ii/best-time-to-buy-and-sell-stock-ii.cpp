class Solution {
public:
    int trade(vector<int>& prices, int buy, int i, int n, vector<vector<int>> &dp){
        if(i==n)
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        if(buy){
            // Can Buy
            profit = max(
                trade(prices, 1, i+1, n, dp),
                -prices[i] + trade(prices, 0, i+1, n, dp)
            );
        } else {
            // Can Sell
            profit = max(
                trade(prices, 0, i+1, n, dp),
                prices[i] + trade(prices, 1, i+1, n, dp)
            );
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return trade(prices, 1, 0, n, dp);

        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // dp[n][0] = 0;
        // dp[n][1] = 0;
        // for(int i=n-1; i>=0; i--){
        //     dp[i][1] = max(
        //         dp[i+1][1],
        //         -prices[i]+dp[i+1][0]
        //     );
        //     dp[i][0] = max(
        //         dp[i+1][0],
        //         prices[i]+dp[i+1][1]
        //     );
        // }
        // return dp[0][1];

        vector<int> prev(2, 0);
        for(int i=n-1; i>=0; i--){
            vector<int> dp(2, 0);
            dp[1] = max(
                prev[1],
                -prices[i]+prev[0]
            );
            dp[0] = max(
                prev[0],
                prices[i]+prev[1]
            );
            prev = dp;
        }
        return prev[1];
    }
};