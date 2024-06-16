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
    int trapWithStack(vector<int>& height) {
        int n = height.size();
        int water = 0;

        stack<int> dec;
        for(int i=0; i<n; i++){
            while(dec.size() && height[i] > height[dec.top()]){
                int maxR = height[i];

                int curr = height[dec.top()];
                dec.pop();

                if(dec.empty())
                    break;
                
                int maxL = height[dec.top()];
                
                int height = min(maxR, maxL) - curr;
                int width = i - dec.top() - 1;
                water += height * width;
            }
            dec.push(height[i]);
        }

        return water;
    }
};