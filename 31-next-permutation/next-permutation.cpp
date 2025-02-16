class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int border = n-1;
        while(border>0 && nums[border-1]>=nums[border]){
            border--;
        }
        if(border==0){
            sort(nums.begin(), nums.end());
            return;
        }
        int l = border, r = n-1;
        int x = nums[border-1];
        int swapidx = border;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m] > x){
                swapidx = m;
                l = m+1;
            } else r = m-1;
        }
        swap(nums[border-1], nums[swapidx]);
        sort(nums.begin()+border, nums.end());
    }   
};