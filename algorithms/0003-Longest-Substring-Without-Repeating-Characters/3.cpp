#include "../header.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        int res = 0, left = -1;
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (m.find(s[i]) != m.end() && m[s[i]] > left) {
                left = m[s[i]];
            }
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};