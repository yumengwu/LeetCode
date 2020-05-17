#include "../header.h"
/*
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
};*/

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> st;
        unordered_map<string, int> m;
        for (string str : banned) {
            st.insert(tolower(str));
        }
        int idx = 0, n = paragraph.length();
        while (idx < n) {
            while (idx < n && !(paragraph[idx] >= 'a' && paragraph[idx] <= 'z' || paragraph[idx] >= 'A' && paragraph[idx] <= 'Z')) ++idx;
            if (idx == n) continue;
            int j = 1;
            while (idx + j < n && (paragraph[idx + j] >= 'a' && paragraph[idx + j] <= 'z' || paragraph[idx + j] >= 'A' && paragraph[idx + j] <= 'Z')) ++j;
            string cur = tolower(paragraph.substr(idx, j));
            if (!st.count(cur)) {
                ++m[cur];
            }
            idx += j;
        }
        string ms;
        int mn = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second > mn) {
                mn = it->second;
                ms = it->first;
            }
        }
        return ms;
    }

    string tolower(string str) {
        string s = str;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] - 'A' + 'a';
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    vector<string> v{};
    cout<<s.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", v)<<endl;
    return 0;
}
