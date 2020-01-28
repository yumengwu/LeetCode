#include "../header.h"

// brute force
// class Solution {
// public:
//     bool checkValidString(string s) {
//         if (s.length() == 0) {
//             return true;
//         }
//         return helper(s, 0, 0);
//     }
    
//     bool helper(string & s, int start, int cnt) {
//         if (cnt < 0) {
//             return false;
//         }
//         for (int i = start; i < s.length(); ++i) {
//             if (s[i] == '(') {
//                 ++cnt;
//             }
//             else if (s[i] == ')') {
//                 --cnt;
//                 if (cnt < 0) {
//                     return false;
//                 }
//             }
//             else {
//                 return helper(s, i + 1, cnt) || helper(s, i + 1, cnt + 1) || helper(s, i + 1, cnt - 1);
//             }
//         }
//         return cnt == 0;
//     }
// };

// stack
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        if (n == 0) {
            return true;
        }
        stack<int> left, star;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                left.push(i);
            }
            else if (s[i] == '*') {
                star.push(i);
            }
            else {
                if (left.size() == 0 && star.size() == 0) {
                    return false;
                }
                if (left.size()) {
                    left.pop();
                }
                else {
                    star.pop();
                }
            }
        }
        while (left.size() && star.size()) {
            if (left.top() > star.top()) {
                return false;
            }
            left.pop(); star.pop();
        }
        return left.empty();
    }
};