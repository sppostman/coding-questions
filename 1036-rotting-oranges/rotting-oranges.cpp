class Solution {
    static const int dirs = 4;
    static constexpr int di[dirs] = { 0, 0, 1, -1 };
    static constexpr int dj[dirs] = { 1, -1, 0, 0 };

    static bool isSafe(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> oranges = grid;
        int n = grid.size(), m = grid[0].size();

        int fresh = 0;
        queue<pair<int,int>> rotten;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(oranges[i][j] == 1)
                    fresh++;
                else if(oranges[i][j] == 2)
                    rotten.push({ i, j });
            }
        }

        int mins = 0;
        while((!rotten.empty()) && fresh>0){
            mins++;
            int active = rotten.size();
            while(active--){
                auto [i, j] = rotten.front();
                rotten.pop();

                for(int d=0; d<dirs; d++){
                    int nxtI = i+di[d], nxtJ = j+dj[d];
                    if(isSafe(nxtI, nxtJ, n, m) && oranges[nxtI][nxtJ] == 1){
                        oranges[nxtI][nxtJ] = 2;
                        rotten.push({ nxtI, nxtJ });
                        fresh--;
                    }
                }
            }
        }

        return fresh > 0 ? -1 : mins;  
    }
};