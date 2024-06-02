class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0;
        int n = nums.size();

        if(n == 1)  return 0;

        int count = 1;

        while(i < n-1){
            if(i+nums[i] >= n-1)
                return count;
            
            int maxReachMaker = -1;
            for(int j=i+1; j<n && j<=i+nums[i]; j++){
                if(maxReachMaker == -1 || j+nums[j] >= maxReachMaker+nums[maxReachMaker]){
                    maxReachMaker = j;
                    printf("Matchmaker is %d\n", maxReachMaker);
                }
            }
            i = maxReachMaker;
            count++;
        }
        
        return count;
    }
};