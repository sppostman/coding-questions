class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int pos = 0, neg = 1;
        for(int n : nums){
            if(n>0){
                res[pos] = n;
                pos+=2;
            }else{
                res[neg] = n;
                neg+=2;
            }
        }
        return res;
    }

    
};