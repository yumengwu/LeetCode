#include "../header.h"

// bfs
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q;
        unordered_set<string> st;
        q.push(s);
        bool has = false;
        while (q.size()) {
            string cur = q.front();
            q.pop();
            if (isValid(cur)) {
                res.push_back(cur);
                has = true;
            }
            if (has) {
                continue;
            }
            for (int i = 0; i < cur.size(); ++i) {
                if (cur[i] == '(' || cur[i] == ')') {
                    string next = cur.substr(0, i) + cur.substr(i + 1);
                    if (!st.count(next)) {
                        q.push(next);
                        st.insert(next);
                    }
                }
            }
        }
        return res;
    }
    
    bool isValid(string s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(') {
                ++cnt;
            }
            else if (c == ')' && --cnt < 0) {
                return false;
            }
        }
        return cnt == 0;
    }
};