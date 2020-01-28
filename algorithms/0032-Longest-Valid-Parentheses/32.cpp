#include "../header.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n == 0 || n == 1) {
            return 0;
        }
        int res = 0;
        vector<int> v(n, 0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    v[i] = 2 + (i > 1 ? v[i - 2] : 0);
                }
                else {
                    if (v[i - 1]) {
                        if (i - 1 - v[i - 1] >= 0 && s[i - 1 - v[i - 1]] == '(') {
                            v[i] = v[i - 1] + 2 + (i - 1 - v[i - 1] - 1 >= 0 ? v[i - 1 - v[i - 1] - 1] : 0);
                        }
                    }
                }
                res = max(res, v[i]);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.longestValidParentheses(")(((((()())()()))()(()))(")<<endl;
    return 0;
}