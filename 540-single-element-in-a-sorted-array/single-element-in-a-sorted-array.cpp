class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        

        if(n==1 || nums[0] != nums[1])
            return nums[0];
        if(nums[n-1] != nums[n-2])
            return nums[n-1];

        int l = 1, r = n-2;

        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m] != nums[m-1] && nums[m] != nums[m+1])
                return nums[m];
            if(nums[m] == nums[m-1]){
                if((m&1) == 1)
                    l = m+1;
                else
                    r = m-2;
            } else {
                if((m&1) == 0)
                    l = m+2;
                else
                    r = m-1;
            }
        }

        return -1;

        // int l=2, r=n-3;
        // while(l<r){
        //     int mid = l+(r-l)/2;
        //     if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
        //         return nums[mid];

        //     if(nums[mid] == nums[mid+1]){
        //         if((r-mid+1) & 1)
        //             l=mid;
        //         else
        //             r=mid-1;
        //     }
        //     else if(nums[mid] == nums[mid-1]){
        //         if((mid-l+1) & 1)
        //             r=mid;
        //         else
        //             l=mid+1;
        //     }
        // }
        // return nums[l];
    }
};