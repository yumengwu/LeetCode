#include "../header.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        if (amount == 0) {
            return 0;
        }
        if (coins.size() == 0) {
            return -1;
        }
        vector<int> v(amount + 1, INT_MAX);
        v[0] = 0;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                if (v[j - coins[i]] != INT_MAX && v[j] > v[j - coins[i]] + 1) {
                    v[j] = v[j - coins[i]] + 1;
                }
            }
        }
        return v[amount] == INT_MAX ? -1 : v[amount];
    }
};