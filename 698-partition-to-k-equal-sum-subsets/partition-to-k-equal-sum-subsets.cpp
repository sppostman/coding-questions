class Solution {
public:
    bool dfs(int start, vector<int>& nums, vector<bool>& used, int k, int curSum, int target) {
        if (k == 1) return true;  // last subset is guaranteed valid
        
        if (curSum == target) 
            return dfs(0, nums, used, k - 1, 0, target);

        for (int i = start; i < nums.size(); i++) {
            if (used[i] || curSum + nums[i] > target) continue;

            used[i] = true;
            if (dfs(i + 1, nums, used, k, curSum + nums[i], target)) 
                return true;
            used[i] = false;

            // prune duplicate subset starts
            if (curSum == 0) return false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        if (total % k != 0) return false;

        sort(nums.rbegin(), nums.rend()); // decreasing sort
        vector<bool> used(nums.size(), false);
        return dfs(0, nums, used, k, 0, total / k);
    }
};
