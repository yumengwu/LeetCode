#include "../header.h"

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0, right = 0, res = 0;
        unordered_map<int, int> m;
        while (right < s.length()) {
            ++m[s[right]];
            while (m.size() > 2) {
                if (--m[s[left]] == 0) {
                    m.erase(s[left]);
                }
                ++left;
            }
            res = max(res, right - left + 1);
            ++right;
        }
        return res;
    }
};