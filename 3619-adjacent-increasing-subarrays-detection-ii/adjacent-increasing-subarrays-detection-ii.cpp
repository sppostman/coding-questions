class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1)
            return n>1;
        vector<int> pref(n);
        for(int i=1; i<n; i++)
            pref[i] = pref[i-1] + (nums[i] > nums[i-1]);

        for(int i=0; i+2*k-1<n; i++){
            int j = i+k;
            if((pref[i+k-1]-pref[i] == k-1) && (pref[j+k-1]-pref[j] == k-1))
                return true;
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int l = 1, r = nums.size()/2;
        int res = 1;
        while(l<=r){
            int k = l+(r-l)/2;
            if(hasIncreasingSubarrays(nums, k)){
                res = k;
                l = k+1;
            } else r = k-1;
        }
        return res;
    }
};