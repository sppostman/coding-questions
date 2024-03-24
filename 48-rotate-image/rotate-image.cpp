class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        /*
        Transpose & then reverse row-wiser

        1 4 7  1 4 7
        2 5    2 5 8
        3      3 6 9
        */

        // Transpose
        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++)
                swap(matrix[i][j], matrix[j][i]);

        // Reverse horizontally
        for(int i=0; i<n; i++)
            for(int j=0; j<n/2; j++)
                swap(matrix[i][j], matrix[i][n-j-1]);
    }
};