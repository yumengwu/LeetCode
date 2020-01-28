#include "../header.h"

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        int n = words.size();
        if (n == 0) {
            return res;
        }
        unordered_map<string, int> cnt;
        for (int i = 0; i < n; ++i) {
            ++cnt[words[i]];
        }
        map<int, vector<string>> m;
        for (unordered_map<string, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
            m[it->second].push_back(it->first);
        }
        for (map<int, vector<string>>::reverse_iterator rit = m.rbegin(); rit != m.rend(); ++rit) {
            if (k <= 0) {
                break;
            }
            sort(rit->second.begin(), rit->second.end());
            int ii = k >= rit->second.size() ? rit->second.size() : k;
            for (int i = 0; i < ii; ++i) {
                res.push_back(rit->second[i]);
            }
            k -= rit->second.size();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> v{"i", "love", "leetcode", "i", "love", "coding"};
    v = s.topKFrequent(v, 2);
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<endl;
    }
    return 0;
}