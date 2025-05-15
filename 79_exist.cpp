class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        string temp = ""; temp+=word[0];
        vector<vector<bool>> used(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++) 
            for(int j=0;j<board[0].size();j++) 
                if(board[i][j]==word[0] && dfs(i,j,board,word,temp,used)) return true;
        return false;
    }
    bool dfs(int i, int j, vector<vector<char>>& board, string& word, string& temp, vector<vector<bool>>& used) {
        used[i][j] = true;
        if(temp.size()==word.size()) return true;
        if(i && !used[i-1][j] && board[i-1][j]==word[temp.size()]) {
            temp += board[i-1][j];
            if(dfs(i-1,j,board,word,temp,used)) return true; 
            temp.pop_back();
        }
        if(j && !used[i][j-1] && board[i][j-1]==word[temp.size()]) {
            temp += board[i][j-1];
            if(dfs(i,j-1,board,word,temp,used)) return true; 
            temp.pop_back();
        }
        if(i+1<board.size() && !used[i+1][j] && board[i+1][j]==word[temp.size()]) {
            temp += board[i+1][j];
            if(dfs(i+1,j,board,word,temp,used)) return true; 
            temp.pop_back();
        }
        if(j+1<board[0].size() && !used[i][j+1] && board[i][j+1]==word[temp.size()]) {
            temp += board[i][j+1];
            if(dfs(i,j+1,board,word,temp,used)) return true; 
            temp.pop_back();
        }
        used[i][j] = false;
        return false;
    }
};