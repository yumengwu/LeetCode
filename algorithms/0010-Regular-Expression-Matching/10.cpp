#include "../header.h"

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int m = s.length(), n = p.length();
//         vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
//         dp[0][0] = true;
//         for (int i = 1; i <= n; ++i) {
//             if (p[i - 1] == '*') {
//                 dp[i][0] = dp[i - 2][0];
//             }
//         }
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j <= m; ++j) {
//                 if (p[i - 1] != '.' && p[i - 1] != '*') {
//                     dp[i][j] = p[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : false;
//                 }
//                 else if (p[i - 1] == '.') {
//                     dp[i][j] = dp[i - 1][j - 1];
//                 }
//                 else {
//                     dp[i][j] = dp[i - 2][j] || (s[j - 1] == p[i - 2] || p[i - 2] == '.') && dp[i][j - 1];
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };

// dp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.length(), n = s.length();
        bool dp[m + 1][n + 1];
        memset(dp, 0, (m + 1) * (n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            if (p[i - 1] == '*') {
                dp[i][0] = dp[i - 2][0];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 2][j] || (dp[i][j - 1] && (p[i - 2] == s[j - 1] || p[i - 2] == '.'));
                }
            }
        }
        return dp[m][n];
    }
};

// C++ re
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         string re = "^";
//         int n = p.length();
//         for (int i = 0; i < n; ++i) {
//             if (p[i] >= 'a' && p[i] <= 'z') {
//                 re += p[i];
//             }
//             else if (p[i] == '.') {
//                 re += "[a-z]";
//             }
//             else {
//                 re += "*";
//             }
//         }
//         return regex_match(s, regex(re));
//     }
// };