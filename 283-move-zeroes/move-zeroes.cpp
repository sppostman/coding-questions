class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int anchor = 0, i=0;
        for(; i<n; i++){
            nums[anchor] = nums[i];
            if(nums[i] != 0)
                anchor++;
        }
        while(anchor<n)
            nums[anchor++]=0;

        // int z=0;
        // printf("n %d\n", n);
        // for(int i=0; i<n; i++){
        //     if(nums[i]==0){
        //         z++;
        //         // printf("skip %d\n", nums[i]);
        //         continue;
        //     }
        //     // printf("z:%d, nums[%d] <- nums[%d] (%d) | now, n-z: %d\n", z, i-z, i, nums[i], n-z);
        //     nums[i-z] = nums[i];


        //     // if(i-z != i && i+1 >= n-z){
        //     //     printf("set to 0 %d[%d]\n", nums[i],i);
        //     //     nums[i]=0;
        //     // }
        // }


        // // printf("Zs: %d\n",z);
        // while(z-- > 0){
        //     nums[n-1-z] = 0;
        // }
    }
};