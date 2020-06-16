#include "../header.h"

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1 = 0, m2 = 0;
        for (int i : nums) {
            if (i >= m1) {
                m2 = m1;
                m1 = i;
            }
            else if (i > m2) {
                m2 = i;
            }
        }
        return (m1 - 1) * (m2 - 1);
    }
};

