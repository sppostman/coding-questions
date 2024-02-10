class Solution {
public:
    int mySqrt(int x) {
        if(x<2)
            return x;
        
        // long i=1;
        // while(i*i <= x){
        //     i++;
        // }
        // return i-1;

        long l=1, r=x/2, mid;
        long ans=1;
        while(l<=r){
            mid = l+(r-l)/2;
            if(mid*mid <= x){
                ans = mid;
                l = mid+1;
            } else
                r = mid-1;
        }
        return ans;
    }
};