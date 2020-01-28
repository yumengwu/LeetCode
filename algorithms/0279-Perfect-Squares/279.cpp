#include "../header.h"

class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        int i = 0;
        while (i * i <= n) {
            v.push_back(i * i);
            ++i;
        }
        vector<vector<int>> dp(v.size(), vector<int>(n + 1, INT_MAX));
        for (int i = 0; i < v.size(); ++i) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            dp[0][i] = INT_MAX;
        }
        for (int i = 1; i < v.size(); ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j - v[i] >= 0) {
                    dp[i][j] = min(dp[i][j - v[i]] + 1, dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[v.size() - 1][n];
    }
};