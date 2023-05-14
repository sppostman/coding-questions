class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int targetCount = n/3 + 1;

        // Map - O(n) space & time
        unordered_map<int,int> counter;
        vector<int> res;
        for(int n:nums){
            counter[n]++;
            if(counter[n] == targetCount){
                res.push_back(n);
            }
        }
        return res;
    }
};