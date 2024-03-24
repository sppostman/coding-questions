class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();

        // vector<bool> rowHasZ(m, false);
        // vector<bool> colHasZ(n, false);
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(matrix[i][j] == 0){
        //             rowHasZ[i] = true;
        //             colHasZ[j] = true;
        //         }
        //     }
        // }
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(rowHasZ[i] || colHasZ[j])
        //             matrix[i][j] = 0;
        //     }
        // }

        // No extra space
        int col0 = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j==0)
                        col0 = 0;
                    else
                        matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<m; i++){
            for(int j=n-1; j>0; j--){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j] = 0;
            }
        }
        if(matrix[0][0] == 0){
            for(int j=0; j<n; j++)
                matrix[0][j] = 0;
        }
        if(col0 == 0){
            for(int i=0; i<m; i++)
                matrix[i][0] = 0;
        }
    }
};