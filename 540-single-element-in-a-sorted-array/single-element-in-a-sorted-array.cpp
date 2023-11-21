class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=n-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if((mid==0 || nums[mid] != nums[mid-1]) && (mid==n-1 || nums[mid] != nums[mid+1]))
                return nums[mid];

            if(mid+1<n && nums[mid] == nums[mid+1]){
                if((r-mid+1) & 1)
                    l=mid;
                else
                    r=mid-1;
            }
            else if(mid > 0 && nums[mid] == nums[mid-1]){
                if((mid-l+1) & 1)
                    r=mid;
                else
                    l=mid+1;
            }
        }
        return nums[l];
    }
};