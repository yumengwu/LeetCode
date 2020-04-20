#include "../header.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            m[target - nums[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            auto it = m.find(nums[i]);
            if (it != m.end() && i != it->second) {
                return {i, it->second};
            }
        }
        return {};
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int> res;
//         if (n < 2) {
//             return res;
//         }
//         map<int, int> m;
//         for (int i = 0; i < n; ++i) {
//             m[target - nums[i]] = i;
//         }
//         for (int i = 0; i < n; ++i) {
//             if (m.find(nums[i]) != m.end() && m[nums[i]] != i) {
//                 res.push_back(i);
//                 res.push_back(m[nums[i]]);
//                 break;
//             }
//         }
//         return res;
//     }
// };