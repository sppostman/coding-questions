class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        // space - O(n), time - O(n)
        int trapped = 0;
        int pmax = height[0];
        vector<int> smax(n, 0);
        smax[n-1] = height[n-1];
        
        for(int i=n-2; i>=0; i--)
            smax[i] = max(smax[i+1], height[i]);
        
        for(int i=1; i<n-1; i++){
            trapped += max(min(pmax, smax[i+1]) - height[i], 0);
            pmax = max(pmax, height[i]);
        }
        return trapped;
        
        // space - O(2n), time - O(n)
        // int trapped = 0;
        // vector<int> pmax(n, 0);
        // vector<int> smax(n, 0);
        // pmax[0] = height[0];
        // smax[n-1] = height[n-1];

        // for(int i=1; i<n; i++)
        //     pmax[i] = max(pmax[i-1], height[i]);
        
        // for(int i=n-2; i>=0; i--)
        //     smax[i] = max(smax[i+1], height[i]);
        
        // for(int i=1; i<n-1; i++)
        //     trapped += max(min(pmax[i-1], smax[i+1]) - height[i], 0);
        // return trapped;
    }
};