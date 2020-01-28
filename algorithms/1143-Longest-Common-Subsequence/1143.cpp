#include "../header.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        if (n == 0 || m == 0) {
            return 0;
        }
        int ** v = new int * [n + 1];
        for (int i = 0; i <= n; ++i) {
            v[i] = new int [m + 1];
        }
        for (int i = 0; i <= n; ++i) {
            v[i][0] = 0;
        }
        for (int i = 0; i <= m; ++i) {
            v[0][i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    v[i][j] = v[i - 1][j - 1] + 1;
                }
                else {
                    v[i][j] = max(v[i- 1][j - 1], max(v[i - 1][j], v[i][j - 1]));
                }
            }
        }
        int res = v[n][m];
        delete [] v;
        return res;
    }
};