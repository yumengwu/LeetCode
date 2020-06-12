#include "../header.h"

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (n == 2) {
            return true;
        }
        sort(coordinates.begin(), coordinates.end(),
             [] (const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        if (coordinates[0][0] == coordinates[1][0]) {
            for (int i = 2; i < n; ++i) {
                if (coordinates[i][0] != coordinates[0][0]) {
                    return false;
                }
            }
            return true;
        }
        else {
            double d = (coordinates[1][1] - coordinates[0][1] + 0.0) / (coordinates[1][0] - coordinates[0][0]);
            for (int i = 2; i < n; ++i) {
                double t = (coordinates[i][1] - coordinates[0][1] + 0.0) / (coordinates[i][0] - coordinates[0][0]);
                if (abs(d - t) > 0.00001) {
                    return false;
                }
            }
            return true;
        }
    }
};

