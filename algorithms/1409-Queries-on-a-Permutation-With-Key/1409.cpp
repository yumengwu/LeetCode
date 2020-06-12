#include "../header.h"

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> res, v;
        for (int i = 0; i < m; ++i) {
            v.push_back(i + 1);
        }
        for (int q : queries) {
            int i;
            for (i = 0; i < m; ++i) {
                if (v[i] == q) {
                    break;
                }
            }
            res.push_back(i);
            v.erase(v.begin() + i);
            v.insert(v.begin(), q);
        }
        return res;
    }
};

