class Solution {
public:
bool dfsIsClosed(int i, int j, vector<vector<int>>& matrix, 
        int N, int M, vector<vector<bool>> &visited
    ){
        bool isClosed = true;
        visited[i][j] = true;
        
        if(i==0 || j==0 || i==N-1 || j==M-1){
            isClosed = false;    
            // printf("On boundary @ %d,%d\n", i,j);
        }
        
        int rows[] = { i,   i,   i-1, i+1};
        int cols[] = { j-1, j+1, j,   j };
        
        for(int c=0; c<4; c++){
            int p = rows[c], q = cols[c];
            if(
                p>-1 && q>-1 && p<N && q<M &&
                !matrix[p][q] && !visited[p][q]
            ){
                if(!dfsIsClosed(p,q,matrix,N,M,visited))
                    isClosed = false;
            }
        }
        
        return isClosed;
    }
    
    int closedIsland(vector<vector<int>>& matrix) {
        int N=matrix.size(), M = matrix[0].size();
        int closedIslands = 0;
        vector<vector<bool>> visited(N, vector<bool>(M,false));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!matrix[i][j] && !visited[i][j]){
                    if(dfsIsClosed(i,j, matrix, N, M, visited)){
                        closedIslands++;
                        // printf("Dfs from %d,%d - closed\n", i,j);
                    }
                }
            }   
        }
        return closedIslands;
    }
};