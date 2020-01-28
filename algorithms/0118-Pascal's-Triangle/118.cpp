#include "../header.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) {
            return res;
        }
        for (int i = 1; i <= numRows; ++i) {
            vector<int> v(i, 1);
            for (int j = 1; j < v.size() - 1; ++j) {
                v[j] = res.back()[j - 1] + res.back()[j];
            }
            res.push_back(v);
        }
        return res;
    }
};