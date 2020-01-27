#include "../header.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        int sl = s.length(), tl = t.length();
        if (sl != tl) {
            return false;
        }
        vector<int> cnt(26, 0);
        for (int i = 0; i < sl; ++i) {
            ++cnt[s[i] - 'a'];
        }
        for (int i = 0; i < tl; ++i) {
            --cnt[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i]) {
                return false;
            }
        }
        return true;
    }
};