class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberrOfSubarraysLessK(nums,k) - numberrOfSubarraysLessK(nums,k-1);
    }
    int numberrOfSubarraysLessK(vector<int>& nums, int k) {
        int odds = 0, count=0;
        int i=0, j=0;
        int n = nums.size();
        while(j<n){
            odds += nums[j] & 1;
            while(odds > k)
                odds -= nums[i++] & 1;
            count += j-i+1;
            j++;
        }
        return count;
    }
};