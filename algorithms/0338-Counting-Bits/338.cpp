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

/*
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            if (i & 1) {
                res[i] = res[(i - 1) / 2] + 1;
            }
            else {
                res[i] = res[i / 2];
            }
        }
        return res;
    }
};*/

