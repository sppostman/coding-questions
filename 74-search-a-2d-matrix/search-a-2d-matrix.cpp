class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        if(target < matrix[0][0] || matrix[m-1][n-1] < target)
            return false;


        int tr = -1;
        int lr=0,rr=m-1;
        
        while(lr <= rr){
            int mr = lr + (rr-lr)/2;
            if(matrix[mr][0] <= target && target <= matrix[mr][n-1]){
                tr=mr;
                break;
            }
            if(target < matrix[mr][0])
                rr = mr-1;
            else
                lr = mr+1;
        }

        if(tr == -1)
            return false;
        
        int l=0, r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(matrix[tr][mid] == target)
                return true;
            if(target < matrix[tr][mid])
                r = mid-1;
            else
                l = mid+1;
        }
        return false;



        // int foundRange = 0;

        // // search for valid range
        // int mrow;
        // int lrow = 0, rrow = matrix.size()-1;
        // while(lrow <= rrow){
        //     mrow = lrow+(rrow-lrow)/2;
        //     if(target>=matrix[mrow][0]){
        //         if(target <= matrix[mrow][n-1]){
        //             foundRange = mrow;
        //             break;
        //         } else {
        //             lrow = mrow+1;
        //         }
        //     } else {
        //         rrow = mrow-1;
        //     }
        // }

        // // printf("Found range: %d\n", foundRange);


        // // search in range
        // int l=0, r=n-1, mid;
        // while(l<=r){
        //     mid=l+(r-l)/2;
        //     if(matrix[foundRange][mid] == target)
        //         return true;
        //     if(matrix[foundRange][mid] < target)
        //         l=mid+1;
        //     else
        //         r=mid-1;
        // }

        // return false;



    }
};