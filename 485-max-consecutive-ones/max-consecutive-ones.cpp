class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxcons = nums[0]==1;
        int currcons = nums[0]==1;

        for(int i=1; i<n; i++){
            if(nums[i]==1){
                currcons++;
            } else {
                currcons = 0;
            }
            maxcons = max(maxcons, currcons);
        }
        return maxcons;
    }
};