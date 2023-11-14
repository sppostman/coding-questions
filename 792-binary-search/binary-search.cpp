class Solution {
public:
    int sch(vector<int>& nums, int target, int l, int r){
        if(l > r){
            return -1;
        }
        int mid = l + (r-l)/2;

        if(nums[mid] == target)
            return mid;
            
        if(nums[mid] < target)
            return sch(nums, target, mid+1, r);
        return sch(nums, target, l, mid-1);
    }
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;

        return sch(nums, target, l, r);

        // int mid;
        // while(l<=r){
        //     mid = l + (r-l)/2;
        //     if(nums[mid] == target)
        //         return mid;
        //     if(nums[mid] < target)
        //         l = mid+1;
        //     else
        //         r = mid-1;
        // }
        // return -1;
    }
};