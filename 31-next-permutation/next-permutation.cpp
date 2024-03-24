class Solution {
public:
     void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int border = -1;
        for(int i=n-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                border = i-1;
                break;
            }
        }

        if(border == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i=n-1; i>border; i--){
            if(nums[i] > nums[border]){
                swap(nums[i], nums[border]);
                break;
            }
        }

        reverse(nums.begin()+border+1, nums.end());
        // 1 2 5 3 4
    }
};