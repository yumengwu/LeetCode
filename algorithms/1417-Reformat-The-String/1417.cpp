#include "../header.h"

class Solution {
public:
    string reformat(string s) {
        queue<char> qa, qn;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                qa.push(s[i]);
            }
            else {
                qn.push(s[i]);
            }
        }
        if (abs((int) qa.size() - (int) qn.size()) > 1) {
            return "";
        }
        string res = "";
        if (qa.size() < qn.size()) {
            queue<char> temp;
            temp = qa;
            qa = qn;
            qn = temp;
        }
        while (qa.size() && qn.size()) {
            res += qa.front();
            res += qn.front();
            qa.pop();
            qn.pop();
        }
        if (qa.size()) {
            res += qa.front();
        }
        else if (qn.size()) {
            res += qn.front();
        }
        return res;
    }
};
