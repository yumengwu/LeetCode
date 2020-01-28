#include "../header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || n == 1) {
            return 0;
        }
        int has1sell = 0;
        int has1no = -prices[0];
        int has0no = 0;
        int has0buy = -prices[0];
        for (int i = 1; i < n; ++i) {
            if (has1no < has0buy) {
                has1no = has0buy;
            }
            has0buy = has0no - prices[i];
            if (has0no < has1sell) {
                has0no = has1sell;
            }
            has1sell = has1no + prices[i];
        }
        if (has1sell > has0no) {
            return has1sell;
        }
        else {
            return has0no;
        }
    }
};