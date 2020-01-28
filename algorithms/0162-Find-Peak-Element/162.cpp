#include "../header.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        int l = 1, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid - 1;
            }
            if (nums[mid] > nums[mid - 1]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l - 1;
    }
};

int main()
{
    vector<int> v{1,2,3,1};
    Solution s;
    cout<<s.findPeakElement(v)<<endl;
    return 0;
}