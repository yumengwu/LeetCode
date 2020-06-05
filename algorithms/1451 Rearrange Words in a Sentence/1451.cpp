#include "../header.h"

class Solution {
public:
    string arrangeWords(string text) {
        map<int, vector<string>> m;
        int idx = 0, n = text.size();
        while (idx < n) {
            int j = idx + 1;
            while (j < n && text[j] != ' ') ++j;
            m[j - idx].push_back(text.substr(idx, j - idx));
            idx = j + 1;
        }
        string res;
        for (auto it = m.begin(); it != m.end(); ++it) {
            for (string ss : it->second) {
                string s = ss;
                if (res.length() == 0) {
                    if (s[0] >= 'a') {
                        s[0] = s[0] - 'a' + 'A';
                    }
                    res += s;
                }
                else {
                    if (s[0] <= 'Z') {
                        s[0] = s[0] - 'A' + 'a';
                    }
                    res += ' ';
                    res += s;
                }
            }
        }
        return res;
    }
};

