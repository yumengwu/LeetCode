#include "../header.h"

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> m;
        vector<string> res;
        for (string s : names) {
            if (m.count(s)) {
                int idx = m[s];
                while (1) {
                    string temp = s;
                    temp += '(';
                    temp += to_string(idx);
                    temp += ')';
                    if (m.count(temp)) {
                        ++idx;
                    }
                    else {
                        m[s] = idx + 1;
                        res.push_back(temp);
                        ++m[temp];
                        break;
                    }
                }
            }
            else {
                ++m[s];
                res.push_back(s);
            }
        }
        return res;
    }

    int parseSuffix(string s) {
        if (s.length() == 0 || s.back() != ')') {
            return -1;
        }
        int idx = s.length() - 1;
        while (idx >= 0 && s[idx] != '(') --idx;
        return idx;
    }
};

