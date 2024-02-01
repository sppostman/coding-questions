class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if(n%3 != 0)    return {};

        for(int i=0; i<n; i+=3){
            vector<int> next;
            for(int j=i; j<i+3; j++){
                if(nums[j]-nums[i] > k)
                    return {};
                next.push_back(nums[j]);
            }
            result.push_back(next);
            // cout<<nums[i]<<", ";
        }

        return result;
    }
};