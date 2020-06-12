#include "../header.h"

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = nums1[i] * nums2[j];
                }
                else if (i == m - 1) {
                    dp[i][j] = max(nums2[j] * nums1[i], dp[i][j + 1]);
                }
                else if (j == n - 1) {
                    dp[i][j] = max(nums1[i] * nums2[j], dp[i + 1][j]);
                }
                else {
                    int a = nums1[i] * nums2[j];
                    a = max(a, a + dp[i + 1][j + 1]);
                    dp[i][j] = max(max(a, dp[i + 1][j + 1]), max(dp[i][j + 1], dp[i + 1][j]));
                }
            }
        }
        return dp[0][0];
    }
};

