#include "../header.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                --i;
            }
            else {
                ++j;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> v{{-1,3}};
    Solution s;
    cout<<s.searchMatrix(v, 3)<<endl;
    return 0;
}