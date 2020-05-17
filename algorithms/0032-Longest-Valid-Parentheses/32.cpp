#include "../header.h"

/*
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
};*/

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> v(n, 0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    v[i] = 2;
                    if (i - 2 > 0) {
                        v[i] += v[i - 2];
                    }
                }
                else {
                    if (v[i - 1] && i - 1 - v[i - 1] >= 0 && s[i - 1 - v[i - 1]] == '(') {
                        v[i] = v[i - 1] + 2;
                        if (i - 2 - v[i - 1] >= 0 && v[i - 2 - v[i - 1]]) {
                            v[i] += v[i - 2 - v[i - 1]];
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i : v) {
            res = max(res, i);
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
