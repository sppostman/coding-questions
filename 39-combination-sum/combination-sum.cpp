class Solution {
public:
    void combine(vector<int>& candidates, vector<int> &curr, int idx, int target, vector<vector<int>> &result){
        if(idx<0)
            return;
        if(target==0){
            result.push_back(curr);
            return;
        }
        combine(candidates, curr, idx-1, target, result);

        if(target >= candidates[idx]){
            curr.push_back(candidates[idx]);
            combine(candidates, curr, idx, target-candidates[idx], result);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> result;
        combine(candidates, curr, candidates.size()-1, target, result);
        return result;
    }
};