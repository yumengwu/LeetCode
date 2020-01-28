#include "../header.h"

class Master {
  public:
    int guess(string word);
};

class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int cur = 0, cnt = 0;
        while (cnt < 10 && cur < 6) {
            string str = wordlist[rand() % (wordlist.size())];
            cur = master.guess(str);
            if (cur == 6) {
                break;
            }
            vector<string> temp;
            for (int i = 0; i < wordlist.size(); ++i) {
                if (compare(wordlist[i], str) == cur) {
                    temp.push_back(wordlist[i]);
                }
            }
            wordlist = temp;
        }
    }
    
    int compare(string & s1, string & s2) {
        int res = 0;
        for (int i = 0; i < 6; ++i) {
            if (s1[i] == s2[i]) {
                ++res;
            }
        }
        return res;
    }
};