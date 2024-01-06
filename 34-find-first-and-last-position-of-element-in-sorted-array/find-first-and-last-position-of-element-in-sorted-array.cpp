class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // int n=nums.size();
        // int l=0, r=n-1;
        // int lb=n;
        // while(l<=r){
        //     int mid = l+(r-l)/2;
        //     if(nums[mid] >= target){
        //         lb = mid;
        //         r=mid-1;
        //     } else
        //         l = mid+1;
        // }

        // if(lb == n || nums[lb] != target)
        //     return {-1,-1};

        // int ub=n;
        // l=0, r=n-1;
        // while(l<=r){
        //     int mid = l+(r-l)/2;
        //     if(nums[mid] > target){
        //         ub = mid;
        //         r=mid-1;
        //     } else
        //         l=mid+1;
        // }
        // return {lb, ub-1};
        
        int st = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(st == nums.size() || nums[st] != target)
            return {-1,-1};
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return { st, end-1 };
    }

};