#include "../header.h"

class Solution {
public:
    string minWindow(string s, string t) {
        if (s == "") {
            return "";
        }
        int left = 0, right = 0, cnt = 0, minLen = INT_MAX;
        string res = "";
        map<char, int> m;
        for (char c : t) {
            ++m[c];
        }
        while (right < s.length()) {
            if (--m[s[right++]] >= 0) {
                ++cnt;
            }
            while (cnt == t.length()) {
                if (minLen > right - left) {
                    minLen = right - left;
                    res = s.substr(left, minLen);
                }
                if (++m[s[left++]] > 0) {
                    --cnt;
                }
            }
        }
        return minLen == INT_MAX ? "" : res;
    }
};