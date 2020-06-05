#include "../header.h"

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> tm;
        for (int i : target) {
            ++tm[i];
        }
        for (int i : arr) {
            if (!tm.count(i)) {
                return false;
            }
            --tm[i];
        }
        for (auto it = tm.begin(); it != tm.end(); ++it) {
            if (it->second != 0) {
                return false;
            }
        }
        return true;
    }
};

