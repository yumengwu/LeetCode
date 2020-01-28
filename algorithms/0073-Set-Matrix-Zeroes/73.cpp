#include "../header.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return;
        }
        int m = matrix[0].size();
        if (m == 0) {
            return;
        }
        vector<bool> row(n, true), col(m, true);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = false;
                    col[j] = false;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!row[i] || !col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};