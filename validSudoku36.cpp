class Solution {
public:
/*

    Need to check 3 things
    1: No duplicate elements within a 3*3 grid
    2: No duplicates in the same row
    3: No duplicates in the same col

*/
    bool isSafe(vector<vector<char>> &board, int r, int c){
        // check horizontal
        char ch = board[r][c];

        for(int i = 0; i < 9; i++){
            if(i != c && ch == board[r][i]){
                return false;
            }
        }

        // check vertical

        for(int i = 0; i < 9; i++){
            if(i != r && ch == board[i][c]){
                return false;
            }
        }

        // checking in 3*3 grid

        int start_row = 3*(r/3);
        int start_col = 3*(c/3);

        for(int i = start_row; i < start_row + 3; i++){
            for(int j = start_col; j < start_col + 3; j++){
                // dont compare with itself
                if(i != r && j != c && board[i][j] == ch){
                    return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && board[i][j] != ',' && !isSafe(board, i, j)){
                    return false;
                }
            }
        }
        return true;
    }
};