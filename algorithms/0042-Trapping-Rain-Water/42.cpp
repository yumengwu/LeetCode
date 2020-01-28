#include "../header.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int topHeight = -1;
        int curTop = 0;
        int total = 0;
        int temp = 0;
        int len = height.size();
        for (int i = 0; i < len; ++i) {
            if (height[i] >= curTop) {
                total += temp;
                temp = 0;
                curTop = height[i];
            }
            else {
                temp += curTop - height[i];
            }
            if (height[i] > topHeight) {
                topHeight = height[i];
            }
        }
        curTop = 0;
        temp = 0;
        for (int i = len - 1; i >= 0; --i) {
            if (height[i] >= curTop) {
                total += temp;
                temp = 0;
                curTop = height[i];
            }
            else {
                temp += curTop - height[i];
            }
            if (height[i] == topHeight) {
                break;
            }
        }
        return total;
    }
};

int main()
{
    return 0;
}