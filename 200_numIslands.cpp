class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        const int h = grid.size(), w = grid[0].size();
        int count = 0;
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        int h = grid.size(), w = grid[0].size();
        if(i < 0 || i >= h || j < 0 || j >= w || grid[i][j] != '1') return;
        grid[i][j] = '2';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};