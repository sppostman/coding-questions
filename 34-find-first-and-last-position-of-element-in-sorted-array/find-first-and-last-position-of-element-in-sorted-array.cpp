class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st = lb(nums,target,0,nums.size()-1);
        if(st == nums.size() || nums[st] != target)
            return {-1,-1};
        return { st, ub(nums,target,0,nums.size()-1)-1 };
    }
    int lb(vector<int>& nums, int x, int l, int r){
        int ans=nums.size();
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] >= x){
                ans=mid;
                r=mid-1;
            } else
                l=mid+1;
        }
        return ans;
    }
    int ub(vector<int>& nums, int x, int l, int r){
        int ans=nums.size();
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] > x){
                ans=mid;
                r=mid-1;
            } else
                l=mid+1;
        }
        return ans;
    }
};