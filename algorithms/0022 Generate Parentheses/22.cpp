#include "../header.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {};
        }
        if (n == 1) {
            return {"()"};
        }
        pair<int, int> p(n, n);
        vector<string> res;
        vector<char> temp;
        helper(res, temp, p);
        return res;
    }
    
    void helper(vector<string>& res, vector<char>& temp, pair<int, int> p) {
        if (p.first == 0) {
            string str = "";
            for (char c : temp) {
                str += c;
            }
            for (int i = 0; i < p.second; ++i) {
                str += ')';
            }
            res.push_back(str);
            return;
        }
        temp.push_back('(');
        --p.first;
        helper(res, temp, p);
        ++p.first;
        temp.pop_back();
        if (p.second > p.first) {
            temp.push_back(')');
            --p.second;
            helper(res, temp, p);
            temp.pop_back();
        }
    }
};
