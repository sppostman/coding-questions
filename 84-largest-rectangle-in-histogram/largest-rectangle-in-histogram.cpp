class Solution {
public:
    vector<int> smaller(vector<int>& heights, int n, bool prev) {
        vector<int> se(n, 0);
        stack<int> ls;

        int start = prev ? 0 : n-1;
        int delta = prev ? 1 : -1;
        int outofboundSmaller = prev ? -1 : n;

        for(int i=start; prev ? i<n : i>=0 ; i+=delta){
            while(ls.size() && heights[ls.top()] >= heights[i]){
                int j = ls.top();
                ls.pop();
                se[j] = ls.size() ? ls.top() : outofboundSmaller;
            }
            ls.push(i);
        }
        while(ls.size()){
            int j = ls.top();
            ls.pop();
            se[j] = ls.size() ? ls.top() : outofboundSmaller;
        }
        return se;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse = smaller(heights, n, true);
        vector<int> nse = smaller(heights, n, false);
        
        int maxArea = 0;
        for(int i=0; i<n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            maxArea = max(maxArea, (left+right-1)*heights[i]);
        }
        return maxArea;
    }
};