class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> dp(1<<n, INT_MAX);
        dp[0] = 0;
        for(int mask=1; mask<(1<<n); mask++){
            for(int j=0; j<n; j++){
                if(mask & (1<<j)){
                    int prevsum = dp[mask ^ (1<<j)];
                    int newsum = prevsum+(nums1[__builtin_popcount(mask) - 1] ^ nums2[j]);
                    dp[mask] = min(dp[mask], newsum);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};