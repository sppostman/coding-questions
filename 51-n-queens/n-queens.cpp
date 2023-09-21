class Solution {
public:
    bool isSafe(
        int i, int j, int n,
        bool *rows, bool *diags, bool *diags2,
        vector<string> &board
    ){
        // printf("Check safe %d, %d \- %d, %d, %d \n", i, j, i, i+j, n-1 + j-i);
        if(
            rows[i] || diags[i+j] || diags2[n-1 + j-i]
        ){
            return false;
        }
        return true;

        // for(int c=0; c<j; c++){
        //     if(board[i][c] == 'Q')
        //         return false;
        // }

        // int r = i-1, c = j-1;
        // while(r>-1 && c>-1){
        //     if(board[r][c] == 'Q')
        //         return false;
        //     r--;
        //     c--;
        // }
        
        // r = i+1;
        // c = j-1;
        // while(r<n && c>-1){
        //     if(board[r][c] == 'Q')
        //         return false;
        //     r++;
        //     c--;
        // }
        // return true;
    }

    void toggleQueen(
        int i, int j, int n, bool rows[n], bool diags[2*n-1], bool diags2[2*n-1],
        vector<string> &board, bool place
    ){
        board[i][j] = place ? 'Q' : '.';
        rows[i]=place;
        diags[i+j]=place;
        diags2[n-1 + j-i] = place;
    }

    void nq(
        int j, int n, bool rows[n], bool diags[2*n-1], bool diags2[2*n-1],
        vector<string> &board, vector<vector<string>> &result
    ){
        if(j==n){
            result.push_back(board);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(isSafe(i, j, n, rows, diags, diags2, board)){
                toggleQueen(i, j, n, rows, diags, diags2, board, true);
                nq(j+1, n, rows, diags, diags2, board, result);
                toggleQueen(i, j, n, rows, diags, diags2, board, false);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string row(n, '.');
        vector<string> board(n, row);

        bool rows[n];
        bool diags[2*n-1];
        bool diags2[2*n-1];
        fill(rows, rows+n, false);
        fill(diags, diags+ (2*n-1), false);
        fill(diags2, diags2+ (2*n-1), false);

        nq(0, n, rows, diags, diags2, board, result);
        return result;
    }
};