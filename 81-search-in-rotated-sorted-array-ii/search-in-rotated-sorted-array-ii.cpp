class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;

        while(l<=r){
            int m = l+(r-l)/2;

            if(nums[m] == target)
                return true;            
            if(nums[l] == nums[r] && nums[l] == nums[m]){
                l++;
                r--;
            } else if(
                (nums[l] < nums[m] && nums[l] <= target && target <= nums[m]) ||
                (nums[l] > nums[m] && (nums[l] <= target || target <= nums[m]))
            ){
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return false;
    }
};