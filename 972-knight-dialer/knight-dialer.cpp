const int MOD = 1e9+7;

class Solution {
public:
    int paths(int n, int cell, vector<vector<int>> &nb, vector<vector<int>> &dp){
        // printf("for %d(%d), explore\n", cell, n);
        if(dp[cell][n] != -1)
            return dp[cell][n];
            
        if(n==1)
            return 1;
        int count = 0;
        for(int adj : nb[cell]){
            count = (count+paths(n-1, adj, nb, dp))%MOD;
        }
        return dp[cell][n] = count;
    }
    int knightDialer(int n) {
        if(n==1)
            return 10;

        vector<vector<int>> nb {
         {4,6}, {6, 8}, {7,9}, {4,8}, {0,3,9}, {}, {0, 1,7}, {2,6}, {1,3}, {2,4}
        };
        vector<vector<int>> dp(10, vector<int>(n+1, -1));
        
        for(int i=0; i<10; i++){
            dp[i][1] = 1;
            dp[i][2] = nb[i].size();
        }
        int ways = 0;
        for(int i=0; i<10; i++){
            ways = (ways + paths(n, i, nb, dp))%MOD;
        }
        return ways;
    }
};