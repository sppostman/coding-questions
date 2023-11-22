class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int r=0, c=m-1;
        while(r<n && c>-1){
            if(target == matrix[r][c])
                return true;
            if(target < matrix[r][c])
                c--;
            else
                r++;
        }
        return false;
    }
};