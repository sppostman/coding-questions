class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int prod = 1;
        for(auto n : nums){
            prod *= n;
            res = max(res, prod);
            if(prod == 0) prod = 1;
        }
        prod = 1;
        for(auto it=nums.rbegin(); it<nums.rend(); it++){
            prod *= *it;
            res = max(res, prod);
            if(prod == 0) prod = 1;
        }
        return res;
    }
};