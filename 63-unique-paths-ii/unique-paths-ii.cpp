class Solution {
public:
    int gopaths(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int i, int j, int m, int n){
        if(i==m-1 && j==n-1)
            return obstacleGrid[i][j] == 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        int paths = 0;
        
        if(i+1 < m && obstacleGrid[i+1][j] == 0)
            paths += gopaths(obstacleGrid, dp, i+1, j, m, n);
        if(j+1 < n && obstacleGrid[i][j+1] == 0)
            paths += gopaths(obstacleGrid, dp, i, j+1, m, n);
        return dp[i][j]=paths;
    };
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1])
            return 0;
        int paths=0;
        return gopaths(obstacleGrid,dp,0,0,m,n);
    }
};