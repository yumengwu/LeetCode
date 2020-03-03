#include "../header.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 32; ++i) {
            cnt += ((x & 1) ^ y) & 1;
            x >>= 1;
            y >>= 1;
        }
        return cnt;
    }
};