class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        
        vector<int> extras;
        for(int i=0; i<n-k; i++){
            extras.push_back(nums[i]);
        }

        int i = 0;
        while(i<k){
            nums[i] = nums[n-k+i];
            i++;
        }

        for(int e : extras)
            nums[i++] = e;
    }
};