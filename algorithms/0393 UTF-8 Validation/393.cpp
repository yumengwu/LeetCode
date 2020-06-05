#include "../header.h"

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, n = data.size();
        while (i < n) {
            if ((data[i] & 0x80) == 0) {
                ++i;
                continue;
            }
            else if ((data[i] & 0x40) > 0 
                    && (data[i] & 0x20) == 0) {
                if (i + 1 >= n 
                        || !((data[i + 1] & 0x80) > 0 
                            && (data[i + 1] & 0x40) == 0)) {
                    return false;
                }
                i += 2;
                continue;
            }
            else if ((data[i] & 0x40) > 0 
                    && (data[i] & 0x20) > 0 && (data[i] & 0x10) == 0) {
                if (i + 2 >= n 
                        || !((data[i + 1] & 0x80) > 0 
                            && (data[i + 1] & 0x40) == 0 
                            && (data[i + 2] & 0x80) > 0 
                            && (data[i + 2] & 0x40) == 0)) {
                    return false;
                }
                i += 3;
                continue;
            }
            else if ((data[i] & 0x40) > 0 && (data[i] & 0x20) > 0 
                    && (data[i] & 0x10) > 0 && (data[i] & 0x08) == 0) {
                if (i + 3 >= n 
                        || !((data[i + 1] & 0x80) > 0 
                            && (data[i + 1] & 0x40) == 0 
                            && (data[i + 2] & 0x80) > 0 
                            && (data[i + 2] & 0x40) == 0 
                            && (data[i + 3] & 0x80) > 0 
                            && (data[i + 3] & 0x40) == 0)) {
                    return false;
                }
                i += 4;
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

