class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> lused;
        int n = heights.size();

        for(int i=1; i<n; i++){
            if(heights[i] <= heights[i-1])
                continue;

            int jump = heights[i]-heights[i-1];
            lused.push(jump);

            if(lused.size() > ladders){
                bricks -= lused.top();
                lused.pop();
            }
            if(bricks < 0)
                return i-1;
        }
        return n-1;
    }

    // 4 12 2 7 3 18 20 3 19
    //  l  - b - l  
};