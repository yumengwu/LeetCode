#include "../header.h"

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 1) {
            return false;
        }
        for (long i = 1; i <= num; ++i) {
            if (i * i == num) {
                return true;
            }
            if (i * i > num) {
                return false;
            }
        }
        return false;
    }
};

