#include "../header.h"
/*
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        priority_queue<string, vector<string>, Compare> q;
        int n = logs.size();
        vector<string> res, digit;
        for (int i = 0; i < n; ++i) {
            int idx = getLogType(logs[i]);
            if (idx == 0) {
                digit.push_back(logs[i]);
            }
            else {
                q.push(logs[i]);
            }
        }
        while (q.size()) {
            res.push_back(q.top());
            q.pop();
        }
        for (int i = 0; i < digit.size(); ++i) {
            res.push_back(digit[i]);
        }
        return res;
    }
    
private:
    struct Compare {
        bool operator()(string s1, string s2) {
            int i1 = 0, i2 = 0;
            while (s1[i1] != ' ') ++i1;
            while (s2[i2] != ' ') ++i2;
            string ss1 = s1.substr(i1), ss2 = s2.substr(i2);
            return ss1 == ss2 ? s1 > s2 : ss1 > ss2;
        }
    };
    
    int getLogType(string str) {
        int idx = 0, n = str.length();
        while (idx < n && str[idx] != ' ') ++idx;
        ++idx;
        return str[idx] >= '0' && str[idx] <= '9' ? 0 : idx;
    }
};*/

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res, digitLog;
        vector<pair<string, string>> letterLog;
        for (string s : logs) {
            int check = helper(s);
            if (check == -1) {
                digitLog.push_back(s);
            }
            else {
                letterLog.push_back(make_pair(s, s.substr(check)));
            }
        }
        sort(letterLog.begin(), letterLog.end(), [] (const pair<string, string>& a, const pair<string, string>& b) -> bool {
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        for (auto it : letterLog) {
            res.push_back(it.first);
        }
        for (string s : digitLog) {
            res.push_back(s);
        }
        return res;
    }
    
    int helper(string s) {
        int ws = 0;
        for (int i = ws; i < s.length(); ++i) {
            if (s[i] == ' ') {
                ws = i;
                break;
            }
        }
        return s[ws + 1] >= '0' && s[ws + 1] <= '9' ? -1 : ws;
    }
};

