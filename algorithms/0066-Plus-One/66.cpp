#include "../header.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res = digits;
        int index = digits.size() - 1, carry = 1;
        while (index >= 0 && carry > 0) {
            int temp = res[index] + carry;
            res[index] = temp % 10;
            carry = temp / 10;
            --index;
        }
        if (carry) {
            res.insert(res.begin(), carry);
        }
        return res;
    }
};

/* class Solution { */
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         reverse(digits.begin(), digits.end());
//         int idx = 0, c = 1;
//         while (idx < digits.size() || c) {
//             if (c == 0) {
//                 break;
//             }
//             if (idx == digits.size()) {
//                 digits.push_back(c);
//                 break;
//             }
//             int t = digits[idx] + c;
//             digits[idx++] = t % 10;
//             c = t / 10;
//         }
//         reverse(digits.begin(), digits.end());
//         return digits;
//     }
/* }; */

