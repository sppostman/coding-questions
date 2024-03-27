class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for(int a : nums)
            total += a;
        if(total == 0)
            return 0;
        
        int i=0, j=0;
        int ones = 0;
        int swaps = total-1;
        while(j < n+total-1){
            if(j-i < total){
                ones += nums[j%n];
                j++;
                swaps = min(swaps, total-ones);
            } else {
                ones -= nums[i%n];
                ones += nums[j%n];
                i++;
                j++;
                swaps = min(swaps, total-ones);
            }
        }
        return swaps;
    }
};