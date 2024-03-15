class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;

        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
        
        // vector<int> extras;
        // for(int i=0; i<n-k; i++){
        //     extras.push_back(nums[i]);
        // }

        // for(int i=0; i<k; i++)
        //     nums[i] = nums[n-k+i];
        // for(int i=k; i<n; i++){
        //     nums[i] = extras[i-k];
        // }

        // int i = 0;
        // while(i<k){
        //     nums[i] = nums[n-k+i];
        //     i++;
        // }
        // for(int e : extras)
        //     nums[i++] = e;
    }
};