class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0);
        if(total&1)
            return false;
        
        long long half = total >> 1; // total / 2
        int n = nums.size();

        // starting from ith position, is it possible to select items such that sum is tsum
        // dp[i][tsum] -> dp[i+1][tsum] or dp[i+1][tsum-a[i]]

        vector<bool> nxt(half+1);
        nxt[0] = true;
        for(int i=n-1; i>=0; i--){
            vector<bool> dp = nxt;
            for(int tsum=0; tsum<=half; tsum++){
                // dp[tsum] = nxt[tsum];
                if(nums[i] <= tsum && nxt[tsum-nums[i]])
                    dp[tsum] = true;
            }
            nxt = dp;
        }

        return nxt[half];
    }
};