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
        // int l=0;
        // int curr = 0;
        // while(curr < len){
        //     while(curr+1 < len && nums[curr+1] == nums[curr])
        //         curr++;
        //     cout << "Curr @ " << curr << ", l @ " << l << endl;
        //     nums[l++] = nums[curr++];
        // }
        // return l;
    }
};