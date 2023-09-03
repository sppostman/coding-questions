class Solution {
public:
    void subsets(
        vector<int>& nums, int n, vector<int> curr,
        vector<vector<int>> &result, set<vector<int>> &taken
    ){
        if(n<0){
            sort(curr.begin(), curr.end());
            if(!taken.count(curr)){
                result.push_back(curr);
                taken.insert(curr);
            }
            return;
        }
        subsets(nums, n-1, curr, result, taken);

        curr.push_back(nums[n]);
        subsets(nums, n-1, curr, result, taken);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> taken;
        vector<vector<int>> result;
        vector<int> curr;
        subsets(nums, nums.size()-1, curr, result, taken);
        return result;
        // result.push_back({});
        // for(int i=0;i<nums.size(); i++){
        //     vector<int> curr;
        //     for(int j=i; j<nums.size(); j++){
        //         curr.push_back(nums[j]);
        //         if(!taken.count(curr)){
        //             result.push_back(curr);
        //             taken.insert(curr);
        //         }
        //     }
        // }
        // return result;
    }
};