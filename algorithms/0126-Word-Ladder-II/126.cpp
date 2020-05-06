#include "../header.h"

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict, words;
        vector<vector<string>> res;
        int n = wordList.size();
        if (n == 0) {
            return res;
        }
        for (int i = 0; i < n; ++i) {
            dict.insert(wordList[i]);
        }
        vector<string> path;
        path.push_back(beginWord);
        queue<vector<string>> q;
        q.push(path);
        int depth = 1, minDepth = INT_MAX;
        while (q.size()) {
            auto cur = q.front();
            q.pop();
            if (cur.size() > depth) {
                for (string w : words) {
                    dict.erase(w);
                }
                words.clear();
                depth = cur.size();
                if (depth > minDepth) {
                    break;
                }
            }
            string last = cur.back();
            for (int i = 0; i < last.size(); ++i) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newLast[i] = ch;
                    if (!dict.count(newLast)) {
                        continue;
                    }
                    words.insert(newLast);
                    vector<string> nextPath = cur;
                    nextPath.push_back(newLast);
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minDepth = depth;
                    }
                    else {
                        q.push(nextPath);
                    }
                }
            }
        }
        return res;
    }
};