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
        int l = 0, r = m;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (l == r - 1) {
                break;
            }
            if (matrix[mid][0] == target) {
                return true;
            }
            if (matrix[mid][0] > target) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        int row = l;
        if (target < matrix[row][0] || target > matrix[row].back()) {
            return false;
        }
        l = 0;
        r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] == target) {
                return true;
            }
            if (matrix[row][mid] > target) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    cout<<s.searchMatrix(v, 34)<<endl;
    return 0;
}