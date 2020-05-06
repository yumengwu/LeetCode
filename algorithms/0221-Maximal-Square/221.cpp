#include "../header.h"

// brute force
// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int m = matrix.size();
//         if (m == 0) {
//             return 0;
//         }
//         int n = matrix[0].size(), res = 0;
//         vector<vector<int>> cnt(m, vector<int>(n, 0));
//         for (int i = 0; i < n; ++i) {
//             cnt[m - 1][i] = matrix[m - 1][i] - '0';
//         }
//         for (int i = m - 2; i >= 0; --i) {
//             for (int j = 0; j < n; ++j) {
//                 if (matrix[i][j] == '1') {
//                     cnt[i][j] = cnt[i + 1][j] + 1;
//                 }
//             }
//         }
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 int curmin = cnt[i][j];
//                 int k;
//                 for (k = 0; j + k < n && k <cnt[i][j]; ++k) {
//                     curmin = min(curmin, cnt[i][j + k]);
//                     int temp = min(curmin, k + 1);
//                     res = max(res, temp * temp);
//                 }
//             }
//         }
//         return res;
//     }
// };

//dp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size(), res = 0;
        vector<vector<int>> cnt(m, vector<int>(n, -1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, helper(cnt, matrix, i, j));
            }
        }
        return res * res;
    }
    
    int helper(vector<vector<int>> & cnt, vector<vector<char>>& matrix, int row, int col) {
        if (cnt[row][col] >= 0) {
            return cnt[row][col];
        }
        if (matrix[row][col] == '0') {
            return cnt[row][col] = 0;
        }
        int left = row == matrix.size() - 1 ? 0 : helper(cnt, matrix, row + 1, col);
        int right = col == matrix[0].size() - 1 ? 0 : helper(cnt, matrix, row, col + 1);
        left = min(left, right);
        if (left == 0) {
            return cnt[row][col] = 1;
        }
        if (matrix[row + left][col + left] == '1') {
            return cnt[row][col] = left + 1;
        }
        else {
            return cnt[row][col] = left;
        }
    }
};