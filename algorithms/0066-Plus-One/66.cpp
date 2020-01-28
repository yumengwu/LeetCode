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