class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& og) {
        vector<vector<int>> mat = og;
        int m = mat.size(), n=mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        
        queue<pair<int,int>> toVisit;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0)
                    toVisit.push({ i, j });
            }
        }

        int di[] = {0,0,-1,1};
        int dj[] = {-1,1,0,0};

        int currTime = 0;
        while(toVisit.size()){
            currTime++;

            int pendingAtLevel = toVisit.size();
            while(pendingAtLevel--){
                int ui = toVisit.front().first;
                int uj = toVisit.front().second;
                toVisit.pop();

                for(int d=0; d<4; d++){
                    int vi = ui + di[d];
                    int vj = uj + dj[d];

                    if(vi>=0 && vi<m && vj>=0 && vj<n && mat[vi][vj] == 1){
                        mat[vi][vj] = 0;
                        dist[vi][vj] = currTime;
                        toVisit.push({ vi, vj });
                    }
                }
            }
        }

        return dist;
    }
};