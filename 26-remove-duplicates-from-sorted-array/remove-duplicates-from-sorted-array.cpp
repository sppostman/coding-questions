class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int anchor = 0;
        int n = nums.size();
        while(anchor<n && i<n){
            while(i+1<n && nums[i+1]==nums[i])
                i++;
            nums[anchor++] = nums[i++];
        }
        return anchor;
    }
};