#include "../header.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        while (n > 1) {
            if (n & 1 != 0) {
                return false;
            }
            n >>= 1;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isPowerOfTwo(218)<<endl;
    return 0;
}