#include "../header.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i1 = 0, i2 = 0;
        while (i1 < s.length() && i2 < t.length()) {
            if (s[i1] == t[i2]) {
                ++i1;
                ++i2;
            }
            else {
                ++i2;
            }
        }
        return i1 == s.length();
    }
};

