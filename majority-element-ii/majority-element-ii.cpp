class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int targetCount = n/3 + 1;
        map<int,int> counter;
        vector<int> res;
        for(int n:nums){
            if(counter[n] == -1)
                continue;
            counter[n]++;
            if(counter[n] >= targetCount){
                res.push_back(n);
                counter[n] = -1;
            }
        }
        return res;
    }
};