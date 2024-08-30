class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subLessThanK(nums, k) - subLessThanK(nums, k-1);
    }
    int subLessThanK(vector<int>& nums, int k) {
        if(k==0)
            return 0;
        int i=0, j=0;
        int n = nums.size();
        map<int,int> freq;
        int count = 0;
        while(j<n){
            freq[nums[j]]++;
            while(freq.size() > k){
                freq[nums[i]]--;
                if(freq[nums[i]] == 0)
                    freq.erase(nums[i]);
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
};