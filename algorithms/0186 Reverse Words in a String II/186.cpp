#include "../header.h"

class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); ++i) {
            int j = i + 1;
            while (j < s.size() && s[j] != ' ') ++j;
            int l = i, r = j - 1;
            while (l < r) {
                char temp = s[l];
                s[l] = s[r];
                s[r] = temp;
                ++l;
                --r;
            }
            i = j;
        }
    }
};