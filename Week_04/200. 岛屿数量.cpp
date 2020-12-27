class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col,const int& row_size, const int& col_size) {
        grid[row][col] = '0';

        if (col + 1 < col_size && grid[row][col + 1] == '1') dfs(grid, row, col + 1, row_size, col_size);
        if (col - 1 >= 0 && grid[row][col - 1] == '1') dfs(grid, row, col - 1, row_size, col_size);
        if (row + 1 < row_size && grid[row + 1][col] == '1') dfs(grid, row + 1, col, row_size, col_size);
        if (row - 1 >= 0 && grid[row - 1][col] == '1') dfs(grid, row - 1, col, row_size, col_size);
    }
    int numIslands(vector<vector<char>>& grid) {
        int nums = 0;
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        int row_size = grid.size();
        int col_size =grid[0].size();
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[i].size(); j ++) {
                if (grid[i][j] == '1') {
                    nums ++;
                    dfs(grid, i, j, row_size, col_size);
                }
            }
        }
        return nums;
    }
};
