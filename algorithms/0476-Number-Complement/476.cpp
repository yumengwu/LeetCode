#include "../header.h"

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) {
            return 1;
        }
        unsigned n = num, flag = 0x80000000;
        while ((n & flag) == 0) {
            n |= flag;
            flag >>= 1;
        }
        return n ^ 0xffffffff;
    }
};

