class Solution {
public:
    static map<pair<int,int>, int> dp;
    int uniquePaths(int x, int y) {
        int n = x+y-2;
        int r = x>y ? y-1 : x-1;
        long res=1;
        for(int i=1;i<=r;i++){
            res = (n-i+1)*res / i;
        }
        return (int)res;

        // Optimal nCr
        // int n = x+y-2;
        // int r = x>y ? y-1 : x-1;    // Ensure least combinations
        // double res = 1;

        // for(int i=1; i<=r; i++){
        //     res = (res * (n-r+i))/i;
        // }
        // return (int)res;
        
        // pair<int,int> curr = make_pair(m,n);
        // if(dp.count(curr))
        //     return dp[curr];
        // if(m==1 || n==1){
        //     return 1;
        // }
        // int res = uniquePaths(m-1, n) + uniquePaths(m, n-1);
        // dp[curr] = res;
        // return res;
    }
};
map<pair<int,int>, int> Solution::dp;