#include "../header.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for (string str : emails) {
            s.insert(transfer(str));
        }
        return s.size();
    }
    
    string transfer(string s) {
        int atIdx;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '@') {
                atIdx = i;
                break;
            }
        }
        char temp[atIdx + 1] = {0};
        int i = 0;
        for (int j = 0; j < atIdx; ++j) {
            if (s[j] == '+') {
                break;
            }
            if (s[j] != '.') {
                temp[i++] = s[j];
            }
        }
        string res = temp;
        res += s.substr(atIdx);
        return res;
    }
};