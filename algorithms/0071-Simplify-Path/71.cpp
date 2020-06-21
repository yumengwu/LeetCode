#include "../header.h"

/* class Solution { */
// public:
//     string simplifyPath(string path) {
//         vector<string> v = split(path);
//         stack<string> s;
//         for (int i = 0; i < v.size(); ++i) {
//             if (v[i] == ".") {
//                 continue;
//             }
//             if (v[i] == "..") {
//                 if (!s.empty()) {
//                     s.pop();
//                 }
//             }
//             else {
//                 s.push(v[i]);
//             }
//         }
//         if (s.empty()) {
//             return "/";
//         }
//         else {
//             string res = "";
//             while (!s.empty()) {
//                 res = "/" + s.top() + res;
//                 s.pop();
//             }
//             return res;
//         }
//     }
//     vector<string> split(string str) {
//         vector<string> v;
//         if (str.length() == 0) {
//             return v;
//         }
//         string temp = "";
//         for (int i = 0; i < str.length(); ++i) {
//             if (str[i] != '/') {
//                 temp += str[i];
//             }
//             else {
//                 if (temp != "") {
//                     v.push_back(temp);
//                 }
//                 temp = "";
//             }
//         }
//         if (temp != "") {
//             v.push_back(temp);
//         }
//         return v;
//     }
/* }; */

class Solution {
public:
    string simplifyPath(string path) {
        int idx = 0, n = path.length();
        list<string> l;
        while (idx < n) {
            int j = idx + 1;
            while (j < n && path[j] != '/') ++j;
            string s = path.substr(idx + 1, j - idx - 1);
            if (s == "..") {
                if (l.size()) {
                    l.pop_back();
                }
            }
            else if (!(s == "" || s == ".")) {
                l.push_back(s);
            }
            idx = j;
        }
        if (l.size() && l.back() == "")
            l.pop_back();
        string res;
        if (l.empty()) {
            res = "/";
        }
        else {
            for (string s : l) {
                res += "/";
                res += s;
            }
        }
        return res;
    }
};

