class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int idx = 0, putOne = 0, putTwo = n-1;
        while(idx <= putTwo){
            if(nums[idx] == 1)
                idx++;
            else if(nums[idx] == 2)
                swap(nums[idx], nums[putTwo--]);
            else
                swap(nums[idx++], nums[putOne++]);
        }
    }
};