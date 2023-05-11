class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(!intervals.size())
            return res;
        sort(intervals.begin(), intervals.end());
        res.push_back({intervals[0][0], intervals[0][1]});
        int targetIdx = 0;
        for(vector<int> pair : intervals){
            if(pair[0] <= res[targetIdx][1]){
                res[targetIdx][1] = max(res[targetIdx][1], pair[1]);
            } else {
                res.push_back({pair[0], pair[1]});
                targetIdx++;
            }
        }
        return res;
    }
};