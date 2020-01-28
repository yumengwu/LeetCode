#include "../header.h"

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, int> m;
        vector<vector<string>> res;
        int n = strings.size();
        for (int i = 0; i < n; ++i) {
            string pt = getPattern(strings[i]);
            auto it = m.find(pt);
            if (it == m.end()) {
                m[pt] = res.size();
                vector<string> t{strings[i]};
                res.push_back(t);
            }
            else {
                res[it->second].push_back(strings[i]);
            }
        }
        return res;
    }
    
    string getPattern(string str) {
        string res;
        if (str.length() == 1) {
            return "";
        }
        vector<int> v;
        int n = str.length();
        for (int i = 1; i < n; ++i) {
            v.push_back(int(str[i] - str[i - 1]));
            if (v.back() < 0) {
                v.back() += 26;
            }
        }
        res = to_string(v[0]);
        for (int i = 0; i < n - 2; ++i) {
            res += "*";
            res += to_string(v[i + 1]);
        }
        return res;
    }
};