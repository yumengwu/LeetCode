#include "../header.h"

class Solution {
public:
    void sp(vector<int> & nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int i = 0, j = 0;
        while (j < n) {
            sp(nums, i, j++);
            if (j == n) {
                i++;
                break;
            }
            if (nums[j] == nums[i]) {
                sp(nums, ++i, j++);
            }
            while (j < n && nums[j] == nums[i]) {
                j++;
            }
            i++;
        }
        return i;
    }
};

int main()
{
    Solution s;
    vector<int> v{0,0,0,1,1,1,1,2,3,3};
    cout<<s.removeDuplicates(v)<<endl;
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<' ';
    }cout<<endl;
    return 0;
}