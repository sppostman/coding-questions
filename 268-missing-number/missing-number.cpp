class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long expected = (long)n*(n+1)/2;
        long long actual = 0;
        for(int i : nums)
            actual += i;
        return expected-actual;
    }
};