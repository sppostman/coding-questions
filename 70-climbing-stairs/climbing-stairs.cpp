class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n==0)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        int ways = 0;
        ways += solve(n-1, dp);
        if(n>1)
            ways += solve(n-2, dp);
        return dp[n] = ways;
    }
    int climbStairs(int n) {
        vector<int> dp(50, -1);
        return solve(n, dp);
    }
};