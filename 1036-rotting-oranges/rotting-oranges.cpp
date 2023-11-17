class Solution {
public:
    int orangesRotting(vector<vector<int>> &given) {
        int n=given.size();
        int m=given[0].size();
        
        vector<vector<int>> grid = given;
        queue<pair<int,int>> rotten;

        int fresh=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2)
                    rotten.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }

        int dI[] = {-1, 1, 0, 0};
        int dJ[] = {0, 0, -1, 1};

        int time=0;
        while(fresh && rotten.size()){
            time++;
            int remainingAtLevel = rotten.size();
            while(fresh && remainingAtLevel--){
                pair<int, int> orange = rotten.front();
                rotten.pop();
                for(int d=0; d<4; d++){
                    int nextI = dI[d] + orange.first;
                    int nextJ = dJ[d] + orange.second;

                    if(
                        nextI > -1 && nextI <n && nextJ > -1 && nextJ < m
                        && grid[nextI][nextJ]==1
                    ){
                        grid[nextI][nextJ] = 2;
                        fresh--;
                        rotten.push({nextI, nextJ});
                    }
                }
            }
        }
        return fresh ? -1 : time;
    }
};