class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0;
        int n = nums.size();

        int count = 0;

        while(i < n-1){
            count++;

            if(i+nums[i] >= n-1)
                return count;

            int maxReachMaker = i;
            for(int j=i+1; j<n && j<=i+nums[i]; j++){
                if(j+nums[j] >= maxReachMaker+nums[maxReachMaker]){
                    maxReachMaker = j;
                }
            }
            i = maxReachMaker;
        }
        
        return count;
    }
};