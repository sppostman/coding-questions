class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // long long expected = (long)n*(n+1)/2;
        // long long actual = 0;
        // for(int i : nums)
        //     actual += i;
        // return expected-actual;

        int xor_expected = 0;
        int xor_actual = 0;
        for(int i : nums)
            xor_actual ^= i;
        for(int i=0; i<=n; i++)
            xor_expected ^= i;
        return xor_actual^xor_expected;
    }
};