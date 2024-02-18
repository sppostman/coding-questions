int dj[] = {-1, 0, 1};

class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j1, int j2, int n, int m, vector<vector<vector<int>>> &dp){
        if(i==n || j1==-1 || j2==-1 || j1==m || j2==m)
            return 0;
        
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int cherries = grid[i][j1] + grid[i][j2];
        if(j1==j2)
            cherries -= grid[i][j1];

        int best = 0;
        for(int dj1=0; dj1<3; dj1++){
            for(int dj2=0; dj2<3; dj2++){
                best = max(best, solve(grid, i+1, j1+dj[dj1], j2+dj[dj2], n, m, dp));
            }
        }
        return dp[i][j1][j2] = best + cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(grid, 0, 0, m-1, n, m, dp);
    }
};