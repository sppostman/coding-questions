class Solution {
public:
     void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int border = -1;
        for(int i=n-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                border = i-1;
                break;
            }
        }

        if(border == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i=n-1; i>border; i--){
            if(nums[i] > nums[border]){
                swap(nums[i], nums[border]);
                break;
            }
        }

        reverse(nums.begin()+border+1, nums.end());

        // 1 2 5 3 4
    }
    
    void nextPermutation22(vector<int>& nums) {
        int n = nums.size();
        int breakpoint = -1;
        for(int i=n-2; i>-1; i--){
            if(nums[i] < nums[i+1]){
                breakpoint = i;
                break;
            }
        }
        //printf("Breakpoint [%d]%d\n",breakpoint, breakpoint>-1 ?nums[breakpoint]:-1);
        
        if(breakpoint == -1){
            // reverse if no breakpoint
            reverse(nums.begin(), nums.end());
            // for(int j=0; j<n/2; j++)
            //     swap(nums[j], nums[n-j-1]);
            return;
        } 

        for(int j=n-1; j>breakpoint; j--){
            if(nums[j] > nums[breakpoint]){
            //printf("Swap [%d]%d & [%d]%d\n",breakpoint,nums[breakpoint], j,nums[j]);
                // Put just greater than in breakpoint place
                swap(nums[breakpoint], nums[j]);
                break;
            }
        }

        // Sort nums to the right in ascending, to keep result minimum
        // But since, they're already in descending, just reverse them
        // reverse if no breakpoint
        reverse(nums.begin()+breakpoint+1, nums.end());
    }
};