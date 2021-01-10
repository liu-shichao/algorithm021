class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int height = matrix.size();
        int width = matrix[0].size();
        int max_side = 0;
        vector<vector<int>> dp(height + 1, vector<int>(width + 1, 0));
        for (int row = 0; row < height; row ++) {
            for (int col = 0; col < width; col ++) {
                if (matrix[row][col] == '1') {
                    dp[row + 1][col + 1] = min(min(dp[row + 1][col], dp[row][col + 1]), dp[row][col]) + 1;
                    max_side = max(max_side, dp[row + 1][col + 1]);
                }
            }
        }
        return max_side * max_side;
    }
};
