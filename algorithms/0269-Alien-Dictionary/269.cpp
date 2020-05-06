#include "../header.h"

class Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, int> cnt;
        map<char, set<char>> m;
        int n = words.size();
        if (n == 0) {
            return "";
        }
        for (int i = 0; i < words[0].length(); ++i) {
            m[words[0][i]].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string curcmp = cmp(words[i], words[j]);
                if (curcmp.length()) {
                    m[curcmp[0]].insert(curcmp[1]);
                }
                for (int k = 0; k < words[i].length(); ++k) {
                    if (!m.count(words[i][k])) {
                        m[words[i][k]].clear();
                    }
                }
                for (int k = 0; k < words[j].length(); ++k) {
                    if (!m.count(words[j][k])) {
                        m[words[j][k]].clear();
                    }
                }
            }
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (cnt.find(it->first) == cnt.end()) {
                cnt[it->first] = 0;
            }
            for (auto iitt = it->second.begin(); iitt != it->second.end(); ++iitt) {
                if (it->first != *iitt) {
                    ++cnt[*iitt];
                }
            }
        }
        string res = "";
        set<char> cs;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            if (it->second == 0) {
                cs.insert(it->first);
            }
        }
        while (cs.size()) {
            char zero = *cs.begin();
            cs.erase(zero);
            res += zero;
            auto ts = m[zero];
            for (auto it = ts.begin(); it != ts.end(); ++it) {
                if (--cnt[*it] == 0) {
                    cs.insert(*it);
                }
            }
        }
        if (res.length() != cnt.size()) {
            return "";
        }
        else {
            return res;
        }
    }
    
    string cmp(string s1, string s2) {
        int idx1 = 0, idx2 = 0;
        while (idx1 < s1.length() && idx2 < s2.length() && s1[idx1] == s2[idx2]) {
            ++idx1;
            ++idx2;
        }
        if (idx1 == s1.length() || idx2 == s2.length()) {
            return "";
        }
        else {
            string res = "  ";
            res[0] = s1[idx1];
            res[1] = s2[idx2];
            return res;
        }
    }
};

int main()
{
    Solution s;
    vector<string> v{"wnlb"};
    cout<<s.alienOrder(v)<<endl;
    return 0;
}