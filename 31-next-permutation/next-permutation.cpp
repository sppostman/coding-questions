class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /**
        7 1,3 1
        7 3 1 1

        7 3 8 4 7 1 2 3  ->  ascending, swap last pair
        7 3 8 4 7 1|3 2 -> border on descending, find upperbound swap with it
                            sort on right of border

        7 3 2 1
        
        7 3 8 4 7 2 1 3 
        7 3 8 4 7 2 3 1
        7 3 8 4 7 3 1 2

        7 3 8 4|7 3 2 1 -> descending, swap on border sort right side
        7 3 8 7 1 2 3 4

        **/
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