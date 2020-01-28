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