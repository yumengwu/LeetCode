#include "../header.h"

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n) {
            if (n % 26 == 0) {
                res = 'Z' + res;
                n -= 26;
            } else {
                res = char(n % 26 - 1 + 'A') + res;
                n -= n % 26;
            }
            n /= 26;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.convertToTitle(701)<<endl;
    return 0;
}