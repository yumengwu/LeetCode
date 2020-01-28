#include "../header.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                ss.push(s[i]);
            }
            else {
                if (ss.size() == 0 || s[i] == ')' && ss.top() != '(' || s[i] == ']' && ss.top() != '[' || s[i] == '}' && ss.top() != '{') {
                    return false;
                }
                ss.pop();
            }
        }
        return ss.empty();
    }
};