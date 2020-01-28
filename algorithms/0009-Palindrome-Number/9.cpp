#include "../header.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0 && x != 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        int res = x;
        unsigned int temp = 0;
        while (x > 0) {
            temp = 10 * temp + x % 10;
            x /= 10;
        }
        return temp == res;
    }
};