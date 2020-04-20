#include "../header.h"

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        int index = 0;
        int len = 1;
        int oddOrEven = 1;
        for (int i = 0; i < s.length(); ++i) {
            int odd = searchOdd(s, i);
            int even = searchEven(s, i);
            if (odd > len) {
                index = i;
                len = odd;
                oddOrEven = 1;
            }
            if (even > len) {
                index = i;
                len = even;
                oddOrEven = 0;
            }
        }
        if (oddOrEven == 0) {
            return s.substr(index - len / 2 + 1, len);
        }
        else {
            return s.substr(index - len / 2, len);
        }
    }
    int searchOdd(string & s, int index) {
        int res = 1;
        for (int i = index - 1; i >= 0; --i) {
            if (i >= s.length()) {
                break;
            }
            if (s[i] == s[index - i +index]) {
                res += 2;
            }
            else {
                break;
            }
        }
        return res;
    }
    int searchEven(string & s, int index) {
        int res = 0, i = index, j = index + 1;
        while (i >= 0 && j < s.length()) {
            if (s[i--] == s[j++]) {
                res += 2;
            }
            else {
                break;
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.length();
//         if (n <= 1) {
//             return s;
//         }
//         int idx = 0;
//         int len = 0;
//         bool isOdd = true;
//         for (int i = 0; i < n; ++i) {
//             int templen;
//             bool tempIsOdd;
//             helper(s, i, templen, tempIsOdd);
//             if (templen > len) {
//                 idx = i;
//                 len = templen;
//                 isOdd = tempIsOdd;
//             }
//         }
//         return isOdd ? s.substr(idx - ((len - 1) >> 1), len) : s.substr(idx - ((len - 2) >> 1), len);
//     }
    
//     void helper(string& s, int idx, int& len, bool& isOdd) {
//         int lo = 1;
//         int i = idx - 1;
//         int n = s.length();
//         while (i >= 0 && (idx << 1) - i < n && s[i] == s[(idx << 1) - i]) {
//             lo += 2;
//             --i;
//         }
//         int le = 0;
//         i = idx;
//         while (i >= 0 && (idx << 1) + 1 - i < n && s[i] == s[(idx << 1) + 1 - i]) {
//             le += 2;
//             --i;
//         }
//         if (lo > le) {
//             len = lo;
//             isOdd = true;
//         }
//         else {
//             len = le;
//             isOdd = false;
//         }
//     }
// };

int main()
{
    Solution s;
    cout<<s.longestPalindrome("aiwdhwdhawdawhdaiwihiahwduiawhiua")<<endl;
    return 0;
}