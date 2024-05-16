class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        int flipped = 0;
        int mxOnes = 0;
        while(j<n){
            flipped += nums[j]==0;

            while(flipped > k){
                flipped -= nums[i] == 0;
                i++;
            }
            
            mxOnes = max(mxOnes, j-i+1);
            j++;
        }
        return mxOnes;
    }
};