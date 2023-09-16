class Solution {
public:
    // Gives TLE
    // void findunique(
    //     vector<int>& candidates, int target, int idx,
    //     vector<int> &curr, set<vector<int>> &taken
    // ){
    //     int n = candidates.size();
    //     if(target == 0){
    //         taken.insert(curr);
    //         return;
    //     }
    //     if(idx == n)    return;

    //     if( target >= candidates[idx]){
    //         curr.push_back(candidates[idx]);
    //         findunique(candidates, target-candidates[idx], idx+1, curr, taken);
    //         curr.pop_back();
    //     }
    //     findunique(candidates, target, idx+1, curr, taken);
    // }
    void findunique(
        vector<int>& candidates, int target, int idx,
        vector<int> &curr, vector<vector<int>> &result
    ){
        int n = candidates.size();
        if(target == 0){
            result.push_back(curr);
            return;
        }
        if(idx >= n)    return;


        int next = idx+1;
        if(target >= candidates[idx]){
            curr.push_back(candidates[idx]);
            findunique(candidates, target-candidates[idx], next, curr, result);
            curr.pop_back();
        }
        
        while(next<n && candidates[next] == candidates[idx])
            next++;
        findunique(candidates, target, next, curr, result);
    }
    vector<vector<int>> combinationSum2(vector<int>& given, int target) {
        vector<int> candidates = given;
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        vector<vector<int>> result;
        findunique(candidates, target, 0, curr, result);
        return result;
    }
};