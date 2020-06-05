#include "../header.h"

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int idx = 0, n = sentence.length(), cnt = 1;
        while (idx < n) {
            while (idx < n && sentence[idx] == ' ') ++idx;
            if (idx == n) break;
            if (searchWord == sentence.substr(idx, searchWord.length()))
                return cnt;
            while (idx < n && sentence[idx] != ' ') ++idx;
            ++cnt;
        }
        return -1;
    }
};

