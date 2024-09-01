class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][0] = (dp[i+1][0], -prices[i] + dp[i+2][1])
        // dp[i][1] = (dp[i+1][1], prices[i] + dp[i+1][0])
        vector<int> nextNextDp(2, 0);
        vector<int> nextDp(2, 0);
        vector<int> currDp(2, 0);

        for(int i=n-1; i>=0; i--){
            currDp[0] = max(
                nextDp[0],
                prices[i] + nextNextDp[1]
            );
            currDp[1] = max(
                nextDp[1],
                -prices[i] + nextDp[0]
            );
            nextNextDp = nextDp;
            nextDp = currDp;
        }
        return currDp[1];
    }
};