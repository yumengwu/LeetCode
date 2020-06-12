#include "../header.h"

/*
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
};*/

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        if (m == 0 && n == 0) {
            return true;
        }
        if (p == "*") {
            return true;
        }
        if (m > 0 && n == 0) {
            return false;
        }
        string str;
        str.reserve(n);
        str += p[0];
        for (int i = 1; i < n; ++i) {
            if (!(p[i] == '*' && p[i - 1] == '*')) {
                str += p[i];
            }
        }
        n = str.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = str[i - 1] == '*' ? dp[i - 1][0] : false;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (str[i - 1] >= 'a' && str[i - 1] <= 'z') {
                    dp[i][j] = s[j - 1] == str[i - 1] && dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};

