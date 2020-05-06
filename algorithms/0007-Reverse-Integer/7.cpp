static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 13;
} ();

class Solution {
public:
    int reverse(int x) {
        long res = 0, num = x;
        bool isPositive = num >= 0;
        if (!isPositive) {
            num = -num;
        }
        while (num) {
            res *= 10;
            res += num % 10;
            num /= 10;
        }
        if (!isPositive) {
            res = -res;
        }
        return res <= INT_MAX && res >= INT_MIN ? res : 0;
    }
};