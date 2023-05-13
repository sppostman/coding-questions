class Solution {
public:
    static map<pair<int,int>, int> dp;
    int uniquePaths(int m, int n) {
        if(dp.count(make_pair(m,n)))
            return dp[make_pair(m,n)];
        if(m==1 || n==1){
            return 1;
        }
        int res = uniquePaths(m-1, n) + uniquePaths(m, n-1);
        dp[make_pair(m,n)] = res;
        return res;
    }
};
map<pair<int,int>, int> Solution::dp;