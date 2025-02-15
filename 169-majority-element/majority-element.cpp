class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currel = 1e9+5, currCount = 0;
        for(auto el : nums){
            if(el == currel)
                currCount++;
            else {
                currCount--;
                if(currCount < 0){
                    currel = el;
                    currCount = 1;
                }
            }
        }
        return currel;
    }
};