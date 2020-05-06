#include "../header.h"

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) {
            return 1;
        }
        unsigned n = N, flag = 0x80000000;
        while ((n & flag) == 0) {
            n |= flag;
            flag >>= 1;
        }
        return n ^ 0xffffffff;
    }
};

