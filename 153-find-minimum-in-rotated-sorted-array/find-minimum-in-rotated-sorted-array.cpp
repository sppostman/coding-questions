class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int ans = nums[0];
        while(l<=r){
            int m = l+(r-l)/2;

            ans = min(ans, nums[m]);

            // 3 4 5 6 7 0 1 2 3 4 
            // 5 7 0 1 2 3 4
            
            if(nums[l] <= nums[m]){
                ans = min(ans, nums[l]);
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return ans;
    }
};