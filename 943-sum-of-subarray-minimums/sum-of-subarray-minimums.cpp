class Solution {
public:
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        stack<int> inc;
        int MOD = 1e9+7;
        for(int i=0; i<=n; i++){
            while(inc.size() && (i==n || arr[i] < arr[inc.top()])){
                int elIdx = inc.top();
                inc.pop();

                int l = inc.empty() ? elIdx + 1 : elIdx - inc.top();
                int r = i - elIdx;
                sum += (arr[elIdx] * l * (long)r) % MOD;
                sum %= MOD;
            }
            inc.push(i);
        }
        return sum;
    }
};