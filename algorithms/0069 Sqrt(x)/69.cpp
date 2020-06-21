#include "../header.h"

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int l = 0, r = x / 2;
        while (l < r) {
            int m = l + (r - l) / 2;
            long cur = m;
            cur *= m;
            if (cur > x) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        long ll = l;
        ll *= l;
        return ll > x ? l - 1 : l;
    }
};

