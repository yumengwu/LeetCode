#include "../header.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res{1};
        for (int i = 0; i < rowIndex; ++i) {
            vector<int> v(res.size() + 1, 1);
            for (int j = 1; j < res.size(); ++j) {
                v[j] = res[j - 1] + res[j];
            }
            res = v;
        }
        return res;
    }
};