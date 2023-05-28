class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Naive - O(n^2) for each element, travel ahead and count
        // Better - Hash map of counts o(n) time & space
        // Optimal - Moore - O(n)

        int n=nums.size();
        int el = nums[0], count = 0;
        for(int n : nums){
            if(n == el)
                count++;
            else if(count == 0){
                el=n;
                count=1;
            }
            else
                count--;
        }
        if(count > n/2)
            return el;
        count = 0;
        for(int n:nums)
            if(n==el)
                count++;
        if(count > n/2)
            return el;
        return -1;





















        // int n=nums.size();
        // int el=-1;
        // int count=0;
        // for(int n:nums){
        //     if(n==el)
        //         count++;
        //     else if(count == 0){
        //         el=n;
        //         count=1;
        //     } else {
        //         count--;
        //     }
        // }
        // if(count > n/2)
        //     return el;
        // count=0;
        // for(int n:nums){
        //     if(n==el){
        //         count++;
        //         if(count > n/2){
        //             return el;
        //         }
        //     }
        // }
        // if(count > n/2){
        //     return el;
        // }
        // return -1;
    }
};