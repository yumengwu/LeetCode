#include "../header.h"

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        trieNode * trie = new trieNode();
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            string revStr = word;
            reverse(revStr.begin(), revStr.end());
            trieNode * curTrie = trie;
            for (int j = 0; j < word.length(); ++j) {
                if (hasRemaining(revStr, j)) {
                    curTrie->remaining.push_back(i);
                }
                if (!curTrie->next[revStr[j] - 'a']) {
                    curTrie->next[revStr[j] - 'a'] = new trieNode();
                }
                curTrie = curTrie->next[revStr[j] - 'a'];
            }
            curTrie->endId = i;
        }
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            trieNode * curTrie = trie;
            for (int j = 0; j < word.length(); j++) {
                if (curTrie->endId != -1 && hasRemaining(word, j)) {
                    res.push_back({i, curTrie->endId});
                }
                curTrie = curTrie->next[word[j] - 'a'];
                if (!curTrie) {
                    break;
                }
            }
            if (!curTrie) {
                continue;
            }
            if (curTrie->endId != -1 && curTrie->endId != i) {
                res.push_back({i, curTrie->endId});
            }
            for (int other : curTrie->remaining) {
                res.push_back({i, other});
            }
        }
        return res;
    }

private:
    struct trieNode {
        int endId = -1;
        vector<trieNode *> next;
        vector<int> remaining;
        trieNode() {
            endId = -1;
            next.resize(26, NULL);
        }
    };

    bool hasRemaining(string s, int i) {
        int p1 = i;
        int p2 = s.length() - 1;
        while (p1 < p2) {
            if (s[p1] != s[p2]) return false;
            p1++;
            p2--;
        }
        return true;
    }
};

// class Solution {
// public:
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         vector<vector<int>> res;
//         int n = words.size();
//         if (n == 0) {
//             return res;
//         }
//         trie * root = new trie();
//         bool hasEmpty = false;
//         int emptyIdx;
//         for (int i = 0; i < n; ++i) {
//             addWord(root, words[i], i);
//             if (words[i].length() == 0) {
//                 hasEmpty = true;
//                 emptyIdx = i;
//             }
//         }
//         if (hasEmpty) {
//             for (int i = 0; i < n; ++i) {
//                 if (i != emptyIdx) {
//                     if (isRev(words[i])) {
//                         res.push_back({emptyIdx, i});
//                         res.push_back({i, emptyIdx});
//                     }
//                 }
//             }
//         }
//         for (int i = 0; i < n; ++i) {
//             search(res, root, words[i], i);
//         }
//         return res;
//     }

// private:
//     struct trie {
//         vector<trie *> next;
//         string str;
//         bool isEnd;
//         bool hasStr;
//         bool hasRev;
//         int sidx;
//         int ridx;
//         trie() {
//             next.resize(26, NULL);
//             isEnd = hasStr = hasRev = false;
//             sidx = ridx = -1;
//         }
//     };
    
//     void addWord(trie * root, string word, int idx) {
//         trie * cur = root;
//         for (int i = 0; i < word.length(); ++i) {
//             if (!cur->next[word[i] - 'a']) {
//                 cur->next[word[i] - 'a'] = new trie();
//             }
//             cur = cur->next[word[i] - 'a'];
//         }
//         cur->isEnd = true;
//         cur->hasStr = true;
//         cur->str = word;
//         cur->sidx = idx;
//         string str = word;
//         reverse(str.begin(), str.end());
//         if (word == str) {
//             return;
//         }
//         cur = root;
//         for (int i = word.length() - 1; i >= 0; --i) {
//             if (!cur->next[word[i] - 'a']) {
//                 cur->next[word[i] - 'a'] = new trie();
//             }
//             cur = cur->next[word[i] - 'a'];
//         }
//         cur->isEnd = true;
//         cur->hasRev = true;
//         cur->str = str;
//         cur->ridx = idx;
//     }

//     void search(vector<vector<int>>& res, trie * root, string word, int cidx) {
//         trie * cur = root;
//         vector<pair<string, int>> lv;
//         for (int i = 0; i < word.length(); ++i) {
//             cur = cur->next[word[i] - 'a'];
//             if (cur->hasStr) {
//                 lv.push_back(make_pair(cur->str, cur->sidx));
//             }
//         }
//         for (int i = 0; i < lv.size(); ++i) {
//             if (lv[i].first.length() == word.length()) {
//                 res.push_back({cidx, lv[i].second});
//             }
//             else {
//                 string rem = word.substr(lv[i].first.length());
//                 if (isRev(rem)) {
//                     res.push_back({cidx, lv[i].second});
//                 }
//             }
//         }
//         queue<trie *> q;
//         for (int i = 0; i < 26; ++i) {
//             if (cur->next[i]) {
//                 q.push(cur->next[i]);
//             }
//         }
//         while (q.size()) {
//             cur = q.front();
//             q.pop();
//             if (cur->hasStr) {
//                 string cc = cur->str.substr(word.length());
//                 if (isRev(cc)) {
//                     res.push_back({cidx, cur->sidx});
//                 }
//             }
//             for (int i = 0; i < 26; ++i) {
//                 if (cur->next[i]) {
//                     q.push(cur->next[i]);
//                 }
//             }
//         }
//     }

//     bool isRev(string word) {
//         int len = word.length();
//         for (int i = 0; i < len >> 1; ++i) {
//             if (word[i] != word[len - i - 1]) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     void print(trie * node) {
//         if (!node) {
//             return;
//         }
//         if (node->isEnd) {
//             printf("%s, has: %d %d, rev: %d %d\n", node->str.c_str(), node->hasStr, node->sidx, node->hasRev, node->ridx);
//         }
//         for (int i = 0; i < 26; ++i) {
//             print(node->next[i]);
//         }
//     }
// };

int main()
{
    Solution s;
    vector<string> v{"a","b","c","ab","ac","aa"};
    vector<vector<int>> vv = s.palindromePairs(v);
    for (int i = 0; i < vv.size(); ++i) {
        cout<<vv[i][0]<<" "<<vv[i][1]<<endl;
    }
    return 0;
}