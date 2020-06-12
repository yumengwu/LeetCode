#include "../header.h"

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<long>> v(n, vector<long>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            v[i][i] = 0;
        }
        for (int i = 0; i < prerequisites.size(); ++i) {
            v[prerequisites[i][0]][prerequisites[i][1]] = 1;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (v[i][j] > v[i][k] + v[k][j]) {
                        v[i][j] = v[i][k] + v[k][j];
                    }
                }
            }
        }
        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            res[i] = v[queries[i][0]][queries[i][1]] != INT_MAX;
        }
        return res;
    }
};

