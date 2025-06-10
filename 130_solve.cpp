class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board[0].size();i++) {dfs(i,0,board),dfs(i,board.size()-1,board);}
        for(int i=0;i<board.size();i++) {dfs(0,i,board),dfs(board[0].size()-1,i,board);}
        for(int i=0;i<board.size();i++) for(int j=0;j<board[0].size();j++) if(board[i][j]!='X') board[i][j] = board[i][j]=='A'?'O':'X';
    }
    void dfs(int x, int y, vector<vector<char>>& board) {
        if(x<0||x==board[0].size()||y<0||y==board.size()||board[y][x]!='O') return;
        board[y][x] = 'A';
        dfs(x-1,y,board),dfs(x+1,y,board),dfs(x,y-1,board),dfs(x,y+1,board);
    }
};