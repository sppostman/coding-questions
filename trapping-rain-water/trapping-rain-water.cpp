class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
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
            tmp = min(prefixMax[i], suffixMax[i]);
            if(tmp > height[i])
                trapped += tmp-height[i];
        }

        return trapped;
    }
};