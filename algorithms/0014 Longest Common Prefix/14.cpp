#include "../header.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int idx = 0, n = strs.size();
        if (n == 0) {
            return res;
        }
        if (n == 1) {
            return strs[0];
        }
        while (1) {
            bool isEq = true;
            for (int i = 1; i < n; ++i) {
                if (idx == strs[i].length() || strs[i][idx] != strs[0][idx]) {
                    isEq = false;
                    break;
                }
            }
            if (!isEq) {
                break;
            }
            res += strs[0][idx++];
        }
        return res;
    }
};