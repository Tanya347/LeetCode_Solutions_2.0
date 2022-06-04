class Solution {
public:
    void nQueens_helper(vector<vector<string>>& ans, vector<string> board, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, int row, int n) {
        
        //push back and return if a possibility has been completed
        if(row == n) {
            ans.push_back(board);
            return;
        }
        
        for(int col = 0; col < n; col++) {
            
            //check if the column and diagonals associated with this cell are occupied or not
            if(!cols[col] && !diag1[row + col] && !diag2[row - col + n - 1]) {
                
                //place the queen and mark the columns and diagonals occupied
                board[row][col] = 'Q';
                cols[col] = true;
                diag1[row + col] = true;
                diag2[row - col + n - 1] = true;
                
                //make the call on the next row
                nQueens_helper(ans, board, cols, diag1, diag2, row + 1, n);
                
                //backtrack
                cols[col] = false;
                diag1[row + col] = false;
                diag2[row - col + n - 1] = false;
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        //final vector that will store all the possibilities
        vector<vector<string>> ans;
        
        //vector to store one possibility at a time
        vector<string> board(n, string(n, '.'));
        
        //these vectors store whether these columns or diagonals are occupied or not
        vector<bool> cols(n, false);
        vector<bool> diag1(2*n - 1, false);
        vector<bool> diag2(2*n - 1, false);
        
        nQueens_helper(ans, board, cols, diag1, diag2, 0, n);
        
        return ans;
    }
};