class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // longest subarray with at most k zeros ?
        int n=nums.size();
        int l=0, r=0, zeros=0;
        int mx=0;
        while(r<n){
            zeros += nums[r]==0;

            if(zeros > k){
                zeros -= nums[l]==0;
                l++;
            }
            if(zeros <= k)
                mx = max(mx, r-l+1);
            r++;

            // while(zeros > k){
            //     zeros -= nums[l]==0;
            //     l++;
            // }
            // mx = max(mx, r-l+1);
            // r++;
        }
        return mx;

        // // O(1) space
        // int n=nums.size();
        // int l=0, r=0, skipped=0;
        // int mx = 0;
        // while(r<n){
        //     int el = nums[r];
        //     if(el == 0){
        //         if(skipped<k)
        //             skipped++;
        //         else {
        //             while(nums[l] != 0)
        //                 l++;
        //             l++;
        //         }
        //     }
        //     mx = max(mx, r-l+1);
        //     r++;
        // }
        // return mx;

        // // O(n) space for queue
        // int l=0, r=0;
        // int mx=0, canskip=k;

        // queue<int> lastZ;

        // while(r<n){
        //     int el = nums[r];
        //     if(el == 0){
        //         lastZ.push(r);
        //         if(canskip == 0){
        //             l = lastZ.front()+1;
        //             lastZ.pop();
        //         } else {
        //             canskip--;
        //         }
        //     }
        //     mx = max(mx, r-l+1);
        //     r++;
        // }
        // return mx;
    }
};