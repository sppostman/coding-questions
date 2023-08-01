class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m, vector<vector<bool>> &vis){
        vis[i][j] = true;
        // printf("(%d,%d), ",i,j);

        pair<int,int> combinations[] = {{i-1,j}, {i+1,j}, {i,j-1}, {i,j+1}};
        
        for(auto i : combinations){
            if(
                i.first > -1 && i.first < n &&
                i.second > -1 && i.second < m &&
                grid[i.first][i.second]=='1' && !vis[i.first][i.second]
            ){
                // printf("Go to (%d,%d)\n", i.first,i.second);
                dfs(i.first,i.second,grid,n,m,vis);
            }
        }
        // if(i-1 > -1 && !vis[i-1][j])
        //     dfs(i-1, j, grid, n, m,vis);
        // if(j-1 > -1 && !vis[i][j-1])
        //     dfs(i, j-1, grid, n, m,vis);
        // if(i+1 < n && !vis[i+1][j])
        //     dfs(i+1, j, grid, n, m,vis);
        // if(j+1 < m && !vis[i][j+1])
        //     dfs(i, j+1, grid, n, m,vis);
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        
        int islands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    islands++;
                    // printf("Island starts (%d,%d), ",i,j);
                    dfs(i, j, grid,n,m, vis);
                    // printf("\n");
                }
            }
        }
        return islands;
    }
};