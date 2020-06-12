#include "../header.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        for (int num : nums) {
            set<vector<int>> temp;
            if (res.empty()) {
                temp.insert({num});
            }
            else {
                for (auto vec : res) {
                    for (int j = 0; j <= vec.size(); ++j) {
                        vec.insert(vec.begin() + j, num);
                        temp.insert(vec);
                        vec.erase(vec.begin() + j);
                    }
                }
            }
            res = temp;
        }
        return {res.begin(), res.end()};
    }
};

