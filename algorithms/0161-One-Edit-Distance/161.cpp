#include "../header.h"

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int l1 = s.length(), l2 = t.length();
        if (abs(l1 - l2) > 1) {
            return false;
        }
        if (l1 < l2) {
            return isOneEditDistance(t, s);
        }
        if (l1 == l2) {
            int cnt = 0;
            for (int i = 0; i < l1; ++i) {
                if (s[i] != t[i]) {
                    ++cnt;
                }
            }
            return cnt == 1;
        }
        int idx;
        for (idx = 0; idx < l2; ++idx) {
            if (s[idx] != t[idx]) {
                break;
            }
        }
        return s.substr(idx + 1) == t.substr(idx);
    }
};