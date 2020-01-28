#include "../header.h"

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num + 1);
        if (num == 0) {
            return v;
        }
        for (int i = 1; i <= num; ++i) {
            if (i % 2 == 0) {
                v[i] = v[i >> 1];
            }
            else {
                v[i] = 1 + v[(i - 1) >> 1];
            }
        }
        return v;
    }
};