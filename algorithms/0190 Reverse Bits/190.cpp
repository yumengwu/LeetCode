#include "../header.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t high = 0x80000000, low = 1;
        for (int i = 0; i < 16; ++i) {
            uint32_t th = n & high, tl = n & low;
            n ^= th;
            n ^= tl;
            n |= (th >> (32 - 2 * i - 1));
            n |= (tl << (32 - 2 * i - 1));
            high >>= 1;
            low <<= 1;
        }
        return n;
    }
};

int main()
{
    Solution s;
    cout<<s.reverseBits(43261596)<<endl;
    return 0;
}