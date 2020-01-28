#include "../header.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        int l = 0, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (nums[m] > nums[r]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        l = r;
        r = l > 0 ? l - 1 : n - 1;
        int lm = -1;
        while (l != r) {
            unsigned int m;
            if (l < r) {
                m = l + (r - l) / 2;
            }
            else {
                m = (l + (r + n - l) / 2) % n;
            }
            if (nums[m] == target) {
                return m;
            }
            if (m == lm) {
                break;
            }
            lm = m;
            if (nums[m] > target) {
                r = m;
            }
            else {
                l = (m + 1) % n;
            }
        }
        if (nums[l] == target) {
            return l;
        }
        return -1;
    }
};

int main()
{
    return 0;
}