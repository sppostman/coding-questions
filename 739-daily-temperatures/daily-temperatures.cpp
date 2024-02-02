class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> result(n, 0);

        stack<int> bigger;

        // [73,74,75,71,69,72,76,73]
        for(int i=n-1; i>=0; i--){
            while(!bigger.empty() && t[bigger.top()] <= t[i])
                bigger.pop();
            
            if(!bigger.empty() && t[bigger.top()] > t[i]){
                result[i] = bigger.top() - i;
            }

            bigger.push(i);
        }

        return result;
    }
};