class Solution {
public:
    int solve(int i, char prevChar, string &s, int k, vector<vector<int>> &dp){
        if(i==s.size())
            return 0;
        if(dp[i][prevChar-'a'] != -1)
            return dp[i][prevChar-'a'];

        int res = solve(i+1, prevChar, s, k, dp);
        if(prevChar == '{' || abs(s[i] - prevChar) <= k){
            res = max(res, solve(i+1, s[i], s, k, dp) + 1);
        }
        return dp[i][prevChar-'a'] = res;
    }

    int longestIdealString(string s, int k) {
        int n = s.size();

        // vector<vector<int>> dp(n, vector<int>(27, -1));
        // return solve(0, '{', s, k, dp);

        vector<int> dp(27, 0);
        int maxRes = 0;
        for(int i=0; i<n; i++){
            int curr = s[i]-'a';
            int maxPrev = 0;
            for(int prev=max(0, curr-k); prev<=min(25, curr+k); prev++){
                maxPrev = max(maxPrev, dp[prev]);
            }
            dp[curr] = maxPrev+1;
            maxRes = max(dp[curr], maxRes);
        }
        return maxRes;
    }
};