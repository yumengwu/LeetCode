#include "../header.h"

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if (n == 0) {
            return {};
        }
        if (n == 1) {
            return {"0", "1", "8"};
        }
        // map<char, char> m{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        vector<pair<char, char>> m{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        vector<string> res;
        string temp(n, '1');
        helper(res, temp, 0, n, m);
        return res;
    }
    
    void helper(vector<string>& res, string& s, int idx, int n, vector<pair<char, char>>& m) {
        if (idx >= (n >> 1)) {
            if (n & 1) {
                s[idx] = '1';
                res.push_back(s);
                s[idx] = '8';
                res.push_back(s);
                if (idx > 0) {
                    s[idx] = '0';
                    res.push_back(s);
                }
            }
            else {
                res.push_back(s);
            }
            return;
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (idx == 0 && it->first == '0') {
                continue;
            }
            s[idx] = it->first;
            s[n - idx - 1] = it->second;
            helper(res, s, idx + 1, n, m);
        }
    }
};