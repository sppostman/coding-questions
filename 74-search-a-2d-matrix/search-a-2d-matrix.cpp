class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        if(target < matrix[0][0] || matrix[m-1][n-1] < target)
            return false;

        int l=0, r=m*n-1;
        while(l <= r){
            int mid = l+(r-l)/2;
            int i = mid/n, j=mid%n;
            // printf("mid(%d), [%d][%d] =",mid,i,j);
            cout<<matrix[i][j]<<endl;
            if(matrix[i][j] == target)
                return true;
            if(target < matrix[i][j])
                r = mid-1;
            else
                l = mid+1;
        }
        return false;

        // int tr = -1;
        // int lr=0,rr=m-1;
        
        // while(lr <= rr){
        //     int mr = lr + (rr-lr)/2;
        //     if(matrix[mr][0] <= target && target <= matrix[mr][n-1]){
        //         tr=mr;
        //         break;
        //     }
        //     if(target < matrix[mr][0])
        //         rr = mr-1;
        //     else
        //         lr = mr+1;
        // }

        // if(tr == -1)
        //     return false;
        
        // int l=0, r=n-1;
        // while(l<=r){
        //     int mid = l+(r-l)/2;
        //     if(matrix[tr][mid] == target)
        //         return true;
        //     if(target < matrix[tr][mid])
        //         r = mid-1;
        //     else
        //         l = mid+1;
        // }
        // return false;
    }
};