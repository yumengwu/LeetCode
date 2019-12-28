#include "../header.h"

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        int n = words.size();
        if (n == 0) {
            return res;
        }
        set<string> ss;
        for (int i = 0; i < n; ++i) {
            ss.insert(words[i]);
        }
        for (int i = 0; i < n; ++i) {
            ss.erase(words[i]);
            if (helper(words[i], ss)) {
                res.push_back(words[i]);
            }
            ss.insert(words[i]);
        }
        return res;
    }
    bool helper(string s, set<string>& ss) {
        if (s == "") {
            return false;
        }
        vector<bool> v(s.length() + 1, false);
        v[0] = true;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (v[j] && ss.find(s.substr(j, i - j)) != ss.end()) {
                    v[i] = true;
                    break;
                }
            }
        }
        return v[v.size() - 1];
    }
};