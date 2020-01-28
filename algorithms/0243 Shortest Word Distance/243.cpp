#include "../header.h"

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        vector<int> idx1, idx2;
        for (int i = 0; i < n; ++i) {
            if (words[i] == word1) {
                idx1.push_back(i);
            }
            else if (words[i] == word2) {
                idx2.push_back(i);
            }
        }
        int res = INT_MAX, i = 0, j = 0;
        while (i < idx1.size() && j < idx2.size()) {
            res = min(res, abs(idx1[i] - idx2[j]));
            if (idx1[i] < idx2[j]) {
                ++i;
            }
            else {
                ++j;
            }
        }
        return res;
    }
};