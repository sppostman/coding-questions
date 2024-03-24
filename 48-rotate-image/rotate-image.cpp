class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        /*
        Transpose & then reverse row-wiser

        1       1 4 7   7 4 1
        2 5     2 5 8   8 5 2
        3 6 9   3 6 9   9 6 3
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