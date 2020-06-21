#include "../header.h"

// one pass
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size() - 1;
        for (int i = 0; i <= blue; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[red++]);
            }
            else if (nums[i] == 2) {
                swap(nums[i--], nums[blue--]);
            } 
        }
    }
};

/* class Solution { */
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> cnt(3, 0);
//         for (int i = 0; i < n; ++i) {
//             ++cnt[nums[i]];
//         }
//         for (int i = 0; i < cnt[0]; ++i) {
//             nums[i] = 0;
//         }
//         for (int i = 0; i < cnt[1]; ++i) {
//             nums[i + cnt[0]] = 1;
//         }
//         for (int i = 0; i < cnt[2]; ++i) {
//             nums[i + cnt[0] + cnt[1]] = 2;
//         }
//     }
/* }; */

/* class Solution { */
// public:
//     void sortColors(vector<int>& nums) {
//         int cnta = 0, cntb = 0, cntc = 0;
//         for (int i : nums) {
//             switch (i) {
//                 case 0:
//                     ++cnta;
//                     break;
//                 case 1:
//                     ++cntb;
//                     break;
//                 case 2:
//                     ++cntc;
//                     break;
//                 default:
//                     break;
//             }
//         }
//         int idx = 0;
//         while (cnta--) {
//             nums[idx++] = 0;
//         }
//         while (cntb--) {
//             nums[idx++] = 1;
//         }
//         while (cntc--) {
//             nums[idx++] = 2;
//         }
//     }
/* }; */

