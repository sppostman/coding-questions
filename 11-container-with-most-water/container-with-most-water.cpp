class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int res = 0;
        while(l<r){
            if(height[l] <= height[r]){
                res = max(res, (r-l) * height[l]);
                l++;
            } else {
                res = max(res, (r-l) * height[r]);
                r--;
            }
        }
        return res;
    }
};