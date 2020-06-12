#include "../header.h"

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> v(N, 0);
        int res = -1, n = trust.size();
        for (int i = 0; i < n; ++i) {
            --v[trust[i][0] - 1];
            ++v[trust[i][1] - 1];
        }
        for (int i = 0; i < N; ++i) {
            if (v[i] == N - 1) {
                res = i + 1;
                break;
            }
        }
        return res;
    }
};

