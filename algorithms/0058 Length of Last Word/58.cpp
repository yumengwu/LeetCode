#include "../header.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int idx = 0;
        while (idx < s.length() && s[idx] == ' ') ++idx;
        string temp = "";
        for (; idx < s.length(); ++idx) {
            if (s[idx] == ' ' && temp.length()) {
                res = temp.length();
                temp = "";
            }
            else if (s[idx] != ' ') {
                temp += s[idx];
            }
        }
        if (temp.length()) {
            res = temp.length();
        }
        return res;
    }
};