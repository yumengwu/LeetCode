#include "../header.h"

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();

class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]].push_back(i);
        }
        srand(time(0));
    }

    int pick(int target) {
        int i = rand() % m[target].size();
        return m[target][i];
    }

private:
    unordered_map<int, vector<int>> m;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

