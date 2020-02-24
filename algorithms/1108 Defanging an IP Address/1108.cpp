#include "../header.h"

class Solution {
public:
    string defangIPaddr(string address) {
        char temp[address.length() + 7] = {0};
        int i = 0;
        for (int j = 0; j < address.length(); ++j) {
            if (address[j] != '.') {
                temp[i++] = address[j];
            }
            else {
                temp[i++] = '[';
                temp[i++] = '.';
                temp[i++] = ']';
            }
        }
        string res = temp;
        return res;
    }
};