#include "../header.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = temp;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][n - i - 1];
                matrix[n - j - 1][n - i - 1] = temp;
            }
        }
    }
};

int main()
{
    vector<vector<int>> v{{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.rotate(v);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}