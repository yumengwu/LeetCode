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

// class Solution {
// public:
//     int myAtoi(string str) {
//         long res = 0;
//         int idx = 0, n = str.length();
//         if (n == 0) {
//             return 0;
//         }
//         while (idx < n && str[idx] == ' ') ++idx;
//         bool isPosi = true;
//         if (str[idx] == '-') {
//             ++idx;
//             isPosi = false;
//         }
//         else if (str[idx] == '+') {
//             ++idx;
//         }
//         while (idx < n && str[idx] >= '0' && str[idx] <= '9') {
//             res *= 10;
//             res += str[idx] - '0';
//             ++idx;
//             if (isPosi && res >= INT_MAX) {
//                 return INT_MAX;
//             }
//             if (!isPosi && -res <= INT_MIN) {
//                 return INT_MIN;
//             }
//         }
//         return isPosi ? res : -res;
//     }
// };