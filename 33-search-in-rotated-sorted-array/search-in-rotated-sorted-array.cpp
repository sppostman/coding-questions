class Solution {
public:
    int search(vector<int>& nums, int x) {
        int l = 0, r = nums.size()-1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == x)
                return mid;
            if(nums[mid] >= nums[l]){
                if(x < nums[mid] && x >= nums[l])
                    r = mid-1;
                else
                    l = mid+1;
            } else {
                if(x > nums[mid] && x <= nums[r])
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        
        return -1;
    }
};