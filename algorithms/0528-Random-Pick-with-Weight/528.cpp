#include "../header.h"

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();

class Solution {
public:
    Solution(vector<int>& w) {
        srand(time(0));
        v.resize(w.size(), 0);
        total = 0;
        for (int i = 0; i < w.size(); ++i) {
            total += w[i];
            v[i] = w[i] + (i > 0 ? v[i - 1] : 0);
        }
    }

    int pickIndex() {
        int n = rand() % total;
        int l = 0, r = v.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (v[mid] > n) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

private:
    vector<int> v;
    int total;
};

