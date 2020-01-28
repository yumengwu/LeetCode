#include "../header.h"

class Solution {
public:
    struct point {
        string s;
        int level;
    };
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        if (n == 0) {
            return 0;
        }
        unordered_set<string> s;
        for (int i = 0; i < n; ++i) {
            s.insert(wordList[i]);
        }
        if (s.find(endWord) == s.end()) {
            return 0;
        }
        point pp;
        pp.s = beginWord;
        pp.level = 1;
        queue<point> q;
        q.push(pp);
        while (q.size() > 0) {
            point ppp = q.front();
            q.pop();
            for (int i = 0; i < ppp.s.length(); ++i) {
                for (int j = 0; j < 26; ++j) {
                    string nstr = ppp.s;
                    nstr[i] = j + 'a';
                    if (nstr != ppp.s && s.find(nstr) != s.end()) {
                        if (nstr == endWord) {
                            return ppp.level + 1;
                        }
                        point pppp;
                        pppp.s = nstr;
                        pppp.level = ppp.level + 1;
                        s.erase(nstr);
                        q.push(pppp);
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
    vector<string> v{"hot","dot","dog","lot","log"};
    Solution s;
    cout<<s.ladderLength("hit", "cog", v)<<endl;
    return 0;
}