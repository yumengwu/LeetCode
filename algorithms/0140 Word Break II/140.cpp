#include "../header.h"

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> m;
        return helper(s, wordDict, m);
    }
    
    vector<string> helper(string s, vector<string>& dict, unordered_map<string, vector<string>>& m) {
        auto it = m.find(s);
        if (it != m.end()) {
            return it->second;
        }
        if (s.size() == 0) {
            return {""};
        }
        vector<string> res;
        int n = dict.size();
        for (int i = 0; i < n; ++i) {
            string cur = dict[i];
            if (s.substr(0, cur.size()) != cur) {
                continue;
            }
            vector<string> temp = helper(s.substr(cur.size()), dict, m);
            for (int j = 0; j < temp.size(); ++j) {
                res.push_back(cur + (temp[j].size() == 0 ? "" : " ") + temp[j]);
            }
        }
        m[s] = res;
        return res;
    }
};