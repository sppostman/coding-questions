class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0, prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(prev >= nums[i]){
                res += prev+1-nums[i];
                nums[i] = prev+1;
            }
            prev = nums[i];
        }
        return res;
    }
};