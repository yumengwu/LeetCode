#include "../header.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int m = matrix[0].size();
        if (m == 0) {
            return 0;
        }
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            grid[0][i] = matrix[0][i] - '0';
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    grid[i][j] = grid[i - 1][j] + 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, largestRectangleArea(grid[i]));
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return heights[0];
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && heights[i] > heights[i + 1] || i == n - 1) {
                int mh = heights[i];
                for (int j = i; j >= 0; --j) {
                    if (heights[j] < mh) {
                        mh = heights[j];
                    }
                    res = max(res, mh * (i - j + 1));
                }
            }
        }
        return res;
    }
};