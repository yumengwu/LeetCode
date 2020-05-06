#include "../header.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long d1 = labs(dividend), d2 = labs(divisor), res = 0;
        bool sign = ((dividend < 0) ^ (divisor < 0)) ? false : true;
        if (d2 == 1) {
            return sign ? d1 : -d1;
        }
        while (d1 >= d2) {
            long t = d2, p = 1;
            while (d1 >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            d1 -= t;
        }
        return sign ? res : -res;
    }
};

