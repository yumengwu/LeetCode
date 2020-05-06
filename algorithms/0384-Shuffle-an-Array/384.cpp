#include "../header.h"

static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();

class Solution {
public:
    Solution(vector<int>& nums) {
        v = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> vs = v;
        for (int i = 0; i < vs.size(); ++i) {
            int t = i + rand() % (vs.size() - i);
            swap(vs[i], vs[t]);
        }
        return vs;
    }
    
private:
    vector<int> v;
};