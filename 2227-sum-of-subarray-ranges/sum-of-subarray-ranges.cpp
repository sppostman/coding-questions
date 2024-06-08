class Solution {
public:
    long long subArray(vector<int>& nums, bool minMode){
        stack<int> st;
        int n = nums.size();
        long long sum = 0;

        for(int i=0; i<=n; i++){
            while(st.size()>0 && (i==n || (minMode ? nums[i] < nums[st.top()] : nums[i] > nums[st.top()]))){
                int j = st.top();
                st.pop();

                long long r = i-j;
                long long l = st.empty() ? j+1 : j-st.top() ;
                sum += r * l * nums[j];
            }
            st.push(i);
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return subArray(nums, false) - subArray(nums, true);
    }
};