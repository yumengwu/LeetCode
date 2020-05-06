#include "../header.h"

int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char * cur = buf;
        char temp[4];
        int res;
        int cnt = 0;
        while (n > 0 && (res = read4(temp)) > 0) {
            for (int i = 0; i < 4 && i < n && i < res; ++i) {
                *cur = temp[i];
                ++cur;
                ++cnt;
            }
            n -= 4;
        }
        return cnt;
    }
};