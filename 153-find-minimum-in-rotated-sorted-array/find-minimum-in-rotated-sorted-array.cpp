class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int mn = nums[0];
        while(l<=r){
            int m = l+(r-l)/2;
            mn = min(mn, nums[m]);

            if(nums[l] <= nums[r]){
                return min(mn, nums[l]);
            }

            if(nums[l] <= nums[m]){
                l = m+1;
                // mn = min(nums[l], mn);
            } else {
                r = m-1;
            }
            
        }
        return mn;
    }
};