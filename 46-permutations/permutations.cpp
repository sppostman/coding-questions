class Solution {
public:
    // void perm(
    //     vector<int>& nums, vector<int> &curr,
    //     set<int> &taken, vector<vector<int>> &result
    // ){
    //     if(curr.size() == nums.size()){
    //         result.push_back(curr);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         if(!taken.count(nums[i])){
    //             taken.insert(nums[i]);
    //             curr.push_back(nums[i]);
    //             perm(nums, curr, taken, result);
    //             curr.pop_back();
    //             taken.erase(nums[i]);
    //         }
    //     }
    // }

    void perm2(
        vector<int>& nums, vector<int> &curr,
        vector<bool> &taken, vector<vector<int>> &result
    ){
        if(curr.size() == nums.size()){
            result.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!taken[i]){
                taken[i] = true;
                curr.push_back(nums[i]);
                perm2(nums, curr, taken, result);
                curr.pop_back();
                taken[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;

        // set<int> taken;
        // perm(nums, curr, taken, result);
        
        vector<bool> taken(nums.size());
        perm2(nums, curr, taken, result);
        
        return result;
    }
};