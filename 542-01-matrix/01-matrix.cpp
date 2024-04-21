class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m));
        queue<pair<int,int>> rem;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    rem.push({i,j});
                }
                else
                    dist[i][j] = 1e7;
            }
        }

        int di[] = {0,0,-1,1};
        int dj[] = {-1,1,0,0};
        while(rem.size()){
            int i = rem.front().first;
            int j = rem.front().second;
            rem.pop();

            for(int d=0; d<4; d++){
                int goi = i+di[d];
                int goj = j+dj[d];

                if(goi>=0 && goj>=0 && goi<n && goj<m && dist[i][j]+1 < dist[goi][goj]){
                    dist[goi][goj] = dist[i][j]+1;
                    rem.push({ goi, goj });
                }
            }
        }
        return dist;
    }
};