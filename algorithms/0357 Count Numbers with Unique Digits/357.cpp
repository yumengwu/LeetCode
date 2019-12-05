#include "../header.h"

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int res = 10;
        int cnt = 9;
        for (int i = 1; i < n && i < 10; ++i) {
            cnt *= (10 - i);
            res += cnt;
        }
        return res;
    }
};