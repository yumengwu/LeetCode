#include "../header.h"

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX, n = words.size();
        if (word1 == word2) {
            vector<int> idx;
            for (int i = 0; i < n; ++i) {
                if (words[i] == word1) {
                    idx.push_back(i);
                }
            }
            for (int i = 1; i < idx.size(); ++i) {
                res = min(res, idx[i] - idx[i - 1]);
            }
        }
        else {
            vector<int> idx1, idx2;
            for (int i = 0; i < n; ++i) {
                if (words[i] == word1) {
                    idx1.push_back(i);
                }
                else if (words[i] == word2) {
                    idx2.push_back(i);
                }
            }
            int i = 0, j = 0;
            while (i < idx1.size() && j < idx2.size()) {
                res = min(res, abs(idx1[i] - idx2[j]));
                if (idx1[i] < idx2[j]) {
                    ++i;
                }
                else {
                    ++j;
                }
            }
        }
        return res;
    }
};