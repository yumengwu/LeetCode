#include "../header.h"

class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> v(26, -1);
        v[0] = v['e' - 'a'] = v['i' - 'a'] = v['o' - 'a'] = v['u' - 'a'] = 0;
        for (int i = 0; i < k; ++i) {
            ++v[s[i] - 'a'];
        }
        int res = getnum(v);
        for (int i = k; i < s.length(); ++i) {
            ++v[s[i] - 'a'];
            --v[s[i - k] - 'a'];
            res = max(res, getnum(v));
        }
        return res;
    }
    
    int getnum(vector<int>& v) {
        return v[0] + v['e' - 'a'] + v['i' - 'a'] + v['o' - 'a'] + v['u' - 'a'];
    }
};

