class Solution {
public:
    pair<long long, bool> getPerimeterAtIdx(vector<int>& nums, int idx, long long sum){
        if(idx<2)
            return {0, false};
        return {sum, sum-nums[idx] > nums[idx]};
    }
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        long long perimeter=0;
        long long sum = 0;
        for(int side : nums){
            sum += side;
        }
        sort(nums.begin(), nums.end());

        for(int i=n-1; i>1; i--){
            const auto &[result, valid] = getPerimeterAtIdx(nums, i, sum);
            if(valid)
                return result;
            sum -= nums[i];
        }

        return -1;
    }
};