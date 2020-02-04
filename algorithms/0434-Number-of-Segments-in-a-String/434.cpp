#include "../header.h"

class Solution {
public:
    int countSegments(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int last = s.length() - 1;
        while (last >= 0 && s[last] == ' ') --last;
        if (last < 0) {
            return 0;
        }
        int cnt = 1;
        for (int i = 1; i <= last; ++i) {
            if (s[i] == ' ' && s[i - 1] != ' ') {
                ++cnt;
            }
        }
        return cnt;
    }
};