class Solution {
public:
    double myPow(double x, int n) {
        // bool isNeg = n<0;
        // n=abs(n);
        // double result=1;
        // while(n-- > 0){
        //     result *= x;
        // }
        // return isNeg ? 1/result : result;

        // 3^10
        // 3^2^5 = 9^5
        // 9^4 * 9
        // 81^2 * 9
        // 6561^1 * 9
        // 6561^0 * 6561 * 9
        
        // bool isNeg = n<0;
        // long pow = abs(n);
        // double ans=1;
        // while(pow>0){
        //     if(pow & 1){
        //         ans *= x;
        //         pow--;
        //     } else {
        //         x *= x;
        //         pow >>= 1;
        //     }
        // }
        // return isNeg ? 1.0/ans : ans;

        bool isNeg = n < 0;
        long pow = abs(n);
        double ans=1;

        while(pow>0){
            if(pow&1){
                ans *= x;
                pow--;
            } else {
                x *= x;
                pow >>= 1;
            }
        }

        return isNeg ? 1.0/ans : ans;
    }
};