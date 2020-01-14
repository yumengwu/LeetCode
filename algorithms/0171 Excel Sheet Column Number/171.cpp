#include "../header.h"

class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += pow(26, n - 1 - i) * (s[i] - 'A' + 1);
        }
        return res;
    }
};