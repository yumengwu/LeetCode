#include "../header.h"

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) {
            return false;
        }
        int cnt = 0;
        unsigned n = num;
        while ((n & 1) == 0) {
            ++cnt;
            n >>= 1;
        }
        return n == 1 && cnt % 2 == 0;
    }
};

