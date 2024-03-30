class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int x = *max_element(nums.begin(), nums.end());
        long long total = 0;

        int i=0, j=0;
        int count=0;
        while(j<n){
            count += nums[j]==x;
            while(count == k){
                count -= nums[i] == x;
                i++;
            }
            total += i;
            j++;
        }
        return total;

        // for(int i=0; i<n; i++){
        //     long long count = 0;
        //     for(int j=i; j<n; j++){
        //         count += nums[j]==x;
        //         if(count == k){
        //             total += n-j;
        //             break;
        //         }
        //     }
        // }
        // return total;
    }
};