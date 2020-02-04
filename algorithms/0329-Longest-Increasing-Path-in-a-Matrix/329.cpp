#include "../header.h"

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& m, vector<vector<int>>& dp, int row, int col) {
        if (dp[row][col]) {
            return dp[row][col];
        }
        int cur = m[row][col];
        int u = row > 0 && m[row - 1][col] > cur ? dfs(m, dp, row - 1, col) : 0;
        int d = row < m.size() - 1 && m[row + 1][col] > cur ? dfs(m, dp, row + 1, col) : 0;
        int l = col > 0 && m[row][col - 1] > cur ? dfs(m, dp, row, col - 1) : 0;
        int r = col < m[0].size() - 1 && m[row][col + 1] > cur ? dfs(m, dp, row, col + 1) : 0;
        dp[row][col] = max(max(u, d), max(l, r)) + 1;
        return dp[row][col];
    }
};