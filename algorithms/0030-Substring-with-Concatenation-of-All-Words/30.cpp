#include "../header.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.length() == 0 || words.size() == 0) {
            return res;
        }
        int n = words[0].length();
        if (s.length() < n * words.size()) {
            return res;
        }
        map<string, int> m;
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]]++;
        }
        for (int i = 0; i <= s.length() - n * words.size(); ++i) {
            map<string, int> cnt;
            int j = 0;
            for (j = 0; j < words.size(); ++j) {
                string t = s.substr(i + j * n, n);
                if (!m.count(t)) {
                    break;
                }
                if (cnt.find(t) != cnt.end()) {
                    cnt[t]++;
                }
                else {
                    cnt[t] = 1;
                }
                if (cnt[t] > m[t]) {
                    break;
                }
            }
            if (j == words.size()) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    vector<string> v{"word","good","best","good"};
    Solution s;
    vector<int> v2 = s.findSubstring("wordgoodgoodgoodbestword", v);
    for (int i = 0; i < v2.size(); ++i) {
        cout<<v2[i]<<' ';
    }
    cout<<endl;
    return 0;
}