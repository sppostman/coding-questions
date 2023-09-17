class Solution {
public:
    void perm(
        vector<int>& nums, vector<int> &curr,
        set<int> &taken, vector<vector<int>> &result
    ){
        if(taken.size() == nums.size()){
            result.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!taken.count(nums[i])){
                taken.insert(nums[i]);
                curr.push_back(nums[i]);
                perm(nums, curr, taken, result);
                curr.pop_back();
                taken.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        set<int> taken;
        vector<int> curr;
        perm(nums, curr, taken, result);
        return result;
    }
};