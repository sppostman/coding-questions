class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 1 5 7 10 < 3
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for(int i=0; i<=n; i++){
            while(st.size()>0 && (i==n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i-st.top()-1;

                maxArea = max(maxArea, height*width);
            }
            st.push(i);
        }

        return maxArea;
    }
};