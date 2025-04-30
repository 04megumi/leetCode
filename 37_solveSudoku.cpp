class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<vector<bool>>> cells(3, vector<vector<bool>>(3, vector<bool>(9)));
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.') continue;
                unsigned char n = board[i][j]-'0'-1;
                cols[j][n] = true, rows[i][n] = true, cells[i/3][j/3][n] = true;
            }
        }
        dfs(board,cols,rows,cells,0,0);
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& cols, vector<vector<bool>>& rows, vector<vector<vector<bool>>>& cells, unsigned char i, unsigned char j) {
        if(board[i][j]!='.') {
            if(i==8&&j==8) return true;
            return dfs(board,cols,rows,cells,j==8?i+1:i,(j+1)%9);
        }
        for(int n=0;n<9;n++) {
            if(!cols[j][n]&&!rows[i][n]&&!cells[i/3][j/3][n]) {
                board[i][j] = '0'+(n+1);
                if(i==8&&j==8) return true;
                cols[j][n]=true, rows[i][n]=true, cells[i/3][j/3][n]=true;
                if(dfs(board,cols,rows,cells,j==8?i+1:i,(j+1)%9)) return true;
                cols[j][n]=false, rows[i][n]=false, cells[i/3][j/3][n]=false;
                board[i][j] = '.';
            }
        }
        return false;
    }
};