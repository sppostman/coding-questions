class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n==1 || nums[0] > nums[1])
            return 0;
        if(nums[n-1] > nums[n-2])
            return n-1;

        int l = 1, r = nums.size()-2;

        while(l<=r){
            int m = l+(r-l)/2;

            if(nums[m-1] < nums[m] && nums[m] > nums[m+1])
                return m;
            
            if(nums[m] < nums[m+1]){
                l = m+1;
            } else {
                r = m-1;
            }
        }

        return -1;
    }
};