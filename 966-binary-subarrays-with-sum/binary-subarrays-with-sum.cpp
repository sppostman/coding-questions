class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int k) {
        unordered_map<long, int> ps;
        int n = a.size();
        long sum = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            sum += a[i];
            if(sum == k)
                count++;
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