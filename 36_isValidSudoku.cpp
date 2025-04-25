class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> rows = vector<vector<bool>>(9, vector<bool>(9));
        vector<vector<vector<bool>>> cells(3, vector<vector<bool>>(3, vector<bool>(9)));
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                unsigned char n = board[i][j]-'0'-1;
                if(board[i][j]=='.') continue;
                if(cols[j][n] || rows[i][n] || cells[i/3][j/3][n]) return false;
                cols[j][n] = true, rows[i][n] = true, cells[i/3][j/3][n] = true;
            }
        }
        return true;
    }
};
