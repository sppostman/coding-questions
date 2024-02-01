class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result(n/3);

        if(n%3 != 0)    return {};

        for(int i=0; i<n; i+=3){
            if(nums[i+2]-nums[i] > k)
                return {};

            int subarridx = i/3;
            for(int j=i; j<i+3; j++){
                result[subarridx].push_back(nums[j]);
            }
        }

        return result;
    }
};