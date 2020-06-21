#include "../header.h"

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int c = 0, i = 0, j = 0;
        string res;
        while (i < a.length() || j < b.length() || c) {
            int aa = i < a.length() ? a[i] - '0' : 0;
            int bb = j < b.length() ? b[j] - '0' : 0;
            int t = aa + bb + c;
            res += (t % 2 + '0');
            c = t / 2;
            ++i;
            ++j;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

