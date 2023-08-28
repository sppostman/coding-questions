int deltaY[] = {-1, 1, 0, 0};
int deltaX[] = {0, 0, -1, 1};

class Solution {
public:
    void dfsMarkInvalid(
        int i, int j, int n, int m,
        vector<vector<char>>& board, vector<vector<bool>>& invalid
    ){
        invalid[i][j] = true;
        for(int d=0; d<4; d++){
            int r = deltaY[d] + i;
            int c = deltaX[d] + j;
            if(
                r<n && c<m && r>-1 && c>-1
                && board[r][c] == 'O' && !invalid[r][c]
            )
                dfsMarkInvalid(r,c,n,m,board,invalid);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        vector<vector<bool>> invalid(n, vector<bool>(m));

        for(int i=0;i<n;i++){
            if(board[i][0] == 'O')
                dfsMarkInvalid(i, 0, n, m, board, invalid);
            if(board[i][m-1] == 'O')
                dfsMarkInvalid(i, m-1, n, m, board, invalid);
        }
        for(int i=1;i<m-1;i++){
            if(board[0][i] == 'O')
                dfsMarkInvalid(0, i, n, m, board, invalid);
            if(board[n-1][i] == 'O')
                dfsMarkInvalid(n-1, i, n, m, board, invalid);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !invalid[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};