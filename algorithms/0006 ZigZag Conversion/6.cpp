#include "../header.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int n = s.length();
        string res = "";
        if (n == 0) {
            return res;
        }
        vector<string> v(numRows, "");
        int index = 0;
        char dire = 'd';
        for (int i = 0; i < n; ++i) {
            v[index] += s[i];
            if (dire == 'd') {
                if (index == numRows - 1) {
                    --index;
                    dire = 'u';
                }
                else {
                    ++index;
                }
            }
            else {
                if (index == 0) {
                    ++index;
                    dire = 'd';
                }
                else {
                    --index;
                }
            }
        }
        for (int i = 0; i < numRows; ++i) {
            res += v[i];
        }
        return res;
    }
};