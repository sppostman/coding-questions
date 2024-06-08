class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
        int MOD = 1e9+7;
        stack<int> st;
        int n = arr.size();

        for(int i=0; i<=n; i++){
            while(st.size() > 0 && (i==n || arr[i] <= arr[st.top()]) ){
                int j = st.top();
                st.pop();

                int right = i - j;
                int left = st.empty() ? j+1 : j-st.top();
                long count = (left * right) % MOD;
                sum += (arr[j] * count) % MOD;
                sum %= MOD;
            }
            st.push(i);
        }
        return sum;
    }
};