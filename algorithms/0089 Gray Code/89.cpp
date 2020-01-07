#include "../header.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        if (n == 0) {
            return res;
        }
        --n;
        res.push_back(1);
        int flag = 2;
        while (n--) {
            vector<int> nv;
            for (int i = 0; i < res.size(); i += 2) {
                nv.push_back(res[i]);
                nv.push_back(res[i] | flag);
                nv.push_back(res[i + 1] | flag);
                nv.push_back(res[i + 1]);
            }
            res = nv;
            flag <<= 1;
        }
        return res;
    }
};