#include "../header.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int n = s.length();
        string res = "";
        if (n == 0) {
            return res;
        }
        vector<string> v(numRows, "");
        int index = 0;
        char dire = 'd';
        for (int i = 0; i < n; ++i) {
            v[index] += s[i];
            if (dire == 'd') {
                if (index == numRows - 1) {
                    --index;
                    dire = 'u';
                }
                else {
                    ++index;
                }
            }
            else {
                if (index == 0) {
                    ++index;
                    dire = 'd';
                }
                else {
                    --index;
                }
            }
        }
        for (int i = 0; i < numRows; ++i) {
            res += v[i];
        }
        return res;
    }
};

// class Solution {
// public:
//     string convert(string s, int numRows) {
//         int n = s.length();
//         if (numRows == 1 || n < 2) {
//             return s;
//         }
//         vector<string> v(numRows, "");
//         char c = 'd';
//         int idx = 0;
//         for (int i = 0; i < n; ++i) {
//             v[idx] += s[i];
//             if (c == 'd') {
//                 if (idx == numRows - 1) {
//                     --idx;
//                     c = 'u';
//                 }
//                 else {
//                     ++idx;
//                 }
//             }
//             else {
//                 if (idx == 0) {
//                     ++idx;
//                     c = 'd';
//                 }
//                 else {
//                     --idx;
//                 }
//             }
//         }
//         string res = "";
//         for (int i = 0; i < numRows; ++i) {
//             res += v[i];
//         }
//         return res;
//     }
// };