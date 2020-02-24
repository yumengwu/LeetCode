#include "../header.h"

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if (s.length() < 2) {
            return res;
        }
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                if (s[i] == '+') {
                    s[i] = s[i + 1] = '-';
                    res.push_back(s);
                    s[i] = s[i + 1] = '+';
                }
            }
        }
        return res;
    }
};