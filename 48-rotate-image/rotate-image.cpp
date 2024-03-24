class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        /*
        1 2 3
        4 5 6
        7 8 9

        / Transpose & then reverse row-wiser

        1 4 7  1 4 7
        2 5    2 5 8
        3      3 6 9
        */

        // Transpose
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n-i; j++)
        //         swap(matrix[i][j], matrix[j][i]);
        // }

        // // Transpose
        // for(int i=0; i<n; i++)
        //     for(int j=0; j<i; j++)
        //         swap(matrix[i][j], matrix[j][i]);
        // for(int i=0; i<n; i++)
        //     for(int j=0; j<n/2; j++)
        //         swap(matrix[i][j], matrix[i][n-j-1]);

        // Brute using extra space
        auto res = matrix;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                res[j][n-i-1] = matrix[i][j];
            }
        }
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                matrix[i][j] = res[i][j];
    }
};