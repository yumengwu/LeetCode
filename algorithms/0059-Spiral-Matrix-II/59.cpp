#include "../header.h"

/* class Solution { */
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>> res(n, vector<int>(n, 0));
//         int i = 0, j = 0, cur = 1, cnt = 0;
//         char dire = 'r';
//         while (cnt++ < n * n) {
//             res[i][j] = cur++;
//             switch (dire) {
//                 case 'u':
//                     if (i == 0 || res[i - 1][j] != 0) {
//                         ++j;
//                         dire = 'r';
//                     }
//                     else {
//                         --i;
//                     }
//                     break;
//                 case 'd':
//                     if (i == n - 1 || res[i + 1][j] != 0) {
//                         --j;
//                         dire = 'l';
//                     }
//                     else {
//                         ++i;
//                     }
//                     break;
//                 case 'l':
//                     if (j == 0 || res[i][j - 1] != 0) {
//                         --i;
//                         dire = 'u';
//                     }
//                     else {
//                         --j;
//                     }
//                     break;
//                 case 'r':
//                     if (j == n - 1 || res[i][j + 1] != 0) {
//                         ++i;
//                         dire = 'd';
//                     }
//                     else {
//                         ++j;
//                     }
//                     break;
//                 default:
//                     break;
//             }
//         }
//         return res;
//     }
/* }; */

// straight
/* class Solution { */
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>> res(n, vector<int>(n, 0));
//         int cur = 1, row = 0, col = 0, tar = n * n;
//         char c = 'r';
//         while (cur <= tar) {
//             res[row][col] = cur;
//             if (++cur > tar) {
//                 break;
//             }
//             if (c == 'r') {
//                 if (col == n - 1 || res[row][col + 1] != 0) {
//                     ++row;
//                     c = 'd';
//                 }
//                 else {
//                     ++col;
//                 }
//             }
//             else if (c == 'd') {
//                 if (row == n - 1 || res[row + 1][col] != 0) {
//                     --col;
//                     c = 'l';
//                 }
//                 else {
//                     ++row;
//                 }
//             }
//             else if (c == 'l') {
//                 if (col == 0 || res[row][col - 1] != 0) {
//                     --row;
//                     c = 'u';
//                 }
//                 else {
//                     --col;
//                 }
//             }
//             else {
//                 if (row == 0 || res[row - 1][col] != 0) {
//                     ++col;
//                     c = 'r';
//                 }
//                 else {
//                     --row;
//                 }
//             }
//         }
//         return res;
//     }
/* }; */

// shorter
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int cur = 1;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - i; ++j) {
                res[i][j] = cur++;
            }
            for (int j = i + 1; j < n - i; ++j) {
                res[j][n - i - 1] = cur++;
            }
            for (int j = i + 1; j < n - i; ++j) {
                res[n - i - 1][n - j - 1] = cur++;
            }
            for (int j = i + 2; j < n - i; ++j) {
                res[n - j][i] = cur++;
            }
        }
        if (n & 1) {
            res[n / 2][n / 2] = cur;
        }
        return res;
    }
};

