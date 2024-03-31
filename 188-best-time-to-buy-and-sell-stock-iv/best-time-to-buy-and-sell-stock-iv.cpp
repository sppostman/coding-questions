class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k+1, 0));
        vector<vector<int>> dp(2, vector<int>(k+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                for(int cap=1; cap<=k; cap++){
                    if(buy)
                        dp[buy][cap] = max(
                            ahead[buy][cap],
                            -prices[i] + ahead[0][cap]
                        );
                    else
                        dp[buy][cap] = max(
                            ahead[buy][cap],
                            prices[i] + ahead[1][cap-1]
                        );
                }
            }
            ahead = dp;
        }
        return ahead[1][k];
    }
};