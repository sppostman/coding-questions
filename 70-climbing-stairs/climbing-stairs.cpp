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
        // vector<int> dp(50, -1);
        // return solve(n, dp);

        // 0 1 2 3 4 5
        // 1 1 2 3 5 8
        int prev = 1, prev2 = 1;
        for(int i=2; i<=n; i++){
            int curr = prev+prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};