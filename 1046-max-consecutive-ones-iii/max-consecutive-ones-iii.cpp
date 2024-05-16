class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        int flipped = 0;
        int mxOnes = 0;
        while(j<n){
            while(nums[j]==0 && flipped == k){
                flipped -= nums[i] == 0;
                i++;
            }
            flipped += nums[j]==0;
            mxOnes = max(mxOnes, j-i+1);
            j++;
        }
        return mxOnes;
    }
};