#include "../header.h"

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.length() <= 1) {
            return "";
        }
        int n = palindrome.length() >> 1;
        for (int i = 0; i < n; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome.back() = 'b';
        return palindrome;
    }
};