#include "../header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int res = 0, curMin = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            curMin = min(curMin, prices[i]);
            res = max(res, prices[i] - curMin);
        }
        return res;
    }
};