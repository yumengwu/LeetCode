#include "../header.h"

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        s.insert(n);
        while (n != 1) {
            int m = n;
            int ni = 0;
            while (m) {
                int base = m % 10;
                m /= 10;
                ni += base * base;
            }
            n = ni;
            if (ni == 1 || s.find(ni) != s.end()) {
                break;
            }
            s.insert(ni);
        }
        return n == 1;
    }
};

int main()
{
    Solution s;
    cout<<s.isHappy(19)<<endl;
    return 0;
}