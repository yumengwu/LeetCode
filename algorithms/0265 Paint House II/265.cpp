#include "../header.h"

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) {
            return 0;
        }
        if (costs[0].size() == 0) {
            return 0;
        }
        int min1 = 0, min2 = 0, index1 = -1;
        for (int i = 0; i < n; ++i) {
            int curm1 = INT_MAX, curm2 = curm1, curindex1 = -1;
            for (int j = 0; j < costs[i].size(); ++j) {
                int cost = costs[i][j] + (j == index1 ? min2 : min1);
                if (cost < curm1) {
                    curm2 = curm1;
                    curm1 = cost;
                    curindex1 = j;
                }
                else if (cost < curm2) {
                    curm2 = cost;
                }
            }
            min1 = curm1; min2 = curm2; index1 = curindex1;
        }
        return min1;
    }
};

int main()
{
    vector<vector<int>> v{{4,16},{15,5},{18,17},{10,12},{14,10},{3,10},{2,11},{18,14},{9,1},{14,13}};
    Solution s;
    cout<<s.minCostII(v)<<endl;
    return 0;
}