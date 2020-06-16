#include "../header.h"

/* class Solution { */
// public:
//     bool isNumber(string s) {
//         s = trim(s);
//         if (s.length() == 0) {
//             return false;
//         }
//         return std::regex_match(s, std::regex("[-+]?(\\d+\\.?|\\.\\d+)\\d*(e[-+]?\\d+)?"));
//     }
//
//     string trim(string s) {
//         int n = s.length();
//         int l = 0, r = n - 1;
//         while (l < n && s[l] == ' ') ++l;
//         while (r >= 0 && s[r] == ' ') --r;
//         return r - l >= 0 ? s.substr(l, r - l + 1) : "";
//     }
// };
//
// int main()
// {
//     Solution s;
//     cout<<s.isNumber("4 9")<<endl;
//     return 0;
/* } */

// regex
/* class Solution { */
// public:
//     bool isNumber(string s) {
//         s = trim(s);
//         if (s.length() == 0 || s[0] == '+' || s[0] == '-') {
//             return false;
//         }
//         bool b = false;
//         for (char c : s) {
//             if (!(c == '+' || c == '-' || c == '.' || c == 'e' || (c >= '0' && c <= '9'))) {
//                 return false;
//             }
//             if (c == '.' || c == 'e' || c == '+' || c == '-') {
//                 b = true;
//                 break;
//             }
//         }
//         if (b) {
//             if (std::regex_match(s, std::regex("^\\d*\\.\\d+$"))) {
//                 return true;
//             }
//             if (std::regex_match(s, std::regex("^\\d+\\.\\d*$"))) {
//                 return true;
//             }
//             int idx = -1;
//             for (int i = 0; i < s.length(); ++i) {
//                 if (s[i] == 'e') {
//                     idx = i;
//                     break;
//                 }
//             }
//             if (idx == s.length()) {
//                 return false;
//             }
//             string left = s.substr(0, idx), right = s.substr(idx + 1);
//             if (!(std::regex_match(left, std::regex("^\\d+$")) || std::regex_match(left, std::regex("^\\d*\\.\\d+$")) || std::regex_match(left, std::regex("^\\d+\\.\\d*$")))) {
//                 return false;
//             }
//             return std::regex_match(right, std::regex("^[+-]?\\d+$"));
//         }
//         else {
//             return std::regex_match(s, std::regex("^\\d+$"));
//         }
//         return false;
//     }
//
//     string trim(string s) {
//         int n = s.length();
//         int l = 0, r = n - 1;
//         while (l < n && s[l] == ' ') ++l;
//         while (r >= 0 && s[r] == ' ') --r;
//         if (s[l] == '+' || s[l] == '-') ++l;
//         return r - l >= 0 ? s.substr(l, r - l + 1) : "";
//     }
/* }; */

class Solution {
public:
    bool isNumber(string s) {
        s = trim(s);
        if (s.length() == 0 || s[0] == '+' || s[0] == '-') {
            return false;
        }
        bool b = false;
        for (char c : s) {
            if (!(c == '+' || c == '-' || c == '.' || c == 'e' || (c >= '0' && c <= '9'))) {
                return false;
            }
            if (c == '.' || c == 'e' || c == '+' || c == '-') {
                b = true;
                break;
            }
        }
        if (b) {
            if (parseDigit(s)) {
                return true;
            }
            int idx = -1;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] == 'e') {
                    idx = i;
                    break;
                }
            }
            if (idx == s.length()) {
                return false;
            }
            string left = s.substr(0, idx), right = s.substr(idx + 1);
            if (!(parseNum(left) || parseDigit(left))) {
                return false;
            }
            // return std::regex_match(right, std::regex("^[+-]?\\d+$"));
            return right[0] == '-' || right[0] == '+' ? parseNum(right.substr(1)) : parseNum(right);
        }
        else {
            return parseNum(s);
        }
        return false;
    }

    bool parseNum(string s) {
        if (s.length() == 0) {
            return false;
        }
        for (char c : s) {
            if (c < '0' || c > '9') {
                return false;
            }
        }
        return true;
    }

    bool parseDigit(string s) {
        if (s.length() == 0) {
            return false;
        }
        int idx = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '.') {
                idx = i;
                break;
            }
        }
        if (idx < 0) {
            return false;
        }
        if (idx == 0 && s.length() == 1) {
            return false;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (i == idx) {
                continue;
            }
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }
        return true;
    }

    string trim(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while (l < n && s[l] == ' ') ++l;
        while (r >= 0 && s[r] == ' ') --r;
        if (s[l] == '+' || s[l] == '-') ++l;
        return r - l >= 0 ? s.substr(l, r - l + 1) : "";
    }
};

