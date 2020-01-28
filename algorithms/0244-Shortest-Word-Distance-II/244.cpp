#include "../header.h"

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            m[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> v1 = m[word1], v2 = m[word2];
        int i = 0, j = 0, res = INT_MAX;
        while (i < v1.size() && j < v2.size()) {
            res = min(res, abs(v1[i] - v2[j]));
            if (v1[i] < v2[j]) {
                ++i;
            }
            else {
                ++j;
            }
        }
        return res;
    }

private:
    unordered_map<string, vector<int>> m;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */