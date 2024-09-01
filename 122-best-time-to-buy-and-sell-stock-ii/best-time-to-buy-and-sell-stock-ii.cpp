class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0] => sell
        // dp[i][1] => buy
        int n = prices.size();
        vector<int> nextDp(2, 0);

        for(int i=n-1; i>=0; i--){
            vector<int> dp(2, 0);
            dp[1] = max(
                nextDp[1],
                -prices[i] + nextDp[0]
            );
            dp[0] = max(
                nextDp[0],
                prices[i] + nextDp[1]
            );
            nextDp = dp;
        }
        return nextDp[1];
    }
};