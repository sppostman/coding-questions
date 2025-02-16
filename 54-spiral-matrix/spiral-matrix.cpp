class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int level = 0;
        vector<int> res;
        while(level < ceil(min(m,n)*1.0/2)){
            for(int j=level; j<n-level; j++)
                res.push_back(matrix[level][j]);
            for(int i=level+1; i<m-level; i++)
                res.push_back(matrix[i][n-1-level]);
            if(level != m-level-1)
                for(int j=n-level-2; j>=level; j--)
                    res.push_back(matrix[m-1-level][j]);
            if(level != n-level-1)
                for(int i=m-level-2; i>level; i--)
                    res.push_back(matrix[i][level]);
            level++;
        }
        return res;
    }
};