class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // dp[i][0][0] = prices[i] + dp[i+1][1][1]
        // dp[i][0][1] = prices[i] + dp[i+1][1][2]
        // dp[i][0][2] = 0

        // dp[i][1][0] = -prices[i] + dp[i+1][0][0]
        // dp[i][1][1] = -prices[i] + dp[i+1][0][1]
        // dp[i][1][2] = 0

        vector<vector<int>> nextDp(2, vector<int>(k+1, 0));
        vector<vector<int>> currDp(2, vector<int>(k+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                for(int cap=0; cap<k; cap++){
                    if(buy){
                        currDp[1][cap] = max(
                            nextDp[1][cap],
                            -prices[i] + nextDp[0][cap]
                        );
                    } else {
                        currDp[0][cap] = max(
                            nextDp[0][cap],
                            prices[i] + nextDp[1][cap+1]
                        );
                    }
                }
            }
            nextDp = currDp;
        }
        return nextDp[1][0];
    }
};