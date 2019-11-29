#include "../header.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        char * str = new char[m + 1];
        int i = 0, j = 0;
        while (j < m) {
            str[i++] = p[j++];
            while (j < p.length() && p[j] == '*' && p[j - 1] == '*') {
                j++;
            }
        }
        str[i] = 0;
        m = strlen(str);
        vector<vector<bool>> v(m + 1, vector<bool>(n + 1, false));
        v[0][0] = true;
        for (i = 1; i <= m; ++i) {
            if (str[i - 1] == '*') {
                v[i][0] = v[i - 1][0];
            }
            else {
                v[i][0] = false;
            }
        }
        for (i = 1; i <= m; ++i) {
            for (j = 1; j <= n; ++j) {
                if (str[i - 1] == '*') {
                    v[i][j] = v[i - 1][j] || v[i][j - 1];
                }
                if (str[i - 1] == s[j - 1] || str[i - 1] == '?') {
                    v[i][j] = v[i - 1][j - 1];
                }
            }
        }
        delete [] str;
        return v[m][n];
    }
};