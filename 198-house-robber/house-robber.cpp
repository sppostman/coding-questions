class Solution {
public:
    int robit(vector<int>& nums, vector<vector<int>> &dp, int i, bool cantake) {
        if(i<0) return 0;

        int take = cantake ? 1 : 0;

        if(dp[i][take] != -1)
            return dp[i][take];
        
        int maxResult = robit(nums, dp, i-1, true);

        if(cantake)
            maxResult = max(maxResult, nums[i]+robit(nums, dp, i-1, false));

        return dp[i][take]= maxResult;
    }
    int rob(vector<int>& nums) {
        // 4 2 2 9
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return robit(nums, dp, n-1, true);
    }
};