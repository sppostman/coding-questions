class Solution {
public:
    bool works(vector<int>& nums, int threshold, int divisor){
        int sum = 0;
        for(int el : nums){
            // sum += ceil(el/divisor);
            sum += (el+divisor-1) / divisor;
            if(sum > threshold)
                return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, h = *max_element(nums.begin(), nums.end());
        int mid, ans=-1;
        while(l<=h){
            mid = l+(h-l)/2;
            if(works(nums, threshold, mid)){
                ans = mid;
                h = mid-1;
            } else
                l = mid+1;
        }
        return ans;
    }
};