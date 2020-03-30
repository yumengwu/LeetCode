#include "../header.h"

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> v(128);
        for (int i = 0; i < 128; ++i) {
            v[i].first = 0;
            v[i].second = i;
        }
        for (int i = 0; i < s.length(); ++i) {
            ++v[s[i]].first;
        }
        sort(v.begin(), v.end());
        int idx = 0;
        for (int i = 127; i >= 0; --i) {
            for (int j = 0; j < v[i].first; ++j) {
                s[idx + j] = (char) v[i].second;
            }
            idx += v[i].first;
        }
        return s;
    }
};