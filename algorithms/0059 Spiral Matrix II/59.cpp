#include "../header.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int i = 0, j = 0, cur = 1, cnt = 0;
        char dire = 'r';
        while (cnt++ < n * n) {
            res[i][j] = cur++;
            switch (dire) {
                case 'u':
                    if (i == 0 || res[i - 1][j] != 0) {
                        ++j;
                        dire = 'r';
                    }
                    else {
                        --i;
                    }
                    break;
                case 'd':
                    if (i == n - 1 || res[i + 1][j] != 0) {
                        --j;
                        dire = 'l';
                    }
                    else {
                        ++i;
                    }
                    break;
                case 'l':
                    if (j == 0 || res[i][j - 1] != 0) {
                        --i;
                        dire = 'u';
                    }
                    else {
                        --j;
                    }
                    break;
                case 'r':
                    if (j == n - 1 || res[i][j + 1] != 0) {
                        ++i;
                        dire = 'd';
                    }
                    else {
                        ++j;
                    }
                    break;
                default:
                    break;
            }
        }
        return res;
    }
};