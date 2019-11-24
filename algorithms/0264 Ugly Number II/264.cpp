#include "../header.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int u2 = 0, u3 = 0, u5 = 0;
        int m2, m3, m5;
        while (res.size() < n) {
            m2 = res[u2] * 2;
            m3 = res[u3] * 3;
            m5 = res[u5] * 5;
            int curmin = min(m2, min(m3, m5));
            if (curmin == m2) {
                ++u2;
            }
            if (curmin == m3) {
                ++u3;
            }
            if (curmin == m5) {
                ++u5;
            }
            res.push_back(curmin);
        }
        return res.back();
    }
};

int main()
{
    Solution s;
    cout<<s.nthUglyNumber(10)<<endl;
    return 0;
}