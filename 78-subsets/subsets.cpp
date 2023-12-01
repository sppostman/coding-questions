class Solution {
public:
    void subs(vector<int>& nums, vector<int>& subset, int idx, vector<vector<int>>& res){
        if(idx < 0){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        subs(nums, subset, idx-1, res);
        subset.pop_back();
        subs(nums, subset, idx-1, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> subset;
        subs(nums, subset, n-1, res);
        return res;
    }
};