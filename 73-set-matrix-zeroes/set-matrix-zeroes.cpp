class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();

        vector<bool> rowHasZ(m, false);
        vector<bool> colHasZ(n, false);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    rowHasZ[i] = true;
                    colHasZ[j] = true;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rowHasZ[i] || colHasZ[j])
                    matrix[i][j] = 0;
            }
        }
    }
};