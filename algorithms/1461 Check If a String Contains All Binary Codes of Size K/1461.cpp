#include "../header.h"

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int tar = 1;
        for (int i = 0; i < k; ++i) {
            tar *= 2;
        }
        if (s.length() < tar) {
            return false;
        }
        unordered_set<string> st;
        for (int i = 0; i <= s.length() - k; ++i) {
            st.insert(s.substr(i, k));
        }
        return st.size() == tar;
    }
};

