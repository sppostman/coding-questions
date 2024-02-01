class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if(n%3 != 0)    return {};

        for(int i=0; i<n; i+=3){
            vector<int> next;
            if(nums[i+2]-nums[i] > k)
                return {};
            for(int j=i; j<i+3; j++){
                next.push_back(nums[j]);
            }
            result.push_back(next);
            // cout<<nums[i]<<", ";
        }

        return result;
    }
};