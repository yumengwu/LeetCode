#include "../header.h"

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        if (words.empty()) {
            return 0;
        }
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]] = 0;
        }
        int res = 0;
        for (string word : words) {
            res = max(res, helper(m, word));
        }
        return res;
    }
    
    int helper(unordered_map<string, int> & m, string str) {
        if (m[str]) {
            return m[str];
        }
        int len = str.length();
        if (len == 1) {
            return m[str] = 1;
        }
        int cur = 0;
        for (int i = 0; i < len; ++i) {
            string ns = str.substr(0, i) + str.substr(i + 1);
            if (m.find(ns) != m.end()) {
                cur = max(cur, helper(m, ns));
            }
        }
        return m[str] = cur + 1;
    }
};