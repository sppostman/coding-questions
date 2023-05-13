class Solution {
public:
    static map<pair<int,int>, int> dp;
    int uniquePaths(int m, int n) {
        pair<int,int> curr = make_pair(m,n);
        if(dp.count(curr))
            return dp[curr];
        if(m==1 || n==1){
            return 1;
        }
        int res = uniquePaths(m-1, n) + uniquePaths(m, n-1);
        dp[curr] = res;
        return res;
    }
};
map<pair<int,int>, int> Solution::dp;