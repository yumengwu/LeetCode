#include "../header.h"

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return;
        }
        int m = matrix[0].size();
        v.resize(n);
        for (int i = 0; i < n; ++i) {
            v[i].resize(m);
            v[i][0] = matrix[i][0];
            for (int j = 1; j < m; ++j) {
                v[i][j] = v[i][j - 1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        if (col1 == 0) {
            for (int i = row1; i <= row2; ++i) {
                res += v[i][col2];
            }
        }
        else {
            for (int i = row1; i <= row2; ++i) {
                res += v[i][col2] - v[i][col1 - 1];
            }
        }
        return res;
    }
private:
    vector<vector<int>> v;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */