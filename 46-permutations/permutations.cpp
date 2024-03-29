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

    // void perm2(
    //     vector<int>& nums, vector<int> &curr,
    //     vector<bool> &taken, vector<vector<int>> &result
    // ){
    //     if(curr.size() == nums.size()){
    //         result.push_back(curr);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         if(!taken[i]){
    //             taken[i] = true;
    //             curr.push_back(nums[i]);
    //             perm2(nums, curr, taken, result);
    //             curr.pop_back();
    //             taken[i] = false;
    //         }
    //     }
    // }

    // void perm3(
    //     vector<int>& nums, vector<int> &curr,
    //     int idx, vector<vector<int>> &result
    // ){
    //     if(idx == nums.size()){
    //     // if(curr.size() == nums.size()){
    //         result.push_back(curr);
    //         return;
    //     }
        
    //     for(int i=idx;i<nums.size();i++){
    //         swap(nums[idx], nums[i]);
    //         curr.push_back(nums[idx]);
    //         perm3(nums, curr, idx+1, result);
    //         curr.pop_back();
    //         swap(nums[idx], nums[i]);
    //     }
    // }

    void p3(vector<int> &nums, vector<int> &curr, int i, vector<vector<int>> &result){
        if(i == nums.size()){
            result.push_back(curr);
            return;
        }

        for(int j=i; j<nums.size(); j++){
            swap(nums[i], nums[j]);
            curr.push_back(nums[i]);
            p3(nums, curr, i+1, result);
            curr.pop_back();
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;

        // set<int> taken;
        // perm(nums, curr, taken, result);
        
        // vector<bool> taken(nums.size());
        // perm2(nums, curr, taken, result);
        
        // perm3(nums, curr, 0, result);
        p3(nums, curr, 0, result);
        return result;
    }
};