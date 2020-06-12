#include "../header.h"

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        if (n <= 1) {
            return s;
        }
        set<char> st{'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (st.count(s[i])) {
                v.push_back(i);
            }
        }
        n = v.size();
        for (int i = 0; i < n / 2; ++i) {
            char t = s[v[i]];
            s[v[i]] = s[v[n - i - 1]];
            s[v[n - i - 1]] = t;
        }
        return s;
    }
};

