class Solution {
public:
    int findMin(vector<int>& nums) {
        // Not rotated at all
        if(nums[0] < nums[nums.size()-1])
            return nums[0];
        
        int l=0,r=nums.size()-1,mid;
        int mn = nums[0];
        while(l<=r){
            if(nums[l] <= nums[r])
                return min(mn, nums[l]);

            mid = l+(r-l)/2;
            
            // mn = min(mn, nums[mid]);

            if(nums[l] <= nums[mid]){
                mn = min(mn, nums[l]);
                l = mid+1;
            } else {
                mn = min(mn, nums[mid]);
                r = mid-1;
            }

        }
        return mn;
    }
};