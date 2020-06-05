#include "../header.h"

// use map
class Solution {
public:
    string entityParser(string text) {
        string res;
        int idx = 0, n = text.size();
        map<string, char> m{{"&quot;", '\"'}, {"&apos;", '\''}, {"&amp;", '&'}, {"&gt;", '>'}, {"&lt;", '<'}, {"&frasl;", '/'}};
        while (idx < n) {
            if (text[idx] != '&') {
                res += text[idx++];
                continue;
            }
            int l = cmp(text, res, idx, m);
            if (l > 0) {
                idx += l;
            }
            else {
                res += text[idx++];
            }
        }
        return res;
    }
    
    int cmp(string& s, string& res, int idx, map<string, char>& m) {
        int i = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            string cur = it->first;
            if (s.substr(idx, cur.length()) == cur) {
                res += it->second;
                return cur.length();
            }
        }
        return i;
    }
};

/*
class Solution {
public:
    string entityParser(string text) {
        string res;
        int idx = 0, n = text.size();
        while (idx < n) {
            if (text[idx] != '&') {
                res += text[idx++];
                continue;
            }
            string temp = text.substr(idx, 6);
            if (temp == "&quot;") {
                res += '\"';
                idx += temp.length();
                continue;
            }
            if (temp == "&apos;") {
                res += '\'';
                idx += temp.length();
                continue;
            }
            temp = text.substr(idx, 5);
            if (temp == "&amp;") {
                res += '&';
                idx += temp.length();
                continue;
            }
            temp = text.substr(idx, 4);
            if (temp == "&gt;") {
                res += '>';
                idx += temp.length();
                continue;
            }
            if (temp == "&lt;") {
                res += '<';
                idx += temp.length();
                continue;
            }
            temp = text.substr(idx, 7);
            if (temp == "&frasl;") {
                res += '/';
                idx += temp.length();
                continue;
            }
            res += text[idx++];
        }
        return res;
    }
};*/

