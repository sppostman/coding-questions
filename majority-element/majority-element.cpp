class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el=-1;
        int count=0;
        for(int n:nums){
            if(n==el)
                count++;
            else if(count == 0){
                el=n;
                count=1;
            } else {
                count--;
            }
        }
        if(count > n/2)
            return el;
        count=0;
        for(int n:nums){
            if(n==el){
                count++;
                if(count > n/2){
                    return el;
                }
            }
        }
        if(count > n/2){
            return el;
        }
        return -1;
    }
};