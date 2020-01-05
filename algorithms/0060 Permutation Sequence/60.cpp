#include "../header.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        vector<int> fac(n, 1);
        vector<char> num(n,1);
        for (int i = 1; i < n; ++i) {
            fac[i] = fac[i - 1] * i;
        }
        for(int i=0; i<n; i++) {
            num[i] = (i + 1) + '0';
        }
        k--;
        for(int i = n; i >= 1; --i) {
            int j = k / fac[i - 1];
            k %= fac[i - 1];
            res += num[j];
            num.erase(num.begin() + j);
        }
        return res;
    }
};