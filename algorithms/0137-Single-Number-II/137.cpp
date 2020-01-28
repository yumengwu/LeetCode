#include "../header.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            one = ~two & (one ^ nums[i]);
            two = ~one & (two ^ nums[i]);
        }
        return one;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         set<int> s;
//         int n = nums.size();
//         long ns = 0;
//         for (int i = 0; i < n; ++i) {
//             ns += nums[i];
//             s.insert(nums[i]);
//         }
//         for (auto it = s.begin(); it != s.end(); ++it) {
//             ns -= *it;
//             ns -= *it;
//             ns -= *it;
//         }
//         return (-ns) / 2;
//     }
// };