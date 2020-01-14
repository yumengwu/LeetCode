#include "../header.h"

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.trailingZeroes(1808548329)<<endl;
    return 0;
}