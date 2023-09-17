class Solution {
public:
    bool isSafe(int i, int j, int n, vector<string> &board){
        for(int c=0; c<j; c++){
            if(board[i][c] == 'Q')
                return false;
        }

        int r = i-1, c = j-1;
        while(r>-1 && c>-1){
            if(board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        
        r = i+1;
        c = j-1;
        while(r<n && c>-1){
            if(board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }
        return true;
    }
    void nq(
        int j, int n,
        vector<string> &board, vector<vector<string>> &result
    ){
        if(j==n){
            result.push_back(board);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(isSafe(i, j, n, board)){
                board[i][j] = 'Q';
                nq(j+1, n, board, result);
                board[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string row(n, '.');
        vector<string> board(n, row);
        nq(0, n, board, result);
        return result;
    }
};