class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int rangeStart = intervals[0][0], rangeEnd = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start <= rangeEnd){
                rangeEnd = max(end, rangeEnd);
            } else {
                result.push_back({ rangeStart, rangeEnd });
                rangeStart = start;
                rangeEnd = end;
            }
        }
        result.push_back({ rangeStart, rangeEnd });
        return result;
    }
};