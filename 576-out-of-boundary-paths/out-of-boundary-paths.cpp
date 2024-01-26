const int MOD = 1e9+7;

class Solution {
public:
    int pathsFromHere(int x, int y, int m, int n, int remainingMoves, vector<vector<vector<int>>> &dp){
        if(x<0 || y<0 || x>=m || y>=n){
            return 1;
        }
        if(remainingMoves == 0)
            return 0;

        if(dp[remainingMoves][x][y] != -1)
            return dp[remainingMoves][x][y];

        int dX[] = {-1, 1, 0, 0};
        int dY[] = {0, 0, -1, 1};

        int paths = 0;

        for(int i=0; i<4; i++){
            int nextX = x+dX[i];
            int nextY = y+dY[i];

            paths = (paths + pathsFromHere(nextX, nextY, m, n, remainingMoves-1, dp)) % MOD;
        }

        return dp[remainingMoves][x][y] = paths % MOD;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(
            maxMove+1,
            vector<vector<int>>(m, vector<int>(n, -1))
        );
        return pathsFromHere(startRow, startColumn, m, n, maxMove, dp);
    }
};