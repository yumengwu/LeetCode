#include "../header.h"

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, -1);
        set<int> st;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                res[i] = 1;
                st.insert(i);
            }
            else {
                if (m.count(rains[i])) {
                    int idx = m[rains[i]];
                    auto it = st.upper_bound(idx);
                    if(it == st.end())
                    {
                        return {};
                    }
                    res[*it] = rains[i];
                    st.erase(it);
                }
                m[rains[i]] = i;
            }
        }
        return res;
    }
};

