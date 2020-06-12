#include "../header.h"

class Solution {
public:
    string decodeString(string s) {
        string res;
        int idx = 0, len = s.length();
        while (idx < len) {
            if ((s[idx] >= 'a' && s[idx] <= 'z') || (s[idx] >= 'A' && s[idx] <= 'Z')) {
                res += s[idx++];
            }
            else {
                int j = idx + 1;
                while (s[j] >= '0' && s[j] <= '9') {
                    ++j;
                }
                int k = stoi(s.substr(idx, j - idx));
                idx = j;
                int cnt = 0;
                j = idx;
                while (j < len) {
                    if (s[j] == '[') {
                        ++cnt;
                    }
                    else if (s[j] == ']') {
                        if (--cnt == 0) {
                            break;
                        }
                    }
                    ++j;
                }
                string ss = s.substr(idx + 1, j - idx - 1);
                ss = decodeString(ss);
                while (k--) {
                    res += ss;
                }
                idx = j + 1;
            }
        }
        return res;
    }
};

