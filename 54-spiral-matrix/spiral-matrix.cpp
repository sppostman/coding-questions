class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int m=mat.size(), n=mat[0].size();
        int l=0, r=n-1;
        int t=0, b=m-1;
        while(l<=r && t<=b){
            for(int j=l; j<=r; j++)
                res.push_back(mat[t][j]);
            t++;

            for(int i=t; i<=b; i++)
                res.push_back(mat[i][r]);
            r--;

            if(t <= b){
                for(int j=r; j>=l; j--)
                    res.push_back(mat[b][j]);
                b--;
            }
            if(l <= r){
                for(int i=b; i>=t; i--)
                    res.push_back(mat[i][l]);
                l++;
            }
        }
        return res;
    }
};