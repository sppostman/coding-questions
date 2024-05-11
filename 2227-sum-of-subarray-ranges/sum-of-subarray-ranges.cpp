class Solution {
public:
    long long sumSubArrayMin(vector<int> &nums, int n){
        // 3 1 2 4 => 17

        stack<int> ple;
        long long sum = 0;
        long long left,right;

        for(int i=0; i<n; i++){
            while(ple.size() && nums[ple.top()] > nums[i]){
                int j = ple.top();
                ple.pop();

                left = ple.size() ? j-ple.top() : j+1;
                right = i-j;
                sum += nums[j] * left * right;
            }
            ple.push(i);
        }
        while(ple.size()){
            int j = ple.top();
            ple.pop();

            left = ple.size() ? j-ple.top() : j+1;
            right = n-j;
            sum += nums[j] * left * right;
        }
        return sum;
    }
    long long sumSubArrayMax(vector<int> &nums, int n){
        // 3 1 2 4 => 30

        stack<int> pge;
        long long sum = 0;
        long long left,right;

        for(int i=0; i<n; i++){
            while(pge.size() && nums[pge.top()] < nums[i]){
                int j = pge.top();
                pge.pop();
                
                left = pge.size() ? j-pge.top() : j+1;
                right = i-j;
                sum += nums[j] * left * right;
            }
            pge.push(i);
        }
        while(pge.size()){
            int j = pge.top();
            pge.pop();

            left = pge.size() ? j-pge.top() : j+1;
            right = n-j;
            sum += nums[j] * left * right;
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        return sumSubArrayMax(nums, n) - sumSubArrayMin(nums, n);
    }
};