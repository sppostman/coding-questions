class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> minEffort(n, vector<int>(m, INT_MAX));
        set<pair<int,pair<int,int>>> rem;

        rem.insert({ 0, { 0,0 }});
        minEffort[0][0] = 0;

        while(rem.size()){
            auto it = *(rem.begin());
            int uEffort = it.first;
            int ui = it.second.first;
            int uj = it.second.second;
            rem.erase(it);

            int di[] = {-1,1,0,0};
            int dj[] = {0,0,-1,1};

            for(int d=0; d<4; d++){
                int vi = ui + di[d];
                int vj = uj + dj[d];

                if(vi>=0 && vj>=0 && vi<n && vj<m){
                    int maxEffort = max(uEffort, abs(grid[ui][uj] - grid[vi][vj]));
                    if(maxEffort < minEffort[vi][vj]){
                        rem.erase({minEffort[vi][vj], {vi,vj} });
                        minEffort[vi][vj] = maxEffort;
                        rem.insert({ maxEffort, {vi,vj}});
                    }
                }
            }
        }

        return minEffort[n-1][m-1] == INT_MAX ? -1 : minEffort[n-1][m-1];
    }
};