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


        bool isNeg = n<0;
        long nn=abs(n);
        double ans=1;
        while(nn > 0){
            if(nn&1){
                // Odd
                ans *= x;
                nn--;
            } else {
                x *= x;
                nn /= 2;
            }
        }
        return isNeg ? 1.0/ans : ans;

        // // Needs to go for all 32 bits
        // bool isNegative = n<0;
        // n = abs(n);
        // double base = x, ans=1;
        // while(n>0){
        //     if(n&1){
        //         ans *= base;
        //     }
        //     base *= base;
        //     n >>= 1;
        // }
        // return isNegative ? -ans : ans;
    }
};