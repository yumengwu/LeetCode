#include "../header.h"

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) {
//             return 0;
//         }
//         vector<int> v(n, 0);
//         v[0] = 1;
//         int res = 1;
//         for (int i = 1; i < n; ++i) {
//             v[i] = 1;
//             for (int j = 0; j < i; ++j) {
//                 if (nums[j] < nums[i]) {
//                     v[i] = max(v[i], v[j] + 1);
//                 }
//             }
//             res = max(v[i], res);
//         }
//         return res;
//     }
// };

class Solution {
public:
    int binarySearch(vector<int> & v, int target) {
        int l = 0, r = v.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (v[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return r;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> rc;
        rc.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            if (nums[i] < rc[0]) {
                rc[0] = nums[i];
            }
            else if (nums[i] > rc.back()) {
                rc.push_back(nums[i]);
            }
            else {
                rc[binarySearch(rc, nums[i])] = nums[i];
            }
        }
        return rc.size();
    }
};

int main()
{
    vector<int> v{10,9,2,5,3,7,101,18};
    Solution s;
    cout<<s.lengthOfLIS(v)<<endl;
    return 0;
}