#include "../header.h"

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (x == 0) {
            return 0;
        }
        bool isPos = n > 0;
        unsigned int nn = n;
        if (!isPos) {
            nn = -nn;
        }
        if (nn == 1) {
            return isPos ? x : 1 / x;
        }
        double d1, d2;
        d1 = myPow(x, nn / 2);
        if (nn % 2 == 0) {
            d2 = d1;
        }
        else {
            d2 = d1 * x;
        }
        double res = d1 * d2;
        return isPos ? res : 1 / res;
    }
};