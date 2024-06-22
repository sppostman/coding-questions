class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1])
            return -1;

        vector<vector<int>> minDist(n, vector<int>(n, INT_MAX));
        set<pair<int,pair<int,int>>> rem;

        rem.insert({ 1, { 0,0 }});
        minDist[0][0] = 1;

        while(rem.size()){
            auto it = *(rem.begin());
            int uDist = it.first;
            int ui = it.second.first;
            int uj = it.second.second;
            rem.erase(it);

            for(int i=-1; i<2; i++){
                for(int j=-1; j<2; j++){
                    if(i==0 && j==0)
                        continue;
                    int vi = ui + i;
                    int vj = uj + j;
                    if(
                        vi>=0 && vj>=0 && vi<n && vj<n &&
                        grid[vi][vj] == 0 && uDist+1 < minDist[vi][vj]
                    ){
                        rem.erase({minDist[vi][vj], {vi,vj} });
                        minDist[vi][vj] = uDist+1;
                        rem.insert({ uDist+1, {vi,vj}});
                    }
                }
            }
        }

        return minDist[n-1][n-1] == INT_MAX ? -1 : minDist[n-1][n-1];
    }
};