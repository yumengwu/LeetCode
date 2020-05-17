#include "../header.h"

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> res;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    if (strstr(words[i].c_str(), words[j].c_str())) {
                        res.insert(words[j]);
                    }
                }
            }
        }
        return {res.begin(), res.end()};
    }
};

