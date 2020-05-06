#include "../header.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (m < n) {
            return -1;
        }
        if (n == 0 || m == n && haystack == needle) {
            return 0;
        }
        for (int i = 0; i < m - n + 1; ++i) {
            bool isEqual = true;
            for (int j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) {
                    isEqual = false;
                    break;
                }
            }
            if (isEqual) {
                return i;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int len1 = haystack.length(), len2 = needle.length();
//         if (len1 < len2) {
//             return -1;
//         }
//         if (len1 == len2) {
//             return haystack == needle ? 0 : -1;
//         }
//         for (int i = 0; i <= len1 - len2; ++i) {
//             bool eq = true;
//             for (int j = 0; j < len2; ++j) {
//                 if (haystack[i + j] != needle[j]) {
//                     eq = false;
//                     break;
//                 }
//             }
//             if (eq) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };
