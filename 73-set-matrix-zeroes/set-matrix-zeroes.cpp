class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool rowZ0 = false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    if(i==0)
                        rowZ0 = true;
                    else
                        matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(i==0)
                    matrix[i][j] = rowZ0 ? 0 : matrix[i][j];
                else
                    matrix[i][j] = matrix[i][0]==0 ? 0 : matrix[i][j];
                matrix[i][j] = matrix[0][j] == 0 ? 0 : matrix[i][j];
            }
        }
        if(matrix[0][0] == 0)
            for(int i=0; i<m; i++)
                matrix[i][0] = 0;
        if(rowZ0)
            for(int j=0; j<n; j++)
                matrix[0][j] = 0;
    }
};