class Solution {
public:
    bool isValidSplit(vector<int>& nums, int k, int maxsum){
        if(k > nums.size())
            return false;
        int subs = 1;
        int currsum = 0;
        for(int i=0; i<nums.size(); i++){
            if(currsum + nums[i] <= maxsum)
                currsum += nums[i];
            else {
                subs++;
                if(subs > k)
                    return false;
                currsum = nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = 0;
        for(int n : nums)   r+=n;

        int ans = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(isValidSplit(nums, k, m)){
                r = m-1;
                ans = m;
            } else {
                l = m+1;
            }
        }
        return ans;
    }
};