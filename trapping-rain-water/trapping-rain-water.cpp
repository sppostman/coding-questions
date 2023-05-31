class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        // Time - O(N),  Space - O(1)
        int l=0, r=n-1;
        int lMax=0, rMax=0, res=0;
        while(l<=r){
            if(height[l] <= height[r]){
                if(height[l] >= lMax)
                    lMax = height[l];
                else
                    res += lMax-height[l];
                l++;
            } else {
                if(height[r] >= rMax)
                    rMax = height[r];
                else
                    res += rMax-height[r];
                r--;
            }
        }
        return res;


        // Time - O(3N),  Space - O(2N), 
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);

        prefixMax[0] = height[0];
        suffixMax[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            prefixMax[i] = max(prefixMax[i-1], height[i]);
            suffixMax[n-i-1] = max(suffixMax[n-i], height[n-i-1]);
        }
        int trapped=0;
        int tmp;
        for(int i=0; i<n; i++){
            // Find capacity at that point based on walls
            tmp = min(prefixMax[i], suffixMax[i]);

            // Is current wall occupying that capacity itself ?
            if(tmp > height[i])
                trapped += tmp-height[i];
        }

        return trapped;
    }
};