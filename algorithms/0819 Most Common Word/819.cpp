#include "../header.h"

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string res = "";
        int rescnt = 0;
        set<string> s;
        for (int i = 0; i < banned.size(); ++i) {
            s.insert(banned[i]);
        }
        map<string, int> cnt;
        vector<string> sl = split(paragraph);
        for (int i = 0; i < sl.size(); ++i) {
            if (s.find(sl[i]) == s.end()) {
                ++cnt[sl[i]];
                if (cnt[sl[i]] > rescnt) {
                    res = sl[i];
                    rescnt = cnt[sl[i]];
                }
            }
        }
        return res;
    }
    vector<string> split(string s) {
        vector<string> res;
        string temp = "";
        int index = 0;
        while (index < s.length() && s[index] == ' ') {
            ++index;
        }
        for (; index < s.length(); ++index) {
            if (!(s[index] >= 'a' && s[index] <= 'z' || s[index] >= 'A' && s[index] <= 'Z')) {
                res.push_back(temp);
                temp = "";
                while (index < s.length() - 1 && !(s[index + 1] >= 'a' && s[index + 1] <= 'z' || s[index + 1] >= 'A' && s[index + 1] <= 'Z')) {
                    ++index;
                }
            }
            else {
                temp += s[index] >= 'a' && s[index] <= 'z' ? s[index] : s[index] - 'A' + 'a';
            }
        }
        if (temp.length()) {
            res.push_back(temp);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> v{};
    cout<<s.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", v)<<endl;
    return 0;
}