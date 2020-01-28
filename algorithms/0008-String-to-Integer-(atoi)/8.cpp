#include "../header.h"

class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;
        int range = INT_MAX / 10;
        int i = 0;
        for (; i < str.length(); ++i) {
            if (str[i] != ' ') {
                break;
            }
        }
        if (i == str.length()) {
            return 0;
        }
        if (str[i] == '-') {
            sign = -1;
            ++i;
        }
        else if (str[i] == '+') {
            ++i;
        }
        for (; i < str.length(); ++i) {
            if (!(str[i] >= '0' && str[i] <= '9')) {
                break;
            }
            if (res > range || res == range && str[i] - '0' > 7) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + (str[i] - '0');
        }
        return res * sign;
    }
};