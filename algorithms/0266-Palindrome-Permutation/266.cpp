#include "../header.h"

class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> m;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++m[s[i]];
        }
        int oddcnt = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second & 1) ++oddcnt;
        }
        return oddcnt == 0 || oddcnt == 1;
    }
};