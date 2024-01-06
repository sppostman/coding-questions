class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, r=n-1;
        int lb=n;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m] >= target){
                lb=m;
                r=m-1;
            } else {
                l=m+1;
            }
        }
        if(lb==n || nums[lb] != target)
            return {-1, -1};

        l=0;
        r=n-1;
        int ub=n;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m] <= target){
                l=m+1;
            } else {
                ub=m;
                r=m-1;
            }
        }
        return {lb, ub-1};
        
        // int st = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // if(st == nums.size() || nums[st] != target)
        //     return {-1,-1};
        // int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        // return { st, end-1 };
    }

};