#include "../header.h"

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2) {
            return 1;
        }
        vector<int> v(n + 1, 0);
        v[0] = 1;
        v[1] = 1;
        v[2] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                v[i] = max(v[i], max((i - j) * j, (i - j) * v[j]));
            }
        }
        return v[n];
    }
};