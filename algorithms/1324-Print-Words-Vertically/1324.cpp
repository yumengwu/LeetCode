#include "../header.h"

class Solution {
public:
    vector<string> printVertically(string s) {
        int row = 0, col = 1, len = s.length(), last = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == ' ') {
                ++col;
                row = max(row, i - last);
                last = i + 1;
            }
        }
        row = max(row, len - last);
        vector<string> v(row, "");
        int r = 0, c = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == ' ') {
                r = 0;
                ++c;
            }
            else {
                while (v[r].length() != c) {
                    v[r] += ' ';
                }
                v[r++] += s[i];
            }
        }
        return v;
    }
};