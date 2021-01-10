class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        auto& dp = grid;
        if (dp.size() == 0 || dp[0].size() == 0) return 0;
        int m = dp.size();
        int n = dp[0].size();
        for (int i = 1; i < m; i ++) {
            dp[i][0] = dp[i - 1][0] + dp[i][0];
        }
        for (int j = 1; j < n; j ++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + dp[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
