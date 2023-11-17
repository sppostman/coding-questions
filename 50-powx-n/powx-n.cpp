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
        long pow = abs(n);
        double ans=1;
        while(pow>0){
            if(pow & 1){
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