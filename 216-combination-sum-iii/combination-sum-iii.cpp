class Solution {
public:
    void comb(
        int i, int k, int target,
        vector<int> &curr, vector<vector<int>> &result
    ){
        if(curr.size() == k){
            printf("Size %d, sum %d\n", curr.size(), target);
            if(target == 0){
                result.push_back(curr);
            }
            return;
        }
        if(target <= 0 || i>9){
            return;
        }

        if(target-i >= 0){
            curr.push_back(i);
            comb(i+1, k, target-i, curr, result);
            curr.pop_back();
        }
        comb(i+1, k, target, curr, result);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;
        comb(1, k, n, curr, result);
        return result;
    }
};