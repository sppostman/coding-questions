class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subLessK(nums, k) - subLessK(nums,k-1);
        // // O(n^2)
        // int n=nums.size(), count=0;
        // for(int i=0; i<n; i++){
        //     unordered_map<int, int> freq;
        //     for(int j=i; j<n; j++){
        //         freq[nums[j]]++;
        //         if(freq.size() == k)
        //             count++;
        //         else if(freq.size() > k)
        //             break;
        //     }
        // }
        // return count;
    }
    int subLessK(vector<int>& nums, int k) {
        int i=0, j=0, n=nums.size();
        int count = 0;
        unordered_map<int, int> freq;

        while(j<n){
            freq[nums[j]]++;

            while(freq.size() > k){
                if(--freq[nums[i]] == 0)    
                    freq.erase(nums[i]);
                i++;
            }

            count += j-i+1;

            j++;
        }


        return count;
    }
};