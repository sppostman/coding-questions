class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int firstz = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int lastz = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int pos = nums.size() - lastz;
        int neg = firstz;
        return max(pos, neg);
    }
};