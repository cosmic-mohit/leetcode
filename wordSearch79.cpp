class Solution {
public:
    int m,n;

    int row[4] = {-1,0,0,1};
    int col[4] = {0,-1,1,0};

    bool isValid(int i, int j){
        return i>=0&&i<m&&j>=0&&j<n;
    }

    bool dfs(int i, int j, int idx, string &word, vector<vector<char>> &board){
        if(idx == word.length()) return true;

        if(!isValid(i, j) || board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        for(int k = 0; k < 4; k++){
            int new_i = i + row[k];
            int new_j = j + col[k];
            if(dfs(new_i, new_j, idx+1, word, board)){
                // if path found do backtrack instanly otherwise parent cells ke lie board 
                // corrupt ho jaaega
                board[i][j] = temp;

                // return se pehle safai karni hi padegi
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        char ch = word[0];
        int curr_idx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == ch && dfs(i, j, curr_idx, word, board)){
                    return true;
                }
            }
        }
        return false;
    }
};