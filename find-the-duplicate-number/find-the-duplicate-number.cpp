class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=nums[0];
        int f=nums[0];
        do{
            f = nums[nums[f]];
            s = nums[s];
        }while(f != s);
        // Till now only cycle is detected, exactly where, don't know
        // printf("COllided at %d\n",f) ;
        
        s=nums[0];
        while(s != f){
            f = nums[f];
            s = nums[s];
        }
        return f;
    }
};