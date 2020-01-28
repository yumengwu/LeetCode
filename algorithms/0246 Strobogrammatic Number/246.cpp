#include "../header.h"

class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char, char> m{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        int n = num.length();
        for (int i = 0; i <= n / 2; ++i) {
            if (m.find(num[i]) == m.end() || m[num[i]] != num[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
};