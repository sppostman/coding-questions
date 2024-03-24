class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int k) {
        int n = a.size();
        vector<int> ps(k+n+1,0);
        int sum = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            sum += a[i];
            if(sum == k)
                count++;
            if(sum-k >= 0)
                count+=ps[sum-k];
            ps[sum]++;
        }
        return count;

        // int n = nums.size();
        // int i = 0, j = 0;
        // int sum = 0;
        // int count = 0;
        // while(i<n){
        //     if(sum <= goal)
        //         count++;
        //     if(j<n && sum <= goal)
        //         sum += nums[j++];
        //     else 
        //         sum -= nums[i++];
        // }
        // return count;
    }
};