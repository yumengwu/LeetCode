#include "../header.h"

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> v(n, vector<int>(3, 0));
        v[0][0] = costs[0][0];
        v[0][1] = costs[0][1];
        v[0][2] = costs[0][2];
        for (int i = 1; i < n; ++i) {
            v[i][0] = min(v[i - 1][1], v[i - 1][2]) + costs[i][0];
            v[i][1] = min(v[i - 1][0], v[i - 1][2]) + costs[i][1];
            v[i][2] = min(v[i - 1][0], v[i - 1][1]) + costs[i][2];
        }
        return min(v[n - 1][0], min(v[n - 1][1], v[n - 1][2]));
    }
};