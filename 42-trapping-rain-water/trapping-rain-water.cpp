class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;

        int maxL = 0, maxR = 0;
        int l = 0, r = n-1;

        while(l<=r){
            maxL = max(height[l], maxL);
            maxR = max(height[r], maxR);

            if(height[l] <= height[r]){
                water += min(maxL, maxR) - height[l];
                l++;
            } else {
                water += min(maxL, maxR) - height[r];
                r--;
            }
        }

        return water;
    }
};